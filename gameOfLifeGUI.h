//-------------------------------------------------------------------------
// Plik nag³ówskowy klasy gameOfLifeGUI.h
//
// Klasa implementuje interface "silnik.h", nadpisuje metodê Rysuj dla GUI
//
// Pola w³asne Klasy:
//		--brak
//
// Autor:             Nr_albumu:      Data rozpoczêcia:		Data zakoñczenia:
//Jakub Go³êbiowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#ifndef gameOfLifeGUI_h
#define gameOfLifeGUI_h

#include <SFML/Graphics.hpp>

#include "silnik.h"

class GameOfLifeGUI:public Silnik
{
private:
    unsigned int width = 10;
    unsigned int height = 10;
    sf::RectangleShape ** rectangles;
public:
	//Konstruktory
	GameOfLifeGUI();
	GameOfLifeGUI(const char* plik);
	GameOfLifeGUI(const GameOfLifeGUI & _GameOfLifeGUICopy);

	//operaator przyrównania
	GameOfLifeGUI &operator=(const GameOfLifeGUI & _GameOfLifeGUICopy);

	virtual ~GameOfLifeGUI();

    void SetSizeOfKomorka(unsigned int _x = 10, unsigned int _y = 10);

	void Start(unsigned int _liczba, unsigned int _sleepTime);

	//Implementacja metody z interface'u
	void Rysuj();
};

#endif
