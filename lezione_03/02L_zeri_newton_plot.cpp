/* --------------------------------------------------------------------------------- *\
	CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Zeri di funzione - metodo di Newton con plot
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;

const int		N			= 10;
const int		MAX_ITER	= 20;
const float		EPSILON		= 1e-5;
static int		n_iter		= 0;

const char		*HEAD	= "# ================ #\n# data for gnuplot #\n# ================ #\n\n";
const char		*FN		= "newton.txt";		// nome del file per gnuplot
const char		*FF		= "funzione.txt";	// nome del file per gnuplot
const int		PREC	= 4;				// numero di cifre decimali


/*-------------------------------------------------------------------------------------
	Qui incluse due funzioni da poter provare, insieme a derivata e first guess
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
	Plot di una funzione
		x0:		minima X da plottare
		x1:		massima X da plottare
		d: 		step del plot
-------------------------------------------------------------------------------------*/
void plot_f( float ( *f )( float x ), float x0, float x1, float d ) {
	ofstream	ostr( FF );		// stream di uscita
	ostr << HEAD;				// scrive la header
	ostr.precision( PREC );		// imposta la precisione

	float n	= x0;
	while( n < x1 ) {
        ostr << n << "\t" << f( n ) << endl;
		n += d;
    }

	ostr.close();
}


/*-------------------------------------------------------------------------------------
	un passo della formula ricorsiva
-------------------------------------------------------------------------------------*/
float step( float x0, float ( *f )( float x ), float ( *d )( float x ) ) {
	return	x0 - f( x0 ) / d( x0 );
}


/*-------------------------------------------------------------------------------------
	Algoritmo completo
		x0:		first guess
		f:		funzione di cui trovare uno zero
		d:		derivata della funzione
		ostr:	stream del file su cui scrivere
-------------------------------------------------------------------------------------*/
float newton( float x0, float ( *f )( float x ), float ( *d )( float x ), ofstream &ostr ) {
	float x1;	// final guess
	float e;	// errore

	while( n_iter < MAX_ITER ) {
		n_iter++;
		x1	= step( x0, f, d );
		e	= abs( x1 - x0 );
		ostr << x1 << "\t" << e << endl;	// scrive il nuovo x e l'errore
		if ( e < EPSILON ) {
			return x1;
		}
		x0	= x1;
	}
	return x1;
}


/*-------------------------------------------------------------------------------------
	Wrapper dell'algoritmo per gestire la parte di I/O su file
		x0:		first guess
		f:		funzione di cui trovare uno zero
		d:		derivata della funzione
-------------------------------------------------------------------------------------*/
float do_newton( float x0, float ( *f )( float x ), float ( *d )( float x ) ) {
	float result;

	ofstream	ostr( FN );		// stream di uscita
	ostr << HEAD;				// scrive la header
	ostr.precision( PREC );		// imposta la precisione

	result	= newton( x0, f, d, ostr );
	
	ostr.close();

	return result;
}


int main() {
	float	x;

  	// occorre passare all'algoritmo la funzione desiderata, la sua derivata, e first guess

	float	x0	= 0.5;
	plot_f( fun1, -0.4, 1.1, 0.1 );
	x	= do_newton( x0, fun1, dfun1 );

	// float	x0	= 0.0;
	// plot_f( fun2, 0, 1, 0.1 );
	// x	= do_newton( x0, fun2, dfun2 );

	cout << "Zero approssimato partendo dalla first guess " << x0 << ":  ";
	cout << x << endl;
	cout << "Usando " << n_iter << " iterazioni" << endl;

	return 0;
}