#include "inputs.h"
#include "ports.h"
#include <stdio.h>

#define TOGGLE 't'
#define TURN_ON  's'
#define TURN_OFF 'c'
#define EXIT 'q'
#define ERROR_MESSAGE "Input is not valid\n"
#define CLEAN_BUFFER while(getchar() != '\n')

char getUserInput(void)
{
	printf("Port A controller \n - Insert a number between 0 and 7 to turn on a bit \n - Insert t to toggle all bits \n - Insert s to turn on all bits \n - Insert c to turn off all bits \n - Insert q to exit \n");

	char input, programStatus = PROGRAM_CONTINUE;
	int portA;
	input = getchar();

	if(input >= '0' && input <= '7')
	{
		int bit = (int) (input - 48);
		portA = bitSet(PORT_A, bit);
	}
	else
	{
		switch(input)
		{
		case TOGGLE:
			portA = maskToggle(PORT_A, 0x11);
			break;
		case TURN_ON:
			portA = maskOn(PORT_A, 0x11);
			break;
		case TURN_OFF:
			portA = maskOff(PORT_A, 0x11);
			break;
		case EXIT:
			programStatus = PROGRAM_END;
			break;
		default:
			printf(ERROR_MESSAGE);

		}
	}

	if(programStatus == PROGRAM_CONTINUE)
	{
		printf("\nPORT A: %X\n", portA);
	}

	CLEAN_BUFFER;

	return programStatus;

}
