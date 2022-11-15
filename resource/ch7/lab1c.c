#include <REGX51.H>

char TABLE_TEXT[] = "HELLO!";

void DELAY_MS(int tx) {
	char ti;
	while(tx--) for(ti = 0; ti < 56; ti++);
}

void main(void) {
	char i;
	
	SCON = 0x50;
	TMOD = 0x20;
	TH1  = (256 - (28800 / 9600));
	TL1  = (256 - (28800 / 9600));
	TR1  = 1;
	
	P2_5 = 1;
	
	while(1) {
		while(P2_5 == 0);
		DELAY_MS(50);
		if(P2_5) {
			for(i = 0; i < 6; i++) {
				SBUF = TABLE_TEXT[i];
				while(TI == 0);
				TI = 0;
			}
			while(P2_5);
		}
	}
}