//-------------------------------------------------------------------------
// Plik nagłówskowy klasy komorka.h
//
// Klasa ma za zadanie przechowywać wartość pola planszy
//
//	Pola:
//		bool stan - pole przechowuje stan komorki
//
// Autor:             Nr_albumu:      Data rozpoczęcia:		Data zakończenia:  
//Jakub Gołębiowski   382723		  26.02.2020			04.03.2020
//-------------------------------------------------------------------------

#ifndef komorka_h
#define komorka_h

class Komorka
{
private:
	//pole typu bool, przechowuje wartość 0-1
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