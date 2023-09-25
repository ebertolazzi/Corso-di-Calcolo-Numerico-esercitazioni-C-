/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                Davide Stocco

    Zeri di funzione - Libreria
\* --------------------------------------------------------------------------------- */

#include "cnum.h"
#include <iomanip>

using namespace std;

using cnum::Real;
using cnum::Integer;

static Real const alpha = -0.56714329040978387299996866221035554975381578718651;

/*-------------------------------------------------------------------------------------
  dichiariamo una funzioni da poter provare, insieme a derivata e first guess
-------------------------------------------------------------------------------------*/

static
Real
fun1( Real x ) {
  return exp(x)+x;
}

static
Real
Dfun1( Real x ) {
  return exp(x)+1;
}

static
Real
DDfun1( Real x ) {
  return exp(x);
}

/*-------------------------------------------------------------------------------------
  funzione per stimare l'ordine di convergenza
-------------------------------------------------------------------------------------*/

static
void
order_estimate( cnum::dvec_t const & err ) {
  cout << setw(22) << "err " << setw(22) << "order\n";
  cout << setw(22) << err(0) << setw(22) << "---\n";
  cout << setw(22) << err(1) << setw(22) << "---\n";
  for ( Integer i = 2; i < err.size(); ++i ) {
    Real p = log( abs(err(i)/err(i-1)))/log( abs(err(i-1)/err(i-2)));
    cout
      << setw(22) << err(i)
      << setw(22) << p
      << '\n';
  }
}

/*-------------------------------------------------------------------------------------
  dichiariamo la funzione main
-------------------------------------------------------------------------------------*/

int
main() {
  // setting iniziali
  Real    a      = -10;
  Real    b      = 10;
  Real    tol    = 1e-10;
  Integer flg;
  Integer max_it = 20;
  Real    x0     = 1;
  Real    x1     = 2;
  Real    res;
  cnum::dvec_t a_vec, b_vec, x_vec;
  cout.precision(15);

  /*-------------------------------------------------------------------------------------
    metodo delle secanti
  -------------------------------------------------------------------------------------*/

  res = cnum::zero_secant( fun1, x0, x1, tol, max_it, flg, &x_vec );
  cout
    << "\n\nsecant...........................\n"
    << "flg = " << flg
    << " x = " << res
    << " f(x) = " << setw(22) << fun1(res)
    << " #iter = " << x_vec.size()
    << "\n\n";

  x_vec.array() -= alpha;
  order_estimate( x_vec );

  /*-------------------------------------------------------------------------------------
    metodo di Newton
  -------------------------------------------------------------------------------------*/

  res = cnum::zero_Newton(
    fun1, Dfun1, x0, tol, max_it, flg, &x_vec
  );
  cout
    << "\n\nNewton..............................."
    << "\nflg   = " << flg
    << "\nx     = " << res
    << "\nf(x)  = " << setw(22) << fun1(res)
    << "\n#iter = " << x_vec.size()
    << "\n\n";

  x_vec.array() -= alpha;
  order_estimate( x_vec );

  /*-------------------------------------------------------------------------------------
    metodo di Halley
  -------------------------------------------------------------------------------------*/

  res = cnum::zero_Halley(
    fun1, Dfun1, DDfun1, x0, tol, max_it, flg, &x_vec
  );
  cout
    << "\n\nHalley............................"
    << "\nflg   = " << flg
    << "\nx     = " << res
    << "\nf(x)  = " << setw(22) << fun1(res)
    << "\n#iter = " << x_vec.size()
    << '\n';

  x_vec.array() -= alpha;
  order_estimate( x_vec );

  /*-------------------------------------------------------------------------------------
    metodo di Newton per radici multiple
  -------------------------------------------------------------------------------------*/

  res = cnum::zero_Newton_for_multiple_roots(
    fun1, Dfun1, DDfun1, x0, tol, max_it, flg, &x_vec
  );
  cout
    << "\n\nNewton (m)............................"
    << "\nflg   = " << flg
    << "\nx     = " << res
    << "\nf(x)  = " << setw(22) << fun1(res)
    << "\n#iter = " << x_vec.size()
    << "\n\n";

  x_vec.array() -= alpha;
  order_estimate( x_vec );

  /*-------------------------------------------------------------------------------------
    metodo di Steffsen
  -------------------------------------------------------------------------------------*/

  res = cnum::zero_Steffensen(
    fun1, x0, tol, max_it, flg, &x_vec
  );
  cout
    << "\n\nSteffensen......................."
    << "\nflg   = " << flg
    << "\nx     = " << res
    << "\nf(x)  = " << setw(22) << fun1(res)
    << "\n#iter = " << x_vec.size()
    << "\n\n";

  x_vec.array() -= alpha;
  order_estimate( x_vec );

  /*-------------------------------------------------------------------------------------
    metodo di Newton con Bisezione
  -------------------------------------------------------------------------------------*/

  res = cnum::zero_Newton_bisection(
    fun1, Dfun1, a, b, tol, max_it, flg, &x_vec
  );
  cout
    << "\n\nNewton bisection......................."
    << "\nflg   = " << flg
    << "\nx     = " << res
    << "\nf(x)  = " << setw(22) << fun1(res)
    << "\n#iter = " << x_vec.size()
    << "\n\n";
  x_vec.array() -= alpha;
  order_estimate( x_vec );

  cout << "\nAll done folks!\n";
  return 0;
}
