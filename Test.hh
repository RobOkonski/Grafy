/*
 * Test.hh
 *
 *  Created on: 28 kwi 2019
 *      Author: Robert
 */

#ifndef TEST_HH_
#define TEST_HH_

#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>
#include <chrono>
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

//Zapisyje wyniki czasowe dzialania algorytmow
void ZapiszWyniki(double czasG, double czasM, int rozmiar, int gestosc)
{
	std::fstream plik;
	plik.open("D:\\Programy\\PAMSI_P_projekt_graf\\Wyniki.txt",std::ios::out | std::ios::app);
	if(plik.good())
	{
		plik << "GrafLista " << rozmiar << " " << gestosc << " " << std::setw(16) << czasG << std::endl;
		plik << "GrafMacierz " << rozmiar << " " << gestosc << " " << std::setw(16) << czasM << std::endl;
	}
	plik.close();
}

//Przeprowadza test o zadanych parametrach
template<typename T,int ROZMIAR>
void Test(int iloscTestow,int gestosc)
{
	double wynikiG[iloscTestow];//tablica na wyniki sortowan pojedynczych tablic
	double wynikiM[iloscTestow];//tablica na wyniki sortowan pojedynczych tablic
	double suma_czasowG=0;
	double suma_czasowM=0;
	std::chrono::duration<double> czas;

	for(int i=0;i<iloscTestow;++i)
	{
		GrafLista<T> G(ROZMIAR,gestosc);
		//G.ZapiszGraf("D:\\Programy\\PAMSI_P_projekt_graf\\dane2.txt");
		GrafMacierz<T,ROZMIAR> M(G);

		auto start=std::chrono::system_clock::now();
		DijkstraLista<T>(G);
		auto stop=std::chrono::system_clock::now();
		czas = stop-start;
		wynikiG[i]=czas.count();
		suma_czasowG+=wynikiG[i];

		start=std::chrono::system_clock::now();
		DijkstraMacierz<T,ROZMIAR>(M);
		stop=std::chrono::system_clock::now();
		czas = stop-start;
		wynikiM[i]=czas.count();
		suma_czasowM+=wynikiM[i];

		//std::cout << i << std::endl;
	}
	suma_czasowG/=iloscTestow;
	suma_czasowM/=iloscTestow;

	ZapiszWyniki(suma_czasowG,suma_czasowM,ROZMIAR,gestosc);
}

//Inicjalizuje plik wynikowy pomiaru czasu
void InicjalizujPlik()
{
	std::fstream plik;
	plik.open("D:\\Programy\\PAMSI_P_projekt_graf\\Wyniki.txt",std::ios::out);
	if(plik.good())
	{
		plik << "TypGrafu Rozmiar Gestosc CzasSredni" << std::endl;
	}
	plik.close();
}

#endif /* TEST_HH_ */
