
#include "register.h"
#include "gpio.h"

#define PIN_MUX_CONTROL_GPIO  		0x01 //001
#define PIN_MUX_CONTROL_DISABLED	0x00 //000

static GPIO_MemMapPtr GPIOx[] = {	    PTA_BASE_PTR, 
										PTB_BASE_PTR, 
										PTC_BASE_PTR, 
										PTD_BASE_PTR, 
										PTE_BASE_PTR }; 
static PORT_MemMapPtr PORTx[] = {	    PORTA_BASE_PTR, 
										PORTB_BASE_PTR, 
										PORTC_BASE_PTR, 
										PORTD_BASE_PTR, 
										PORTE_BASE_PTR };

Gpio::Gpio(u8 port,u8 n,u8 dir, u8 level){
	// assert input param
	ASSERT( port < 5u && n < 32u );
	
	// mux for gpio
	PORT_PCR_REG(PORTx[port], n) = PORT_PCR_MUX( PIN_MUX_CONTROL_GPIO );
	
	// set dir 
    if( OUTPUT == dir){
		SET_BIT( GPIO_PDDR_REG(GPIOx[port]) , n );
    }
	else{
		CLR_BIT( GPIO_PDDR_REG(GPIOx[port]) , n );
    }
}

Gpio::~Gpio(){
	// disable io
	PORT_PCR_REG(PORTx[port], n) = PORT_PCR_MUX( PIN_MUX_CONTROL_DISABLED );
}

u8 Gpio::val(){
	return  GET_BIT( GPIO_PDIR_REG(GPIOx[port]) , n );
}

void Gpio::set(){
	SET_BIT( GPIO_PDOR_REG(GPIOx[(port)]) , n );
}

void Gpio::clear(){
	CLR_BIT( GPIO_PDOR_REG(GPIOx[(port)]) , n );
}

void Gpio::toggle(){
	SET_BIT( GPIO_PTOR_REG(GPIOx[(port)]) , n );
} 
