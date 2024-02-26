/* Copyright 2013 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
/* Emulator board-specific configuration */

#include "button.h"
#include "extpower.h"
#include "gpio.h"
#include "host_command.h"
#include "i2c.h"
#include "inductive_charging.h"
#include "lid_switch.h"
#include "motion_sense.h"
#include "motion_lid.h"
#include "power_button.h"
#include "spi.h"
#include "temp_sensor.h"
#include "timer.h"
#include "util.h"

/*
 * GPIO_0 is the name generated by the gpio.inc GPIO macros for all of the host
 * GPIO ports.  This maps back to 0, which is then ignored by the host GPIO mock
 * code.
 */
#define GPIO_0  0

#include "gpio_list.h"

test_mockable_static int dummy_temp_get_val(int idx, int *temp_ptr)
{
	*temp_ptr = 0;
	return EC_SUCCESS;
}

const struct temp_sensor_t temp_sensors[] = {
	{"CPU", TEMP_SENSOR_TYPE_CPU, dummy_temp_get_val, 0, 3},
	{"Board", TEMP_SENSOR_TYPE_BOARD, dummy_temp_get_val, 1, 3},
	{"Case", TEMP_SENSOR_TYPE_CASE, dummy_temp_get_val, 2, 0},
	{"Battery", TEMP_SENSOR_TYPE_BOARD, dummy_temp_get_val, 3, 0},
};
BUILD_ASSERT(ARRAY_SIZE(temp_sensors) == TEMP_SENSOR_COUNT);

test_mockable void button_interrupt(enum gpio_signal signal)
{
};

#ifdef CONFIG_I2C
/* I2C ports */
const struct i2c_port_t i2c_ports[] = {
#ifdef I2C_PORT_BATTERY
	{"battery", I2C_PORT_BATTERY, 100,  0, 0},
#elif defined I2C_PORT_LIGHTBAR
	{"lightbar", I2C_PORT_LIGHTBAR, 100,  0, 0},
#endif
};

const unsigned int i2c_ports_used = ARRAY_SIZE(i2c_ports);
#endif

#ifdef CONFIG_SPI_MASTER
/* SPI devices */
const struct spi_device_t spi_devices[] = {
};

const unsigned int spi_devices_used = ARRAY_SIZE(spi_devices);
#endif

#ifdef TEST_BUILD
/* Poor source of entropy for testing purpose. */
int board_get_entropy(void *buffer, int len)
{
	static uint32_t seed = 0xcafecafe;
	int i = 0;
	uint8_t *data = buffer;

	for (i = 0; i < len; i++) {
		seed *= 7;
		data[i] = seed + (seed >> 24);
	}

	return 1;
}
#endif
