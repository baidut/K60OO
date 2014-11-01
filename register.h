
#ifndef _REGISTER_H_
#define _REGISTER_H_

#define _BV(bit) (1 << (bit))

#define SET_BIT(reg, bit) ((reg) |= _BV(bit))
#define CLR_BIT(reg, bit) ((reg) &= ~_BV(bit)))
#define GET_BIT(reg, bit) ((reg) >> (bit) & 0x1 )

#endif