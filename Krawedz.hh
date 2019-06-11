/*
 * Krawedz.hh
 *
 *  Created on: 22 kwi 2019
 *      Author: Robert
 */

#ifndef KRAWEDZ_HH_
#define KRAWEDZ_HH_

#include <iostream>
#include <cstdlib>
#include <memory>
#include "Lista.hh"
#include "Element.hh"
#include "Wezel.hh"
#include "Incydencje.hh"

//Reprezentacja krawedzi grafu
template<typename T>
class Krawedz{

	T nazwa;						//id krawedzi
	Wezel<T> &W1;					//referencja do pierwszego wezla
	Wezel<T> &W2;					//referencja do drugirgo wezla
	Lista<Wezel<T>&> &incydencjeW1;	//lista referencji do wezlow incydentnych z wezlem W1
	Lista<Wezel<T>&> &incydencjeW2;	//lista referencji do wezlow incydentnych z wezlem W2
	int waga;						//koszt pokonania krawedzi
	static unsigned int istniejace;	//ilosc istniejacych krawedzi

	public:

	//Konstruktor
	Krawedz(T id, Wezel<T> &A, Wezel<T> &B) :W1(A), W2(B), incydencjeW1(A.ZwrocIncydencje()), incydencjeW2(B.ZwrocIncydencje())
	{
		++istniejace;
		nazwa=id;
		waga=rand()%100+1;
		A.DodajIncydancje(B);
		B.DodajIncydancje(A);
		A.DodajIdKrawedziIncydentnych(nazwa);
		B.DodajIdKrawedziIncydentnych(nazwa);
		Incydencje<Wezel<T>> IA(B,waga);
		Incydencje<Wezel<T>> IB(A,waga);
		A.ZwrocI().DodajNaKoniec(IA);
		B.ZwrocI().DodajNaKoniec(IB);
	}

	//Konstruktor
	Krawedz(T id, Wezel<T> &A, Wezel<T> &B,int w) :W1(A), W2(B), incydencjeW1(A.ZwrocIncydencje()), incydencjeW2(B.ZwrocIncydencje())
	{
		++istniejace;
		nazwa=id;
		waga=w;
		A.DodajIncydancje(B);
		B.DodajIncydancje(A);
		A.DodajIdKrawedziIncydentnych(nazwa);
		B.DodajIdKrawedziIncydentnych(nazwa);
		Incydencje<Wezel<T>> IA(B,waga);
		Incydencje<Wezel<T>> IB(A,waga);
		A.ZwrocI().DodajNaKoniec(IA);
		B.ZwrocI().DodajNaKoniec(IB);
	}

	//Konstruktor kopiujacy
	Krawedz(const Krawedz<T> &K) :W1(K.W1), W2(K.W2), incydencjeW1(K.incydencjeW1), incydencjeW2(K.incydencjeW2)
	{
		++istniejace;
		nazwa=K.nazwa;
		waga=K.waga;
	}

	//Destruktor
	~Krawedz()
	{
		--istniejace;
	}

	//Zwraca liczbe istniejacych krawedzi
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

	//Zwraca W1 z mozliwoscia modyfikacji
	Wezel<T> &ZwrocW1()
	{
		return W1;
	}

	//Zwraca W1 bez mozliwosci modyfikacji
	const Wezel<T> &ZwrocW1() const
	{
		return W1;
	}

	//Zwraca W2 z mozliwoscia modyfikacji
	Wezel<T> &ZwrocW2()
	{
		return W2;
	}

	//Zwraca W2 bez mozliwosci modyfikacji
	const Wezel<T> &ZwrocW2() const
	{
		return W2;
	}

	//Zwraca wage z mozliwoscia modyfikacji
	T &ZwrocWage()
	{
		return waga;
	}

	//Zwraca wage bez mozliwosci modyfikacji
	const T &ZwrocWage() const
	{
		return waga;
	}

	//Zwraca incydancjeW1 z mozliwoscia modyfikacji
	Lista<Wezel<T>&> &ZwrocIncydencjeW1()
	{
		return incydencjeW1;
	}

	//Zwraca incydancjeW1 bez mozliwosci modyfikacji
	const Lista<Wezel<T>&> &ZwrocIncydencjeW1() const
	{
		return incydencjeW1;
	}

	//Zwraca incydancjeW2 z mozliwoscia modyfikacji
	Lista<Wezel<T>&> &ZwrocIncydencjeW2()
	{
		return incydencjeW2;
	}

	//Zwraca incydancjeW2 bez mozliwosci modyfikacji
	const Lista<Wezel<T>&> &ZwrocIncydencjeW2() const
	{
		return incydencjeW2;
	}

};

//Definicja pola istniejace szablonu Krawedz
template<typename T> unsigned int Krawedz<T>::istniejace;

//Przeciazenie operatora <<
template <typename T>
std::ostream& operator << (std::ostream &Strm, const Krawedz<T>& K)
{
	Strm << "K" << K.ZwrocNazwe() << " " << K.ZwrocW1().ZwrocNazwe() << " - " << K.ZwrocW2().ZwrocNazwe() << " " << K.ZwrocWage() <<  std::endl;

    return Strm;
}

#endif /* KRAWEDZ_HH_ */
