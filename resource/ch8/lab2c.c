#include <REGX51.H>
#define T0VAL (65536-46080)

char TABLE_L7S[] = {0x6d, 0x66, 0x4f, 0x5b, 0x06, 0x3f};

char i = 0, div_t0 = 0;

void main(void) {
	P2_5 = 1;
	P0 = TABLE_L7S[5];
	
	TMOD = 0x01;
	TH0  = T0VAL / 256;
	TL0  = T0VAL % 256;
	ET0  = 1;
	EA   = 1;
	
	while(1) {
		if(P2_5) TR0 = 1;
	}
}

void T0_ISR(void) interrupt 1 {
	TH0  = T0VAL / 256;
	TL0  = T0VAL % 256;
	
	if(++div_t0 >= 20) {
		div_t0 = 0;
		P0 = TABLE_L7S[i];
		if(++i > 5) {
			i = 0;
			TR0 = 0;
		}
	}
}