/** MAX11131.c
 *  @author arthurzh
 *
 *  See MAX11131.h for usage and public function documentation
 *
 * Private Functions:
 *   set_adc
 *   cycle_cnvst
 *   configure_read_adc_all
 *   write_adc_reg
 *   package_cmd
 */
#include "../inc/MAX11131.h"

/*---------------------- Private Functions Declarations ----------------------*/

#ifdef HAL_SPI_MODULE_ENABLED
/**
 *  Selects/Disables adc for SPI transmissions
 *
 *  @param pinfo        <GPIO_MAX11131_Pinfo*> contains ADC pin defs
 *  @param state        <GPIO_PinState>        state of GPIO PIN
 *                            Note:
 */
static inline void set_adc(GPIO_MAX11131_Pinfo *pinfo, GPIO_PinState state);

/**
 *  Cycles CNVST pin to wakeup ADC for adc conversions
 *
 *  @param pinfo        <GPIO_MAX11131_Pinfo*>   contains ADC pin defs
 *
 */
static inline void cycle_cnvst(GPIO_MAX11131_Pinfo *pinfo);

/**
 * 	Convenience function for updating GPIO_MAX11131_Pinfo to read from pins 0-13
 *
 * 	@param pinfo        <GPIO_MAX11131_Pinfo*>   contains ADC pin defs
 *
 */
static void configure_read_adc_all(GPIO_MAX11131_Pinfo *pinfo);

/**
 *	Private function for transmit and receiving bytes to selected ADC
 *
 *  @param SPI_BUS      <SPI_HandleTypeDef*> SPI object adc is on
 *  @param tx           <uint8_t*> bytes to transmit (expected size 2)
 *  @param adc_out      <uint8_t*> bytes to receive (expected size 2)
 */
static inline void write_adc_reg(SPI_HandleTypeDef *SPI_BUS, uint8_t *tx, uint8_t *rx);

/**
 *  Private function for packing 16 bit command to 8 bit chunks
 *
 *  @param cmd          <uint16_t> 16 bit command
 *  @param tx           <uint8_t*> arr of 16 bit command MSB first (size 2)
 *
 */
static inline void package_cmd(uint16_t cmd, uint8_t *tx);

/*-------------------------Public Interface Functions-------------------------*/

void init_adc(SPI_HandleTypeDef *SPI_BUS, GPIO_MAX11131_Pinfo *pinfo) {
    /*
     * 	Automatically configures ADC to read from custom internal channels
     * 	Steps:
     * 	ADC configuration register
     *      1.  Set AVG_ON bit to 1
     *      2.  Set NAVG[1:0]  to N
     *  ADC custom scan registers
     *      3. Set CUSTOM_SCAN0 register
     *      4. Set CUSTOM_SCAN1 register
     *  ADC mode control register
     *      5. Set SCAN[3:0] to 0111
     *      6. Set CHSEL[3:0] to channel number (not needed for Custom int)
     *      7. Select the right SWCNV bit
     *
     *
     */
    // Configure settings for all ADCs
    uint8_t tx[2] = {0, 0};

    // 	note: these types are taken from the GPIO_TypeDef line 486
    //          in file stm32f446x.h

    // Generate adc config data
    uint16_t ADC_CONFIG_REG	   = MAX11131_CONFIG|SET_MAX11131_AVGON;
    uint16_t ADC_MODE_CNTL_REG = MAX11131_MODE_CNTL|(CUSTOM_INT<<11);

    configure_read_adc_all(pinfo);
    set_read_adc_range(SPI_BUS, pinfo);

    package_cmd(ADC_CONFIG_REG, tx);
    __disable_irq();
    set_adc(pinfo, GPIO_PIN_RESET);
    if (HAL_SPI_Transmit(SPI_BUS, tx, 2, 1) == HAL_TIMEOUT) {}
    set_adc(pinfo, GPIO_PIN_SET);
    __enable_irq();

    package_cmd(ADC_MODE_CNTL_REG, tx);
    __disable_irq();
    set_adc(pinfo, GPIO_PIN_RESET);
    if (HAL_SPI_Transmit(SPI_BUS, tx, 2, 1) == HAL_TIMEOUT) {}
    set_adc(pinfo, GPIO_PIN_SET);
    __enable_irq();
}

