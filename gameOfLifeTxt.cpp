//-------------------------------------------------------------------------
// Plik - cia³o - klasy gameOfLifeTxt.h
//
// Klasa implementuje interface "silnik.h", nadpisuje metodê Rysuj dla konsoli
//
// Pola w³asne Klasy:
//		--brak
//
// Autor:             Nr_albumu:      Data rozpoczêcia:		Data zakoñczenia:
//Jakub Go³êbiowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#include "gameOfLifeTxt.h"

GameOfLifeTxt::GameOfLifeTxt():Silnik()
{
}

GameOfLifeTxt::GameOfLifeTxt(const char * plik):Silnik(plik)
{
}

GameOfLifeTxt::GameOfLifeTxt(const GameOfLifeTxt & _GameOfLifeTxtCopy):Silnik(_GameOfLifeTxtCopy)
{
}

GameOfLifeTxt & GameOfLifeTxt::operator=(const GameOfLifeTxt & _GameOfLifeTxtCopy)
{
	this->GetPlansza() = _GameOfLifeTxtCopy.GetPlansza();
	return *this;
}


GameOfLifeTxt::~GameOfLifeTxt()
{
}

void GameOfLifeTxt::Start(unsigned int _liczba, unsigned int _sleepTime)
{
	for (unsigned int i = 0; i < _liczba; i++)
	{
		Sleep(_sleepTime);
		Analiza();
		Rysuj();
	}
}

void GameOfLifeTxt::Rysuj()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");
	//SetConsoleTextAttribute(hConsole, 7);

	for (unsigned int i = 0; i < this->GetPlansza().GetX(); i++)
	{
		for (unsigned int j = 0; j < this->GetPlansza().GetY(); j++)
		{
			if (GetPlansza().GetKomorka(i, j)) {
				SetConsoleTextAttribute(hConsole, 7);
			}
			else {
				SetConsoleTextAttribute(hConsole, 12);
			}
			std::cout << this->GetPlansza().GetKomorka(i, j) << " ";
		}
		std::cout << std::endl;
	}
}
