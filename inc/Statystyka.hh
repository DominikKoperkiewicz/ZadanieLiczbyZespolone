#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

struct Statystyka
{
    int dobreOdp;
    int zleOdp;
};

void dodajDobra(Statystyka & St);

void dodajZla(Statystyka & St);

int iloscDobrych(Statystyka & St);

int iloscZlych(Statystyka & St);

void ustaw(Statystyka & St, int db, int zl);


#endif
