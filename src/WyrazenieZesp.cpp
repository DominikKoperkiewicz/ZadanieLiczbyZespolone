#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

std::ostream & operator << (std::ostream & out, const Operator & Op)
{
    switch(Op)
    {
        case Op_Dodaj  : out << "+";
            break;
        case Op_Odejmij: out << "-";
            break;
        case Op_Mnoz   : out << "*";
            break;
        case Op_Dziel  : out << "/";
    }
    return out;
}

std::ostream & operator << (std::ostream & out, const WyrazenieZesp & WyrZ)
{
    out << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;
    return out;
}

std::istream & operator >> (std::istream & in, Operator & Op)
{
    char znak;
    in >> znak;
    switch(znak)
    {
        case '+': Op = Op_Dodaj;
            break;
        case '-': Op = Op_Odejmij;
            break;
        case '*': Op = Op_Mnoz;
            break;
        case '/': Op = Op_Dziel;
            break;
        default: in.setstate(std::ios::failbit);
    }
    return in;
}

std::istream & operator >> (std::istream & in, WyrazenieZesp & WyrZ)
{
    in >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return in;
}

void wyswietl(WyrazenieZesp  WyrZ)
{
    wyswietl(WyrZ.Arg1);
    switch(WyrZ.Op)
    {
        case Op_Dodaj  : std::cout << "+";
            break;
        case Op_Odejmij: std::cout << "-";
            break;
        case Op_Mnoz   : std::cout << "*";
            break;
        case Op_Dziel  : std::cout << "/";
    }
    wyswietl(WyrZ.Arg2);
    //cout << "(" << WyrZ.Arg1.re << showpos << WyrZ.Arg1.im << noshowpos << "i)";
    //cout << "(" << WyrZ.Arg2.re << showpos << WyrZ.Arg2.im << noshowpos << "i)";

}

LZespolona oblicz(WyrazenieZesp  WyrZ)
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
