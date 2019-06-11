/*
 * AlgorytmyGgrafowe.hh
 *
 *  Created on: 27 kwi 2019
 *      Author: Robert
 */

#ifndef ALGORYTMYGRAFOWE_HH_
#define ALGORYTMYGRAFOWE_HH_

#include <iostream>
#include <fstream>
#include "KolejkaNaKopcu.hh"
#include "ElementKopca.hh"
#include "Lista.hh"
#include "GrafLista.hh"
#include "GrafMacierz.hh"
#include "Incydencje.hh"

//Algorytm Dijkstry dla typu GrafLista
template<typename T>
void DijkstraLista(GrafLista<T> &G)
{
	//std::cout<<"DijkstraLista"<<std::endl;
	Lista<ElementKopca<T>&> refDoElementowWgIdWezla;
	KolejkaNaKopcu<T> Q(G.ZwrocLW(),G.ZwrocStartowy(),refDoElementowWgIdWezla);
	KolejkaNaKopcu<T> S;

	for(int i=0;i<G.ZwrocLW().Rozmiar();++i)
	{
		ElementKopca<T> Najmniejszy=Q.Zdejmij();
		S.Wsadz(Najmniejszy);

		for(int j=0;j<Najmniejszy.A.ZwrocI().Rozmiar();++j)
		{
			Incydencje<Wezel<T>>& I=Najmniejszy.A.ZwrocI().Zwroc(j+1);
			ElementKopca<T>& incydentny= refDoElementowWgIdWezla.Zwroc(I.Sasiedzi.ZwrocNazwe()+1);
			if(incydentny.droga>Najmniejszy.droga+I.waga)
			{
				incydentny.droga=Najmniejszy.droga+I.waga;
				incydentny.idPoprzedni=Najmniejszy.id;
			}
		}
	}
	//std::cout <<"S" <<std::endl;
	//S.L.Wyswietl();					//opcja wyswietlenia kopca S
	//S.Zapisz();						//opcja zapisywania wyniku dzialania algorytmu
	//std::cout <<"Q" <<std::endl;		//opcja wyswietlenia kopca Q
	//Q.L.Wyswietl();

}

//Algorytm Dijkstry dla typu GrafMacierz
template<typename T,int ROZMIAR>
void DijkstraMacierz(GrafMacierz<T,ROZMIAR> &G)
{
	Lista<ElementKopca<T>&> refDoElementowWgIdWezla;
	KolejkaNaKopcu<T> Q(G.ZwrocLW(),G.ZwrocStartowy(),refDoElementowWgIdWezla);
	KolejkaNaKopcu<T> S;

	for(int i=0;i<ROZMIAR;++i)
	{
		ElementKopca<T> Najmniejszy=Q.Zdejmij();
		S.Wsadz(Najmniejszy);

		for(int j=0;j<ROZMIAR;++j)
		{
			if(G.ZwrocMSasiedztwa()(Najmniejszy.id,j)!=nullptr)
			{
				Krawedz<T>& K=*(G.ZwrocMSasiedztwa()(Najmniejszy.id,j));
				ElementKopca<T>& incydentny=refDoElementowWgIdWezla.Zwroc(j+1);
				if(incydentny.droga>Najmniejszy.droga+K.ZwrocWage())
				{
					incydentny.droga=Najmniejszy.droga+K.ZwrocWage();
					incydentny.idPoprzedni=Najmniejszy.id;
				}
			}
		}
	}
	//std::cout <<"S" <<std::endl;
	//S.L.Wyswietl();				//opcja wyswietlenia kopca S
	//S.Zapisz();					//opcja zapisywania wyniku dzialania algorytmu
	//std::cout <<"Q" <<std::endl;	//opcja wyswietlenia kopca Q
	//Q.L.Wyswietl();

}



#endif /* ALGORYTMYGRAFOWE_HH_ */
