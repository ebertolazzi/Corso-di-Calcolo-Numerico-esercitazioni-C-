/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Integrazione metodo dei trapezi e metodo di Simpson
	(con intervalli irregolari)
\*-----------------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
#include <Eigen/Dense>
 
using namespace std;
using namespace Eigen;


/*-----------------------------------------------------------------------------------*\
	formula dei trapezi
		I	= \sum_{i=1}^n 1/2 ( x_i - x_{i-1} ) ( y_i + y_{i-1} )
		x:	vettore di valori X
		y:	vettore di valori f(X)
\*-----------------------------------------------------------------------------------*/
float trapezi( VectorXf &x, VectorXf &y ) {
	float	s	= 0;
	int		l	= x.size();
	
	for( int i=1; i<l; i++ ) {
		s	+= ( x[ i ] - x[ i - 1 ] ) * ( y[ i ] + y[ i - 1 ] );
	}

	return 0.5 * s;
}

/*-----------------------------------------------------------------------------------*\
	formula di Simpson
		I	= \sum_{i=1}^{n/2} h_i ( y_{2i-2} + 4 y_{2i-1} +y_{2i} )
			dove:
		h_i	= ( x_{2i} - x_{2i-2} ) / 6 

		x:	vettore di valori X
		y:	vettore di valori f(X)
\*-----------------------------------------------------------------------------------*/
float simpson( VectorXf &x, VectorXf &y ) {
	float	s	= 0;
	float	h	= 0;
	int	n	= x.size() / 2;
	
	for( int i = 1; i < n; i++ ) {
		h	= ( x( 2 * i ) - x( 2 * i - 2 ) );
		s	+= h * ( y( 2 * i - 2 ) + 4 * y( 2 * i - 1 ) + y( 2 * i ) );
	}
	return s / 6;
}


/*-----------------------------------------------------------------------------------*\
	dati generati con la funzione da integrare
		x:		vettore di valori X
		y:		vettore di valori f(X)
		n_data:	lunghezza vettori
\*-----------------------------------------------------------------------------------*/
void data_gen( VectorXf &x, VectorXf &y, int n_data ) {
	float	v;

	// genera un vettore di X casuali nel range [-Pi, Pi] ordinati in modo ascendente
	x	= M_PI * VectorXf::Random( n_data );
	// x	= M_PI * VectorXf::LinSpaced( n_data, - M_PI, M_PI );	// per intervalli regolari
	sort( x.data(), x.data() + x.size() );

	// y.resize( n_data );

	// la funzione (inventata a caso)
	for( int i=0; i<n_data; i++ ) {
		v		= x( i );
		y( i )	= 3 + v * v * sin( v ) - 2. * v * sin( 2 * v );
	}
}

/*-----------------------------------------------------------------------------------*/

int main() {
	const int	N	= 40;	// deve essere pari per Simpson
	float		rt;
	float		rs;

	VectorXf	x( N );
	VectorXf	y( N );

	data_gen( x, y, N );
	rt	= trapezi( x, y );
	rs	= simpson( x, y );

	// il risultato dovrebbe essere 25.1327
	cout << "Metodo trapezi usando " << N << " intervalli:\t" << rt << endl;
	cout << "Metodo Simpson usando " << N << " intervalli:\t" << rs << endl;
}