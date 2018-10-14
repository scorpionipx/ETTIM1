#include<htc.h>
#define _XTAL_FREQ 4000000
unsigned char x,y;
void main(void)
{
	TRISD=0;
	T2CON=0b00000100;
	CCP1CON=0b01001100;
	PR2=99;
	CCPR1L=60;
	GIE=1;
	PEIE=1;
	TMR2IE=1;
	TRISA=0b00000001;
	ANSEL=0b00000001;
	ADCON0=0b00000001;
	ADCON1=0;
	while(1)
	{
	GO=1;
	while(GO!=0);
	x=ADRESH;
	__delay_ms(100);

	}
}
void interrupt myfct(void)
{
	if(TMR2IF==1 && TMR2IE==1)
	{
		CCPR1L=x;
//		y++;
//		if(y==100)
//	{ 
//	x++;
//	y=0;
//	}
//		if(x>100)
//		x=0;
		TMR2IF=0;
	}
}