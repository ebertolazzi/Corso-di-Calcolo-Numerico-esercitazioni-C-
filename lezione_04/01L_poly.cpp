/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                Davide Stocco

    Classe Poly
\* --------------------------------------------------------------------------------- */

// includiamo la libreria
#include "cnum.h"


// includiamo i namespaces
using namespace std;
using namespace Eigen;

using cnum::Poly; // polinomio

/*-------------------------------------------------------------------------------------
  dichiariamo la funzione main
-------------------------------------------------------------------------------------*/

int
main() {

  /*-------------------------------------------------------------------------------------
    costruiamo un po' di polinimi con un diversi metodi
  -------------------------------------------------------------------------------------*/

  Vector4d c1( 2, -2, 2, 3 );
  Vector3d c2( 4, 0, 1 );

  Poly p1( c1 );
  Poly p2( c2 );
  Poly p3( 10 );

  /*-------------------------------------------------------------------------------------
    utilizziamo un po' di metodi della classe Poly
  -------------------------------------------------------------------------------------*/

  cout
    << "Il grado di p1: " << p1.degree() << '\n'
    << "Il grado di p2: " << p2.degree() << '\n'
    << '\n';

  cout << "p1    = " << p1 << '\n';
  cout << "p1(2) = " << p1.eval( 2 ) << "\n\n";
  cout << "p2    = " << p2 << '\n';
  cout << "p2(3) = " << p2.eval( 3 ) << "\n\n";

  cout << "derivata di p1 = " << p1.derivative() << "\n\n";
  cout << "integrale di p1 = " << p1.integral() << "\n\n";

  p3  = p1 + p2;
  cout << "somma di p1 e p2 = " << p3 << "\n\n";

  p3  = p1 * p2;
  cout << "prodotto di p1 e p2 = " << p3 << "\n\n";

  cout << "prodotto di\np3 = " << p3 << "\ncon\np1 = " << p1 << '\n';
  cout << "p3 * p1 => " << p3*p1 << "\n\n";
  p3 *= p1;
  cout << "p3 *= p1 => " << p3 << "\n\n";

  return 0;
}
