// to be autogenerated from master commands file
#define NUM_CMD_ITEMS     3

void cmd0_ptr(uint8_t* data, uint8_t* status)
{

}

void cmd1_ptr(uint8_t* data, uint8_t* status)
{

}

void cmd2_ptr(uint8_t* data, uint8_t* status)
{

}

void (*cmds_ptr[NUM_CMD_ITEMS])(uint8_t*, uint8_t*) = {
cmd0_ptr,
cmd1_ptr,
cmd2_ptr
};

// Note: to call a function do
/**
 * (*cmds_ptr[0])(array ptr here)
 */
