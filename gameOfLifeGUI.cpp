//-------------------------------------------------------------------------
// Plik - cia³o -  klasy gameOfLifeGUI.h
//
// Klasa implementuje interface "silnik.h", nadpisuje metodê Rysuj dla GUI
//
// Pola w³asne Klasy:
//		--brak
//
// Autor:             Nr_albumu:      Data rozpoczêcia:		Data zakoñczenia:
//Jakub Go³êbiowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#include "gameOfLifeGUI.h"

GameOfLifeGUI::GameOfLifeGUI() :Silnik()
{
}

GameOfLifeGUI::GameOfLifeGUI(const char* plik) : Silnik(plik)
{
}

GameOfLifeGUI::GameOfLifeGUI(const GameOfLifeGUI & _GameOfLifeGUICopy) : Silnik(_GameOfLifeGUICopy)
{
}

GameOfLifeGUI & GameOfLifeGUI::operator=(const GameOfLifeGUI & _GameOfLifeGUICopy)
{
	this->GetPlansza() = _GameOfLifeGUICopy.GetPlansza();
	return *this;
}


GameOfLifeGUI::~GameOfLifeGUI()
{
}

void GameOfLifeGUI::SetSizeOfKomorka(unsigned int _x, unsigned int _y)
{
    this->width = _x;
    this->height = _y;
}

void GameOfLifeGUI::Start(unsigned int _liczba, unsigned int _sleepTime)
{
    sf::RenderWindow window(sf::VideoMode(this->width*this->GetPlansza().GetY(), this->height*this->GetPlansza().GetX()), "SFML works!");

    /*sf::RectangleShape ***/ rectangles = new sf::RectangleShape*[this->GetPlansza().GetY()];
    for(unsigned int i=0;i<this->GetPlansza().GetY();i++){
        rectangles[i] = new sf::RectangleShape[this->GetPlansza().GetX()];
    }
    for(unsigned int i=0;i<this->GetPlansza().GetY();i++){
        for(unsigned int j=0;j<this->GetPlansza().GetX();j++){
            rectangles[i][j] = sf::RectangleShape(sf::Vector2f(width,height));
            rectangles[i][j].setOrigin(sf::Vector2f((float)i*width*-1,(float)j*height*-1));
        }
    }
    //sf::CircleShape shape(100.f);

    //shape.setOrigin(sf::Vector2f(-100.f, 0.f));
    //shape.setFillColor(sf::Color(255.f,255.f,0.f,255.f));

    while (window.isOpen())
    {
        for(unsigned int i = 0; i < _liczba; i++)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            //if(i==0)Sleep(10000);
            Analiza();
            Rysuj();
            for (unsigned int i = 0; i < this->GetPlansza().GetY(); i++)
            {
                for (unsigned int j = 0; j < this->GetPlansza().GetX(); j++)
                {
                        window.draw(rectangles[i][j]);
                }
            }
            window.display();
            Sleep(_sleepTime);
        }
        break;
    }

    //Destruktor zmiennej dynamicznej
    for (unsigned int i = 0; i < this->GetPlansza().GetY(); i++) {
		delete[]rectangles[i];
	}
	delete[]rectangles;
}

void GameOfLifeGUI::Rysuj()
{
    for (unsigned int i = 0; i < this->GetPlansza().GetY(); i++)
	{
		for (unsigned int j = 0; j < this->GetPlansza().GetX(); j++)
		{
			if (GetPlansza().GetKomorka(j,i)==1) {
				rectangles[i][j].setFillColor(sf::Color(100, 250, 50));
				//window.draw(rectangles[i][j]);
			}
			else {
                rectangles[i][j].setFillColor(sf::Color(150, 50, 250));
                //window.draw(rectangles[i][j]);

			}
			//std::cout << this->GetPlansza().GetKomorka(i, j) << " ";
		}
	}
}
