//-------------------------------------------------------------------------
// Plik nag��wskowy klasy silnik.h
//
// Klasa abstrakcyjna, ma za zadanie przechowywa� obiekt plansza, analizowa�
//		aktualny stan gry i by� interfacem dla wszystkich rozbudowa�
//		gry (wersja graficzna/konsolowa itp)
//
// Pola Klasy:
//		Plansza plansza - obiekt przechowuj�cy aktualny stan gry
//
// Autor:             Nr_albumu:      Data rozpocz�cia:		Data zako�czenia:
//Jakub Go��biowski   382723		  26.02.2020			04.03.2020
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

	//Metoda analizuj�ca nast�pn� pozycj� gry
	void Analiza();

	unsigned int LiczbaZywych(unsigned int i, unsigned int j);
	// bool policzStan(unsigned int x);

	//Metoda uruchamiaj�ca gre, przyjmuje 2 pocz�tkowe warto�ci
	//	pierwsza to liczba pokole�, druga czas mi�dzy kolejnymi
	//	pokoleniami
	virtual void Start(unsigned int _liczba, unsigned int _sleepTime)=0;

	//Metoda czytowirtualna, musi by� nadpisana w dziecku
	virtual void Rysuj() = 0;
};

#endif
