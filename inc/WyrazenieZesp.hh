#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

std::ostream & operator << (std::ostream & out, const Operator & Op);

std::ostream & operator << (std::ostream & out, const WyrazenieZesp & WyrZ);

std::istream & operator >> (std::istream & in, Operator & Op);

std::istream & operator >> (std::istream & in, WyrazenieZesp & WyrZ);

LZespolona oblicz(WyrazenieZesp  WyrZ);

#endif
