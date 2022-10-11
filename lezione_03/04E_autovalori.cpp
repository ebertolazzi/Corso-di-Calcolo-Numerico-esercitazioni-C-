/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2021/22)                  Alice Plebe

    Esempio: autovettori e autovalori di una matrice
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

#define PREC    3       // precisione per la stampa dei decimali


int main() {
    cout.precision( PREC );                     // imposta la precisione per la stampa dei decimali

    Matrix3f    A;                              // una matrice 3x3 di float
    A << 0, 1, 0, 0, 0, 1, 4, -17, 8;           // riempita con questi valori

    EigenSolver<Matrix3f>   slv;                // l'oggetto solver
    slv.compute( A );                           // risolve per la matrice A

    cout << "\nMatrice A\n";
    cout << A << endl;

    cout << "\nGli autovalori di A\n";
    cout << slv.eigenvalues() << endl;          // estrae gli autovalori (in formato con numeri complessi)

    cout << "\nGli autovettori di A\n";
    cout << slv.eigenvectors() << endl;         // estrae gli autovettori (in formato con numeri complessi)

    /* ---------------------------------------------
        verifica la proprieta`:    A v = l v
    --------------------------------------------- */
    float       l   = slv.eigenvalues()[ 0 ].real();        // il primo autovalore (senza la parte immaginaria)
    Vector3f    v   = slv.eigenvectors().col( 0 ).real();   // il primo autovettore (senza la parte immaginaria)

    // i seguenti sono equivalenti
    cout << "\nA * v\n";
    cout << A * v << endl;
    cout << "\nl * v\n";
    cout << l * v << endl;

    /* ---------------------------------------------
        verifica la proprieta`:    A = V D V^-1
    --------------------------------------------- */
    Matrix3f    V   = slv.eigenvectors().real();                // matrice degli autovettori (senza la parte immaginaria)
    Matrix3f    D   = slv.eigenvalues().real().asDiagonal();    // matrice diagonale con gli autovettori

    cout << "\nMatrice V\n";
    cout << V << endl;
    cout << "\nMatrice D\n";
    cout << D << endl;

    // i seguenti sono equivalenti
    cout << "\nV D V^-1\n";
    cout << V * D * V.inverse() << endl;
    cout << "\nMatrice A\n";
    cout << A << endl;

    return 0;
}