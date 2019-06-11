/*
 * GrafLista.hh
 *
 *  Created on: 23 kwi 2019
 *      Author: Robert
 */

#ifndef GRAFLISTA_HH_
#define GRAFLISTA_HH_

#include <iostream>
#include <cstdlib>
#include <memory>
#include <fstream>
#include "Lista.hh"
#include "Wezel.hh"
#include "Krawedz.hh"
#include "Incydencje.hh"

//Reperezentacja grafu spojnego za pomoca list sasiedztwa
template<typename T>
class GrafLista{

	T startowy;								//wezel startowy
	Lista<std::shared_ptr<Wezel<T>>> LW;	//lista wezlow
	Lista<std::shared_ptr<Krawedz<T>>> LK;	//lista krawedzi
	static unsigned int istniejace;			//licznik istniejacych obiektow tego typu

	public:

	//Konstruktor
	GrafLista(int rozmiar)
	{
		//Tworzy graf spojny o najmniejszej mo¿liwej liczbie krawêdzi

		++istniejace;

		for(int i=0;i<rozmiar;++i)
		{
			std::shared_ptr<Wezel<T>> W=std::make_shared<Wezel<T>>(i);
			LW.DodajNaKoniec(W);
		}

		for(int i=0;i<rozmiar-1;++i)
		{
			Wezel<T> &A=*(LW.Zwroc(i+2));
			Wezel<T> &B=*(LW.Zwroc((rand()%(i+1))+1));
			std::shared_ptr<Krawedz<T>> K=std::make_shared<Krawedz<T>>(i,A,B);
			LK.DodajNaKoniec(K);
		}

		Wezel<T> &A=*(LW.Zwroc(1));
		startowy=A.ZwrocNazwe();
	}

	//Konstruktor
	GrafLista(int rozmiar, int gestosc)
	{
		//Tworzy graf spojny o zadanej gêstoœci

		++istniejace;
		int kraw=0;

		if(gestosc<0 || gestosc>100)
		{
			std::cerr << "!!! NIEWLASCIWA GESTOSC GRAFU !!!" << std::endl << std::endl;
			exit(EXIT_FAILURE);
		}

		int krawedzie=(rozmiar*(rozmiar-1)*gestosc/200);
		//std::cout << "Krawedzie: " << krawedzie << std::endl;

		if(krawedzie<(rozmiar-1))
		{
			std::cerr << "!!! PRZY ZADANEJ GESTOSCI NIE DA SIE STWORZYC GRAFU SPOJNEGO !!!" << std::endl << std::endl;
			exit(EXIT_FAILURE);
		}

		for(int i=0;i<rozmiar;++i)
		{
			std::shared_ptr<Wezel<T>> W=std::make_shared<Wezel<T>>(i);
			LW.DodajNaKoniec(W);
		}

		if(gestosc==100)
		{
			for(int i=0;i<rozmiar-1;++i)
			{
				for(int j=i+1;j<rozmiar;++j)
				{
					Wezel<T> &A=*(LW.Zwroc(i+1));
					Wezel<T> &B=*(LW.Zwroc(j+1));
					std::shared_ptr<Krawedz<T>> K=std::make_shared<Krawedz<T>>(kraw,A,B);
					kraw++;
					LK.DodajNaKoniec(K);
				}
			}
		}
		else
		{
			for(int i=0;i<rozmiar-1;++i)
			{
				Wezel<T> &A=*(LW.Zwroc(i+2));
				Wezel<T> &B=*(LW.Zwroc((rand()%(i+1))+1));
				std::shared_ptr<Krawedz<T>> K=std::make_shared<Krawedz<T>>(i,A,B);
				LK.DodajNaKoniec(K);
			}
			krawedzie-=(rozmiar-1);

			for(int i=0;i<krawedzie;++i)
			{
				int losowanie;
				int blad;
				int iloscIncydencjiA;

				do{
					blad=0;
					losowanie=(rand()%rozmiar)+1;
					Wezel<T> &pom=*(LW.Zwroc(losowanie));

					if(pom.ZwrocIncydencje().Rozmiar()>=(rozmiar-1))
					{
						blad=1;
					}

				}while(blad!=0);

				Wezel<T> &A=*(LW.Zwroc(losowanie));
				iloscIncydencjiA=A.ZwrocIncydencje().Rozmiar();

				do{
					blad=0;
					losowanie=(rand()%rozmiar)+1;
					Wezel<T> &pom=*(LW.Zwroc(losowanie));

					if(pom.ZwrocIncydencje().Rozmiar()>=(rozmiar-1))
					{
						blad=1;
					}
					else if((A.ZwrocNazwe())==(pom.ZwrocNazwe()))
					{
						blad=1;
					}
					else
					{
						for(int j=0;j<iloscIncydencjiA;++j)
						{
							if((pom.ZwrocNazwe())==(A.ZwrocIncydencje().Zwroc(j+1).ZwrocNazwe()))
							{
								blad=1;
							}
						}
					}

				}while(blad!=0);

				Wezel<T> &B=*(LW.Zwroc(losowanie));

				std::shared_ptr<Krawedz<T>> K=std::make_shared<Krawedz<T>>(i+rozmiar-1,A,B);
				LK.DodajNaKoniec(K);
			}
		}

		Wezel<T> &A=*(LW.Zwroc(1));
		startowy=A.ZwrocNazwe();
	}

