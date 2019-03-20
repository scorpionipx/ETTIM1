/*************************
Functie de Interschimbare...
Intersch.cpp
*************************/
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

void Interschimb(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
};

int main()
{
	int x = 1;
	int y = 2;
	cout << "x=" << x << "  y=" << y << endl;
	Interschimb(x,y);
	cout << "x=" << x << "  y=" << y << endl;
	getch();
	return 0;
}