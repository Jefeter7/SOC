/*
This is library for HD44780 LCD diplay. For correct function please refer to the circuit below:
PORTB0-3 to DB4-7 =>
PORTB3/DB7 is also connected to PORTC2 to serve as busy flag <=
PORTC0 to RS =>
PORTC1 to E =>
R/W pin grounded ?
NOTES:
	RW = 0 write, 1 read
	RS = 0 instruction register,  data register
	E = starts data read write
	 */ 


#ifndef LCD4BINT_H_
#define LCD4BINT_H_

void LCD_8init(void);
void LCD_4init(void);
void sendB(char comdat, char c);
void enter(void);
void BF(void);
void Lputs (char *s);
void home(void);
void hometwo(void);
void clrscr(void);

#endif /* LCD4BINT_H_ */