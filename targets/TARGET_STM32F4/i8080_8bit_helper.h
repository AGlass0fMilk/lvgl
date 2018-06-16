
#ifndef STM32F4XX_FSMC_H
#define STM32F4XX_FSMC_H
#include <stm32f4xx_ll_fsmc.h>
#endif

#define TFT_REG_ADDRESS 0x60000000
#define TFT_RAM_ADDRESS 0x60010000
#define TFT_BUS(d)     (*((volatile unsigned short *) d))
	
//void i8080_reset_pins(void);
//void i8080_init_pins(void);
//void i8080_init_fsmc(void);
void i8080_init_helper(void);

//SSD1963 COMMAND TABLE
//void SSD1963__nop(void);
//void SSD1963__soft_reset(void);
//unsigned int SSD1963__get_power_mode(void);
//unsigned int SSD1963__get_address_mode(void);
//unsigned int SSD1963__get_display_mode(void);
//unsigned int SSD1963__get_tear_effect_status(void);
//void SSD1963__enter_sleep_mode(void);
//void SSD1963__exit_sleep_mode(void);
//void SSD1963__enter_partial_mode(void);
//void SSD1963__enter_normal_mode(void);
//void SSD1963__exit_invert_mode(void);
//void SSD1963__enter_invert_mode(void);
//void SSD1963__set_gamma_curve(unsigned int p1);
//void SSD1963__set_display_off(void);
//void SSD1963__set_display_on(void);
//void SSD1963__set_column_address(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
//void SSD1963__set_page_address(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
//void SSD1963__write_memory_start(void);
//void SSD1963__read_memory_start(void);
//void SSD1963__set_partial_area(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
//void SSD1963__set_scroll_area(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6);
//void SSD1963__set_tear_off(void);
//void SSD1963__set_tear_on(unsigned int p1);
//void SSD1963__set_address_mode(unsigned int p1);
//void SSD1963__set_scroll_start(unsigned int p1, unsigned int p2);
//void SSD1963__exit_idle_mode(void);
//void SSD1963__enter_idle_mode(void);
//void SSD1963__write_memory_continue(void);
//void SSD1963__read_memory_continue(void);
//void SSD1963__set_tear_scanline(unsigned int p1, unsigned int p2);
//unsigned int SSD1963__get_scanline(unsigned int p_n);
//unsigned int SSD1963__read_ddb(unsigned int p_n);
//void SSD1963__set_lcd_mode(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7);
//unsigned int SSD1963__get_lcd_mode(unsigned int p_n);
//void SSD1963__set_hori_period(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7, unsigned int p8);
//unsigned int SSD1963__get_hori_period(unsigned int p_n);
//void SSD1963__set_vert_period(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7);
//unsigned int SSD1963__get_vert_period(unsigned int p_n);
//void SSD1963__set_gpio_conf(unsigned int p1, unsigned int p2);
//unsigned int SSD1963__get_gpio_conf(unsigned int p_n);
//void SSD1963__set_gpio_value(unsigned int p1);
//void SSD1963__set_gpio_status(unsigned int p1);
//void SSD1963__set_post_proc(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
//unsigned int SSD1963__get_post_proc(unsigned int p_n);
//void SSD1963__set_pwm_conf(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6);
//unsigned int SSD1963__get_pwm_conf(unsigned int p_n);
//void SSD1963__set_lcd_gen0(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7);
//unsigned int SSD1963__get_lcd_gen0(unsigned int p_n);
//void SSD1963__set_lcd_gen1(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7);
//unsigned int SSD1963__get_lcd_gen1(unsigned int p_n);
//void SSD1963__set_lcd_gen2(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7);
//unsigned int SSD1963__get_lcd_gen2(unsigned int p_n);
//void SSD1963__set_lcd_gen3(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7);
//unsigned int SSD1963__get_lcd_gen3(unsigned int p_n);
//void SSD1963__set_gpio0_rop(unsigned int p1, unsigned int p2);
//unsigned int SSD1963__get_gpio0_rop(unsigned int p_n);
//void SSD1963__set_gpio1_rop(unsigned int p1, unsigned int p2);
//unsigned int SSD1963__get_gpio1_rop(unsigned int p_n);
//void SSD1963__set_gpio2_rop(unsigned int p1, unsigned int p2);
//unsigned int SSD1963__get_gpio2_rop(unsigned int p_n);
//void SSD1963__set_gpio3_rop(unsigned int p1, unsigned int p2);
//unsigned int SSD1963__get_gpio3_rop(unsigned int p_n);
//void SSD1963__set_dbc_conf(unsigned int p1);
//unsigned int SSD1963__get_dbc_conf(void);
//void SSD1963__set_dbc_th(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7, unsigned int p8, unsigned int p9);
//unsigned int SSD1963__get_dbc_th(unsigned int p_n);
//void SSD1963__set_pll(unsigned int p1);
//void SSD1963__set_pll_mn(unsigned int p1, unsigned int p2, unsigned int p3);
//unsigned int SSD1963__get_pll_mn(unsigned int p_n);
//unsigned int SSD1963__get_pll_status(void);
//void SSD1963__set_deep_sleep(void);
//void SSD1963__set_lshift_freq(unsigned int p1, unsigned int p2, unsigned int p3);
//unsigned int SSD1963__get_lshift_freq(unsigned int p_n);
//void SSD1963__set_pixel_data_interface(unsigned int p1);
//unsigned int SSD1963__get_pixel_data_interface(void);
//
//
//
//
