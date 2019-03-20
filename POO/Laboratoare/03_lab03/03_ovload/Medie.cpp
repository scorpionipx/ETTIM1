/*****************************
Supraincarcarea functiilor
medie.cpp
*****************************/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>

using namespace std;
float Media(int a, int b)
//Media aritmetica a 2 intregi
{
    cout << "media aritmetica a 2 intregi" << endl;
    float Med = float(a+b)/2;
    return Med;
}

float Media(int a, float b)
//Modulul mediei aritmetice ponderate a unui intreg //cu un real
{
    cout << "modulul mediei aritmetice ponderate";
    cout << " a unui intreg cu un real" << endl;
    double Med = (0.25*a+1.25*b)/1.5;
    return Med;
}

float Media(int a, int b, int c)
//Media geometrica a 3 intregi
{
    cout << "media geometrica a 3 intregi" << endl;
    float exp=1./3;
    float Med=pow(a*b*c,exp);
    return Med;
}

void Media(int a, int b, float c)
//Media armonica a 2 intregi si un real fara //returnare de valoare
{
    cout << "media armonica a 2 intregi si un ";
    cout << "real fara returnare de valoare";
    cout << endl;
    float Med;
    
    if (a!=0 && b!=0 && c!=0)
        {
            Med=3/(1/a+1/b+1/c);
            cout << "Media armonica testata Ma=";
            cout << Med << endl;
        }
    else
        {
            cout << "Media armonica nu se poate";
            cout << " calcula!"<<endl;
        }
}

int main()
{
    double x,z;
    float y;

    cout << endl << "Se apleaza ";
    cout << "Media(7,8)=" << Media(7,8) << endl;

    //cout << endl << "Se apleaza ";
    //cout << "Media(7,8.5)=" << Media(7,8.5);
    //cout << endl;
    
    cout << endl << "Se apleaza ";
    y=8.5;
    cout << "Media(7,y=8.5)=" << Media(7,y);
    cout << endl;

    cout << endl << "Se apleaza ";
    x = Media(6,8);
    cout << "Media(6,8)=x=" << x << endl;

    cout << endl << "Se apleaza ";
    cout << "Media(5,8,9)=" << Media(5,8,9) <<endl;

    // z este de tip double. Ce se intampla?
    cout << endl << "Se apleaza ";
    z = Media(5,8,9);  
    cout << "Media(5,8,9)=z=" << z << endl;

    //cout << endl << "Se apleaza ";
    //float t = Media(5,8,9.5);
    //cout << "Media(5,8,9.5)=t=" << t << endl;

    y=1.7;
    
    //cout << endl << "Se apleaza ";
    //cout << "Media(3,2,1.7)=" << Media(3,2,1.7);
    //cout <<endl;

    cout << endl << "Se apleaza ";
    Media(3,2,y);

    //cout << endl << "Se apleaza ";
    //Media(3,2,1.7);

    //Atentie la functiile apelate mai jos:

    cout << endl << "Se apleaza ";
    Media(1,5,0);

    cout << endl << "Se apleaza ";
    Media(1,y,0);

    cout << endl << "Se apleaza ";
    Media(1,0,y);

    _getch();
    return 0;
}