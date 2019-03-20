#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI firDeExecutie( LPVOID lpParam )
{
	cout<<"Al doilea fir de executie!"<<endl;
	return 0;
}
int main()
{
	cout<<"Firul de executie main\n";
	DWORD threadId = 0;
	//Crearea unui thread prin utilizarea functiei CreateThread
	//Aceasta functie returneaza valoare de tip HANDLE si reprezinta un identificator al firului de executie 
	HANDLE hThread = CreateThread( 
		nullptr,                   
		0,                // utilizeaza dimensiunea implicita pentru stiva firului de executie
		firDeExecutie,    // numele functie fir de executie
		0,                // argument pentru functia firului de executie(lpParam)
		0,                      
		&threadId);

	/*se asteapta ca al doilea fir sa isi termine executia
	In caz contrar este posibil ca programul sa isi termine executia(firul main), 
	iar al doilea fir sa nu se execute niciodata. */
	
	//1) Adorminea firului main prin utilizarea functiei sleep
	//Sleep(1000); //1 secunda

	/*2) Utilizarea functiei WaitForSingleObject( sau WaitForMultipleObjects) care asteapta ca handle-ul 
	firului de executie sa fie semnalat in momentul in care firul isi termina executia.*/
	WaitForSingleObject(hThread, INFINITE); 
	
	CloseHandle(hThread);
	return 0;
}
