/*
 * IncFile1.h
 *
 * Created: 11/14/2016 9:20:50 AM
 *  Author: leader
 */ 

#ifndef SEVEN_SEG_H
#define SEVEN_SEG_H
#include <inttypes.h>
#include <avr/io.h>

#define bitRead(var, pin) (((var)>>(pin)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(var, bit, bitvalue) (bitvalue ? bitSet(var, bit) : bitClear(var, bit))
#define pinRead(port, pin) ((port) & 0x01<<(pin)) // read from port and value of (port)== PINR  COMMAND
#define makePort(value) (&value)
#define makePORTS(colport, colportDIR, rowport, rowportDIR, rowINPUTreg)   &colport, &colportDIR, &rowport, (&rowportDIR), (&rowINPUTreg)
#define LOW 0
#define HIGH 1
#define BLANK 16

#define COMMON_ANODE 1
#define COMMON_CATHODE 0
#define DIRECTLY 1
#define BYDRIVER 2

class SEVEN_SEG{
	public:
	SEVEN_SEG(char mode, volatile uint8_t* port, uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG);
    SEVEN_SEG (char mode, volatile uint8_t*  port, uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, uint8_t pinDP);
	SEVEN_SEG(char mode, volatile uint8_t* port,  uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD);
	void ledtest();
	void print(unsigned char number);
	void clear();
	void setPoint();
	void clearPoint();
	
	private:
	void init(char connection, char mode, volatile uint8_t*  port, uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, uint8_t pinDP);
	volatile uint8_t* DDRP_finder(volatile uint8_t *prt);
	char _pinarray[8];
	volatile uint8_t *_port;
	volatile uint8_t* _DDRP;
	volatile uint8_t* DIReg;																
	char _mode;
	unsigned char _number;
	char _connection;
	
	};

#endif 