/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2021/22)               Enrico Betolazzi

    Interpolazione di Lagrange - Utilizzo della libreria
\* --------------------------------------------------------------------------------- */

#include <iostream>

// includiamo la libreria
#include "cnum.h"

// includiamo i namespaces
using namespace std;

using cnum::Integer; // intero
using cnum::dvec_t;  // vettore lunghezza variabile
using cnum::Poly;    // polinomio

/*-------------------------------------------------------------------------------------
  dichiariamo la funzione main
-------------------------------------------------------------------------------------*/

int
main() {
  // Test 1 - cnum::Lagrange_interpolation
  Integer n = 1;
  dvec_t x, y;

  x.resize(n+1);
  y.resize(n+1);
  x << 0, 1;
  y << 1, 2;

  Poly p = cnum::Lagrange_interpolation(x,y);
  std::cout << p << '\n';

  // Test 2 - cnum::Lagrange_interpolation
  n = 3;
  x.resize(n+1);
  y.resize(n+1);
  x << 0, 1, 2, 3;
  y << 0, 1, 4, 9;

  p = cnum::Lagrange_interpolation(x,y);
  std::cout << p << '\n';

  return 0;
}
