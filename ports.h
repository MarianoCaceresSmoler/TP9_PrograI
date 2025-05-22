#ifndef PORTS_H_
#define PORTS_H_

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_D 'D'

void bitSet(char port, int bit);

void bitCLr(char port, int bit);

char bitGet(char port, int bit);

void bitToggle(char port, int bit);

void maskOn(char port, int mask);

void maskOff(char port, int mask);

void maskToggle(char port, int mask);

#endif /* PORTS_H_ */