	//Konstruktor
	GrafLista(const char* sciezka)
	{
		++istniejace;

		int krawedzie;
		int rozmiar;

		std::fstream plik;
		plik.open(sciezka,std::ios::in);

		if(plik.good())
		{
			plik >> krawedzie >> rozmiar >> startowy;

			for(int i=0;i<rozmiar;++i)
			{
				std::shared_ptr<Wezel<T>> W=std::make_shared<Wezel<T>>(i);
				LW.DodajNaKoniec(W);
			}

			for(int i=0;i<krawedzie;++i)
			{
				T nazwaA;
				T nazwaB;
				int waga;

				plik >> nazwaA >> nazwaB >> waga;

				Wezel<T> &A=*(LW.Zwroc(nazwaA+1));
				Wezel<T> &B=*(LW.Zwroc(nazwaB+1));

				std::shared_ptr<Krawedz<T>> K=std::make_shared<Krawedz<T>>(i,A,B,waga);
				LK.DodajNaKoniec(K);
			}
		}
	}

	//Konstruktor kopiujacy
	GrafLista(const GrafLista<T> &G)
	{
		++istniejace;
		LW=G.LW;
		LK=G.LK;

	}

	//Destruktor
	~GrafLista()
	{
		--istniejace;
	}

	//Zwraca liczbe istniejacych wezlow
	static unsigned int existing()
	{
		return istniejace;
	}

	//Wyswietla graf
	void Wyswietl()
	{
		LW.Wyswietl();
		LK.Wyswietl();
	}

	//Zwraca referencje do wezla startowego
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

	//Zapisuje graf do pliku
	void ZapiszGraf(const char* sciezka)
	{
		std::fstream plik;
		plik.open(sciezka,std::ios::out);

		if(plik.good())
		{
			plik << ZwrocLK().Rozmiar() << " " << ZwrocLW().Rozmiar() << " " << startowy << std::endl;

			for(int i=0;i<ZwrocLK().Rozmiar();++i)
			{
				Krawedz<T> &K=*(ZwrocLK().Zwroc(i+1));
				plik << K.ZwrocW1().ZwrocNazwe() << " " << K.ZwrocW2().ZwrocNazwe() << " " << K.ZwrocWage() << std::endl;
			}
		}
	}
};

//Definicja pola istniejace szablonu Wezel
template<typename T> unsigned int GrafLista<T>::istniejace;

#endif /* GRAFLISTA_HH_ */
