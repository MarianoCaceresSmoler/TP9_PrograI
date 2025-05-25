#include "leds.h"
#include "ports.h"
#include <stdio.h>

#define PORT PORT_A

void turnOnLED(int number)
{
	bitSet(PORT, number);
}

void toggleAllLEDs(void)
{
	maskToggle(PORT, 0xFF);
}

void turnOnAllLEDs(void)
{
	maskOn(PORT, 0xFF);

}

void turnOffAllLEDs(void)
{
	maskOff(PORT, 0xFF);
}

void showLEDs(void)
{
	int i;
	int led;

	// Imprime el valor del puerto en binario, utilizando la funcion de la libreria ports
	for(i = 7; i >= 0; i--)
	{
		led = bitGet(PORT, i);
		printf(" %d ", led);
	}
	putchar('\n');

}
