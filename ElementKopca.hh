/*
 * ElementKopca.hh
 *
 *  Created on: 24 kwi 2019
 *      Author: Robert
 */

#ifndef ELEMENTKOPCA_HH_
#define ELEMENTKOPCA_HH_

#include <iostream>
#include "Wezel.hh"

//Reprezentacja elementu kolejki na kopcu
template<typename T>
struct ElementKopca
{
	int droga;		//koszt drogi do tego wezla od wezla startowego
	Wezel<T> &A;	//referencja na wezel
	T id;			//id wezla
	T idPoprzedni;	//id wezla poprzedniego (jak nie ma poprzedniego to idPoprzedni=-1)

	//Konstruktor
	ElementKopca(Wezel<T> &W) :A(W)
	{
		droga=10000000;
		id=W.ZwrocNazwe();
		idPoprzedni=-1;
	}

	//Konstruktor
	ElementKopca(Wezel<T> &W,int d) :A(W)
	{
		droga=d;
		id=W.ZwrocNazwe();
		idPoprzedni=-1;

	}

	//Konstruktor kopiujacy
	ElementKopca(const ElementKopca<T> &Elem):A(Elem.A)
	{
		droga=Elem.droga;
		id=Elem.id;
		idPoprzedni=Elem.idPoprzedni;
	}

	//Zmienia wartosc parametru droga na zadana
	void ZmienWartDrogi(int dr)
	{
		droga=dr;
	}
};

//Przeciazenie operatora <<
template <typename T>
std::ostream& operator << (std::ostream &Strm, const ElementKopca<T>& Elem)
{
	Strm << Elem.A << " " << Elem.droga << " " << Elem.idPoprzedni << std::endl;

    return Strm;
}
#endif /* ELEMENTKOPCA_HH_ */
