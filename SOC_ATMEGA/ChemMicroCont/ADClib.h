

#ifndef ADCLIB_H_
#define ADCLIB_H_
#include <avr/io.h>
//FUNCTION PROTOTYPES
void AdcInit(void);
uint16_t AdcRead(char);
char tempbuf[1];
#endif