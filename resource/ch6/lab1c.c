#include <REGX51.H>

code char L7S[] = {0x6d, 0x66, 0x4f, 0x5b, 0x06, 0x3f};

void timer_delay_1s(void);

main(void) {
	char i;
	P2_5 = 1;
	TMOD = 0x11;
	while(1) {
		while(!P2_5);
		for(i=0; i<6; i++) {
			P0 = L7S[i];
			timer_delay_1s();
		}
	}
}

void timer_delay_1s(void) {
	char i;
	for(i=20; i>0; i--) {
		TH0 = (65536 - 46080) / 256;
		TL0 = (65536 - 46080) % 256;
		TR0 = 1;
		while(TF0 == 0);
		TR0 = 0;
		TF0 = 0;
	}
}