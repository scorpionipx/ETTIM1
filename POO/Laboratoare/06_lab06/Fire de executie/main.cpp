#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "CBuffer.h"



using namespace std;

//Firul de executie consumator
DWORD WINAPI Consumator( LPVOID lpParam )
{
	CBuffer* buffer = static_cast<CBuffer*> (lpParam);
	buffer->consumator();
	return 0;
}

//Firul de executie Producator
DWORD WINAPI Producator( LPVOID lpParam )
{	
	CBuffer* buffer = static_cast<CBuffer*> (lpParam);
	buffer->producator();
	return 0;
}

int main()
{
	static const int MAX_THREADS = 2;
	HANDLE hThread[MAX_THREADS];
	DWORD threadIdCons;
	DWORD threadIdProd;

	CBuffer* b = new CBuffer(); // bufferul comun care va fi accesat de cele doua fire de executie

	hThread[0] = CreateThread( 
		NULL,                 
		0,                    
		Producator,     
		b,         
		0,                      
		&threadIdProd);

	hThread[1] = CreateThread( 
		NULL,                   
		0,                      
		Consumator,       
		b,         
		0,                     
		&threadIdCons);  
	//WaitForMultipleObjects asteapta ca cele doua fire de executie sa isi termine executia
	WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE);
	delete b;

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	return 0;
}


