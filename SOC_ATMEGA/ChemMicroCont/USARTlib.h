/*
 * USARTlib.h
 *
 * Created: 12.10.2017 20:16:42
 *  Author: Patrik
 */ 


#ifndef USARTLIB_H_
#define USARTLIB_H_
//#include "AllinOne.h"
#include <avr/io.h>
#define Xtal 8000000
void USART_init( unsigned int baudr);
void USART_Transmit_byte( unsigned char data ); //send byte
unsigned char USART_Receive_byte( void );
void USART_send_string(char *str);
#endif /* USARTLIB_H_ */