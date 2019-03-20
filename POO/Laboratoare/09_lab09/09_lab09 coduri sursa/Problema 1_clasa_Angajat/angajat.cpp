#include <iostream>
#include <conio.h>
using namespace std;

class Angajat                  // angajat class
   {
   private:
      enum { LUNG=30 };          // lungimea maxima a numelui
      char nume[LUNG];           // numele angajatului 
      unsigned long numar;     //  ID-ul angajatului 
   public:
      void intro_date()
         {
         cout << "\n   Introduceti numele: "; cin >> nume;
         cout << "   Introduceti ID-ul angajatului : ";      cin >> numar;
         }
      void afis_date()
         {
         cout << "\n   Nume = " << nume;
         cout << "\n   Numar  = " << numar;
         }
   };
class Manager : public Angajat     // clasa manager
   {
   private:
      enum { LUNG=40 };          // lungimea maxima a titlului
      char titlu[LUNG];          // "vice-presedinte" etc.
      int nr_masini;              // numarul de masini
   public:
      void intro_date()
         {
         Angajat::intro_date();
         cout << "   Introduceti titlul: ";         cin >> titlu;
         cout << "   Introduceti numarul de masini: "; cin >> nr_masini  ;
         }
      void afis_date()
         {
         Angajat::afis_date();
         cout << "\n   Titlu = " << titlu;
         cout << "\n   Numarul de masini  = " << nr_masini ;
         }
   };
class Cercetator : public Angajat      // clasa cercetator
   {
   private:
      int pub;      // numbar de publicatii
   public:
      void intro_date()
         {
         Angajat::intro_date();
         cout << "   Introduceti numarul de publicatii: "; cin >> pub;
         }
      void afis_date()
         {
         Angajat::afis_date();
         cout << "\n   Numarul de publicatii = " << pub;
         }
   };
class Muncitor : public Angajat        // clasa muncitor
   {
   };
int main()
   {
   Manager m1, m2;
   Cercetator c1;
   Muncitor l1;
   cout << endl;
   cout << "\nIntroduceti date pt. manager 1";     // date pentru
   m1.intro_date();                             // diversi angajati
   cout << "\nIntroduceti date pt. manager 2";
   m2.intro_date();
   cout << "\n Introduceti date pt. cercetator 1";
   c1.intro_date();
   cout << "\nIntroduceti date pt.muncitor 1";
   l1.intro_date();
   cout << "\nDate despre manager 1";           // afisare date 
   m1.afis_date();                            //  angajati
   cout << "\nDate despre manager 2";
   m2.afis_date();
   cout << "\nDate despre cercetator 1";
   c1.afis_date();
   cout << "\nDate despre muncitor 1";
   l1.afis_date();
   cout<<"\nApasati o tasta...";
   _getch();
   return 0;
   }
    
