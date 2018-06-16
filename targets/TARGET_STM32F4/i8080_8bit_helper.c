
#ifndef TFT_H
#define TFT_H
#include "i8080_8bit_helper.h"
#endif

//Set all control lines as input to allow auto-init
void i8080_reset_pins(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//Enable clocks
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);
	
	//16-bit
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7 | GPIO_Pin_11 | GPIO_Pin_12;

	//8-bit
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7 | GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	//16-bit
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;

	//8-bit
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}


void i8080_init_pins(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable GPIOD, GPIOE, GPIOF, GPIOG and AFIO clocks */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOG | RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOF, ENABLE);

	/*-- GPIO Configuration ------------------------------------------------------*/
	/* SRAM Data lines,  NOE (/RD) and NWE (/WR) configuration */

	// 16-bit interface only
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_4 | GPIO_Pin_5;

	// 8-bit interface
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC);
	//GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FSMC); 	// 16-bit interface only
	//GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FSMC); 	// 16-bit interface only
	//GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC); 	// 16-bit interface only
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC);

	// 16-bit only
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;

	// 8-bit interface
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOE, GPIO_PinSource7 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource8 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource10 , GPIO_AF_FSMC);
	/*GPIO_PinAFConfig(GPIOE, GPIO_PinSource11 , GPIO_AF_FSMC);	// 16-bit interface only
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12 , GPIO_AF_FSMC);	 // 16-bit interface only
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13 , GPIO_AF_FSMC);	// 16-bit interface only
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14 , GPIO_AF_FSMC);	// 16-bit interface only
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource15 , GPIO_AF_FSMC);*/	// 16-bit interface only

	/* SRAM Address lines configuration (/RS)*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOD, &GPIO_InitStructure);  
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource11, GPIO_AF_FSMC);           

	/* NE3 configuration (/CS)*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 

	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource7, GPIO_AF_FSMC);
	
	/*/RESET */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_SetBits(GPIOD, GPIO_Pin_12);
}

//FSMC configuration
void i8080_init_fsmc(void)
{
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
	FSMC_NORSRAMTimingInitTypeDef  p;

	/* Enable FMC clock */
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);

	/*-- FMC Configuration ------------------------------------------------------*/
	/*----------------------- SRAM Bank 1 ----------------------------------------*/
	/* FMC_Bank1_NORSRAM1 configuration */
	p.FSMC_AddressSetupTime = 5;
	p.FSMC_AddressHoldTime = 1;
	p.FSMC_DataSetupTime = 9;
	p.FSMC_BusTurnAroundDuration = 0;
	p.FSMC_CLKDivision = 1;
	p.FSMC_DataLatency = 0;
	p.FSMC_AccessMode = FSMC_AccessMode_A;
	/* Color LCD configuration ------------------------------------
	LCD configured as follow:
	- Data/Address MUX = Disable
	- Memory Type = SRAM
	- Data Width = 8bit
	- Write Operation = Enable
	- Extended Mode = Enable
	- Asynchronous Wait = Disable */

	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
	FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;
	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;

	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);   

	/* Enable FMC NOR/SRAM Bank1 */
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);
}


void i8080_init_helper(void)
{
	//Control lines as input
	i8080_reset_pins();
	
	i8080_init_pins();
	i8080_init_fsmc();
	
	//Display on
//	SSD1963__set_display_on();
//
//	//Set pixel data interface to 16-bit (565)
//	SSD1963__set_pixel_data_interface(0x03);
//
//	//Set address mode
//	SSD1963__set_address_mode(0x02);
//
//	//Backlight @ 0x00
//	SSD1963__set_pwm_conf(0x06,0x00,0x01,0xF0,0x00,0x00);
//
//	//Backlight on
//	TFT_5V_Enable();
//
	//Brightness @ 100%
	//SSD1963__set_pwm_conf(0x06,0xD9,0x01,0xF0,0x00,0x00);
}


