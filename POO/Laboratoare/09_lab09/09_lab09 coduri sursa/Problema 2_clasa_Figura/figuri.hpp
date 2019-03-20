#ifndef _FIGURI_H
#define _FIGURI_H

// declaratie clasa figura

class Figura
   {
   private:
      int xCo, yCo;             // coordonate figura
      int dim;                  // dimensiune  figura
   protected:                  
      int getx() const { return xCo; }
      int gety() const { return yCo; }
      int getz() const { return dim; }
      void jos() const;         // prototip
   public:                      // constructor 3-arg 
      Figura(int x, int y, int s) : xCo(x), yCo(y), dim(s)
         {  }
      virtual void deseneaza() const = 0;  // functie pur virtuala
   };

// declaratie clasa patrat, derivata din figura

class Patrat : public Figura     // patrat
   {
   public:                      //  constructor 3-arg
      Patrat(int x, int y, int s) : Figura(x, y, s)
         {  }
      void deseneaza() const;        // prototip
   };

// declaratie clasa triunghi, derivata din figura

class Triunghi : public Figura                  // triunghi
   {
   public:                                
      Triunghi(int x, int y, int s) : Figura(x, y, s)
         {  }
      void deseneaza() const;             
   };

// declaratie clasa bol, derivata din figura

class Bol : public Figura       // triunghi cu varful in jos
   {
   public:                      
      Bol(int x, int y, int s) : Figura(x, y, s)
         {  }
      void deseneaza() const;   
   };



#endif