#include <REGX51.H>
#include "timer.h"
#include "input0.h"
#include "display0.h"
//#include "input1.h"
//#include "display1.h"

char mode = 0;
char tempRI;

void mode0(void) {
  
}

void mode1(void) {
  
}

void mode2(void) {
  
}

void mode3(void) {
  
}


void timer0_isr(void) interrupt 1 {
  /*
  static char offset = 0;
  
  TH0 = t0_val / 256;
	TL0 = t0_val % 256;

  if (++offset == 10) {
    offset = 0;
    
  }
  */
  
  /*
  TH0 = t0_val / 256;
	TL0 = t0_val % 256;
  
  if (++time.milli == 1000) {
    time.milli = 0;
    if (++time.second == 60) {
      time.second = 0;
      if (++time.minute == 60) {
        time.minute = 0;
        if (++time.hour == 24) {
          time.hour = 0;
        }
      }
    }
  }
  */
}

void int1_isr(void) interrupt 2 {
  
}

void uart_isr(void) interrupt 4 {
  if (RI) {
    
		//tempRI = SBUF;
    //SBUF = tempRI;

		RI = 0;    
	} else if (TI) {
		
    
		TI = 0;
	}
  
}

void loop(void) {
  button_loop();
  switch_loop();
  display0_loop();
  //keyboard_loop();
  //display1_loop();
  
  switch (mode) {
    case 0: mode0(); break;
    case 1: mode1(); break;
    case 2: mode2(); break;
    case 3: mode3(); break;
  }
}

void setup(void) {
  button_init();
  switch_init();
  display0_init();
  //display1_init();
  
  //int1_init();
  //timer0_init(1, (65536 - 46080), 0);
  //uart_init(9600);
  
  //led = L7S_T[0];
}

void main(void) {
  setup();
  while (1) loop();
}