//-------------------------------------------------------------------------
// Plik nag³ówskowy klasy silnik.h
//
// Klasa abstrakcyjna, ma za zadanie przechowywaæ obiekt plansza, analizowaæ
//		aktualny stan gry i byæ interfacem dla wszystkich rozbudowañ
//		gry (wersja graficzna/konsolowa itp)
//
// Pola Klasy:
//		Plansza plansza - obiekt przechowuj¹cy aktualny stan gry
//
// Autor:             Nr_albumu:      Data rozpoczêcia:		Data zakoñczenia:
//Jakub Go³êbiowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#ifndef silnik_h
#define silnik_h

#include <windows.h>

#include "plansza.h"

class Silnik
{
private:
	Plansza plansza;
protected:
	Plansza GetPlansza()const;
public:
	//Konstruktory
	Silnik();
	Silnik(const char * plik);
	Silnik(const Silnik & _SilnikCopy);

	//operator przypisania
	Silnik &operator=(const Silnik & _SilnikCopy);

	virtual ~Silnik();

	//Metoda analizuj¹ca nastêpn¹ pozycjê gry
	void Analiza();

	unsigned int LiczbaZywych(unsigned int i, unsigned int j);
	// bool policzStan(unsigned int x);

	//Metoda uruchamiaj¹ca gre, przyjmuje 2 pocz¹tkowe wartoœci
	//	pierwsza to liczba pokoleñ, druga czas miêdzy kolejnymi
	//	pokoleniami
	virtual void Start(unsigned int _liczba, unsigned int _sleepTime)=0;

	//Metoda czytowirtualna, musi byæ nadpisana w dziecku
	virtual void Rysuj() = 0;
};

#endif
