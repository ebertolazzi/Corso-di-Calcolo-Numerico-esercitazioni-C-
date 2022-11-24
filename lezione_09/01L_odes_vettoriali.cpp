/* --------------------------------------------------------------------------------- *\
  CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23) Davide Stocco & Riccardo Bertollo

  Integrazione di ODEs saclari (metodo di Eulero, Midpoint e Heun)
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cmath>

#include <Eigen/Dense>

typedef double real;
typedef int    integer;

typedef Eigen::Matrix<real, 2, 1> vec2; // 2x1 vector type (column vector)
typedef Eigen::Matrix<real, 3, 1> vec3; // 3x1 vector type (column vector)
typedef Eigen::Matrix<real, 4, 1> vec4; // 4x1 vector type (column vector)

const std::string head  = "# --------------------------\n# data generated for gnuplot\n# --------------------------\n";
const std::string	fname = "plot_data";
const std::string fext  = "txt";

#define N_POINTS_PLOT 1e3 // Numero di punti per il plot
#define N_POINTS_INT  5e1 // Numero di punti per l'integrazione

const real m      = 1.0;  // Massa del pendolo
const real l      = 1.0;  // Lunghezza del pendolo
const real g      = 9.81; // Accelerazione di gravità
const real omega0 = 0.0;  // Velocita iniziale (non toccare)
const real theta0 = 0.01; // Angolo iniziale

/*-----------------------------------------------------------------------------------*\
  Un paio di funzioni per testare l'algoritmo
\*-----------------------------------------------------------------------------------*/

vec2
pendulum_simple(
  real t, // Variabile indipendente
  vec2 x  // Variabile dipendente
)
{
  return vec2(x(1), -(g/l)*x(0));
}

vec2
pendulum_nonlinear(
  real t, // Variabile indipendente
  vec2 x  // Variabile dipendente
)
{
  return vec2(x(1), -(g/l)*std::sin(x(0)));
}

vec2
pendulum_exact(
  real t // Variabile indipendente
)
{
  real s = std::sqrt(g/l);
  return vec2(theta0*std::cos(s*t), -theta0*s*std::sin(s*t));
}

/*-----------------------------------------------------------------------------------*\
  Formula di Eulero per l'integrazione di ODEs
    t0: estremo iniziale dell'intervallo di integrazione
    t1: estremo finale dell'intervallo di integrazione
    x0: condizioni iniziali
    f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/

template<typename vecN>
vecN
euler(
  real t0,
  real t1,
  vecN x0,
  vecN (*f)(real t, vecN x)
)
{
  return x0 + (t1 - t0) * f(t0,x0);
}

/*-----------------------------------------------------------------------------------*\
  Formula di Eulero modificato (o midpoint) per l'integrazione di ODEs
    t0: estremo iniziale dell'intervallo di integrazione
    t1: estremo finale dell'intervallo di integrazione
    x0: condizioni iniziali
    f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/

template<typename vecN>
vecN
midpoint(
  real t0,
  real t1,
  vecN x0,
  vecN (*f)(real t, vecN x)
)
{
  real dt = t1 - t0;
  return x0 + dt * f(
    t0 + dt / real(2.0),
    x0 + dt / real(2.0) * f(t0,x0)
  );
}

/*-----------------------------------------------------------------------------------*\
  Formula di Heun per l'integrazione di ODEs
    t0: estremo iniziale dell'intervallo di integrazione
    t1: estremo finale dell'intervallo di integrazione
    x0: condizioni iniziali
    f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/

template<typename vecN>
vecN
heun(
  real t0,
  real t1,
  vecN x0,
  vecN (*f)(real t, vecN x)
)
{
  // Applichiamo eulero per calcolare una stima di y_{k+1}
  vecN x1_tmp = euler(t0, t1, x0, f);

  // Applichiamo la formula di heun
  real dt = t1 - t0;
  return x0 + dt / real(2.0) * (f(t0,x0) + f(t1,x1_tmp));
}

/*-----------------------------------------------------------------------------------*\
  Formula di Runge-Kutta di ordine 4 per l'integrazione di ODEs
    t0: estremo iniziale dell'intervallo di integrazione
    t1: estremo finale dell'intervallo di integrazione
    x0: condizioni iniziali
    f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/

template<typename vecN>
vecN
rk4(
  real t0,
  real t1,
  vecN x0,
  vecN (*f)(real t, vecN x)
)
{
  real dt = t1 - t0;
  vecN k1 = dt * f(t0, x0);
  vecN k2 = dt * f(t0 + dt / real(2.0), x0 + k1 / real(2.0));
  vecN k3 = dt * f(t0 + dt / real(2.0), x0 + k2 / real(2.0));
  vecN k4 = dt * f(t0 + dt, x0 + k3);
  return x0 + (k1 + real(2.0) * k2 + real(2.0) * k3 + k4) / real(6.0);
}

/*-----------------------------------------------------------------------------------*\
  Wrapper per scrivere i dati su file per gnuplot
    t0: estremo iniziale dell'intervallo di integrazione
    t1: estremo finale dell'intervallo di integrazione
    f:  funzione da integrare
    fe: soluzione della funzione da integrare
\*-----------------------------------------------------------------------------------*/