////SSD1963 COMMAND TABLE
//void SSD1963__nop(void)
//{
//	TFT_REG=0x00;
//}
//
//void SSD1963__soft_reset(void)
//{
//	TFT_REG=0x01;
//}
//
//unsigned int SSD1963__get_power_mode(void)
//{
//	TFT_REG=0x0A;
//	return TFT_RAM;
//}
//
//unsigned int SSD1963__get_address_mode(void)
//{
//	TFT_REG=0x0B;
//	return TFT_RAM;
//}
//
//unsigned int SSD1963__get_display_mode(void)
//{
//	TFT_REG=0x0D;
//	return TFT_RAM;
//}
//
//unsigned int SSD1963__get_tear_effect_status(void)
//{
//	TFT_REG=0x0E;
//	return TFT_RAM;
//}
//
//void SSD1963__enter_sleep_mode(void)
//{
//	TFT_REG=0x10;
//}
//
//void SSD1963__exit_sleep_mode(void)
//{
//	TFT_REG=0x11;
//}
//
//void SSD1963__enter_partial_mode(void)
//{
//	TFT_REG=0x12;
//}
//
//void SSD1963__enter_normal_mode(void)
//{
//	TFT_REG=0x13;
//}
//
//void SSD1963__exit_invert_mode(void)
//{
//	TFT_REG=0x20;
//}
//
//void SSD1963__enter_invert_mode(void)
//{
//	TFT_REG=0x21;
//}
//
//void SSD1963__set_gamma_curve(unsigned int p1)
//{
//	TFT_REG=0x26;
//  TFT_RAM=p1;
//}
//
//void SSD1963__set_display_off(void)
//{
//	TFT_REG=0x28;
//}
//
//void SSD1963__set_display_on(void)
//{
//	TFT_REG=0x29;
//}
//
//void SSD1963__set_column_address(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4)
//{
//	TFT_REG=0x2A;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//}
//
//void SSD1963__set_page_address(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4)
//{
//	TFT_REG=0x2B;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//}
//
//void SSD1963__write_memory_start(void)
//{
//	TFT_REG=0x2C;
//}
//
//void SSD1963__read_memory_start(void)
//{
//	TFT_REG=0x2E;
//}
//
//void SSD1963__set_partial_area(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4)
//{
//	TFT_REG=0x30;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//}
//
//void SSD1963__set_scroll_area(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6)
//{
//	TFT_REG=0x33;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//}
//
//void SSD1963__set_tear_off(void)
//{
//	TFT_REG=0x34;
//}
//
//void SSD1963__set_tear_on(unsigned int p1)
//{
//	TFT_REG=0x35;
//	TFT_RAM=p1;
//}
//
//void SSD1963__set_address_mode(unsigned int p1)
//{
//	TFT_REG=0x36;
//	TFT_RAM=p1;
//}
//
//void SSD1963__set_scroll_start(unsigned int p1, unsigned int p2)
//{
//	TFT_REG=0x37;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//}
//
//void SSD1963__exit_idle_mode(void)
//{
//	TFT_REG=0x38;
//}
//
//void SSD1963__enter_idle_mode(void)
//{
//	TFT_REG=0x39;
//}
//
//void SSD1963__write_memory_continue(void)
//{
//	TFT_REG=0x3C;
//}
//
//void SSD1963__read_memory_continue(void)
//{
//	TFT_REG=0x3E;
//}
//
//void SSD1963__set_tear_scanline(unsigned int p1, unsigned int p2)
//{
//	TFT_REG=0x44;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//}
//
//unsigned int SSD1963__get_scanline(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>2) return r;
//
//	TFT_REG=0x45;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//unsigned int SSD1963__read_ddb(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>5) return r;
//
//	TFT_REG=0xA1;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_lcd_mode(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7)
//{
//	TFT_REG=0xB0;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//	TFT_RAM=p7;
//}
//
//unsigned int SSD1963__get_lcd_mode(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>7) return r;
//
//	TFT_REG=0xB1;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_hori_period(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7, unsigned int p8)
//{
//	TFT_REG=0xB4;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//	TFT_RAM=p7;
//	TFT_RAM=p8;
//}
//
//unsigned int SSD1963__get_hori_period(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>8) return r;
//
//	TFT_REG=0xB5;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_vert_period(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7)
//{
//	TFT_REG=0xB6;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//	TFT_RAM=p7;
//}
//
//unsigned int SSD1963__get_vert_period(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>7) return r;
//
//	TFT_REG=0xB7;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_gpio_conf(unsigned int p1, unsigned int p2)
//{
//	TFT_REG=0xB8;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//}
//
//unsigned int SSD1963__get_gpio_conf(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>2) return r;
//
//	TFT_REG=0xB9;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_gpio_value(unsigned int p1)
//{
//	TFT_REG=0xBA;
//	TFT_RAM=p1;
//}
//
//void SSD1963__set_gpio_status(unsigned int p1)
//{
//	TFT_REG=0xBB;
//	TFT_RAM=p1;
//}
//
//void SSD1963__set_post_proc(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4)
//{
//	TFT_REG=0xBC;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//}
//
//unsigned int SSD1963__get_post_proc(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>4) return r;
//
//	TFT_REG=0xBD;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_pwm_conf(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6)
//{
//	TFT_REG=0xBE;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//}
//
//unsigned int SSD1963__get_pwm_conf(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>6) return r;
//
//	TFT_REG=0xBF;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_lcd_gen0(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7)
//{
//	TFT_REG=0xC0;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//	TFT_RAM=p7;
//}
//
//unsigned int SSD1963__get_lcd_gen0(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>7) return r;
//
//	TFT_REG=0xC1;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_lcd_gen1(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7)
//{
//	TFT_REG=0xC2;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//	TFT_RAM=p7;
//}
//
//unsigned int SSD1963__get_lcd_gen1(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>7) return r;
//
//	TFT_REG=0xC3;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_lcd_gen2(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7)
//{
//	TFT_REG=0xC4;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//	TFT_RAM=p7;
//}
//
//unsigned int SSD1963__get_lcd_gen2(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>7) return r;
//
//	TFT_REG=0xC5;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_lcd_gen3(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7)
//{
//	TFT_REG=0xC6;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//	TFT_RAM=p7;
//}
//
//unsigned int SSD1963__get_lcd_gen3(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>7) return r;
//
//	TFT_REG=0xC7;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_gpio0_rop(unsigned int p1, unsigned int p2)
//{
//	TFT_REG=0xC8;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//}
//
//unsigned int SSD1963__get_gpio0_rop(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>2) return r;
//
//	TFT_REG=0xC9;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_gpio1_rop(unsigned int p1, unsigned int p2)
//{
//	TFT_REG=0xCA;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//}
//
//unsigned int SSD1963__get_gpio1_rop(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>2) return r;
//
//	TFT_REG=0xCB;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_gpio2_rop(unsigned int p1, unsigned int p2)
//{
//	TFT_REG=0xCC;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//}
//
//unsigned int SSD1963__get_gpio2_rop(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>2) return r;
//
//	TFT_REG=0xCD;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_gpio3_rop(unsigned int p1, unsigned int p2)
//{
//	TFT_REG=0xCE;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//}
//
//unsigned int SSD1963__get_gpio3_rop(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>2) return r;
//
//	TFT_REG=0xCF;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_dbc_conf(unsigned int p1)
//{
//	TFT_REG=0xD0;
//	TFT_RAM=p1;
//}
//
//unsigned int SSD1963__get_dbc_conf(void)
//{
//	TFT_REG=0xD1;
//	return TFT_RAM;
//}
//
//void SSD1963__set_dbc_th(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7, unsigned int p8, unsigned int p9)
//{
//	TFT_REG=0xD4;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//	TFT_RAM=p4;
//	TFT_RAM=p5;
//	TFT_RAM=p6;
//	TFT_RAM=p7;
//	TFT_RAM=p8;
//	TFT_RAM=p9;
//}
//
//unsigned int SSD1963__get_dbc_th(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>9) return r;
//
//	TFT_REG=0xD5;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_pll(unsigned int p1)
//{
//	TFT_REG=0xE0;
//	TFT_RAM=p1;
//}
//
//void SSD1963__set_pll_mn(unsigned int p1, unsigned int p2, unsigned int p3)
//{
//	TFT_REG=0xE2;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//}
//
//unsigned int SSD1963__get_pll_mn(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>3) return r;
//
//	TFT_REG=0xE3;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//unsigned int SSD1963__get_pll_status(void)
//{
//	TFT_REG=0xE4;
//	return TFT_RAM;
//}
//
//void SSD1963__set_deep_sleep(void)
//{
//	TFT_REG=0xE5;
//}
//
//void SSD1963__set_lshift_freq(unsigned int p1, unsigned int p2, unsigned int p3)
//{
//	TFT_REG=0xE6;
//	TFT_RAM=p1;
//	TFT_RAM=p2;
//	TFT_RAM=p3;
//}
//
//unsigned int SSD1963__get_lshift_freq(unsigned int p_n)
//{
//  unsigned int i=0;
//	unsigned int r=0;
//
//	//If incorrect parameter, return 0.
//	if(p_n<1 || p_n>3) return r;
//
//	TFT_REG=0xE7;
//
//	for(i=0;i<p_n;i++)
//	{
//		r=TFT_RAM;
//	}
//
//	return r;
//}
//
//void SSD1963__set_pixel_data_interface(unsigned int p1)
//{
//	TFT_REG=0xF0;
//	TFT_RAM=p1;
//}
//
//unsigned int SSD1963__get_pixel_data_interface(void)
//{
//	TFT_REG=0xF1;
//	return TFT_RAM;
//}
