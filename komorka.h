//-------------------------------------------------------------------------
// Plik nag��wskowy klasy komorka.h
//
// Klasa ma za zadanie przechowywa� warto�� pola planszy
//
//	Pola:
//		bool stan - pole przechowuje stan komorki
//
// Autor:             Nr_albumu:      Data rozpocz�cia:		Data zako�czenia:  
//Jakub Go��biowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#ifndef komorka_h
#define komorka_h

class Komorka
{
private:
	//pole typu bool, przechowuje warto�� 0-1
	bool stan;
public:
	//Konstruktory
	Komorka();
	Komorka(bool _stan);
	Komorka(const Komorka & _KomorkaCopy);

	//operator przypisania
	Komorka &operator=(const Komorka & _KomorkaCopy);

	//destruktor
	virtual ~Komorka();
	
	//gettery
	bool getStan()const;
	int getStanInt()const;

	//settery
	void setStan(bool _stan);
};

#endif