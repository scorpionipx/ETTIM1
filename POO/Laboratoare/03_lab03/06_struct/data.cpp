#include <iostream>
#include <conio.h>
using namespace std;

enum ZilePeSapt {Luni, Marti, Miercuri, Joi, Vineri, Sambata, Duminica};
enum LuniPeAn {Ian, Feb, Mar, Apr, Mai, Iun, Iul, Aug, Sep, Oct, Nov, Dec};

struct Data
	{
		ZilePeSapt NumeZi;
		int Zi;
		LuniPeAn Luna;
		int An;
	};

int main()
{
	LuniPeAn OLuna, AltaLuna;
	Data DataNasterii, DataOarecare;

	OLuna = Ian;
	AltaLuna = Oct;

	DataNasterii. NumeZi = Luni;
	DataNasterii.Zi = 25;
	DataNasterii.Luna = AltaLuna;
	DataNasterii.An = 1982;

	DataOarecare = DataNasterii;

	cout << "Anul nasterii: " << DataNasterii.An << endl;
	_getch();
	return 0;
}
