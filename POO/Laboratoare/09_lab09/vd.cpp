#include <iostream>
using namespace std;
class Base
{
   	public:
      	Base(){ cout<<"Constructing Base\n";}
      	
     // this is a destructor:
	
	~Base(){ cout<<"Destroying Base\n";}
};

class Derive: public Base
{
        public:
       	Derive(){ cout<<"Constructing Derive\n";}
       	
       	~Derive(){ cout<<"Destroying Derive\n";}
 };

void main()
{
    	Base *basePtr = new Derive();
        
        delete basePtr;
}