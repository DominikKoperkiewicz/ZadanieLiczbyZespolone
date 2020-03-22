#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


LZespolona utworz(double r, double i);
void wyswietl(LZespolona Z1);
std::istream & operator >> (std::istream & in, LZespolona & Z); //Wczytaj
std::ostream & operator << (std::ostream & out, const LZespolona & Z); //Wyswietl

LZespolona  sprzezona(LZespolona Z1); // Liczba sprzezona

double modul(LZespolona Z1); // wartosc bezwzgledna/odleglosc

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

bool  operator != (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator = (LZespolona  Skl1,  LZespolona  Skl2);


#endif
