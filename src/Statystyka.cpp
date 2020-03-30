#include "Statystyka.hh"
#include <iostream>

void ustaw(Statystyka & St, int db, int zl)
{
    St.dobreOdp = db;
    St.zleOdp = zl;
}

void dodajDobra(Statystyka & St)
{
    St.dobreOdp++;
}

void dodajZla(Statystyka & St)
{
    St.zleOdp++;
}


int iloscDobrych(Statystyka St)
{
    return St.dobreOdp;

}

int iloscZlych(Statystyka St)
{
    return St.zleOdp;
}

std::ostream & operator << (std::ostream & out, const Statystyka & St)
{
  out << "\n";
  out << "------------Statystyki------------\n";
  out << "Ilosc poprawnych odpowiedzi: " << iloscDobrych(St) << "\n";
  out << "Ilosc blednych odpowiedzi: " << iloscZlych(St) << "\n";
  out << "Wynik procentowy: " << (iloscDobrych(St)*100.0)/(iloscZlych(St) + iloscDobrych(St)) << "%\n";
  out << "----------------------------------";
  out << "\n";
  return out;
}
