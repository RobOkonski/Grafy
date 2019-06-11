/*
 * Lista.hh
 *
 *  Created on: 22 kwi 2019
 *      Author: Robert
 */

#ifndef LISTA_HH_
#define LISTA_HH_

#include <iostream>
#include <memory>
#include <cstdlib>
#include "Element.hh"

//Reprezentacja listy dwukierunkowej
template<typename T>
class Lista{

	Element<T>* head; //glowa listy
	Element<T>* tail; //ogon listy

	public:

	//Konstruktor
	Lista()
	{
		head=nullptr;
		tail=nullptr;
	}

	//Konstruktor kopiujacy
	Lista(const Lista<T> &L)
	{
		head=L.head;
		tail=L.tail;
	}
/*
	~Lista()
	{
		tail=nullptr;
		while(head!=nullptr)
		{
			Element<T>* pom;

			pom=head;
			head=head->nastepny;
			delete pom;
		}
	}*/

	//Dodaje obiekt na poczatek listy
	void DodajNaPoczatek(T &ob);

	//Dodaje obiekt na koniec listy
	void DodajNaKoniec(T &ob);

	//Usuwa obiekt z poczatku listy
	void UsunZPoczatku();

	//Usuwa obiekt z konca listy
	void UsunZKonca();

	//Wyswietla liste
	void Wyswietl() const;

	//Zwraca rozmiar listy
	int Rozmiar() const;

	//Zwraca obiekt znajdujacy sie na danej pozycji listy
	T &Zwroc(int pozycja);

	//Zwraca glowe listy
	Element<T>* ZwrocHead()
	{
		return head;
	}

	//Zamienia miejscami 2 elementy listy
	void ZamienMiejscami(int pozycja1, int pozycja2);
};

//Dodaje obiekt na poczatek listy
template<typename T>
void Lista<T>::DodajNaPoczatek(T &ob)
{
	Element<T>* nowy=new Element<T>(ob);

	if(head==nullptr&&tail==nullptr)
	{
		head=nowy;
		tail=nowy;
	}
	else if((head==nullptr&&tail!=nullptr)||(head!=nullptr&&tail==nullptr))
	{
		std::cerr << "!!! ZGUBIONO CIAGLOSC LISTY !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		nowy->ZwrocNastepny()=head;
		head->ZwrocPoprzedni()=nowy;
		head=nowy;
	}
}

//Dodaje obiekt na koniec listy
template<typename T>
void Lista<T>::DodajNaKoniec(T &ob)
{
	Element<T>* nowy=new Element<T>(ob);
	if(head==nullptr&&tail==nullptr)
	{
		head=nowy;
		tail=nowy;
	}
	else if((head==nullptr&&tail!=nullptr)||(head!=nullptr&&tail==nullptr))
	{
		std::cerr << "!!! ZGUBIONO CIAGLOSC LISTY !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		nowy->ZwrocPoprzedni()=tail;
		tail->ZwrocNastepny()=nowy;
		tail=nowy;
	}
}

