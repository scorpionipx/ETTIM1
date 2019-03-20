#include <iostream >
#include <math.h>    
using namespace std;

class Complex
   {
       double real;
       double imag;
     public:

       Complex(double x=0.0, double y=0.0)
       {
           real=x;imag=y;
       }

       Complex(const Complex& c)
       {
           real=c.real;imag=c.imag;
        }

       double mod()
       {
           return sqrt(real*real+imag*imag);
       }

       double& retreal()
       {
           return real;
       }

       double& retimag()
       {
           return imag;
       }

       Complex operator + (const Complex &) const;
       friend  Complex operator + (double , const Complex& ); 
       friend istream& operator >>(istream &, Complex&);
       friend ostream& operator <<(ostream &, const Complex&);       
       ~Complex(){}
   };

 
Complex Complex :: operator + (const Complex& z) const
   {
       Complex temp;
       temp.real=real+z.real;
       temp.imag=imag+z.imag;
       return temp;
   }

   Complex operator + (double x, const Complex& z)
   {
       Complex temp;
       temp.real=x+z.real;
       temp.imag=z.imag;
       return temp;
   } 

   istream& operator >>(istream & in, Complex& z)
  {
  	in>>z.real>>z.imag;
  	return in;
  }

 ostream& operator <<(ostream &out, const Complex& z)
 {
	out<<z.real<<"+i"<<z.imag<<endl;
	return out;
}

int main(void)
{
       		Complex z1; 
       		const Complex z4(2,2);
	   	Complex z5;
       		z1=z4+z5;  
	   	cout<<z1<<endl;
       		cout<<"z1=";
       		cin>>z1;
       		cout<<"z1= "<<z1;
	   	z1=3.0+z4;
	   	cout<<"z1= "<<z1;
       		return 0;
}
