#include "Statystyka.hh"

void dodajDobra(Statystyka & St)
{
    St.dobreOdp++;
}

void dodajZla(Statystyka & St)
{
    St.zleOdp++;
}


int iloscDobrych(Statystyka & St)
{
    return St.dobreOdp;

}

int iloscZlych(Statystyka & St)
{
    return St.zleOdp;
}

void ustaw(Statystyka & St, int db, int zl)
{
    St.dobreOdp = db;
    St.zleOdp = zl;
}
