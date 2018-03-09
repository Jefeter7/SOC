/*
 * ADClib.c
 *
 * Created: 24.10.2017 19:14:04
 *  Author: 
 */ 
#include "ADClib.h"

void AdcInit(void)
{
	DDRC &= ~(1<<PORTC2) | ~(1<<PORTC4) | ~(1<<PORTC5); //set  channels as inputs
			//AVCC with external capacitor at AREF pin, channel by default 0 will be changed in AdcRead()
	ADCSRA |= (1<<ADPS2);//|(1<<ADPS1)|(1<<ADPS0); //set prescaler to 128
	
}

uint16_t AdcRead(char chnl) //takes in channel and outputs read value, we are using ADC2(0010), ADC4(0100) and ADC5(0101)
{
	ADMUX = 0b01000000 | chnl;//or with 0b01000000 to set external volt ref.  channel by default 0 will be changed in AdcRead() //set channel
	ADCSRA |= (1<<ADEN) | (1<<ADSC); //enable ADC and start conversion
	while (ADCSRA & (1<<ADSC)); //wait while conversion is in progress
	ADCSRA &= ~(1<<ADEN); //turn off ADC
	
	return (ADCL | (ADCH<<8));	
}