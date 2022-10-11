/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Manipolare matrici e vettori con Eigen
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


int main() {
	Matrix4f	A;			                    // una matrice 4x4 di float
	Matrix4f	B;			                    // una matrice 4x4 di float
	Vector4f	U;			                    // un vettore 4x1 di float

	A	= Matrix4f::Zero();		                // tutti zero
	cout << endl << "zero:" << endl;
	cout << A << endl;

	A	= Matrix4f::Ones();		                // tutti uno
	cout << endl << "ones:" << endl;
	cout << A << endl;

	A	+= Matrix4f::Random();		            // quella di prima con un po' di rumore
	cout << endl << "ones + random:" << endl;
	cout << A << endl;

	A	= Matrix4f::Identity();		            // identity matrix
	cout << endl << "identity:" << endl;
	cout << A << endl;

	// linear space: valori equidistanziati tra minimo e massimo dati
	U	= Vector4f::LinSpaced( 4, -0.8, 0.7 );
	cout << endl << "linear space:" << endl;
	cout << U << endl;

	A.diagonal()	= U;                        // matrice diagonale con i valori di U
	cout << A << endl;
	A	            = U.asDiagonal();           // equivalente a sopra
	cout << A << endl;

	for ( int r=0; r<4; r++ ) {
		U       = Vector4f::LinSpaced( 4, -0.8, 0.7 * ( r + 1 ) );
		B.row( r )	= U;		                // assegna un vettore come riga della matrice
	}
	cout << endl << "B:" << endl;
	cout << B << endl;

	// estrae varie porzioni della matrice
	cout << endl << "B.col( 1 ):" << endl;
	cout << B.col( 1 ) << endl;
	cout << endl << "B.topLeftCorner( 2, 2 ):" << endl;
	cout << B.topLeftCorner( 2, 2 ) << endl;
	
	// questo e` il modo piu` generale, preleva un qualunque blocco contiguo
	cout << endl << "Central block of B:" << endl;
	cout << B.block( 1, 1, 2, 2 ) << endl;

    return 0;
}