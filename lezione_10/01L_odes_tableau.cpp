/* --------------------------------------------------------------------------------- *\
  CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24) Davide Stocco & Riccardo Bertollo

  Integrazione di ODEs saclari (metodo di Eulero, Midpoint e Heun)
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cmath>
#include <utility>
#include <vector>

#include <Eigen/Dense>

typedef double real;
typedef int    integer;

typedef Eigen::Matrix<real, 2, 1>  vec2; // 2x1 vector type (column vector)
typedef Eigen::Matrix<real, 2, 2>  mat2; // 2x2 matrix type
typedef Eigen::Matrix<real, 3, 1>  vec3; // 3x1 vector type (column vector)
typedef Eigen::Matrix<real, 3, 3>  mat3; // 3x3 matrix type
typedef Eigen::Matrix<real, 4, 1>  vec4; // 4x1 vector type (column vector)
typedef Eigen::Matrix<real, 4, 4>  mat4; // 4x4 matrix type

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

/*-----------------------------------------------------------------------------------*\
  Formula di RUnge-Kutta generica per l'integrazione di ODEs
    t0: estremo iniziale dell'intervallo di integrazione
    t1: estremo finale dell'intervallo di integrazione
    dt: passo di integrazione
    x0: condizioni iniziali
    f:  funzione da integrare
    s:  soluzione
\*-----------------------------------------------------------------------------------*/

template<typename vecN, typename matN>
void
RungeKutta(
  real t0,
  real t1,
  real dt,
  vecN x0,
  vecN (*f)(real, vecN),
  std::vector<std::pair<real, vecN> > s
)
{
  // Tablaue di Runge-Kutta
    mat4 A;
    A << 0.0, 0.0, 0.0, 0.0,
         0.5, 0.0, 0.0, 0.0,
         0.0, 0.5, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0;
    vec4 b;
    b << 1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0;
    vec4 c;
    c << 0.0, 0.5, 0.5, 1.0;

  // Numero di punti per l'integrazione
  integer N = (t1-t0)/dt;

  // Inizializzazione della soluzione
  s.resize(N);

  // Integrazione dei vari passi
  real t = t0;
  vecN x = x0;
  s[0] = std::make_pair(t0, x0);
  for (integer i = 1; i < N; ++i)
  {
    // Runge-Kutta
    vecN k1 = f(t, x);
    vecN k2 = f(t + c(1)*dt, x + dt*A(1,0)*k1);
    vecN k3 = f(t + c(2)*dt, x + dt*(A(2,0)*k1 + A(2,1)*k2));
    vecN k4 = f(t + c(3)*dt, x + dt*(A(3,0)*k1 + A(3,1)*k2 + A(3,2)*k3));
    x += dt*(b(0)*k1 + b(1)*k2 + b(2)*k3 + b(3)*k4);

    // Aggiornamento della soluzione
    s[i] = std::make_pair(t, x);

    // Aggiornamento della variabile indipendente
    t += dt;
  }

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
  std::vector<std::pair<real, vec2> > s;

  RungeKutta<vec2, mat2>( t0, t1, (t1-t0)/100, ic, pendulum_simple, s );

  std::cout
    << "That's all Folks!" << std::endl;

  return 0;
}