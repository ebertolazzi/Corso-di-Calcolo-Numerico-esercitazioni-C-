/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Definire matrici e vettori con Eigen
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


int main() {
    Matrix<float, 4, 4>     A;      // una matrice 4x4 di float
    Matrix<int, 4, 1>       B;      // un vettore di 4 interi
    Matrix<float, 4, 1>     C;      // un vettore di 4 float

    for ( int i=0; i<4; i++ ) {
        B( i )	= 2 * i;            // notare l'indicizzazione tra parentesi tonde
    }

    // notare come sia possibile inviare direttamente allo stream di output qualunque oggetto Matrix
    cout << "B:" << endl;
    cout << B << endl;

    for ( int i=0; i<4; i++ ) {
        C( i )	= 2. - 0.1 * B( i );
        for ( int j=0; j<4; j++ ) {
            A( i, j )	= i * i - 0.2 * B( j );
        }
    }

    cout << endl << "A:" << endl;
    cout << A << endl;

    cout << endl << "A * C:" << endl;
    cout << ( A * C ) << endl;      // moltiplicazione matrice 4x4 con vettore 4x1

    return 0;
}