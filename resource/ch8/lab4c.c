#include <REGX51.H>
#define	N 27

char TEXT[] = "The keyboard you pressed is ", k = ' ', SPACE = ' ';
char i = 0, send = 0;

void main(void) {
	TMOD = 0x20;
	TH1  = 0xfd;
	SCON = 0x50;
	TR1	 = 1;
	ES   = 1;
	EA   = 1;
	
	send = 1;
	TI	 = 1;
	while(1);
}

void UART_ISR(void) interrupt 4 {
	if(TI) {
		TI = 0;
		if(send) {
			if(i == -2) SBUF = k;
			else if(i == -1) SBUF = SPACE;
			else if(i >=  0) SBUF = TEXT[i];
			if(++i > N) i = -2, send = 0;
		}
	}
	if(RI) {
		RI = 0;
		k = SBUF;
		send = 1;
		TI = 1;
	}
}