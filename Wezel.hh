/*
 * Wezel.hh
 *
 *  Created on: 22 kwi 2019
 *      Author: Robert
 */

#ifndef WEZEL_HH_
#define WEZEL_HH_

#include <iostream>
#include <cstdlib>
#include <memory>
#include "Element.hh"
#include "Lista.hh"
#include "Incydencje.hh"

//Reprezentacja wez³a (wierzcholka) grafu
template<typename T>
class Wezel{

	T nazwa;						//nazwa (id) wezla
	//Element<T> refElem;			//referencja do pozycji na liscie wezlow
	Lista<Wezel<T>&> incydencje;	//lista referencji do wezlow incydentnych
	Lista<T> IdKrawedziIncydentnych;//lista id krawedzi incydentnych
	Lista<Incydencje<Wezel<T>>> I;	//Lista wezlow sasiednich z waga krawedzi laczacej
	static unsigned int istniejace; //licznik istniejecych wezow

	public:

	//Lista<Wezel<T>> incydancje;		//lista incydancji
	//Konstruktor
	Wezel()
	{
		++istniejace;
	}

	//Konstruktor
	Wezel(T id)
	{
		++istniejace;
		nazwa=id;
	}

	//Konstruktor kopiujacy
	Wezel(const Wezel<T> &W)
	{
		++istniejace;
		nazwa=W.nazwa;
		incydencje=W.incydencje;
	}

	//Destruktor
	~Wezel()
	{
		--istniejace;
	}

	//Zwraca liczbe istniejacych wezlow
	static unsigned int existing()
	{
		return istniejace;
	}

	//Zwraca nazwe z mozliwoscia modyfikacji
	T &ZwrocNazwe()
	{
		return nazwa;
	}

	//Zwraca nazwe bez mozliwosci modyfikacji
	const T &ZwrocNazwe() const
	{
		return nazwa;
	}

	//Zwraca liste incydencji z mozliwoscia modyfikacji
	Lista<Wezel<T>&> &ZwrocIncydencje()
	{
		return incydencje;
	}

	//Zwraca liste incydencji bez mozliwosci modyfikacji
	const Lista<Wezel<T>&> &ZwrocIncydencje() const
	{
		return incydencje;
	}

	//Zwraca liste id krawedzi incydentnych z mozliwoscia modyfikacji
	Lista<T> &ZwrocIdKrawedziIncydentnych()
	{
		return IdKrawedziIncydentnych;
	}

	//Zwraca liste id krawedzi incydentnych bez mozliwosci modyfikacji
	const Lista<T> &ZwrocIdKrawedziIncydentnych() const
	{
		return IdKrawedziIncydentnych;
	}

	//Zwraca liste I z mozliwoscia modyfikacji
	Lista<Incydencje<Wezel<T>>> &ZwrocI()
	{
		return I;
	}

	//Zwraca liste I bez mozliwosci modyfikacji
	const Lista<Incydencje<Wezel<T>>> &ZwrocI() const
	{
		return I;
	}

	//Dodaj wezel incydentny
	void DodajIncydancje(Wezel<T> &W)
	{
		incydencje.DodajNaPoczatek(W);
	}

	//Dodaj id krawedzi incydentnej
	void DodajIdKrawedziIncydentnych(T K)
	{
		IdKrawedziIncydentnych.DodajNaPoczatek(K);
	}
};


//Przeciazenie operatora <<
template <typename T>
std::ostream& operator << (std::ostream &Strm, const Wezel<T>& W)
{
	Strm << "W" << W.ZwrocNazwe() << " ";

    return Strm;
}

//Definicja pola istniejace szablonu Wezel
template<typename T> unsigned int Wezel<T>::istniejace;

#endif /* WEZEL_HH_ */
