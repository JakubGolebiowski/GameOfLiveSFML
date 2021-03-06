//-------------------------------------------------------------------------
// Plik nagłówskowy klasy silnik.h
//
// Klasa abstrakcyjna, ma za zadanie przechowywać obiekt plansza, analizować
//		aktualny stan gry i być interfacem dla wszystkich rozbudowań
//		gry (wersja graficzna/konsolowa itp)
//
// Pola Klasy:
//		Plansza plansza - obiekt przechowujący aktualny stan gry
//
// Autor:             Nr_albumu:      Data rozpoczęcia:		Data zakończenia:
//Jakub Gołębiowski   382723		  26.02.2020			04.03.2020
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

	//Metoda analizująca następną pozycję gry
	void Analiza();

	unsigned int LiczbaZywych(unsigned int i, unsigned int j);
	// bool policzStan(unsigned int x);

	//Metoda uruchamiająca gre, przyjmuje 2 początkowe wartości
	//	pierwsza to liczba pokoleń, druga czas między kolejnymi
	//	pokoleniami
	virtual void Start(unsigned int _liczba, unsigned int _sleepTime)=0;

	//Metoda czytowirtualna, musi być nadpisana w dziecku
	virtual void Rysuj() = 0;
};

#endif
