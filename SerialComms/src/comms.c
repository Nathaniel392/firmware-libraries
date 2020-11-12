/*
 * comms.c
 *
 *  Created on: Jul 21, 2020
 *      Author: Arthur Zhang, Jack Taliercio
 */

#include "../../SerialComms/inc/comms.h"

void init_board(uint8_t board_addr) {
	CLB_board_addr = board_addr;
}

void init_data(uint8_t *buffer, int16_t buffer_sz, CLB_Packet_Header* header) {
	if (buffer_sz == -1) {	// standard telem
	    // repack CLB_telem_data
	    pack_telem_data(CLB_telem_data);
		CLB_buffer = CLB_telem_data;
		CLB_buffer_sz = NUM_TELEM_ITEMS;
	} else {				// custom telem
		CLB_buffer = buffer;
		CLB_buffer_sz = buffer_sz;
	}
	CLB_header = header;
}

uint8_t send_data(UART_HandleTypeDef* uartx) {
	/* Procedure for sending data:
		1. Compute checksum for given data, updating packet header
		2. Stuff packet from buffer
		3. Send packet via UART
		4. Repeats steps 2-3 until buffer is fully transmitted
		5. Return status/errors in transmission if they exist
	*/
	uint16_t clb_pos = 0;						// position in clb buffer
	uint16_t clb_sz = CLB_buffer_sz;			// clb buffer sz
	uint16_t ping_pos = 0;						// position in ping buffer
	uint16_t ping_sz = PING_MAX_PACKET_SIZE;	// packet size

	// Note: assumes that header sz is less than 255 bytes
	uint8_t header_buffer[CLB_HEADER_SZ] = {0};
	CLB_header->checksum = compute_checksum();
	pack_header(CLB_header, header_buffer);
	pack_packet(header_buffer, CLB_ping_packet+ping_pos, CLB_HEADER_SZ);
	ping_pos += CLB_HEADER_SZ;

	uint8_t send_termination_bit = 0;
	while (clb_pos < CLB_buffer_sz) {
		uint16_t clb_sz_left = clb_sz - clb_pos;
		uint16_t ping_sz_left = ping_sz - ping_pos;
		uint16_t transfer_sz_left = (clb_sz_left > ping_sz_left) ? 
										ping_sz_left : clb_sz_left;
		// fill up ping buffer as much as possible
		pack_packet(CLB_buffer+clb_pos, CLB_ping_packet+ping_pos, 
													transfer_sz_left);
		
		clb_pos += transfer_sz_left;
		ping_pos += transfer_sz_left;

		uint16_t stuffed_packet_sz = stuff_packet(CLB_ping_packet, 
											CLB_pong_packet, ping_pos);

		// add termination character to transmission if possible
		if (clb_pos == clb_sz) {
		    if (stuffed_packet_sz < 255) {
		        CLB_pong_packet[stuffed_packet_sz++] = 0;
		    } else {
		        send_termination_bit = 1;
		    }
		}

		transmit_packet(uartx, stuffed_packet_sz);

		if (ping_pos >= ping_sz) {
			ping_pos = 0;
		}
	}

	if (send_termination_bit) {
	    CLB_pong_packet[0] = 0;
	    transmit_packet(uartx, 1);
	}
	return 0; // TODO: return better error handling
}

uint8_t receive_data(UART_HandleTypeDef* uartx) {
	/**	Procedure for receiving data:
	 * 	1. Receive first packet, parse header
	 * 	2. Specific behavior depending on packet_type and target_addr
	 *  3. Verify checksum after decoding all data
	 * 
	 * 	Note: 	The boards only expect to receive data/cmds within 254 bytes
	 * 	       	any custom packet types that require more than 254 bytes will
	 * 			have to be spread out over multiple packet type ids
	 */
	receive_packet(uartx, PONG_MAX_PACKET_SIZE);

	unstuff_packet(CLB_pong_packet, CLB_ping_packet, PONG_MAX_PACKET_SIZE);

	CLB_Packet_Header header;
	unpack_header(&header, CLB_ping_packet);

	uint8_t checksum_status = verify_checksum(header.checksum);
	if (checksum_status!=0) {
		return 1; // drop transmission if checksum is bad
	}

	uint8_t cmd_status = 0;
	if (CLB_board_addr == header.target_addr) {
		(*cmds_ptr[header.packet_type])(CLB_ping_packet, &cmd_status);
	}

	// TODO: more error handling depending on cmd status
	return cmd_status;
}

