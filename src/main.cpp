#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"
/*
#include "LZespolona.cpp"
#include "WyrazenieZesp.cpp"
#include "Statystyka.cpp"
*/
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  Statystyka Staty;
  ustaw(Staty,0,0);
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona   Odp;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    //cout << " Czesc rzeczywista pierwszego argumentu: ";
    //cout << WyrZ_PytanieTestowe.Op << endl;
    cout << ":? Podaj Wynik Operacji: " << WyrZ_PytanieTestowe << "\n   Twoja odpowiedz: ";
    cin >> Odp;
    if(Odp == oblicz(WyrZ_PytanieTestowe))
    {
        dodajDobra(Staty);
        cout << ":) Dobra odpowiedz\n\n";
    }
    else
    {
        dodajZla(Staty);
        cout << ":( Bledna odpowiedz \n\n";
    }
  }


  cout << endl;
  cout << " Koniec testu" << endl;
  cout << "------------Statystyki------------\n";
  cout << "Ilosc poprawnych odpowiedzi: " << iloscDobrych(Staty) << "\n";
  cout << "Ilosc blednych odpowiedzi: " << iloscZlych(Staty) << "\n";
  cout << "Wynik procentowy: " << (iloscDobrych(Staty)*100.0)/(iloscZlych(Staty) + iloscDobrych(Staty)) << "%\n";
  cout << "----------------------------------";
  cout << endl;

}
