/*
 * USARTlib.c
 *
 * Created: 12.10.2017 20:16:17
 *  Author: Patrik
 */ 
#include "USARTlib.h"

void USART_init( unsigned int baudr)
{
	//add baudrate converter
	char ubrr= 12;//(((long)Xtal/(16*baudr))-1); //38400 has only 0.2%err
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	//Enable receiver and transmitter 
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);/* Set frame format: 8data, 1stop bit */
	UCSR0C = (3<<UCSZ00);
}

void USART_Transmit_byte( unsigned char data ) //send byte
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

unsigned char USART_Receive_byte( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}

void USART_send_string(char *str)
{
	while(*str)
	{
		USART_Transmit_byte(*str);
		str++;
	}
}