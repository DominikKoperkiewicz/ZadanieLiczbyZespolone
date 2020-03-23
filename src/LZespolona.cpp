#include "LZespolona.hh"
#include <cmath>

LZespolona utworz(double r, double i)
{
    LZespolona Z;
    Z.re = r;
    Z.im = i;
    return Z;
}



std::istream & operator >> (std::istream & in, LZespolona & Z)
{
    char znak;
    in >> znak;
    if(znak != '(') in.setstate(std::ios::failbit);
    in >> Z.re >> Z.im >> znak;
    if(znak != 'i') in.setstate(std::ios::failbit);
    in >> znak;
    if(znak != ')') in.setstate(std::ios::failbit);
    return in;
}

std::ostream & operator << (std::ostream & out, const LZespolona & Z)
{
    out << "(" << Z.re << std::showpos << Z.im << std::noshowpos << "i)";
    return out;
}

LZespolona  sprzezona(LZespolona Z1)
{
  LZespolona  Wynik;

  Wynik.re = Z1.re;
  Wynik.im = Z1.im * (-1);
  return Wynik;
}

double modul(LZespolona Z1)
{
    double Wynik = sqrt(Z1.re * Z1.re + Z1.im * Z1.im);
    return Wynik;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.im * Skl2.re + Skl1.re * Skl2.im;
  return Wynik;
}

/*
LZespolona  operator = (LZespolona  &Skl1,  LZespolona  Skl2)
{
  &Skl1.re = Skl2.re;
  &Skl1.im = Skl2.im;
  return Skl1;
}
*/

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  Wynik = Skl1 * sprzezona(Skl2) / ( modul(Skl2)*modul(Skl2) );
  //Wynik.re = Wynik.re/( modul(Skl2)*modul(Skl2) );
  //Wynik.im = Wynik.im/( modul(Skl2)*modul(Skl2) );

  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  double  Skl2)
{
  LZespolona Wynik;
  Wynik.re = Wynik.re/Skl2;
  Wynik.im = Wynik.im/Skl2;

  return Wynik;
}

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
    if(abs(Skl1.re - Skl2.re) < 0.00001 && abs(Skl1.im - Skl2.im) < 0.00001) return true;
    return false;
}

bool  operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
    return !(Skl1 == Skl2);
}
