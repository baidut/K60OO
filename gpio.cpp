
#include "register.h"
#include "gpio.h"

#define PIN_MUX_CONTROL_GPIO  		0x01 //001
#define PIN_MUX_CONTROL_DISABLED	0x01 //000

static struct GPIO_MemMap *GPIOx[] = {	PTA_BASE_PTR, 
										PTB_BASE_PTR, 
										PTC_BASE_PTR, 
										PTD_BASE_PTR, 
										PTE_BASE_PTR }; 
static struct PORT_MemMap *PORTx[] = {	PORTA_BASE_PTR, 
										PORTB_BASE_PTR, 
										PORTC_BASE_PTR, 
										PORTD_BASE_PTR, 
										PORTE_BASE_PTR };

Gpio::Gpio(u8 port,u8 n,u8 dir = INPUT){
	// assert input param
	ASSERT( port < 5u && n < 32u );
	
	// mux for gpio
	PORT_PCR_REG(PORTX[port], n) = PORT_PCR_MUX( PIN_MUX_CONTROL_GPIO );
	
	// set dir 
	if( OUPUT == dir)
		SET_BIT( GPIO_PDDR_REG(GPIOx[port]) , n );
	else 
		CLR_BIT( GPIO_PDDR_REG(GPIOx[port]) , n );
}

Gpio::~Gpio(){
	// disable io
	PORT_PCR_REG(PORTX[port], n) = PORT_PCR_MUX( PIN_MUX_CONTROL_DISABLED );
}

Gpio::val(){
	return  GET_BIT( GPIO_PDIR_REG(GPIOx[port]) , n );
}

Gpio::set(){
	SET_BIT( GPIO_PDOR_REG(GPIOx[(port)]) , n );
}

Gpio::clear(){
	CLR_BIT( GPIO_PDOR_REG(GPIOx[(port)]) , n );
}

Gpio::toggle(){
	SET_BIT( GPIO_PTOR_REG(GPIOx[(port)]) , n );
} 
