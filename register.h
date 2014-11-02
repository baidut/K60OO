
#ifndef _REGISTER_H_
#define _REGISTER_H_

#define _BV(bit) (1 << (bit))

#define SET_BIT(reg, bit) do{(reg) |= _BV(bit);}while(0)
#define CLR_BIT(reg, bit) do{(reg) &= ~_BV(bit);}while(0)
#define GET_BIT(reg, bit) ((reg) >> (bit) & 0x1)

#endif