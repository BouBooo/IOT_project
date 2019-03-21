#include "mbed.h"

namespace {
#define WAITEEE_MS 20000
}

static DigitalOut led1(LED1);
static I2C i2c(I2C1_SDA, I2C1_SCL);
static AnalogIn adc(ADC_IN1);

char cmdd[2];
uint8_t lm75_adress = 0x48 << 1;

int main()
{

	while(true)
	{
		//Temperature
		cmdd[0] = 0x00;
		i2c.write(lm75_adress, cmdd, 1);
		i2c.read(lm75_adress, cmdd, 2);
		float temperature = ((cmdd[0] << 8 | cmdd[1]) >> 7) * 0.5;
		printf("Temperature : %f \n", temperature);
		// Humidity
		float hum = adc.read()*3.3;
		float measure_percent = hum * 100.0 / 3.3;
		printf("Humidity : %f%\n", measure_percent);
		Thread::wait(WAITEEE_MS);
	}
}
