#include <windows.h>

class CBuffer
{
private:
	static const int BUFFER_SIZE = 10;	
	int m_indexCurent;
	int m_buffer[BUFFER_SIZE];
	int val;
	CRITICAL_SECTION   m_sectiuneCritica;
		
public:
	CBuffer(void);
	~CBuffer(void);
	void consumator();
	void producator();
};

