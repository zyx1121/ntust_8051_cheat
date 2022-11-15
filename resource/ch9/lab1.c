#include <REGX51.H>

char i, Step=0;
char CW[4]  = {3, 6, 12, 9};

void Delay_ms(int tx) {
  char ti;
  while (tx--)
  for (ti=0;ti<56;ti++);
}

void main(void) {
  while (1) {
    for(i=0;i<4;i++) {
      if (P2_7) Step = CW[i]; 
      else      Step = CW[3 - i]; 
      
      P0 = Step; 
      P2 = Step | 0xf0;
      
      if(P2_6) Delay_ms(200); 
      else     Delay_ms(10); 
    }
  }
}