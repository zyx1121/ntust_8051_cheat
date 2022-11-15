code char decodekey[] = {7, 4, 1, 0, 8, 5, 2, 10, 9, 6, 3, 11, 12, 13, 14, 15}; 

typedef enum status_e {idle, press, hold, release} status_t;

typedef struct keyboard_s { 
 char status; 
 int  time; 
} keyboard_t;
	
keyboard_t key[16];

void keyboard_loop(void) { 
	unsigned char x, i, y[4] = {0xf7, 0xfb, 0xfd, 0xfe}; 
  
	static char read;
	
	read = 16;
  
	for (i = 0; i < 4; i++) { 
		P0 = y[i]; 
		x = P0 & 0xf0; 
		if (x == 0x70)   	read = decodekey[i * 4]; 
		else if (x == 0xb0) read = decodekey[i * 4 + 1]; 
		else if (x == 0xd0) read = decodekey[i * 4 + 2]; 
		else if (x == 0xe0) read = decodekey[i * 4 + 3]; 
	}
	
	for (i = 0; i < 16; i++) { 
		switch (key[i].status) { 
			case idle:
				if (i == read) key[i].status = press; 
				break; 
			case press:
				key[i].status = hold;
				break;
			case hold:
				if (i != read) key[i].status = release, key[i].time = 0; 
				else if (key[i].time < 5000) key[i].time++;
				break; 
			case release:
				key[i].status = idle; 
				break; 
		}
	}
}