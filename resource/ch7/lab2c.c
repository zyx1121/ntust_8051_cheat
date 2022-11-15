#include <REGX51.H>

char TABLE_PW[] = "ABC";
char TABLE_L7S[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x67};

void main(void) {
	char i;
	
	SCON = 0x50;
	TMOD = 0x20;
	TH1  = (256 - (28800 / 9600));
	TL1  = (256 - (28800 / 9600));
	TR1  = 1;
	
	while(1) {
		i = 0;
		while(i != 3) {
			while(RI == 0);
			RI = 0;
			SBUF = SBUF;
			while(TI == 0);
			TI = 0;
			if(SBUF == TABLE_PW[i]) i++; else i = 0;
		}
		while(RI == 0);
		RI = 0;
		SBUF = SBUF;
		while(TI == 0);
		TI = 0;
		P0 = TABLE_L7S[SBUF - 0x30];
	}
}