void read_adc(SPI_HandleTypeDef *SPI_BUS, GPIO_MAX11131_Pinfo *pinfo,
                                                uint16_t *adc_out) {
    /*
     Read ADC Procedure for internal clock using SWCNV bit set(pg17):
          1. Set CS high to initiate conversions
          2. Wait for EOC pin to be pulled low
          3. Read from FIFO register on DOUT pin
          4. Set CS high again

     Read ADC Procedure for internal clock not using SWCNV bit
          1. Set CS high
          2. Set CNVST low for at least 5ns before pulling high again
          3. Wait for EOC to be pulled low
          4. Set CS low and High to initiate serial communications
             Note: EOC stays low until CS or CNVST is pulled low again
     */
    /* ADC startup and FIFO register intialization */

    set_adc(pinfo, GPIO_PIN_SET);
    cycle_cnvst(pinfo);
    while (HAL_GPIO_ReadPin(pinfo->MAX11131_EOC_PORT,
                            pinfo->MAX11131_EOC_ADDR)) {}

    /* Serial communications with ADC */

    // The number of bytes in the FIFO is simply the
    // number of channels * 2 (bytes for each channel)
    uint8_t rx[2] = {0};
    uint8_t tx[2] = {0};
    for (uint8_t i = 0; i < pinfo->NUM_CHANNELS; ++i) {
        __disable_irq();
        set_adc(pinfo, GPIO_PIN_RESET);
        write_adc_reg(SPI_BUS, tx, rx);
        set_adc(pinfo, GPIO_PIN_SET);
        __enable_irq();

        uint16_t adc_counts = ((rx[0]<<8)|rx[1]) & 0x0FFF;
        uint16_t channelId = (rx[0] >> 4) & 0x0F;
        adc_out[channelId] = adc_counts;
    }

}

void set_read_adc_range(SPI_HandleTypeDef *SPI_BUS, GPIO_MAX11131_Pinfo *pinfo) {
    /*
     Configure Custom ADC read procedure (pg32-33):
     1. Set AVGON BIT reg to 1
     2. Set NAVG to desired number of samples (default 4 samples)
     3. Set CUSTOM Scan0 and CUSTOM Scan1 Registers
     4. Set ADC MODE CONTROL REGISTER SET SCAN[3:0] 0b0111
     5. Set CHSEL[3:0] to Channel Number (Not needed for CUSTOM INT)
     6. Set SWCNV bit to 1 to enable conversions with chip select
     */
    uint8_t tx[2];

    uint16_t SET_SCAN_REGISTER_0 = MAX11131_CUSTOM_SCAN0;
    uint16_t SET_SCAN_REGISTER_1 = MAX11131_CUSTOM_SCAN1;
    uint8_t num_channels		= pinfo->NUM_CHANNELS;

    for (uint8_t i = 0; i < num_channels; ++i) {
        uint8_t ch = pinfo->MAX11131_CHANNELS[i];
        if (ch > 7) {
            ch -= MAX11131_CUSTOM_SCAN0_SUB;
            SET_SCAN_REGISTER_0 = SET_SCAN_REGISTER_0 | (1 << ch);
        } else {
            ch += MAX11131_CUSTOM_SCAN1_ADD;
            SET_SCAN_REGISTER_1 = SET_SCAN_REGISTER_1 | (1 << ch);
        } // sets channel register bit in Custom Scan0 Register
    }

    /* Set ADC to custom scan channel range */

    /* Transmit custom channels to send data from */
    package_cmd(SET_SCAN_REGISTER_0, tx);
    __disable_irq();
    set_adc(pinfo, GPIO_PIN_RESET);
    if (HAL_SPI_Transmit(SPI_BUS, tx, 2, 1) == HAL_TIMEOUT) {}
    set_adc(pinfo, GPIO_PIN_SET);
    __enable_irq();

    package_cmd(SET_SCAN_REGISTER_1, tx);
    __disable_irq();
    set_adc(pinfo, GPIO_PIN_RESET);
    if (HAL_SPI_Transmit(SPI_BUS, tx, 2, 1) == HAL_TIMEOUT) {}
    set_adc(pinfo, GPIO_PIN_SET);
    __enable_irq();
}

void configure_read_adc_all(GPIO_MAX11131_Pinfo *pinfo) {
    // Convenience function for reading all channels on adc
    pinfo->NUM_CHANNELS = MAX11131_MAX_CHANNELS;
    for (uint8_t i = 0; i < MAX11131_MAX_CHANNELS; ++i) {
        pinfo->MAX11131_CHANNELS[i] = i;
    }
    pinfo->MAX11131_CHANNELS[14] = 15;
}

void write_adc_reg(SPI_HandleTypeDef *SPI_BUS, uint8_t *tx, uint8_t *rx) {
    if (HAL_SPI_TransmitReceive(SPI_BUS, tx, rx, 2, 1) == HAL_TIMEOUT) {
    }
}

void package_cmd(uint16_t cmd, uint8_t *tx) {
    tx[0] = (cmd >> 8) & 0x00ff;
    tx[1] = (cmd & 0x00ff);
}

void set_adc(GPIO_MAX11131_Pinfo *pinfo, GPIO_PinState state) {
    HAL_GPIO_WritePin(pinfo->MAX11131_CS_PORT, pinfo->MAX11131_CS_ADDR, state);
}

void cycle_cnvst(GPIO_MAX11131_Pinfo *pinfo) {
    HAL_GPIO_WritePin(
        pinfo->MAX11131_CNVST_PORT, pinfo->MAX11131_CNVST_ADDR, GPIO_PIN_RESET
    );
    asm("nop");  // Clock Freq maxes at 180 MHz, at which each noop instruction
    asm("nop");  // takes about 5.5 ns to complete
    HAL_GPIO_WritePin(
        pinfo->MAX11131_CNVST_PORT, pinfo->MAX11131_CNVST_ADDR, GPIO_PIN_SET
    );
}
#endif
