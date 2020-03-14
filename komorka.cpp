//-------------------------------------------------------------------------
// Plik nag³ówskowy klasy komorka.h
//
// Klasa ma za zadanie przechowywaæ wartoœæ pola planszy
//
//	Pola:
//		bool stan - pole przechowuje stan komorki
//
// Autor:             Nr_albumu:      Data rozpoczêcia:		Data zakoñczenia:  
//Jakub Go³êbiowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#include "komorka.h"

Komorka::Komorka():stan(0)
{
}

Komorka::Komorka(bool _stan):stan(_stan)
{
}

Komorka::Komorka(const Komorka & _KomorkaCopy)
{
	this->stan = _KomorkaCopy.stan;
}

Komorka & Komorka::operator=(const Komorka & _KomorkaCopy)
{
	if (this != &_KomorkaCopy) {
		this->stan = _KomorkaCopy.stan;
	}
	return *this;
}


Komorka::~Komorka()
{
}

bool Komorka::getStan() const
{
	return this->stan;
}

int Komorka::getStanInt() const
{
	if (this->stan == true) {
		return 1;
	}
	else {
		return 0;
	}
}

void Komorka::setStan(bool _stan)
{
	this->stan = _stan;
	return;
}