void receive_packet(UART_HandleTypeDef* uartx, uint16_t sz) {
	HAL_UART_Receive(uartx, CLB_pong_packet, sz, 1);
}

void transmit_packet(UART_HandleTypeDef* uartx, uint16_t sz) {
	// currently abstracted in case we need more transmisison options
	// transmit packet via serial TODO: error handling
    for (uint16_t i = 0; i < sz; ++i) {
        CLB_pong_packet[i] += '0'; // convert to ASCII before UART transmission
    }
	HAL_UART_Transmit(uartx, CLB_pong_packet, sz, HAL_MAX_DELAY);
}

void unpack_header(CLB_Packet_Header* header, uint8_t* header_buffer) {
	header->packet_type = header_buffer[0];
	header->target_addr = header_buffer[1];
	header->priority	= header_buffer[2];
	header->checksum	= (header_buffer[4]<<8)|header_buffer[3];
}

void pack_header(CLB_Packet_Header* header, uint8_t*header_buffer) {
	header_buffer[0] = header->packet_type;
	header_buffer[1] = header->target_addr;
	header_buffer[2] = header->priority;
	header_buffer[3] = 0xff&(header->checksum);		// little endian
	header_buffer[4] = 0xff&((header->checksum)>>8);
}

void pack_packet(uint8_t *src, uint8_t *dst, uint16_t sz) {
	uint8_t *curr = src;
	uint8_t *end = src + sz;
	while (curr != end) {
		*dst++ = *curr++;
	}
}

uint8_t verify_checksum(uint16_t checksum) {
	// TODO: Implement checksum checking procedure
	return 0;
}

uint16_t compute_checksum() {
	// TODO: Implement checksum procedure, use 0 dummy value temporarily
	return 0; 
}

//This code was shamelessly stolen from wikipedia, docs by me tho
uint16_t stuff_packet(uint8_t *unstuffed, uint8_t *stuffed, uint16_t length) {

	//Start just keeps track of the start point
	uint8_t *start = stuffed;
	//Code represents the number of positions till the next 0 and code_ptr
	//holds the position of the last zero to be updated when the next 0 is found
	uint8_t code = 1;
	uint8_t *code_ptr = stuffed++; //Note: this sets code_ptr to stuffed, then ++ stuffed

	while (length--)
	{
		//If the current byte is not zero, add that byte to stuffed data and increment
		//the position of the last zero (code)
		if (*unstuffed){
			*stuffed++ = *unstuffed;
			++code;

		}
		//IF the current byte is not zero, OR if the current code is maxed out
		//Update the last zero position with code, reset code, and set the code_ptr
		//To the new stuffed position
		if (!*unstuffed++ || code == 0xFF){ /* Input is zero or complete block */
			*code_ptr = code;
			code = 1;
			code_ptr = stuffed++;
		}
	}
	//Set the final code
	*code_ptr = code;
	//Returns length of encoded data
	return stuffed - start;
}


/*
 * UnStuffData decodes "length" bytes of data at
 * the location pointed to by "ptr", writing the
 * output to the location pointed to by "dst".
 *
 * Returns the length of the decoded data
 * (which is guaranteed to be <= length).
 */
uint16_t unstuff_packet(uint8_t *stuffed, uint8_t *unstuffed, uint16_t length)
{
	uint8_t *start = unstuffed, *end = stuffed + length;
	uint8_t code = 0xFF, copy = 0;

	for (; stuffed < end; copy--) {
		if (copy != 0) {
			*unstuffed++ = *stuffed++;
		} else {
			if (code != 0xFF)
				*unstuffed++ = 0;
			copy = code = *stuffed++;
			if (code == 0)
				break; /* Source length too long */
		}
	}
	return unstuffed - start;
}
