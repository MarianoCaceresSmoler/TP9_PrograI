#include "ports.h"

#define toUpperCase(arg) ((arg) - 32)

typedef unsigned short int uint16_t;
typedef unsigned char uint8_t;

typedef union
{
	struct
	{
		uint8_t portB;
		uint8_t portA;
	};
	uint16_t portD;
} ports_t;

static ports_t ports;

static void writePort(char port, uint16_t value);
static uint16_t getPort(char port);

void bitSet(char port, int bit)
{
	uint16_t portValue = getPort(port);
	portValue = portValue | (1<<bit);
	writePort(port, portValue);
}

void bitCLr(char port, int bit)
{
	uint16_t portValue = getPort(port);
	portValue = portValue & (~(1<<bit));
	writePort(port, portValue);
}

char bitGet(char port, int bit)
{
	char bitValue;
	uint16_t portValue = getPort(port);
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

void maskOn(char port, int mask)
{
	uint16_t portValue = getPort(port);
	portValue = portValue | mask;
	writePort(port, portValue);
}

void maskOff(char port, int mask)
{
	uint16_t portValue = getPort(port);
	portValue = portValue & (~mask);
	writePort(port, portValue);
}

void maskToggle(char port, int mask)
{
	uint16_t portValue = getPort(port);
	portValue = portValue ^ mask;
	writePort(port, portValue);
}


static uint16_t getPort(char port)
{
	uint16_t value;

	switch(toUpperCase(port))
	{
	case PORT_A:
		value = (uint16_t) ports.portA;
		break;
	case PORT_B:
		value = (uint16_t) ports.portB;
		break;
	case PORT_D:
		value = ports.portD;
		break;
	// default: VER MANEJO DE ERRORES
	}

	return value;
}

static void writePort(char port, uint16_t value)
{
	switch(port)
	{
	case PORT_A:
		ports.portA = (uint8_t) value;
		break;
	case PORT_B:
		ports.portB = (uint8_t) value;
		break;
	case PORT_D:
		ports.portD = value;
		break;
	// default:; VER MANEJO DE ERRORES
	}
}



