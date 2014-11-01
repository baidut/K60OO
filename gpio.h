
/**
 * eg1: 
 * Gpio key = Gpio(PTB, 2);
 * Gpio led = Gpio(PTA, 8, OUTPUT, 1);
 * for(;;){
 * 	 if( 1== key.val() )
 *	   led.set();
 *   else led.clear();
 * }
 */
 
#ifndef _GPIO_H_
#define _GPIO_H_

enum {
	INPUT = 0,
	OUTPUT = 1
};

class Gpio{
public:
	Gpio(u8 port,u8 n,u8 dir = INPUT);
	Gpio(u8 port,u8 n,u8 dir,u8 level){
		this-> Gpio(port, n, dir);
		this-> val(level);
	}
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
private:
	u8 port;
	u8 pin;
};

#endif