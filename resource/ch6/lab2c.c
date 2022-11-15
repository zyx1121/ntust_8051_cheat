#include <REGX51.H>

code char SEG_table[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x67};

void Delay_ms(int tx) {
	char ti;
	while(tx--)
		for(ti=0; ti<56; ti++);
}

main(void) {
	unsigned int xi = 0;
	P3_4 = 1;
	TMOD = 0x55;
	TR0 = 1;
	
	while(1) {
		TL0 = 0x00;
		TH0 = 0x00;
		Delay_ms(1);
		xi = TL0;
		xi = xi / 10;
		P0 = SEG_table[xi];
	}
}