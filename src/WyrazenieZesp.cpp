#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Wyswietl(WyrazenieZesp  WyrZ)
{
    cout << "(" << WyrZ.Arg1.re << showpos << WyrZ.Arg1.im << noshowpos << "i)";
    cout << "(" << WyrZ.Arg2.re << showpos << WyrZ.Arg2.im << noshowpos << "i)";

}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZespolona Z1;

    switch(WyrZ.Op)
    {
        case Op_Dodaj  : return WyrZ.Arg1 + WyrZ.Arg2;
        case Op_Odejmij: return WyrZ.Arg1 - WyrZ.Arg2;
        case Op_Mnoz   : return WyrZ.Arg1 * WyrZ.Arg2;
        case Op_Dziel  : return WyrZ.Arg1 / WyrZ.Arg2;
    }
}
