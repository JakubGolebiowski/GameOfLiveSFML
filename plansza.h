//-------------------------------------------------------------------------
// Plik nag��wskowy klasy plansza.h
//
// Klasa ma za zadanie przechowywa� tablic� obiekt�w typu "Komorka"
//
// Pola Klasy:
//		Komorka**plansza - 2wymiarowy wska�nik na tablic� obiekt�w typu komorka
//		unsigned int x - wymiar x, odpowiadaj�cy pierwszemu wymiarowi tablicy plansza
//		unsigned int y - wymiar y, odpowiadaj�cy drugiemu wymiarowi tablicy plansza
//
// Autor:             Nr_albumu:      Data rozpocz�cia:		Data zako�czenia:  
//Jakub Go��biowski   382723		  26.02.2020			04.03.2020
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
	void SetSize(unsigned int _x, unsigned int _y); // czy�ci tablice do samych zer
	void SetKomorka(unsigned int _x, unsigned int _y, bool _stan);

	//Gettery
	bool GetKomorka(unsigned int _x, unsigned int _y)const;
	int GetKomorkaInt(unsigned int _x, unsigned int _y)const;
	unsigned int GetX()const;
	unsigned int GetY()const;
	Komorka ** GetPlansza()const;

};

#endif