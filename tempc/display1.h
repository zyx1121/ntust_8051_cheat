#define L7S_P0 P3_3 
#define L7S_P1 P3_4 
#define L7S_P2 P3_5 
#define L7S_P3 P2_5

typedef struct l7s_s {
	char dot;
	char led;
} l7s_t;

l7s_t l7s[4];

void display1_init(void) {
	char i;
	for (i = 0; i < 4; i++)
		l7s[i].dot = 0, l7s[i].led = 0;
}

void display1_loop() { 
	static char i = 0; 
  
	switch (i) { 
		case 0: { 
			L7S_P3 = 0; 
			P2 = l7s[0].led + 0x10 * !l7s[0].dot; 
			L7S_P0 = 1; 
			break; 
		} 
		case 1: { 
			L7S_P0 = 0; 
			P2 = l7s[1].led + 0x10 * !l7s[1].dot; 
			L7S_P1 = 1; 
			break; 
		} 
		case 2: { 
			L7S_P1 = 0; 
			P2 = l7s[2].led + 0x10 * !l7s[2].dot; 
			L7S_P2 = 1; 
			break; 
		} 
		case 3: { 
			L7S_P2 = 0; 
			P2 = l7s[3].led + 0x10 * !l7s[3].dot; 
			L7S_P3 = 1; 
			break; 
		} 
	}
	
	if (++i == 4) i = 0;
}