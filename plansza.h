//-------------------------------------------------------------------------
// Plik nag³ówskowy klasy plansza.h
//
// Klasa ma za zadanie przechowywaæ tablicê obiektów typu "Komorka"
//
// Pola Klasy:
//		Komorka**plansza - 2wymiarowy wskaŸnik na tablicê obiektów typu komorka
//		unsigned int x - wymiar x, odpowiadaj¹cy pierwszemu wymiarowi tablicy plansza
//		unsigned int y - wymiar y, odpowiadaj¹cy drugiemu wymiarowi tablicy plansza
//
// Autor:             Nr_albumu:      Data rozpoczêcia:		Data zakoñczenia:  
//Jakub Go³êbiowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#ifndef plansza_h
#define plansza_h

#include "komorka.h" 

#include <iostream>
#include <fstream>

class Plansza
{
private:
	Komorka ** plansza;
	unsigned int x;
	unsigned int y;
public:
	//Konstruktory
	Plansza();
	Plansza(unsigned int _x, unsigned int _y); //same zera
	Plansza(const char* _plik);
	Plansza(const Plansza & _PlanszaCopy);

	//operator przypisania
	Plansza &operator=(const Plansza & _PlanszaCopy);

	virtual ~Plansza();

	//Settery
	void SetSize(unsigned int _x, unsigned int _y); // czyœci tablice do samych zer
	void SetKomorka(unsigned int _x, unsigned int _y, bool _stan);

	//Gettery
	bool GetKomorka(unsigned int _x, unsigned int _y)const;
	int GetKomorkaInt(unsigned int _x, unsigned int _y)const;
	unsigned int GetX()const;
	unsigned int GetY()const;
	Komorka ** GetPlansza()const;

};

#endif