#include "ports.h"
#include <stdio.h>

#define BIT_CHECK(b) (((b) >= 0) && ((b) <= 15))
#define PORT_CHECK(p) (((p) == PORT_A) || ((p) == PORT_B) || ((p) == PORT_D))
#define BIT_ERROR_MESSAGE "Wrong port number"
#define PORT_ERROR_MESSAGE "Port is not defined"

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

int bitSet(char port, int bit)
{
	uint16_t portValue;

	if(PORT_CHECK(port))
	{
		portValue = getPort(port);

		if(BIT_CHECK(bit))
		{
			portValue = portValue | (1<<bit);
			writePort(port, portValue);
		}
		else
		{
			printf(BIT_ERROR_MESSAGE);
		}

	}
	else{
		printf(PORT_ERROR_MESSAGE);
		return 0;
	}

	return portValue;
}

int bitCLr(char port, int bit)
{

	uint16_t portValue;

	if(PORT_CHECK(port))
	{
		portValue = getPort(port);

		if(BIT_CHECK(bit))
		{
			portValue = portValue & (~(1<<bit));
			writePort(port, portValue);
		}
		else
		{
			printf(BIT_ERROR_MESSAGE);
		}
	}
	else
	{
		printf(PORT_ERROR_MESSAGE);
		return 0;
	}

	return portValue;
}

int bitGet(char port, int bit)
{
	char bitValue;
	uint16_t portValue;

	if(PORT_CHECK(port))
	{
		portValue = getPort(port);

		if(BIT_CHECK(bit))
		{
			bitValue = ((portValue & (1<<bit)) != 0);
		}
		else
		{
			printf(BIT_ERROR_MESSAGE);
		}
	}
	else
	{
		printf(PORT_ERROR_MESSAGE);
		return 0;
	}

	return bitValue;
}

int bitToggle(char port, int bit)
{
	uint16_t portValue;

	if(PORT_CHECK(port))
	{
		portValue = getPort(port);

		if(BIT_CHECK(bit))
		{
			portValue = portValue ^ (1<<bit);
			writePort(port, portValue);
		}
		else
		{
			printf(BIT_ERROR_MESSAGE);
		}
	}
	else
	{
		printf(PORT_ERROR_MESSAGE);
		return 0;
	}

	return portValue;

}

int maskOn(char port, int mask)
{
	uint16_t portValue;

	if(PORT_CHECK(port))
	{
		portValue = getPort(port);
		portValue = portValue | mask;
		writePort(port, portValue);
	}
	else
	{
		printf(PORT_ERROR_MESSAGE);
		return 0;
	}

	return portValue;

}

int maskOff(char port, int mask)
{
	uint16_t portValue;

	if(PORT_CHECK(port))
	{
		portValue = getPort(port);
		portValue = portValue & (~mask);
		writePort(port, portValue);
	}
	else
	{
		printf(PORT_ERROR_MESSAGE);
		return 0;
	}

	return portValue;

}

int maskToggle(char port, int mask)
{
	uint16_t portValue;

	if(PORT_CHECK(port))
	{
		portValue = getPort(port);
		portValue = portValue ^ mask;
		writePort(port, portValue);
	}
	else
	{
		printf(PORT_ERROR_MESSAGE);
		return 0;
	}

	return portValue;

}


static uint16_t getPort(char port)
{
	uint16_t value;

	switch(port)
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
	default:
		printf(PORT_ERROR_MESSAGE);
		value = 0;
		break;
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
	default:
		printf(PORT_ERROR_MESSAGE);
		break;
	}
}



