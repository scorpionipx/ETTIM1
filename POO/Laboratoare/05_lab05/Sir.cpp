#include <iostream>
#include <string.h>
using namespace std;
class Sir
{
    char *psir;
    int lung;
   public:
    Sir(char * s="");
    Sir(int);
 //   Sir(const Sir&);
    void afissir();
    ~Sir(){ delete []psir;}
};

Sir:: Sir (char *sursa)
{
    lung=strlen(sursa);
    psir=new char[lung+1];
    strcpy(psir, sursa);
    cout<<"Constructor sursa="<<sursa<<endl;
}

Sir:: Sir(int l)
{
    lung=l;
    psir=new char[l+1];
	cout<<"Constructor sursa="<<l<<endl;
    *psir='\0';
}

//Sir ::Sir(const Sir& sursa) 
//{
//    lung=sursa.lung;
//    psir=new char[lung+1];
//    strcpy(psir, sursa.psir);
//    cout<<"Constructor cop. sursa=" 
//           <<sursa.psir<<endl;
//}

void Sir::afissir()
{
    cout<<psir;
}
int main()
{
    Sir s1(70), s2("OK");
    cout<<"s1=";         
    s1.afissir();
    cout<<endl;
    cout<<"s2=";
    s2.afissir();
    cout<<endl;
    Sir s3("C++ este un C mai bun");
    cout<<"s3=";
    s3.afissir();
    cout<<endl;    
    Sir s4(s3);
    cout<<"s4=";
    s4.afissir();
    cout<<endl;
    return 0;
}

