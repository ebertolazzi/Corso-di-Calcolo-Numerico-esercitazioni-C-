/* --------------------------------------------------------------------------------- *\
  CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Zeri di funzione - metodo di Newton

    Gli zeri di una funzione sono valori x tali che f( x ) = 0
    Il metodo di Newton usa la formula iterativa
      x_{n+1} = x_n - f( x_n ) / f'( x_n )
    dove x_n e` il valore approssimato dello zero della funzione al passo n
    dell'iterazione.

    Occorre fornire un first guess x_0 e conoscere la derivata f' della funzione.

    Un criterio per stimare l'errore dell'approssimazione e` confrontarlo
    con l'approssimazione precedente
      \epsilon = | x_{n+1} - x_n |
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <cmath>

using namespace std;

const int   MAX_ITER = 20;
const float EPSILON  = 1e-5;
static int  n_iter   = 0;


/*-------------------------------------------------------------------------------------
  dichiariamo delle funzioni da poter provare, insieme a derivata e first guess
-------------------------------------------------------------------------------------*/

// uno zero e` ovvio x = 0
// il secondo meno ovvio, da cercare con first guess x_0 = 0.5
float fun1( float x ) {
  return x * x - sin( x );
}

float dfun1( float x ) {
  return 2 * x - cos( x );
}

// first guess x_0 = 0.0
float fun2( float x ) {
  return 1 - 2 * x * exp( - x / 2 );
}

float dfun2( float x ) {
  return ( x - 2 ) / exp( x / 2 );
}

/*-------------------------------------------------------------------------------------
  un passo della formula ricorsiva
-------------------------------------------------------------------------------------*/

float step( float x0, float ( *f )( float x ), float ( *d )( float x ) ) {
  return x0 - f( x0 ) / d( x0 );
}

/*-------------------------------------------------------------------------------------
  Algoritmo completo
    x0: first guess
    f:  funzione di cui trovare uno zero
    d:  derivata della funzione
-------------------------------------------------------------------------------------*/

float newton( float x0, float ( *f )( float x ), float ( *d )( float x ) ) {
  float x1; // final guess
  float e;  // errore

  while( n_iter < MAX_ITER ) {
    n_iter++;
    x1 = step( x0, f, d );
    e = abs( x1 - x0 );
    cout << "x: " << x1 << "\te: " << e << endl; // scrive il nuovo x e l'errore
    if ( e < EPSILON ) {
      return x1;
    }
    x0 = x1;
  }
  return x1;
}

/*-------------------------------------------------------------------------------------
  dichiariamo la funzione main
-------------------------------------------------------------------------------------*/

int main() {
  float x;

    // occorre passare all'algoritmo la funzione desiderata, la sua derivata, e first guess

  float x0 = 0.5;
  x = newton( x0, fun1, dfun1 );

  // float x0 = 0.0;
  // x = newton( x0, fun2, dfun2 );

  cout << endl << "Zero approssimato partendo dalla first guess " << x0 << ": ";
  cout << x << endl;
  cout << "Usando " << n_iter << " iterazioni" << endl;

  return 0;
}
