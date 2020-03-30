#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>

struct Statystyka
{
    int dobreOdp;
    int zleOdp;
};

void ustaw(Statystyka & St, int db, int zl);

void dodajDobra(Statystyka & St);

void dodajZla(Statystyka & St);

int iloscDobrych(Statystyka St);

int iloscZlych(Statystyka St);

std::ostream & operator << (std::ostream & out, const Statystyka & St);

#endif
