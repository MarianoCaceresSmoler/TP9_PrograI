#ifndef PORTS_H_
#define PORTS_H_

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_D 'D'

int bitSet(char port, int bit);

int bitCLr(char port, int bit);

int bitGet(char port, int bit);

int bitToggle(char port, int bit);

int maskOn(char port, int mask);

int maskOff(char port, int mask);

int maskToggle(char port, int mask);

#endif /* PORTS_H_ */
