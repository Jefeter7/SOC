/*
 * lcd4bint.c
 *
 * Created: 27.8.2017 15:47:44
 *  Author: Patrick
 */ 
#define command 0
#define dat 1
#define tst 100
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#define Xtal 8000000

#include <stdlib.h>
/*uses pins PORTB0-7 and PORTC*/

void LCD_8init(void)
{
	_delay_ms(500);
	/*so the thing i did here is that I interchanged PORTB0 for PORTC3 since PORTB0 is used as clkout, any data sent to PORTB shall be manually
	written to PORTC4 to take effect*/
	DDRB = 0b11111111; //set d0-7 to outputs 
	DDRC |= (1<<PORTC0) | (1<<PORTC1) | (1<<PORTC3); //set rs and en and additional interchanged portb
	//DDRC &= ~(1<<PORTC2); //this one can serve as busy flag when you disconnect led from it and connect to db7
	_delay_ms(100);
	PORTB = 0b00111000;			//FUNCTION SET- 2LINE,8BIT,5x8Font
	enter();
	_delay_ms(100);
	sendB(command, 0b00001110);	//Display ON Cursor On
	sendB(command, 0b00000110);	//increment position
}
void LCD_4init(void)
{
	DDRB |= (1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3);
	_delay_ms(10);
	PORTB = 0x2;
	enter();

	
	sendB(command, 0x20);	//3
	sendB(command, 0b00001110);//4
	sendB(command, 0b00000110);//5
	sendB(dat, 0b01001000);//6
}



void sendB(char comdat, char c) //send byte
{
	PORTC &= ~(1<<PORTC);
	PORTB = 0;
	if(comdat) 
		PORTC |= (1<<PORTC0);
	else
		PORTC &= ~(1<<PORTC0);
	PORTB = c;
	
	if ((c & 1) == 1)
		PORTC |= (1<<PORTC3);
	else
		PORTC &= ~(1<<PORTC3); //important part resembles portb[0] to portc[x] to connect to db0
	enter();
	
	
}
void enter(void)
{
	PORTC |= (1<<PORTC1);
	_delay_us(tst);
	PORTC &= ~(1<<PORTC1);
}

void BF (void)
{
	while(PINC2);
}


void Lputs(char *s)
{
	while (*s)
	{
		sendB(dat,*s);
		s++;
	}
}

//#######DISPLAY COMMANDS

void clrscr(void) //clears screen sets home
{
	sendB(command, 1);
}

void home(void) //returns cursor home 0x00
{
	sendB(command,2);
}

void hometwo(void) //returns home in second row 0x40
{
	sendB(command, 40+128);
}