//============================================================================
// Name        : PAMSI_P_projekt_graf.cpp
// Author      : Robert
// Version     :
// Copyright   : Your copyright notice
// Description : Graf in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <fstream>
#include "Lista.hh"
#include "Wezel.hh"
#include "Krawedz.hh"
#include "GrafLista.hh"
#include "Macierz.hh"
#include "GrafMacierz.hh"
#include "KolejkaNaKopcu.hh"
#include "ElementKopca.hh"
#include "AlgorytmyGrafowe.hh"
#include "Test.hh"

using namespace std;

#define ROZMIAR10 10
#define ROZMIAR30 30
#define ROZMIAR50 50
#define ROZMIAR70 70
#define ROZMIAR100 100
#define ROZMIAR200 200
#define ROZMIAR500 500
#define ROZMIAR1000 1000

int main()
{
/*	//TEST DO SPRAWOZDANIA

	InicjalizujPlik();

	cout << "Gestosc 25% " << endl;
	Test<int,ROZMIAR30>(100,25);
	Test<int,ROZMIAR50>(100,25);
	Test<int,ROZMIAR70>(100,25);
	Test<int,ROZMIAR100>(100,25);
	Test<int,ROZMIAR200>(100,25);

	cout << "Gestosc 50% " << endl;
	Test<int,ROZMIAR30>(100,50);
	Test<int,ROZMIAR50>(100,50);
	Test<int,ROZMIAR70>(100,50);
	Test<int,ROZMIAR100>(100,50);
	Test<int,ROZMIAR200>(100,50);

	cout << "Gestosc 75% " << endl;
	Test<int,ROZMIAR30>(100,75);
	Test<int,ROZMIAR50>(100,75);
	Test<int,ROZMIAR70>(100,75);
	Test<int,ROZMIAR100>(100,75);
	Test<int,ROZMIAR200>(100,75);

	cout << "Gestosc 100% " << endl;
	Test<int,ROZMIAR30>(100,100);
	Test<int,ROZMIAR50>(100,100);
	Test<int,ROZMIAR70>(100,100);
	Test<int,ROZMIAR100>(100,100);
	Test<int,ROZMIAR200>(100,100);
*/

	GrafLista<int> G(10,25);
	G.ZwrocLW().Wyswietl();
	G.ZwrocLK().Wyswietl();

	DijkstraLista<int>(G);

	return 0;
}
