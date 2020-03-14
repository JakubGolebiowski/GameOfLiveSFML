//-------------------------------------------------------------------------
// Plik nag³ówskowy klasy gameOfLifeTxt.h
//
// Klasa implementuje interface "silnik.h", nadpisuje metodê Rysuj dla konsoli
//
// Pola w³asne Klasy:
//		HANDLE hConsole - Pole z windows.h, zmienia kolor w konsoli windosa
//
// Autor:             Nr_albumu:      Data rozpoczêcia:		Data zakoñczenia:
//Jakub Go³êbiowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#ifndef gameOfLifeTxt_h
#define game_ofLifeTxt_h

#include "silnik.h"

class GameOfLifeTxt:public Silnik
{
public:
	HANDLE hConsole;
	//Konstruktory
	GameOfLifeTxt();
	GameOfLifeTxt(const char* plik);
	GameOfLifeTxt(const GameOfLifeTxt & _GameOfLifeTxtCopy);

	//operaator przyrównania
	GameOfLifeTxt &operator=(const GameOfLifeTxt & _GameOfLifeTxtCopy);

	virtual ~GameOfLifeTxt();

	void Start(unsigned int _liczba, unsigned int _sleepTime);

	//Implementacja metody z interface'u
	void Rysuj();
};

#endif
