//-------------------------------------------------------------------------
// Plik - cia³a - klasy plansza.h
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

#include "plansza.h"

Plansza::Plansza():x(0),y(0)
{
	plansza = 0;
}

Plansza::Plansza(unsigned int _x, unsigned int _y):x(_x),y(_y)
{
	plansza = new Komorka *[x];
	for (unsigned int i = 0; i < x; i++) {
		plansza[i] = new Komorka[y];
	}

	for (unsigned int i = 0; i < x; i++)
	{
		for (unsigned int j = 0; j < y; j++)
		{
			plansza[i][j] = Komorka(0);
		}
	}
}

Plansza::Plansza(const char * _plik)
{
	std::ifstream otworz;
	otworz.open(_plik);

	bool a=0;
	if (otworz.good()) {
		
			otworz >> this->x;
			otworz >> this->y;

			plansza = new Komorka *[x];
			for (unsigned int i = 0; i < x; i++) {
				plansza[i] = new Komorka[y];
			}
			for (unsigned int i = 0; i < x; i++) {
				for (unsigned int j = 0; j < y; j++)
				{
					otworz >> a;
					if(a)plansza[i][j].setStan(1);
					else plansza[i][j].setStan(0);
				}
			}
		
	}
	else {
		std::cout << "Brak pliku :(" << std::endl;
	}
}

Plansza::Plansza(const Plansza & _PlanszaCopy):x(_PlanszaCopy.x), y(_PlanszaCopy.y)
{
	plansza = new Komorka *[x];
	for (unsigned int i = 0; i < x; i++) {
		plansza[i] = new Komorka[y];
	}

	for (unsigned int i = 0; i < x; i++)
	{
		for (unsigned int j = 0; j < y; j++)
		{
			plansza[i][j] = _PlanszaCopy.plansza[i][j];
		}
	}
}

Plansza & Plansza::operator=(const Plansza & _PlanszaCopy)
{
	if (this != &_PlanszaCopy) {
		if (this != NULL) {
			for (unsigned int i = 0; i < this->GetX(); i++)
			{
				delete[]plansza[i];
			}
			delete[]plansza;
		}
		plansza = new Komorka *[x];
		for (unsigned int i = 0; i < x; i++) {
			plansza[i] = new Komorka[y];
		}

		for (unsigned int i = 0; i < x; i++)
		{
			for (unsigned int j = 0; j < y; j++)
			{
				plansza[i][j] = _PlanszaCopy.plansza[i][j];
			}
		}
	}
	return *this;
}


Plansza::~Plansza()
{
	for (unsigned int i = 0; i < x; i++) {
		delete[]plansza[i];
	}
	delete[]plansza;
}

void Plansza::SetSize(unsigned int _x, unsigned int _y)
{
	for (unsigned int i = 0; i < x; i++)
	{
		delete[]this->plansza[i];
	}
	delete[]this->plansza;

	this->x = _x;
	this->y = _y;

	plansza = new Komorka *[x];
	for (unsigned int i = 0; i < x; i++) {
		plansza[i] = new Komorka[y];
	}

	for (unsigned int i = 0; i < x; i++)
	{
		for (unsigned int j = 0; j < y; j++)
		{
			plansza[i][j] = Komorka(0);
		}
	}
}

void Plansza::SetKomorka(unsigned int _x, unsigned int _y, bool _stan)
{
	if (x > _x && y > _y) {
		plansza[_x][_y]= Komorka(_stan);
	}
	return;
}

bool Plansza::GetKomorka(unsigned int _x, unsigned int _y) const
{
	if (x > _x && y > _y) {
		return (plansza[_x][_y].getStan())?1:0;
	}
	else {
		std::cout << "Brak podanego pola" << std::endl;
		return 0;
	}
}

int Plansza::GetKomorkaInt(unsigned int _x, unsigned int _y) const
{
	if (x > _x && y > _y) {
		return (plansza[_x][_y].getStanInt()) ? 1 : 0;
	}
	else {
		std::cout << "Brak podanego pola" << std::endl;
		return 0;
	}
}

unsigned int Plansza::GetX() const
{
	return this->x;
}

unsigned int Plansza::GetY() const
{
	return this->y;
}

Komorka ** Plansza::GetPlansza() const
{
	return this->plansza;
}


