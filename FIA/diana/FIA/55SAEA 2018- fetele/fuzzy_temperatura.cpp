/*lab1: sisteme fuzzy - functie de calcul temperatura
scazut: 15 18 22;
         1 1 1
mediu:  18 22 28;
        0  1   0
crescut: 24 35 40;
        0  1   1
		np=numar de puncte existente;				  */
		
#include<stdio.h>
#include<conio.h>
float t[3][3] = {{15,18,20}, {18,22,28}, {24,35,40}};
float ut[3][3] = {{1,1,0}, {0,1,0}, {0,1,1}};
float grad_apartenenta(float , float *, float *, int);

int main(void)
{
	float xc,utc[3];
	printf("temp_curenta:\n");
	scanf("%f",&xc);

utc[0] = grad_apartenenta(xc,t[0],ut[0],3);
printf ("grad_apartenenta: %f",utc[0]);
getch();
return 0;
}
float grad_apartenenta(float xc, float x[], float y[], int np)
{
int i;
for(i=0; i<np-1;i++)
   {
	if (xc>=x[i] && xc<=x[i+1])
		{
	   if(y[i] < y[i+1])
		  return (xc-x[i])/(x[i+1]-x[i])*(y[i+1]-y[i])+y[i];
	   if(y[i] > y[i+1])
		  return (x[i+1]-xc)/(x[i+1]-x[i])*(y[i]-y[i+1])+y[i+1];
		if(y[i]==y[i+1])
		   return y[i];
	   }
   }	   
}
	
	
