#include "ports.h"

typedef unsigned short int uint16_t;
typedef unsigned char uint8_t;

typedef union
{
	uint16_t portD;
	struct
	{
		uint8_t portA;
		uint8_t portB;
	};
} PORTS;

static PORTS ports;

static void writePort(char port, uint16_t value);
static uint16_t getPort(char port);



void bitSet(char port, int bit)
{
	int portValue = getPort(port);
	portValue = portValue | (1<<bit);
	writePort(port, portValue);
}

void bitCLr(char port, int bit)
{
	int portValue = getPort(port);
	portValue = portValue & (~(1<<bit));
	writePort(port, portValue);
}

char bitGet(char port, int bit)
{
	char bitValue;
	int portValue = getPort(port);
	bitValue = ((portValue & (1<<bit)) != 0);
	return bitValue;
}

void bitToggle(char port, int bit)
{
	char bitValue;
	bitValue = bitGet(port, bit);

	if(bitValue)
	{
		bitCLr(port, bit);
	}else
	{
		bitSet(port, bit);
	}

}

static uint16_t getPort(char port)
{
	uint16_t value;

	switch(port)
	{
	case 'a':
	case 'A':
		value = (uint16_t) ports.portA;
		break;
	case 'b':
	case 'B':
		value = (uint16_t) ports.portB;
		break;
	case 'd':
	case 'D':
		value = ports.portD;
		break;
	}

	return value;
}

static void writePort(char port, uint16_t value)
{
	switch(port)
	{
	case 'a':
	case 'A':
		ports.portA = (uint8_t) value;
		break;
	case 'b':
	case 'B':
		ports.portB = (uint8_t) value;
		break;
	case 'd':
	case 'D':
		ports.portD = value;
		break;
	}
}



