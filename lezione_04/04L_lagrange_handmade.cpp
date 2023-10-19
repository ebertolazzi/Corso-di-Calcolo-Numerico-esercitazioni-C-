/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2021/22)               Enrico Betolazzi

    Interpolazione di Lagrange - DIY
\* --------------------------------------------------------------------------------- */

#include <iostream>

// includiamo la libreria
#include "cnum.h"

// includiamo i namespaces
using namespace std;

using cnum::Poly;      // polinomio
using Eigen::VectorXd; // vettore lunghezza variabile di double

typedef int    Integer; // tipo di numero intero
typedef double Real;    // tipo di numero reale

/*-------------------------------------------------------------------------------------
  construzione della funzione per interpolare un polinomio
-------------------------------------------------------------------------------------*/

// dati i punti (x[i], y[i]) calcola il corrispondente polinomio interpolante
Poly
Lagrange_interpolation( VectorXd const & x, VectorXd const & y ) {
  Integer nx = x.size();
  Integer ny = y.size();
  if ( nx != ny ) {
    cerr
      << "Errore nella chiamata di interpolazione_di_Lagrange(x,y):\n"
      << "dimensione x = " << nx
      << " e dimensione y = " << ny
      << " devono essere uguali\n";
    exit(0);
  }
  return cnum::Lagrange_interpolation( x.data(), y.data(), nx );
}

/*-------------------------------------------------------------------------------------
  construzione della funzione per interpolare un polinomio (overloaded)
-------------------------------------------------------------------------------------*/

Poly
Lagrange_interpolation( Real const x[], Real const y[], Integer npts ) {
  Poly res( npts ), lk(0), tmp(0);

  for ( Integer k = 0; k < npts; ++k ) {
    // azzero polinomio
    lk.set_scalar(1);
    for ( Integer j = 0; j < npts; ++j ) {
      // skip j == k
      if ( j != k ) lk *= tmp.set_monomial( -x[j] );
    }
    // somma (y(k)/lk(x(k))*lk al polinomio res
    res += (y[k]/lk.eval(x[k])) * lk;
  }
  return res;
};

/*-------------------------------------------------------------------------------------
  dichiariamo la funzione main
-------------------------------------------------------------------------------------*/

int
main() {

  // Test 1 - Lagrange_interpolation
  Integer n = 1;
  VectorXd x, y;

  x.resize(n+1);
  y.resize(n+1);
  x << 0, 1;
  y << 1, 2;

  Poly p = Lagrange_interpolation(x,y);
  std::cout << p << '\n';

  // Test 2 - Lagrange_interpolation
  n = 3;
  x.resize(n+1);
  y.resize(n+1);
  x << 0, 1, 2, 3;
  y << 0, 1, 4, 9;

  p = Lagrange_interpolation(x,y);
  std::cout << p << '\n';

  return 0;
}
