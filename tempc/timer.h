// (65536 - 922)
// (65536 - 46080)
int t0_val = (65536 - 922);

typedef struct time_s {
	int  milli;
	char second;
	char minute;
	char hour;

	char half;
} time_t;

time_t time;

void timer0_init(char mode, int _t0_val, char counter) {
	t0_val = _t0_val;
  
  TMOD |= mode | (counter  ? 0x04 : 0x00);
  
	TH0 = t0_val / 256;
	TL0 = t0_val % 256;
	TR0 = 1;
  
  ET0 = 1;
  EA  = 1;
}

void uart_init(int baudrate) {
	SCON |= 0x50;
	TMOD |= 0x20;
  
	TH1 = (256 - (28800 / baudrate));
	TL1 = (256 - (28800 / baudrate));
	TR1 = 1;
  
  ES = 1;
  EA = 1;
}

void int1_init(void) {
  IE1 = 0;
  IT1 = 1;
  EX1 = 1;
  EA  = 1;
}