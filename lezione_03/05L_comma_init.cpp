/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Definire matrici e vettori con Eigen
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


int main() {
    int		    size    = 5;
    Matrix2f	A;			        // una matrice 2x2 di float
    Matrix4f	B;			        // una matrice 4x4 di float
    MatrixXf	C( size, size );	// una matrice 5x5 di float

    Vector2f	V( 0.2, 0.4 );		// un vettore 2x1 di float a cui sono stati direttamente assegnati i valori
    Vector4f	U;			        // un vettore 4x1 di float

    A << 0.8, 0.7, -0.1, -0.5;		// uso semplice di comma initializer
    cout << endl << "A:" << endl;
    cout << A << endl;

    U << V, V;				        // comma initializer con due blocchi

    // per comodita` mostriamo i vettori in orizzontale
    cout << endl << "V:\t" << V.transpose() << endl;
    cout << "U:\t" << U.transpose() << endl;

    B << A, 1.5 * A, 0.5 * A, -A;	// comma initializer con quattro blocchi
    cout << endl << "B:" << endl;
    cout << B << endl;

    C << B, U, U.transpose(), 0;	// comma initializer con blocchi di dimensione varia

    return 0;
}