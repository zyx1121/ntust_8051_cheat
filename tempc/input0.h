#define BTN_N 2
#define BTN_P0 P2_5
#define BTN_P1 P2_4
#define BTN_P2 P3_3

#define SWT_N 2
#define SWT_P0 P2_7
#define SWT_P1 P2_6

typedef enum btn_status_e {idle, press, hold, release} btn_status_t;

typedef struct button_s {
    char status;
    int time;
} button_t;

button_t btn[3];

char swt[2];

void switch_init() {
    P2 = 0xff;
}

void button_init() {
    P2 = 0xff;
}

void switch_loop() {
    swt[0] = SWT_P0;
    swt[1] = SWT_P1;
}

void button_loop() {
    char i, read;

    for (i = 0; i < BTN_N; i++) {
		switch (i) {
			case 0: read = BTN_P0; break;
			case 1: read = BTN_P1; break;
			case 2: read = BTN_P2; break;
		}
        switch (btn[i].status) {
            case idle:
                if (read) btn[i].status = press;
                break;
            case press:
                btn[i].status = hold;
                break;
            case hold:
                if (!read) btn[i].status = release;
                else if (btn[i].time < 5000) btn[i].time++;
                break;
            case release:
                btn[i].status = idle;
                break;
        }
    }
}
