/*
 * KolejkaNaKopcu.hh
 *
 *  Created on: 24 kwi 2019
 *      Author: Robert
 */

#ifndef KOLEJKANAKOPCU_HH_
#define KOLEJKANAKOPCU_HH_

#include <iostream>
#include <memory>
#include <fstream>
#include "Lista.hh"
#include "Element.hh"
#include "ElementKopca.hh"

//Reprezentacja kolejki priorytetowej na kopcu
template<typename T>
struct KolejkaNaKopcu{

	Lista<ElementKopca<T>> L; //Lista elementow kopca

	//Konstruktor pustego kopca
	KolejkaNaKopcu(){};

	//Konstruktor zapelnionego kopca
	KolejkaNaKopcu(Lista<std::shared_ptr<Wezel<T>>> &LW, T start,Lista<ElementKopca<T>&> &ref)
	{
		for(int i=0;i<LW.Rozmiar();++i)
		{
			Wezel<T> &W=*(LW.Zwroc(i+1));
			if(W.ZwrocNazwe()==start)
			{
				ElementKopca<T> Elem(W,0);
				Wsadz(Elem);
				ref.DodajNaKoniec(L.Zwroc(1));//wrzucamy po kolei bo na liscie wez³ow id s¹ po kolei
			}
			else
			{
				ElementKopca<T> Elem(W);
				Wsadz(Elem);
				ref.DodajNaKoniec(L.Zwroc(L.Rozmiar()));
			}
		}
	}

	//Wsadzanie na koniec kopca i ustawianie elementu w zadanym miejscu
	void Wsadz(ElementKopca<T> &Elem)
	{
		L.DodajNaKoniec(Elem);
		int r=L.Rozmiar();
		int ojciec;

		while(r>1)
		{
			if(r%2==0 )
			{
				ojciec=r/2;
			}
			else
			{
				ojciec=(r-1)/2;
			}
			ElementKopca<T> Ojciec=L.Zwroc(ojciec);
			if(Ojciec.droga>Elem.droga)
			{
				L.ZamienMiejscami(ojciec,r);
				//std::cout << "zamieniono" << std::endl;
			}
			else
			{
				break;
			}
			r=ojciec;

		}
	}

	//Zdejmowanie elementu ze szczytu kopca
	ElementKopca<T> &Zdejmij()
	{
		ElementKopca<T> &Elem=L.Zwroc(1);
		L.ZamienMiejscami(1,L.Rozmiar());
		L.UsunZKonca();
		Kopcowanie();

		return Elem;
	}

	//Podtrzymanie charakteru kopca
	void Kopcowanie()
	{
		int r=1;
		do{
			if(2*r+1<=L.Rozmiar())
			{
				ElementKopca<T> &a=L.Zwroc(r);
				ElementKopca<T> &b=L.Zwroc(2*r);
				ElementKopca<T> &c=L.Zwroc((2*r)+1);
				if(b.droga<a.droga&&b.droga<c.droga)
				{
					L.ZamienMiejscami(r,2*r);
					r=2*r;
				}
				else if(c.droga<a.droga)
				{
					L.ZamienMiejscami(r,2*r+1);
					r=2*r+1;
				}
				else
				{
					break;
				}
			}
			else if(2*r<=L.Rozmiar())
			{
				ElementKopca<T> &a=L.Zwroc(r);
				ElementKopca<T> &b=L.Zwroc(2*r);
				if(b.droga<a.droga)
				{
					L.ZamienMiejscami(r,2*r);
					r=2*r;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}while(r<=L.Rozmiar());
	}

	//Znajduje element o zadanym id/nazwie
	ElementKopca<T>& Znajdz(T nazwa)
	{
		Element<ElementKopca<T>>* iterator=L.ZwrocHead();
		while(iterator->obiekt.id!=nazwa)
		{
			iterator=iterator->nastepny;
		}
		return iterator->obiekt;
	}

	//Zapisuje wynik algorytmu dijkstry
	void Zapisz()
	{
			std::fstream plik;
			plik.open("D:\\Programy\\PAMSI_P_projekt_graf\\DijkstaWynik.txt",std::ios::out);
			if(plik.good())
			{

				for(int i=0;i<L.Rozmiar();++i)
				{
					Lista<T> Droga;
					T s;
					ElementKopca<T> E=L.Zwroc(i+1);
					Droga.DodajNaPoczatek(E.id);
					if(E.idPoprzedni!=(-1))
					{
						s=E.idPoprzedni;

						while(s!=(-1))
						{
							Droga.DodajNaPoczatek(s);
							s=(Znajdz(s)).idPoprzedni;
						}
					}
					plik << "W" << E.id << " Koszt: " << std::setw(4) << E.droga << " Droga: ";
					for(int j=0;j<Droga.Rozmiar();++j)
					{
						plik << "W" << Droga.Zwroc(j+1) << " ";
					}
					plik << std::endl;
				}
			}
			plik.close();
	}

};

#endif /* KOLEJKANAKOPCU_HH_ */