template<typename vecN>
void
do_integrate(
  real t0,
  real t1,
  vecN ic,
  vecN (*f)(real t, vecN x),
  vecN (*fe)(real t)
)
{
  // Inizializiamo il file di output
  std::ofstream o_exact( fname + "_exact." + fext ); // File stream di uscita
  std::ofstream o_euler( fname + "_euler." + fext ); // File stream di uscita
  std::ofstream o_midpoint( fname + "_midpoint." + fext ); // File stream di uscita
  std::ofstream o_heun( fname + "_heun." + fext ); // File stream di uscita
  std::ofstream o_rk4( fname + "_rk4." + fext ); // File stream di uscita

  // Scrivimo l'header su file
  o_exact << head;
  o_euler << head;
  o_midpoint << head;
  o_heun << head;
  o_rk4 << head;

  real dt;
  vecN x0, x1;

  // Scrive prima i dati della funzione integrata
  std::cout << "Writing exact solution...";
  dt = (t1 - t0) / N_POINTS_PLOT;
  for (real t = t0; t < t1; t += dt)
  {
    o_exact << t << " " << fe(t).transpose() << std::endl;
  }
  std::cout << "\tDone!" << std::endl;

  // Scrive poi i dati della funzione integrata con i vari metodi
  // Metodo di Eulero
  std::cout << "Integrating with Euler...";
  dt = (t1 - t0) / N_POINTS_INT;
  x0 = ic;
  o_euler << t0 << " " << ic.transpose() << std::endl;
  for (real t = t0; t < t1; t += dt)
  {
    x1 = euler<vecN>(t, t+dt, x0, f);
    o_euler << t+dt << " " << x1.transpose() << std::endl;
    x0 = x1;
  }
  std::cout << "\tDone!" << std::endl;

  // Metodo di Eulero modificato
  std::cout << "Integrating with Midpoint...";
  x0 = ic;
  o_midpoint << t0 << " " << ic.transpose() << std::endl;
  for (real t = t0; t < t1; t += dt)
  {
    x1 = midpoint<vecN>(t, t+dt, x0, f);
    o_midpoint << t+dt << " " << x1.transpose() << std::endl;
    x0 = x1;
  }
  std::cout << "\tDone!" << std::endl;

  // Metodo di heun
  std::cout << "Integrating with Heun...";
  x0 = ic;
  o_heun << t0 << " " << ic.transpose() << std::endl;
  for (real t = t0; t < t1; t += dt)
  {
    x1 = heun<vecN>(t, t+dt, x0, f);
    o_heun << t+dt << " " << x1.transpose() << std::endl;
    x0 = x1;
  }
  std::cout << "\tDone!" << std::endl;

  // Metodo di Runge-Kutta di ordine 4
  std::cout << "Integrating with RK4...";
  x0 = ic;
  o_rk4 << t0 << " " << ic.transpose() << std::endl;
  for (real t = t0; t < t1; t += dt)
  {
    x1 = rk4<vecN>(t, t+dt, x0, f);
    o_rk4 << t+dt << " " << x1.transpose() << std::endl;
    x0 = x1;
  }
  std::cout << "\tDone!" << std::endl;

  // Chiudiamo il file
  o_exact.close();
  o_euler.close();
  o_midpoint.close();
  o_heun.close();
  o_rk4.close();
}

/*-----------------------------------------------------------------------------------*\
  Main
\*-----------------------------------------------------------------------------------*/

int
main(void)
{
  real t0 = 0.0;
  real t1 = 5.0;
  vec2 ic(theta0, omega0);
  do_integrate<vec2>( t0, t1, ic, pendulum_simple, pendulum_exact );

  std::cout
    << "That's all Folks!" << std::endl;

  return 0;
}