//-------------------------------------------------------------------------
// Plik - cia³a - klasy silnik.h
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

#include "silnik.h"

Plansza Silnik::GetPlansza() const
{
	return this->plansza;
}

Silnik::Silnik():plansza()
{
}

Silnik::Silnik(const char * plik):plansza(plik)
{
}

Silnik::Silnik(const Silnik & _SilnikCopy):plansza(_SilnikCopy.plansza)
{
}

Silnik & Silnik::operator=(const Silnik & _SilnikCopy)
{
	if (this != &_SilnikCopy) {
		this->plansza = _SilnikCopy.plansza;
	}
	return *this;
}


Silnik::~Silnik()
{
}

void Silnik::Analiza()
{
	Plansza temp(this->plansza);

	for (unsigned int i = 0; i < this->plansza.GetX(); i++)
	{
		for (unsigned int j = 0; j < this->plansza.GetY(); j++)
		{
			unsigned int value = LiczbaZywych(i, j);
			if (value ==3) { temp.SetKomorka(i, j, 1);  }
			else if (value == 2)continue;
			else if (value > 3 || value < 2) { temp.SetKomorka(i, j, 0); }
		}
	}
	this->plansza = temp;
}

unsigned int Silnik::LiczbaZywych(unsigned int i, unsigned int j)
{
	unsigned int value = 0;
	unsigned int temp1 = (unsigned int)(((j - 1) == -1) ? (plansza.GetY() - 1) : j - 1);
	unsigned int temp2 = (unsigned int)(((j + 1) == plansza.GetY()) ? 0 : j + 1);
	unsigned int temp3 = (unsigned int)(((i - 1) == -1) ? (plansza.GetX() - 1) : i - 1);
	unsigned int temp4 = (unsigned int)(((i + 1) == plansza.GetX()) ? 0 : i + 1);

	value = (unsigned int)plansza.GetKomorkaInt(i, temp1) +
		(unsigned int)plansza.GetKomorkaInt(i, temp2) +
		(unsigned int)plansza.GetKomorkaInt(temp3, temp1) +
		(unsigned int)plansza.GetKomorkaInt(temp4, temp1) +
		(unsigned int)plansza.GetKomorkaInt(temp3, temp2) +
		(unsigned int)plansza.GetKomorkaInt(temp4, temp2) +
		(unsigned int)plansza.GetKomorkaInt(temp4, j) +
		(unsigned int)plansza.GetKomorkaInt(temp3, j);
	return value;
}


