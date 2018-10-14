#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

	 float t[3][3] = {{ 15,18,20},{18,22,28},{24,35,40}};  	// declarare matrice + valori
	 float ut[3][3] = { {1,1,0},   {0,1,0},   {0,1,1}};		// intervale 1,0
	 float grad_apart(float,float *,float *,int);  // prototipul functiei
	
int main(void) {	
	//declarare variabile
	float tc,utc[3];
	// se ia temperatura de la tastatura
	printf("Dati temperatura:");
	scanf("%f",&tc);
	utc[0]=grad_apart(tc,t[0],ut[0],3);
	//afisare grad apartenenta
	printf("Gradul de apartenenta este: %f",utc[0]);
	getch();
	return 0;	
}
		// corp functie
	float grad_apart(float xc, float x[],float y[],int np)
	{	int i;
		for(i=0;i<np-1;i++)
		{
			if( xc>=x[i] && xc<=x[i+1])
				{
					if(y[i]<=y[i+1])
						return ((xc-x[i])/(x[i+1]-x[i])*(y[i+1]-y[i])+y[i]);
					if(y[i]>y[i+1])
						return ((x[i+1]-xc)/(x[i+1]-x[i])*(y[i]-y[i+1]+y[i+1]));
					if(y[i]==y[i+1]) 
						return (y[i]);
				}
			}	
			return y[np-1];
	}
