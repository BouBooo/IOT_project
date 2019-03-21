/*
 * Copyright (c) 2017, CATIE, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "mbed.h"

namespace {
#define PERIOD_MS 500
}

static DigitalOut led1(LED1);
/*static InterruptIn button(BUTTON1);
static Timer timer;
static Serial uart(UART1_TX, UART1_RX);*/
static I2C i2c(I2C1_SDA, I2C1_SCL);
static AnalogIn adc(ADC_IN1);
char cmdd[2];
uint8_t lm75_adress = 0x48 << 1;
int x = 0;


//Thread::wait(PERIOD_MS);

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for delays)
int data()
{
    while (x<40) {
        // test the voltage on the initialized analog pin
        //  to a logic 1 otherwise a logic 0

    	float hum = adc.read()*3.3;
    	float measure_percent = hum * 100.0 / 3.3;

        // print the percentage and 16 bit normalized values
        printf("Humidity (%): %f%\n", measure_percent);
        //printf("normalized: 0x%04X \n", adc.read_u16());
        x += 1;

        Thread::wait(PERIOD_MS);
    }

	while(x>39)
	{
		// Get and print temp
		cmdd[0] = 0x00;
		i2c.write(lm75_adress, cmdd, 1);
		i2c.read(lm75_adress, cmdd, 2);
		x += 1;


		float temperature = ((cmdd[0] << 8 | cmdd[1]) >> 7) * 0.5;

		printf("Temperature : %f \n", temperature);

		Thread::wait(PERIOD_MS);

	}
}
