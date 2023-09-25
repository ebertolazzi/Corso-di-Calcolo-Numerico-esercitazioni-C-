/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Integrazione metodo di Gauss
\*-----------------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>

using namespace std;


/*-----------------------------------------------------------------------------------*\
	dati tabulati X, e pesi corrispondenti, nell'intervallo [-1,1]
	(valori ottenuti con Mathematica)
\*-----------------------------------------------------------------------------------*/
const float GAUSSX3[ 3 ]	= {-0.774597, 0., 0.774597};
const float GAUSSW3[ 3 ]	= {0.555556, 0.888889, 0.555556};
const float GAUSSX4[ 4 ]	= {-0.861136, -0.339981, 0.339981, 0.861136};
const float GAUSSW4[ 4 ]	= {0.347855, 0.652145, 0.652145, 0.347855};
const float GAUSSX6[ 6 ]	= {-0.93247, -0.661209, -0.238619, 0.238619, 0.661209, 0.93247};
const float GAUSSW6[ 6 ]	= {0.171324, 0.360762, 0.467914, 0.467914, 0.360762, 0.171324};


/*-----------------------------------------------------------------------------------*\
	formula di Gauss
		I	= \sum_{i=1}^{n} w_i f( x_i )

		*f:	la funzione da integrare
		a:	primo estremo di integrazione
		b:	secondo estremo di integrazione
		n:	numero di punti da usare (3/4/6)
\*-----------------------------------------------------------------------------------*/
float gauss( float ( *f )( float x ), float a, float b, int n ) {
	float	m	= ( b - a ) / 2;	// serve per normalizzare l'intervallo
	float	s	= 0;
	float	z;

	for( int i = 0; i < n; i++ ) {
		if ( n == 3 ) {
			z	= a + m * ( GAUSSX3[ i ] + 1 );
			s	+= GAUSSW3[ i ] * m * f( z );
		}
		if ( n == 4 ) {
			z	= a + m * ( GAUSSX4[ i ] + 1 );
			s	+= GAUSSW4[ i ] * m * f( z );
		}
		if ( n == 6 ) {
			z	= a + m * ( GAUSSX6[ i ] + 1 );
			s	+= GAUSSW6[ i ] * m * f( z );
		}
	}
	return s;
}


/*-----------------------------------------------------------------------------------*\
	funzione da integrare (la stessa vista negli altri esempi)
\*-----------------------------------------------------------------------------------*/
float fun( float x ) {
	return	3 + x * x * sin( x ) - 2. * x * sin( 2 * x );
}

/*-----------------------------------------------------------------------------------*/

int main() {
	const int	N	= 3;	// dev'essere 3 o 4 o 6
	float		r;

	r	= gauss( fun, -M_PI, M_PI, N );

	// il risultato dovrebbe essere 25.1327
	cout << "Metodo Gauss usando " << N << " punti:\t" << r << endl;

	return 0;
}