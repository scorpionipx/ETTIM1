#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vv(10,-2);      
	int aa[] = {3, 6, 4}; 
    vector<int> v(aa, aa+sizeof(aa)/sizeof(int)); 
 	vector<int>::iterator p; //declara un iterator pt un vector de intregi
 	for (p=v.begin(); p!=v.end(); p++) cout << *p << " "; //afiseaza elem. lui v
	cout<<endl;
	sort(v.rbegin(),v.rend()); // descresc
	swap(v,vv); //interschimba v cu vv
	for (p=v.begin(); p!=v.end(); p++) cout << *p << " "; //afiseaza elem. lui v
    cout<<endl;
	try
	{
	  cout<<v.at(100);
	//  cout<<v[100];  // Nu arunca exceptie!!!
	 } 
	 catch(out_of_range )
	 {
		 cout<<"auoaleu!";
	 }

	 cout << "\nUtilizarea functiei distance() "
         " pt. a calcula nr. de pozitii dintre 2 iteratori.";
    
	 int a[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
     list<int> intList(a, a+10);
     cout << "\n Valorile din lista\n";
     copy(intList.begin(), intList.end(), ostream_iterator<int>(cout, " "));
     cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

     list<int>::iterator p1 = intList.begin();
     list<int>::iterator p2 = intList.end();
      ++p1; ++p1; ++p1; //p1  pointeaza la a 4-a valoare
      --p2; --p2;       //p2  pointeaza la a 8-a valoare 
     cout << "\np1 pointeaza la valoarea" << *p1 << " (a 4-a valoare).";
     cout << "\np2 pointeaza la valoarea " << *p2 << " (a 9-a valare).";
     cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

     cout << "\nNumarul de valori (pozitii) dintre cele 2 valori(inclusiv) este "
         << (int)distance(p1, p2) + 1 << " (= 9-4+1).";

	 return 0;

}
