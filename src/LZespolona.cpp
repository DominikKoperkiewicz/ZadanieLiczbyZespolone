#include "LZespolona.hh"




LZespolona  con(LZespolona Z1)
{
  LZespolona  Wynik;

  Wynik.re = Z1.re;
  Wynik.im = Z1.im * (-1);
  return Wynik;
}

double abs(LZespolona Z1)
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
  Wynik = Skl1 * con(Skl2);
  Wynik.re = Wynik.re/( abs(Skl2)*abs(Skl2) );
  Wynik.im = Wynik.im/( abs(Skl2)*abs(Skl2) );

  return Wynik;
}
