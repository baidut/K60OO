/**
// 应用实例：按键KEY按下，LED亮，松开按键，LED灭
// 强调可读性写法：

	#define KEY_DOWN 1
	#define KEY_UP	!KEY_DOWN
	#define LED_ON	 0
	#define LED_OFF	!LED_ON

	Gpio key = Gpio(PTB, 2);
	Gpio led = Gpio(PTA, 8, OUTPUT, LED_OFF);
	
	for(;;){
		if( KEY_DOWN == key.read() )
			led.write(LED_ON);
		else
			led.write(LED_OFF);
	}

// 强调简洁性写法：

	Gpio led(PTB,2);
	Gpio key(PTA,8,OUTPUT,1);
	
	for(;;)led = !key; 

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
	
	void set();
	void clear();
	void toggle();
	
	u8 read();
	void write(u8 level){
		if(level)
			this-> set();
		else 
			this-> clear();	
	}
	
	u8 val(){
		return this-> read();
	}
	void val(u8 level){
		this-> write(level);
	}
	// 支持51风格
	// led = 1; // LED置高
	// if(key)led = !led; // 如果按键按下，则LED翻转
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