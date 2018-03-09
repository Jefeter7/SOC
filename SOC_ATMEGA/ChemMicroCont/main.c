#define F_CPU 8000000
void test (void);
void Int_init(void);
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>
#include <string.h>
#include "lcd4bint.h"
#include "USARTlib.h"
#include "ADClib.h"
#include "resources.h"
/* there are temperature, pH and UV probe connected to the ADC pins, PORTC2,4,5 are free to use, Voltage reference of X volts is connected to Aref.*/
static char	chtemp=4, chuv=2, chpH=5; //temp probe to PC4 and respectively
uint16_t temp,pH,uv;
uint8_t		controlint, icounter = 0;

char buffer[5], Tbuf[10];

int main(void)
{
    AdcInit();
	USART_init(38400);
	Int_init();
	
    while (1) 
    {
		if(USART_Receive_byte() == 'X') //if request 'X' arrives then measurements are done and results retrieved 
		{
			pH = AdcRead(chpH);
			temp = AdcRead(chtemp);
			uv = AdcRead(chuv);
			
			Tbuf[0] = ((temp<<8)>>8);
			if(temp>>8 != 0)	//correctment Process
				Tbuf[1] = (temp>>8); //if the result is less than 512 this byte is be set to Null what is BAD, yep remember to zeroe that at the end so that next under-512 ADC result is set similarly
			else
				Tbuf[1] = 0b10000000;
			
			Tbuf[2] = ((pH<<8)>>8);
			if(pH>>8 != 0)
				Tbuf[3] = (pH>>8);
			else
				Tbuf[3] = 0b10000000;
			//
			Tbuf[4] = 2;		//not to read
			//
			Tbuf[5] = ((uv<<8)>>8);
			if(uv>>8 != 0)			//does not have to be here but is safer since not definition of upper byte in memory of computer might result in wild bugs
				Tbuf[6] = (uv>>8);
			else
				Tbuf[6] = 0b10000000;
			//Always whole buffer is sent, null terminated by Tbuf[7]
			if(icounter)
			{
				icounter--;
				Tbuf[4] = 1;	//to read	
				_delay_ms(50);		
			}
			
			USART_send_string(Tbuf);
			

		}
    }
}

void test (void)
{
	USART_send_string("hi");
}

void Int_init(void)
{
	EICRA &= ~(1<<ISC00) | ~(1<<ISC01);
	EIMSK |= (1<<INT0);
	sei();
}

ISR(INT0_vect) //set 
{
	//controlint = 1;
	icounter = 3; //set value for transmit cycles
	// user code here
}
