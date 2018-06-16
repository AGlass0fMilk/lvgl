/**
 * @file lvgl_objects.h
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
#ifndef LVGL_TARGETS_TARGET_STM32F4_LVGL_OBJECTS_H_
#define LVGL_TARGETS_TARGET_STM32F4_LVGL_OBJECTS_H_

#ifdef _cplusplus
extern "C" {
#endif

typedef struct i8080_8bit_s
{
		uint32_t data_address;
		uint32_t command_address;
} i8080_8bit_s;

#ifdef _cplusplus
}
#endif

#endif /* LVGL_TARGETS_TARGET_STM32F4_LVGL_OBJECTS_H_ */
