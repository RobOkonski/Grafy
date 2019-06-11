/*
 * Element.hh
 *
 *  Created on: 22 kwi 2019
 *      Author: Robert
 */

#ifndef ELEMENT_HH_
#define ELEMENT_HH_

//Reprezentacja elementu listy dwukierunkowej
template<typename T>
struct Element{

	Element* nastepny;			//wskaznik na element nastepny listy
	Element* poprzedni;			//wskaznik na element poprzedni listy
	T obiekt;					//obiekt z ktorych sklada sie lista

	//Konstruktor
	Element(T &ob) :obiekt(ob)
	{
		nastepny=nullptr;
		poprzedni=nullptr;
	}

	//Konstruktor kopiujacy
	Element(const Element<T> &Elem) :obiekt(Elem.obiekt)
	{
		nastepny=Elem.nastepny;
		poprzedni=Elem.poprzedni;
	}

	//Destruktor
	~Element(){}

	//Zwraca dostep do wskaznika nastepny z mozliwoscia modyfikacji
	Element* &ZwrocNastepny()
	{
		return nastepny;
	}

	//Zwraca dostep do wskaznika nastepny bez mozliwosci modyfikacji
	const Element* &ZwrocNastepny() const
	{
		return nastepny;
	}

	//Zwraca dostep do wskaznika poprzedni z mozliwoscia modyfikacji
	Element* &ZwrocPoprzedni()
	{
		return poprzedni;
	}

	//Zwraca dostep do wskaznika poprzedni bez mozliwosci modyfikacji
	const Element* &ZwrocPoprzedni() const
	{
		return poprzedni;
	}

	//Zwraca dostep do obiektu z mozliwoscia modyfikacji
	T &ZwrocObiekt()
	{
		return obiekt;
	}

	//Zwraca dostep do obiektu z mozliwoscia modyfikacji
	const T &ZwrocObiekt() const
	{
		return obiekt;
	}
};

#endif /* ELEMENT_HH_ */
