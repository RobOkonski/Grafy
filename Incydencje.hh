/*
 * Incydencje.hh
 *
 *  Created on: 25 kwi 2019
 *      Author: Robert
 */

#ifndef INCYDENCJE_HH_
#define INCYDENCJE_HH_

#include <iostream>
#include "Lista.hh"
#include "Wezel.hh"

//Reprezentacja struktury elementu listy incydencji
template<typename T>
struct Incydencje{

	T &Sasiedzi;
	int &waga;

	Incydencje(T &A, int &w) :Sasiedzi(A), waga(w){}
};
#endif /* INCYDENCJE_HH_ */
