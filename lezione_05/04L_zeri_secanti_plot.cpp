/* --------------------------------------------------------------------------------- *\
  CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Zeri di funzione - metodo delle Secanti con plot

    Il metodo delle Secanti usa la formula iterativa
      x_{n+1} = x_n - f( x_n ) ( x_n - x_{n-1} ) / ( f( x_n ) - f( x_{n-1} ) )
    dove x_n e` il valore approssimato dello zero della funzione al passo n
    dell'iterazione.

    Ha il vantaggio di non richiedere la derivata della f() ma occorrono 
    first e second guess.
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;

const int   MAX_ITER = 20;
const float EPSILON  = 1e-5;
static int  n_iter   = 0;

const char  *HEAD  = "# ================ #\n# data for gnuplot #\n# ================ #\n\n";
const char  *FN    = "secanti.txt"; // nome del file per gnuplot
const int    PREC  = 4;             // numero di cifre decimali


/*-------------------------------------------------------------------------------------
  dichiariamo delle funzioni da poter provare, insieme a derivata e first guess
-------------------------------------------------------------------------------------*/

// uno zero e` ovvio x = 0
// il secondo meno ovvio, da cercare con first guess 0.5 e second guess 2.0
float fun1( float x ) {
  return x * x - sin( x );
}

// first guess 0.0 e second guess 2.0
float fun2( float x ) {
  return 1 - 2 * x * exp( - x / 2 );
}

/*-------------------------------------------------------------------------------------
  un passo della formula ricorsiva
-------------------------------------------------------------------------------------*/

float step( float x0, float x1, float ( *f )( float x ) ) {
  return x1 - f( x1 ) * ( x1 - x0 ) / ( f( x1 ) - f( x0 ) );
}

/*-------------------------------------------------------------------------------------
  Algoritmo completo
    x0:   first guess
    x1:   second guess
    f:    funzione di cui trovare uno zero
    ostr: stream del file su cui scrivere
-------------------------------------------------------------------------------------*/

float secant( float x0, float x1, float ( *f )( float x ), ofstream &ostr ) {
  float x2; // final guess
  float e;  // errore

  while( n_iter < MAX_ITER ) {
    n_iter++;
    x2 = step( x0, x1, f );
    e = abs( x2 - x1 );
    ostr << x1 << "\t" << e << endl; // scrive il nuovo x e l'errore
    if ( e < EPSILON ) {
      return x1;
    }
    x0 = x1;
    x1 = x2;
  }
  return x2;
}

/*-------------------------------------------------------------------------------------
  Wrapper dell'algoritmo per gestire la parte di I/O su file
    x0: first guess
    x1: second guess
    f:  funzione di cui trovare uno zero
-------------------------------------------------------------------------------------*/

float do_secant( float x0, float x1, float ( *f )( float x ) ) {
  float result;

  ofstream ostr( FN );    // stream di uscita
  ostr << HEAD;           // scrive la header
  ostr.precision( PREC ); // imposta la precisione

  result  = secant( x0, x1, f, ostr );
  
  ostr.close();

  return result;
}

/*-------------------------------------------------------------------------------------
  dichiariamo la funzione main
-------------------------------------------------------------------------------------*/

int main() {

  float  x;

  // occorre passare all'algoritmo la funzione desiderata, first e second guess

  float  x0  = 0.0;
  float  x1  = 2.0;
  x      = do_secant( x0, x1, fun2 );

  // float  x0  = 0.5;
  // float  x1  = 2.0;
  // x    = do_secant( x0, x1, fun1 );

  cout << "Zero approssimato partendo dalle guess " << x0 << " e " << x1 << ":  ";
  cout << x << endl;
  cout << "Usando " << n_iter << " iterazioni" << endl;

  return 0;
}
