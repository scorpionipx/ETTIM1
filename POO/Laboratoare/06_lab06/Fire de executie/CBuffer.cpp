#include "CBuffer.h"
#include <iostream>
using namespace std;

#define PRODUCATOR_SLEEP_TIME_MS 500
#define CONSUMATOR_SLEEP_TIME_MS 100

#pragma warning( disable:  4351)
CBuffer::CBuffer(void):m_indexCurent(-1), m_buffer(), val(0), m_sectiuneCritica()
{
	 InitializeCriticalSection (&m_sectiuneCritica);	
}

CBuffer::~CBuffer(void) 
{
	DeleteCriticalSection(&m_sectiuneCritica);
}

void CBuffer::producator()
{

	while (true)
	{
		Sleep (rand() % PRODUCATOR_SLEEP_TIME_MS);
		//EnterCriticalSection (&m_sectiuneCritica);
		if(m_indexCurent < BUFFER_SIZE - 1)
		{
			m_indexCurent++;
			Sleep(3); 
			m_buffer[m_indexCurent] = val;
			val++;
			cout<<"Producatorul: valoare "<<val<<", dimensiune buffer "<<m_indexCurent+1 << endl;
		}
		//LeaveCriticalSection(&m_sectiuneCritica);
	}

}
void CBuffer::consumator()
{
	while (true)
	{
    	//EnterCriticalSection (&m_sectiuneCritica);
		if(m_indexCurent != -1)
		{
			int valoareCitita = m_buffer[m_indexCurent];
			m_indexCurent--;

			cout<<"Consumatorul: valoare "<<valoareCitita<<", dimensiune buffer "<<m_indexCurent+1 << endl;
		}	
		//LeaveCriticalSection(&m_sectiuneCritica);
		Sleep (rand() % CONSUMATOR_SLEEP_TIME_MS);

	}
}
