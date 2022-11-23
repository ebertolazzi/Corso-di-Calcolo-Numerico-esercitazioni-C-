/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                 Davide Stocco

    Integrazione di ODEs metodo di Eulero
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cmath>

typedef double real;
typedef int    integer;

#define ANIM 1 // Genera plot 1=animato o 0=statico

const std::string head  = "# --------------------------\n# data generated for gnuplot\n# --------------------------\n";
const std::string	fname = ANIM ? "plot_anim" : "plot_data";
const std::string fext  = "txt";

#define N_POINTS_PLOT 1e3 // Numero di punti per il plot
#define N_POINTS_INT  5e1 // Numero di punti per l'integrazione

/*-----------------------------------------------------------------------------------*\
  Un paio di funzioni per testare l'algoritmo
\*-----------------------------------------------------------------------------------*/

real
fun1(
  real x, // Variabile indipendente
  real y  // Variabile dipendente
)
{
    return std::sin(x);
}

real
fun1_exact(
  real x // Variabile indipendente
)
{
    return std::cos(x);
}

/*-----------------------------------------------------------------------------------*\
  Formula di Eulero per l'integrazione di ODEs
  y_{k+1} = y_k + dx * f(x_k,y_k)
    x0: estremo iniziale dell'intervallo di integrazione
    x1: estremo finale dell'intervallo di integrazione
    y0: condizioni iniziali
    f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/

real
euler(
  real x0,
  real x1,
  real y0,
  real (*f)(real x, real y)
)
{
  return y0 + (x0 - x1) * f(x0,y0);
}

/*-----------------------------------------------------------------------------------*\
  Formula di Eulero modificato (o midpoint) per l'integrazione di ODEs
  y_{k+1} = y_k + dx * f( dx/2*x_k ,dx/2*f(x_k,y_k) )
    x0: estremo iniziale dell'intervallo di integrazione
    x1: estremo finale dell'intervallo di integrazione
    y0: condizioni iniziali
    f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/

real
midpoint(
  real x0,
  real x1,
  real y0,
  real (*f)(real x, real y)
)
{
  real dx = (x0 - x1);
  return y0 + dx * f(
    x0 + dx / real(2.0),
    dx / real(2.0) * f(x0,y0)
  );
}

/*-----------------------------------------------------------------------------------*\
  Formula di Haun per l'integrazione di ODEs
  y_{k+1} = y_k + dx * f( dx/2*x_k ,dx/2*f(x_k,y_k) )
    x0: estremo iniziale dell'intervallo di integrazione
    x1: estremo finale dell'intervallo di integrazione
    y0: condizioni iniziali
    f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/

real
heun(
  real x0,
  real x1,
  real y0,
  real (*f)(real x, real y)
)
{
  real dx = (x0 - x1);

  // Applichiamo eulero per calcolare una stima di y_{k+1}
  // real y1_tmp = y0 + dx * f(x0,y0);
  real y1_tmp = euler(x0, x1, y0, f);

  // Applichiamo la formula di heun
  return y0 + dx / real(2.0) * (f(x0,y0) + f(x1,y1_tmp));
}

/*-----------------------------------------------------------------------------------*\
  Wrapper per scrivere i dati su file per gnuplot
    a:  estremo iniziale dell'intervallo di integrazione
    b:  estremo finale dell'intervallo di integrazione
    f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/

void
do_integrate(
  real a,
  real b,
  real (*f)(real x, real y),
  real (*f_exact)(real x)
)
{
  // Inizializiamo il file di output
  std::ofstream o( fname + "." + fext ); // File stream di uscita
  o << head; // Scrivimo l'header su file

  // Scrive prima i dati della funzione integrata
  for (real x = a; x < b; x += (b - a) / N_POINTS_PLOT)
  {
    o << x << "\t" << f_exact(x) << std::endl;
  }
  o << "\n\n"; // Inseriamodue righe vuote in gnuplot per separare i data block

  // Calcoliamo il passo dell' integrale
  real dx = (b - a) / N_POINTS_INT;

  // Scrive prima i dati degli integrali
  real y0_t, y0_m, y0_e, y1_t, y1_m, y1_e, x0, x1, y0, y1;
  x0   = a;
  y0_e = f_exact(a);
  y0_t = f_exact(a);
  y0_m = f_exact(a);

  // Scriviamo i dati su file
  o << x0 << "\t" << y0_e << "\t" << y0_t << "\t" << y0_m << std::endl;

  for (real x1 = a + dx; x1 <= b; )
  {
    // Calcoliamo i valori di y con i tre metodi
    y1_e = euler( x0, x1, y0_e, f );
    y1_t = midpoint( x0, x1, y0_e, f );
    y1_m = heun( x0, x1, y0_e, f );

    // Update delle variabili
    x0   = x1;
    x1  += dx;
    y0_e = y1_e;
    y0_t = y1_t;
    y0_m = y1_m;

    // Scriviamo i dati su file
    if ( ANIM ) {
        o << "\n\n";  // Due righe vuote in gnuplot separano i data block
    }
    o << x1 << "\t" << y1_e << "\t" << y1_t << "\t" << y1_m << std::endl;
  }

  // Chiudiamo il file
  o.close();
}

/*-----------------------------------------------------------------------------------*\
  Main
\*-----------------------------------------------------------------------------------*/

int
main(void)
{
  real a = 0.0;
  real b = 10.0*M_PI;
  do_integrate( a, b, fun1, fun1_exact );

  std::cout
    << "That's all Folks!" << std::endl;

  return 0;
}