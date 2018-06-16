/**
 * @file i8080_8bit_api.c
 * @brief Brief Description
 * 
 * Detailed Description
 *
 * Link to [markdown like this](@ref PageTag)
 * Make sure you tag the markdown page like this:
 * # Page title {#PageTag}
 * 
 * <a href='MyPDF.pdf'> Link to PDF documents like this</a>
 * If you add document files, make sure to add them into a directory inside a "docs" folder
 * And then run hud-devices/tools/copy-dox-files.py 
 *
 * To use images, make sure they're in an "images" folder and follow the doxygen user manual to add images.
 * You must run copy-dox-files.py after adding images as well.
 *
 * @copyright Copyright &copy; 2018 Heads Up Display, Inc.
 *
 *  Created on: Jun 16, 2018
 *      Author: gdbeckstein
 */

#include "i8080_8bit_api.h"
#include "lvgl_objects.h"
#include "i8080_8bit_helper.h"
#include "stdint.h"

//#if DEVICE_I8080_8BIT

static i8080_8bit_t* m_instance;

void i8080_8bit_init(i8080_8bit_t *obj)
{
	m_instance = obj;

	m_instance->command_address = TFT_REG_ADDRESS;
	m_instance->data_address = TFT_RAM_ADDRESS;

	// Configure associated pins and the FSMC peripheral
	i8080_init_helper();

}

void i8080_8bit_free(i8080_8bit_t *obj)
{
	m_instance = NULL;

	//TODO - deinit pins
}

void i8080_8bit_write(i8080_8bit_t* obj, uint8_t value)
{
	TFT_BUS(obj->command_address) = value;
}

void i8080_8bit_write_bytes(i8080_8bit_t *obj,
		uint8_t* value, uint32_t len)
{
	TFT_BUS(obj->command_address) = *value;
	for(int i = 1; i < len; i++)
	{
		TFT_BUS(obj->data_address) = value[i];
	}

}

uint8_t i8080_8bit_read(i8080_8bit_t *obj)
{
	return (uint8_t) TFT_BUS(obj->data_address);
}

//#endif


