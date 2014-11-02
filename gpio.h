/**
 * eg1: 
 * Gpio key = Gpio(PTB, 2);
 * Gpio led = Gpio(PTA, 8, OUTPUT, 1);
 * for(;;){
 * 	 if( 1== key.val() )
 *	   led.set();
 *   else led.clear();
 * }
 * 支持51风格
 * led = 1;
 * if(key)led = !led;
 */
 
#ifndef _GPIO_H_
#define _GPIO_H_

#include "common.h"

enum {
	INPUT = 0,
	OUTPUT = 1
};

enum {
	PTA,
	PTB,
	PTC,
	PTD,
	PTE
};

class Gpio{
public:
	Gpio(u8 port,u8 n,u8 dir = INPUT,u8 level = 0);
	~Gpio();
	u8 val();
	void set();
	void clear();
	void toggle();
	void val(u8 level){
		if(level)
			this-> set();
		else 
			this-> clear();
	}
	Gpio& operator = (u8 level){
		this-> val(level);
		return * this;
	}
	operator u8(){
		return this-> val();
	}
private:
	u8 port;
	u8 n;
};

#endif