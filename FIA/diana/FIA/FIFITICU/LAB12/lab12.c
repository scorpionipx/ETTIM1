#include<htc.h>

void main (void)
{
 TRISB=0xFF;
 ANSEL=0;
 ANSELH=0;
 TRISD=0;
 INTCON=0b10011000;
 IOCB=0b11110000;
 WPUB=0;

  while(1)
 {
 }
}
void interrupt my_isr(void)
{
 if(INTF==1 && INTE==1)
 { INTF=0;
if(INTEDG==1)
{INTEDG=0;PORTD=0xFF;}
else
{INTEDG=1;PORTD=0;}

 }

if(RBIF==1&& RBIE==1)

{if(RB4==1) RD4=1;
else RD4=0;

if(RB5==1) RD5=1;
else RD5=0;

if(RB6==1) RD6=1;
else RD6=0;

if(RB7==1) RD7=1;
else RD7=0;

RBIF=0;
}
}


 