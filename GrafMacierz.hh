/*
 * GrafMacierz.hh
 *
 *  Created on: 24 kwi 2019
 *      Author: Robert
 */

#ifndef GRAFMACIERZ_HH_
#define GRAFMACIERZ_HH_

#include <iostream>
#include <memory>
#include "Wezel.hh"
#include "Krawedz.hh"
#include "Macierz.hh"
#include "GrafLista.hh"
#include "Lista.hh"

//Reprezentacja grafu spojnego na macierzy sasiedztwa
template<typename T, int ROZMIAR>
class GrafMacierz{

	T startowy;									//wezel startowy
	Lista<std::shared_ptr<Wezel<T>>> LW;		//lista wezlow
	Lista<std::shared_ptr<Krawedz<T>>> LK;		//lista krawedzi
	SMacierz<Krawedz<T>*,ROZMIAR> MSasiedztwa;	//macierz sasiedztwa (wskazniki na krawedz)
	static unsigned int istniejace; 			//licznik istniejecych obiektow tego typu

	public:

	//Konstruktor
	GrafMacierz(GrafLista<T>& G)
	{
		++istniejace;
		LW=G.ZwrocLW();
		LK=G.ZwrocLK();
		startowy=G.ZwrocStartowy();

		for(int i=0;i<LK.Rozmiar();++i)
		{
			Krawedz<T> &A=*(LK.Zwroc(i+1));
			T a=A.ZwrocW1().ZwrocNazwe();
			T b=A.ZwrocW2().ZwrocNazwe();
			MSasiedztwa(a,b)=&A;
			MSasiedztwa(b,a)=&A;

		}
	}

	//Destruktor
	~GrafMacierz()
	{
		--istniejace;
	}

	//Zwraca liczbe istniejacych grafow
	static unsigned int existing()
	{
		return istniejace;
	}

	//Wyswietla graf
	void Wyswietl()
	{
		LW.Wyswietl();
		LK.Wyswietl();
		std::cout << MSasiedztwa << std::endl;
	}

	//Zwraca macierz sasiedztwa
	SMacierz<Krawedz<T>*,ROZMIAR>& ZwrocMSasiedztwa()
	{
		return MSasiedztwa;
	}

	//Zwraca wezel startowy
	T &ZwrocStartowy()
	{
		return startowy;
	}

	//Zwraca liste wezlow
	Lista<std::shared_ptr<Wezel<T>>> &ZwrocLW()
	{
		return LW;
	}

	//Zwraca liste krawedzi
	Lista<std::shared_ptr<Krawedz<T>>> &ZwrocLK()
	{
		return LK;
	}

};

//Definicja pola istniejace szablonu GrafMAcierz
template<typename T,int ROZMIAR> unsigned int GrafMacierz<T,ROZMIAR>::istniejace;

#endif /* GRAFMACIERZ_HH_ */