//Usuwa obiekt z poczatku listy
template<typename T>
void Lista<T>::UsunZPoczatku()
{
	if(head==nullptr&&tail==nullptr)
	{
		std::cout << "!!! LISTA JEST PUSTA !!!" << std::endl;
	}
	else if((head==nullptr&&tail!=nullptr)||(head!=nullptr&&tail==nullptr))
	{
		std::cerr << "!!! ZGUBIONO CIAGLOSC LISTY !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
	else if(Rozmiar()==1)
	{
		delete head;
		head=nullptr;
		tail=nullptr;
	}
	else
	{
		Element<T>* pom=head;

		head=head->ZwrocNastepny();
		head->ZwrocPoprzedni()=nullptr;
		delete pom;
	}
}

//Usuwa obiekt z poczatku listy
template<typename T>
void Lista<T>::UsunZKonca()
{
	if(head==nullptr&&tail==nullptr)
	{
		std::cout << "!!! LISTA JEST PUSTA !!!" << std::endl;
	}
	else if((head==nullptr&&tail!=nullptr)||(head!=nullptr&&tail==nullptr))
	{
		std::cerr << "!!! ZGUBIONO CIAGLOSC LISTY !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
	else if(Rozmiar()==1)
	{
		delete head;
		head=nullptr;
		tail=nullptr;
	}
	else
	{
		Element<T>* pom=tail;

		tail=tail->ZwrocPoprzedni();
		tail->ZwrocNastepny()=nullptr;
		delete pom;
	}
}

//Wyswietla liste
template<typename T>
void Lista<T>::Wyswietl() const
{
	Element<T>* iterator=head;

	while(iterator!=nullptr)
	{
		//std::cout<<*(iterator->ZwrocObiekt()); //opcja dla wskaznikow
		std::cout<<iterator->ZwrocObiekt();		 //opcja dla niewskaznikow
		iterator=iterator->ZwrocNastepny();
	}
	std::cout<<std::endl;
}

//Zwraca rozmiar listy
template<typename T>
int Lista<T>::Rozmiar() const
{
	int i=1;
	Element<T>* iterator=head;

	if(iterator==nullptr)
	{
		return 0;
	}

	while(iterator->ZwrocNastepny()!=nullptr)
	{
		iterator=iterator->ZwrocNastepny();
		++i;
	}

	return i;
}

//Zwraca obiekt znajdujacy sie na danej pozycji listy
template<typename T>
T &Lista<T>::Zwroc(int pozycja)
{
	//T szukana;
	Element<T>* iterator=head;

	if(pozycja<=0)
	{
		std::cout<< "!!! LISTE NUMERUJEMY OD 1 !!!" <<std::endl;
	}
	else if(pozycja>Rozmiar())
	{
		std::cout<< "!!! LISTA NIE MA TYLU ELEMENTOW !!!" <<std::endl;
	}
	else
	{
		//Element<T>* iterator=head;
		for(int i=1;i<pozycja;++i)
		{
			iterator=iterator->ZwrocNastepny();
		}
		//szukana=iterator->ZwrocObiekt();
	}

	//return szukana;
	return iterator->ZwrocObiekt();
}

//Zamienia miejscami 2 elementy listy
template<typename T>
void Lista<T>::ZamienMiejscami(int pozycja1, int pozycja2)
{
	if(pozycja1<1 || pozycja1>Rozmiar() || pozycja2<1 || pozycja2>Rozmiar())
	{
		std::cout << "!!! PODNAO INDEKSY ELEMENTOW KTORE NIE ISTNIEJA !!!" << std::endl;
	}
	else
	{
		Element<T>* A=head;
		for(int i=1;i<pozycja1;++i)
		{
			A=A->nastepny;
		}
		Element<T>* B=head;
		for(int i=1;i<pozycja2;++i)
		{
			B=B->nastepny;
		}
		Element<T>* Aprev=A->poprzedni;
		Element<T>* Anext=A->nastepny;
		Element<T>* Bprev=B->poprzedni;
		Element<T>* Bnext=B->nastepny;

		if(pozycja2-pozycja1==1)		//gdy obiekty sa obok siebie w danej kolejnosci podawania argumentow
		{
			//std::cout << "obok siebie" << std::endl;
			A->nastepny=Bnext;
			A->poprzedni=B;
			B->nastepny=A;
			B->poprzedni=Aprev;

			if(Aprev==nullptr)
			{
				head=B;
			}
			else
			{
				Aprev->nastepny=B;
			}

			if(Bnext==nullptr)
			{
				tail=A;
			}
			else
			{
				Bnext->poprzedni=A;
			}
		}
		else if(pozycja1-pozycja2==1)			//gdy obiekty sa obok siebie w danej kolejnosci podawania argumentow
		{
			//std::cout << "obok siebie2" << std::endl;
			A->nastepny=B;
			A->poprzedni=Bprev;
			B->nastepny=Anext;
			B->poprzedni=A;

			if(Anext==nullptr)
			{
				tail=B;
			}
			else
			{
				Anext->poprzedni=B;
			}

			if(Bprev==nullptr)
			{
				head=A;
			}
			else
			{
				Bprev->nastepny=A;
			}
		}
		else							//obiekty maja inny/inne obiekty miedzy soba
		{
			A->nastepny=Bnext;
			A->poprzedni=Bprev;
			B->nastepny=Anext;
			B->poprzedni=Aprev;

			if(Aprev==nullptr)
			{
				head=B;
			}
			else
			{
				Aprev->nastepny=B;
			}

			if(Anext==nullptr)
			{
				tail=B;
			}
			else
			{
				Anext->poprzedni=B;
			}

			if(Bprev==nullptr)
			{
				head=A;
			}
			else
			{
				Bprev->nastepny=A;
			}

			if(Bnext==nullptr)
			{
				tail=A;
			}
			else
			{
				Bnext->poprzedni=A;
			}
		}
	}
}

#endif /* LISTA_HH_ */
