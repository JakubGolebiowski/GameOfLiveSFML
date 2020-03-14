// Main_rozszerzony.cpp

#include "gameOfLifeGUI.h"
#include "komorka.h"
#include "silnik.h"
#include "plansza.h"
#include "gameOfLifeTxt.h"

int main()
{
	//Plansza p("test01.txt");

	//testKomorka(); //OK
	//testPlansza(); //OK

	//p.SetKomorka(1, 1, 1);
	//p.Narysuj(); // aktualnie usuniête z implementacji
	//Plansza p2(p);
	//p2.Narysuj(); // aktualnie usuniête z implementacji
	//Plansza p3 = p2;
	//p3.Narysuj(); // aktualnie usuniête z implementacji
	//std::cout<<p.GetKomorka(3,3)<<std::endl;
//Sleep(10000);
	GameOfLifeTxt g0("test01.txt");
	g0.Start(100, 200);

	GameOfLifeGUI g1("test01.txt");
	g1.SetSizeOfKomorka(50,50);
	g1.Start(100, 200);
}

/*
int main()
{
    /*sf::RenderWindow window(sf::VideoMode(400, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    //sf::Vertex vertex;
    //vertex.position = sf::Vector2f(10.f, 50.f);
    shape.setOrigin(sf::Vector2f(-100.f, 0.f));
    shape.setFillColor(sf::Color(255.f,255.f,0.f,255.f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    GameOfLifeGUI g1("test01.txt");
    g1.Start(20, 200);

    return 0;
}*/

