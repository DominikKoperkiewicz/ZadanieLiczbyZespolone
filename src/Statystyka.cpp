#include "Statystyka.hh"
#include <iostream>

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

void ustaw(Statystyka & St, int db, int zl)
{
    St.dobreOdp = db;
    St.zleOdp = zl;
}

void wyswietl(Statystyka St)
{
  std::cout << "\n";
  std::cout << " Koniec testu" << "\n";
  std::cout << "------------Statystyki------------\n";
  std::cout << "Ilosc poprawnych odpowiedzi: " << iloscDobrych(St) << "\n";
  std::cout << "Ilosc blednych odpowiedzi: " << iloscZlych(St) << "\n";
  std::cout << "Wynik procentowy: " << (iloscDobrych(St)*100.0)/(iloscZlych(St) + iloscDobrych(St)) << "%\n";
  std::cout << "----------------------------------";
  std::cout << "\n";
}
