/// BEGIN AUTOGENERATED SECTION - MODIFICATIONS TO THIS CODE WILL BE OVERWRITTEN


/// telem_parser.py
/// Autogenerated by telem_defines_globals_generate.py on Sun Dec 20 13:50:00 2020

import time
import struct

class TelemParser:

	def __init__(self):
		self.csv_header = "Time (s),valve_states (),pressure[0] (counts),pressure[1] (counts),pressure[2] (counts),pressure[3] (counts),pressure[4] (counts),pressure[5] (counts),pressure[6] (counts),pressure[7] (counts),ebatt (Volts),main_cycle_time (Amps),motor_cycle_time (),adc_cycle_time (counts),telemetry_cycle_time (counts),load[2] (counts),load[3] (counts),telemetry_rate (counts),load[5] (counts),load[6] (counts),load[7] (counts),ivlv[0] (Amps),ivlv[1] (Amps),ivlv[2] (Amps),ivlv[3] (Amps),ivlv[4] (Amps),ivlv[5] (Amps),ivlv[6] (Amps),ivlv[7] (Amps),evlv[0] (Volts),evlv[1] (Volts),evlv[2] (Volts),evlv[3] (Volts),evlv[4] (Volts),evlv[5] (Volts),evlv[6] (Volts),evlv[7] (Volts),e3v (Volts),e5v (Volts),e28v (Volts),i5v (amps),i3v (amps),last_command_id (),tc[0] (K),tc[1] (K),tc[2] (K),tc[3] (K),tc[4] (K),tc[5] (K),tc[6] (K),tc[7] (K),rtd[0] (K),rtd[1] (K),rtd[2] (K),rtd[3] (K),rtd[4] (K),rtd[5] (K),rtd[6] (K),rtd[7] (K),i_mtr_ab[0] (amps),i_mtr_ab[1] (amps),i_mtr_ab[2] (amps),i_mtr_ab[3] (amps),i_mtr[0] (amps),i_mtr[1] (amps),zero (Volts),zero (Volts),zero (Volts),zero (Volts),\n"
		self.log_string = ""
		self.num_items = 68
		
		self.dict = {}
		
		self.items = [''] * self.num_items
		self.items[0] = 'valve_states' 
		self.items[1] = 'pressure[0]' 
		self.items[2] = 'pressure[1]' 
		self.items[3] = 'pressure[2]' 
		self.items[4] = 'pressure[3]' 
		self.items[5] = 'pressure[4]' 
		self.items[6] = 'pressure[5]' 
		self.items[7] = 'pressure[6]' 
		self.items[8] = 'pressure[7]' 
		self.items[9] = 'ebatt' 
		self.items[10] = 'main_cycle_time' 
		self.items[11] = 'motor_cycle_time' 
		self.items[12] = 'adc_cycle_time' 
		self.items[13] = 'telemetry_cycle_time' 
		self.items[14] = 'load[2]' 
		self.items[15] = 'load[3]' 
		self.items[16] = 'telemetry_rate' 
		self.items[17] = 'load[5]' 
		self.items[18] = 'load[6]' 
		self.items[19] = 'load[7]' 
		self.items[20] = 'ivlv[0]' 
		self.items[21] = 'ivlv[1]' 
		self.items[22] = 'ivlv[2]' 
		self.items[23] = 'ivlv[3]' 
		self.items[24] = 'ivlv[4]' 
		self.items[25] = 'ivlv[5]' 
		self.items[26] = 'ivlv[6]' 
		self.items[27] = 'ivlv[7]' 
		self.items[28] = 'evlv[0]' 
		self.items[29] = 'evlv[1]' 
		self.items[30] = 'evlv[2]' 
		self.items[31] = 'evlv[3]' 
		self.items[32] = 'evlv[4]' 
		self.items[33] = 'evlv[5]' 
		self.items[34] = 'evlv[6]' 
		self.items[35] = 'evlv[7]' 
		self.items[36] = 'e3v' 
		self.items[37] = 'e5v' 
		self.items[38] = 'e28v' 
		self.items[39] = 'i5v' 
		self.items[40] = 'i3v' 
		self.items[41] = 'last_command_id' 
		self.items[42] = 'tc[0]' 
		self.items[43] = 'tc[1]' 
		self.items[44] = 'tc[2]' 
		self.items[45] = 'tc[3]' 
		self.items[46] = 'tc[4]' 
		self.items[47] = 'tc[5]' 
		self.items[48] = 'tc[6]' 
		self.items[49] = 'tc[7]' 
		self.items[50] = 'rtd[0]' 
		self.items[51] = 'rtd[1]' 
		self.items[52] = 'rtd[2]' 
		self.items[53] = 'rtd[3]' 
		self.items[54] = 'rtd[4]' 
		self.items[55] = 'rtd[5]' 
		self.items[56] = 'rtd[6]' 
		self.items[57] = 'rtd[7]' 
		self.items[58] = 'i_mtr_ab[0]' 
		self.items[59] = 'i_mtr_ab[1]' 
		self.items[60] = 'i_mtr_ab[2]' 
		self.items[61] = 'i_mtr_ab[3]' 
		self.items[62] = 'i_mtr[0]' 
		self.items[63] = 'i_mtr[1]' 
		self.items[64] = 'zero' 
		self.items[65] = 'zero' 
		self.items[66] = 'zero' 
		self.items[67] = 'zero' 

	def parse_packet(self, packet):
		self.dict[self.items[0]] = int((float(struct.unpack("<I", packet[0:4])[0]))/1)
		self.dict[self.items[1]] = float((float(struct.unpack("<h", packet[4:6])[0]))/1)
		self.dict[self.items[2]] = float((float(struct.unpack("<h", packet[6:8])[0]))/1)
		self.dict[self.items[3]] = float((float(struct.unpack("<h", packet[8:10])[0]))/1)
		self.dict[self.items[4]] = float((float(struct.unpack("<h", packet[10:12])[0]))/1)
		self.dict[self.items[5]] = float((float(struct.unpack("<h", packet[12:14])[0]))/1)
		self.dict[self.items[6]] = float((float(struct.unpack("<h", packet[14:16])[0]))/1)
		self.dict[self.items[7]] = float((float(struct.unpack("<h", packet[16:18])[0]))/1)
		self.dict[self.items[8]] = float((float(struct.unpack("<h", packet[18:20])[0]))/1)
		self.dict[self.items[9]] = float((float(struct.unpack("<h", packet[20:22])[0]))/1000)
		self.dict[self.items[10]] = int((float(struct.unpack("<h", packet[22:24])[0]))/100)
		self.dict[self.items[11]] = int((float(struct.unpack("<B", packet[24:25])[0]))/1)
		self.dict[self.items[12]] = int((float(struct.unpack("<H", packet[25:27])[0]))/1)
		self.dict[self.items[13]] = float((float(struct.unpack("<H", packet[27:29])[0]))/1)
		self.dict[self.items[14]] = float((float(struct.unpack("<H", packet[29:31])[0]))/1)
		self.dict[self.items[15]] = float((float(struct.unpack("<H", packet[31:33])[0]))/1)
		self.dict[self.items[16]] = float((float(struct.unpack("<H", packet[33:35])[0]))/1)
		self.dict[self.items[17]] = float((float(struct.unpack("<H", packet[35:37])[0]))/1)
		self.dict[self.items[18]] = float((float(struct.unpack("<H", packet[37:39])[0]))/1)
		self.dict[self.items[19]] = float((float(struct.unpack("<H", packet[39:41])[0]))/1)
		self.dict[self.items[20]] = float((float(struct.unpack("<B", packet[41:42])[0]))/10)
		self.dict[self.items[21]] = float((float(struct.unpack("<B", packet[42:43])[0]))/10)
		self.dict[self.items[22]] = float((float(struct.unpack("<B", packet[43:44])[0]))/10)
		self.dict[self.items[23]] = float((float(struct.unpack("<B", packet[44:45])[0]))/10)
		self.dict[self.items[24]] = float((float(struct.unpack("<B", packet[45:46])[0]))/10)
		self.dict[self.items[25]] = float((float(struct.unpack("<B", packet[46:47])[0]))/10)
		self.dict[self.items[26]] = float((float(struct.unpack("<B", packet[47:48])[0]))/10)
		self.dict[self.items[27]] = float((float(struct.unpack("<B", packet[48:49])[0]))/10)
		self.dict[self.items[28]] = float((float(struct.unpack("<B", packet[49:50])[0]))/10)
		self.dict[self.items[29]] = float((float(struct.unpack("<B", packet[50:51])[0]))/10)
		self.dict[self.items[30]] = float((float(struct.unpack("<B", packet[51:52])[0]))/10)
		self.dict[self.items[31]] = float((float(struct.unpack("<B", packet[52:53])[0]))/10)
		self.dict[self.items[32]] = float((float(struct.unpack("<B", packet[53:54])[0]))/10)
		self.dict[self.items[33]] = float((float(struct.unpack("<B", packet[54:55])[0]))/10)
		self.dict[self.items[34]] = float((float(struct.unpack("<B", packet[55:56])[0]))/10)
		self.dict[self.items[35]] = float((float(struct.unpack("<B", packet[56:57])[0]))/10)
		self.dict[self.items[36]] = float((float(struct.unpack("<i", packet[57:61])[0]))/100)
		self.dict[self.items[37]] = float((float(struct.unpack("<i", packet[61:65])[0]))/100)
		self.dict[self.items[38]] = float((float(struct.unpack("<h", packet[65:67])[0]))/100)
		self.dict[self.items[39]] = float((float(struct.unpack("<B", packet[67:68])[0]))/100)
		self.dict[self.items[40]] = float((float(struct.unpack("<B", packet[68:69])[0]))/100)
		self.dict[self.items[41]] = float((float(struct.unpack("<H", packet[69:71])[0]))/100)
		self.dict[self.items[42]] = float((float(struct.unpack("<H", packet[71:73])[0]))/100)
		self.dict[self.items[43]] = float((float(struct.unpack("<H", packet[73:75])[0]))/100)
		self.dict[self.items[44]] = float((float(struct.unpack("<H", packet[75:77])[0]))/100)
		self.dict[self.items[45]] = float((float(struct.unpack("<H", packet[77:79])[0]))/100)
		self.dict[self.items[46]] = float((float(struct.unpack("<H", packet[79:81])[0]))/100)
		self.dict[self.items[47]] = float((float(struct.unpack("<H", packet[81:83])[0]))/100)
		self.dict[self.items[48]] = float((float(struct.unpack("<H", packet[83:85])[0]))/100)
		self.dict[self.items[49]] = float((float(struct.unpack("<H", packet[85:87])[0]))/100)
		self.dict[self.items[50]] = float((float(struct.unpack("<H", packet[87:89])[0]))/100)
		self.dict[self.items[51]] = float((float(struct.unpack("<H", packet[89:91])[0]))/100)
		self.dict[self.items[52]] = float((float(struct.unpack("<H", packet[91:93])[0]))/100)
		self.dict[self.items[53]] = float((float(struct.unpack("<H", packet[93:95])[0]))/100)
		self.dict[self.items[54]] = float((float(struct.unpack("<H", packet[95:97])[0]))/100)
		self.dict[self.items[55]] = float((float(struct.unpack("<H", packet[97:99])[0]))/100)
		self.dict[self.items[56]] = float((float(struct.unpack("<H", packet[99:101])[0]))/100)
		self.dict[self.items[57]] = float((float(struct.unpack("<H", packet[101:103])[0]))/100)
		self.dict[self.items[58]] = float((float(struct.unpack("<H", packet[103:105])[0]))/100)
		self.dict[self.items[59]] = float((float(struct.unpack("<H", packet[105:107])[0]))/100)
		self.dict[self.items[60]] = float((float(struct.unpack("<H", packet[107:109])[0]))/100)
		self.dict[self.items[61]] = float((float(struct.unpack("<H", packet[109:111])[0]))/100)
		self.dict[self.items[62]] = float((float(struct.unpack("<H", packet[111:113])[0]))/100)
		self.dict[self.items[63]] = float((float(struct.unpack("<H", packet[113:115])[0]))/100)
		self.dict[self.items[64]] = float((float(struct.unpack("<H", packet[115:117])[0]))/1000)
		self.dict[self.items[65]] = float((float(struct.unpack("<H", packet[117:119])[0]))/1000)
		self.dict[self.items[66]] = float((float(struct.unpack("<H", packet[119:121])[0]))/1000)
		self.dict[self.items[67]] = float((float(struct.unpack("<H", packet[121:123])[0]))/1000)
		self.log_string = str(time.clock()) + ',' + str(self.dict[self.items[0]]) + ',' + str(self.dict[self.items[1]]) + ',' + str(self.dict[self.items[2]]) + ',' + str(self.dict[self.items[3]]) + ',' + str(self.dict[self.items[4]]) + ',' + str(self.dict[self.items[5]]) + ',' + str(self.dict[self.items[6]]) + ',' + str(self.dict[self.items[7]]) + ',' + str(self.dict[self.items[8]]) + ',' + str(self.dict[self.items[9]]) + ',' + str(self.dict[self.items[10]]) + ',' + str(self.dict[self.items[11]]) + ',' + str(self.dict[self.items[12]]) + ',' + str(self.dict[self.items[13]]) + ',' + str(self.dict[self.items[14]]) + ',' + str(self.dict[self.items[15]]) + ',' + str(self.dict[self.items[16]]) + ',' + str(self.dict[self.items[17]]) + ',' + str(self.dict[self.items[18]]) + ',' + str(self.dict[self.items[19]]) + ',' + str(self.dict[self.items[20]]) + ',' + str(self.dict[self.items[21]]) + ',' + str(self.dict[self.items[22]]) + ',' + str(self.dict[self.items[23]]) + ',' + str(self.dict[self.items[24]]) + ',' + str(self.dict[self.items[25]]) + ',' + str(self.dict[self.items[26]]) + ',' + str(self.dict[self.items[27]]) + ',' + str(self.dict[self.items[28]]) + ',' + str(self.dict[self.items[29]]) + ',' + str(self.dict[self.items[30]]) + ',' + str(self.dict[self.items[31]]) + ',' + str(self.dict[self.items[32]]) + ',' + str(self.dict[self.items[33]]) + ',' + str(self.dict[self.items[34]]) + ',' + str(self.dict[self.items[35]]) + ',' + str(self.dict[self.items[36]]) + ',' + str(self.dict[self.items[37]]) + ',' + str(self.dict[self.items[38]]) + ',' + str(self.dict[self.items[39]]) + ',' + str(self.dict[self.items[40]]) + ',' + str(self.dict[self.items[41]]) + ',' + str(self.dict[self.items[42]]) + ',' + str(self.dict[self.items[43]]) + ',' + str(self.dict[self.items[44]]) + ',' + str(self.dict[self.items[45]]) + ',' + str(self.dict[self.items[46]]) + ',' + str(self.dict[self.items[47]]) + ',' + str(self.dict[self.items[48]]) + ',' + str(self.dict[self.items[49]]) + ',' + str(self.dict[self.items[50]]) + ',' + str(self.dict[self.items[51]]) + ',' + str(self.dict[self.items[52]]) + ',' + str(self.dict[self.items[53]]) + ',' + str(self.dict[self.items[54]]) + ',' + str(self.dict[self.items[55]]) + ',' + str(self.dict[self.items[56]]) + ',' + str(self.dict[self.items[57]]) + ',' + str(self.dict[self.items[58]]) + ',' + str(self.dict[self.items[59]]) + ',' + str(self.dict[self.items[60]]) + ',' + str(self.dict[self.items[61]]) + ',' + str(self.dict[self.items[62]]) + ',' + str(self.dict[self.items[63]]) + ',' + str(self.dict[self.items[64]]) + ',' + str(self.dict[self.items[65]]) + ',' + str(self.dict[self.items[66]]) + ',' + str(self.dict[self.items[67]]) + ','