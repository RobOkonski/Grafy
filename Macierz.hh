/*
 * Macierz.hh
 *
 *  Created on: 24 kwi 2019
 *      Author: Robert
 */

#ifndef MACIERZ_HH_
#define MACIERZ_HH_

/*!
 * \file
 * \brief Szablon do tworzenia macierzy
 *
 * Plika zawiera definicje szablonu klasy SMacierz
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
//#include "Wektor.hh"
#include "Krawedz.hh"

/*******************************************************************************/
/* SZABLON KLASY MACIERZ                                                       */
/*******************************************************************************/


template <typename T, int ROZMIAR>
class SMacierz {

  T **macierz;

  public:

  /*!
	 * \brief Konstruktor bezparametryczny macierzy
	 */
  SMacierz()
  {
	  macierz=new T*[ROZMIAR];
	  for(int i=0;i<ROZMIAR;++i)
	  {
		macierz[i]=new T[ROZMIAR];
	  }

	  for(unsigned int i=0; i<ROZMIAR; i++)
	  {
		  for(unsigned int j=0; j<ROZMIAR; j++)
		  {
			  macierz[j][i]=nullptr;
		  }
	  }
  }

  /*!
   *  \brief Metoda zwracajaca dostep do wybranego pola macierzy w celu modyfikacji
   *    \param i - numer wiersza (i < ROZMIAR)
   *    \param j - numer kolumny (j < ROZMIAR)
   * 	\return Zwraca wybrane pole macierzy w celu modyfikacji
   */
  T& operator () (const unsigned int i, const unsigned int j);

  /*!
   *  \brief Metoda zwracajaca dostep do wybranego pola macierzy
   * 		 bez mozliwosci modyfikacji
   *    \param i - numer wiersza (i < ROZMIAR)
   *    \param j - numer kolumny (j < ROZMIAR)
   * 	\return Zwraca wybrane pole macierzy bez mozliwosci modyfikacji
   */
  const T& operator () (const unsigned int i, const unsigned int j) const;

};

/*******************************************************************************/
/* DEFINICJE METOD                                                             */
/*******************************************************************************/

template <typename T, int ROZMIAR>
T& SMacierz<T, ROZMIAR>::operator () (const unsigned int i, const unsigned int j)
{
  if(i<ROZMIAR && j<ROZMIAR) // jesli miescimy sie w zakresie
    return macierz[j][i];    // zwroc zadane pole
  else                       // jesli nie zwroc blad i zakoncz program
    {
      std::cerr << "!!!PRZEKROCZONO ZAKRES !!!" << std::endl << std::endl;
      exit(EXIT_FAILURE);
    }
}

template <typename T, int ROZMIAR>
const T& SMacierz<T, ROZMIAR>::operator () (const unsigned int i, const unsigned int j) const
{
  if(i<ROZMIAR && j<ROZMIAR) // jesli miescimy sie w zakresie
    return macierz[j][i];    // zwroc zadane pole
  else                       // jesli nie zwroc blad i zakoncz program
    {
      std::cerr << "!!!PRZEKROCZONO ZAKRES !!!" << std::endl << std::endl;
      exit(EXIT_FAILURE);
    }
}

/*******************************************************************************/
/* PRZECIAZENIA OPERATOROW << I >>                                             */
/*******************************************************************************/

/*!
 * \brief Przeciazenie operatora strumienia wejscia >> dla macierzy
 * 		\param Strm - strumien wejscia
 * 		\param Mac - macierz do wczytania
 * 		\return Zwtaca strumien wejscia
 */
template <typename T, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, SMacierz<T, ROZMIAR>& Mac)
{
  for(int i=0; i<ROZMIAR; i++)
    {
      Strm >> Mac[i]; // wczytaj wektory kolumnowe macierzy (latwiej na potrzeby zadania)
    }

  return Strm;        // zwroc  strumien
}

/*!
 * \brief Przeciazenie operatora strumienia wyjscia << dla macierzy
 * 		\param Strm - strumien wyjscia
 * 		\param Mac - macierz do wypisania
 * 		\return Zwtaca strumien wyjscia
 */
template <typename T, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, SMacierz<T, ROZMIAR>& Mac)
{
  for(int i=0; i<ROZMIAR; i++)
    {
      for(int j=0; j<ROZMIAR; j++)
		{
			Strm << std::setw(10) << Mac(i,j) << " ";       // wypisz macierz
		}
      Strm << std::endl;
	}
  Strm << std::endl;

  return Strm;                           // zwroc strumien
}

#endif /* MACIERZ_HH_ */
