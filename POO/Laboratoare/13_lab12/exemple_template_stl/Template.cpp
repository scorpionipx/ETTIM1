
#include <iostream>
#include <string>

using namespace std;
template <class T>
T val_min(T *v, int n)
{
	T min=v[0];
	for(int i=0;i<n;i++)
		if(min>v[i])
			min=v[i];
	return min;
}


//val_min(double,int);
//val_min(string,int);
int main(void)
{
	double vv[]={1.0,2.3,44};
	cout<<val_min(vv, 3)<<endl;

	string vs[]={"Azi", "este", "ultimul","laborator","URAAA!"};
	cout<<val_min(vs, 5)<<endl;

	return 0;


}