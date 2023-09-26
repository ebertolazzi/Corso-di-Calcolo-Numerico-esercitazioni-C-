/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Esempio: calcola la trasposta di una matrice
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;


// costanti globali che definiscono la massima dimensione di matrici da allocare in memoria
const int   MAX_ROW     = 10;
const int   MAX_COL     = 10;

// funzione che stampa la matrice passata in argomento
void print_mtrx( int m[ MAX_ROW ][ MAX_COL ], int r, int c ) {
    // il numero di righe e colonne va passato in argomento
    cout << "Matrix (" << r << "x" << c << ")" << endl;
    for ( int i = 0; i < r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            cout << m[ i ][ j ] << "\t";
        }
        cout << endl;
    }
}

// funzione che calcola il trasposto di 'ma' e salva il risultato in 'mb'
void transp_mtrx( int ma[ MAX_ROW ][ MAX_COL ], int ra, int ca, int mb[ MAX_ROW ][ MAX_COL ] ) {
    for ( int i = 0; i < ra; ++i ) {
        for ( int j = 0; j < ca; ++j ) {
            mb[ j ][ i ]    = ma[ i ][ j ];
        }
    }
}

int main() {
    const int   rows_a      = 2;
    const int   cols_a      = 3;
    int         mtrx_a[ MAX_ROW ][ MAX_COL ]    = { { 10, 20, 30 }, { 11, 22, 33 } };

    const int   rows_b      = cols_a;
    const int   cols_b      = rows_a;
    int         mtrx_b[ MAX_ROW ][ MAX_COL ];

    print_mtrx( mtrx_a, rows_a, cols_a );
    transp_mtrx( mtrx_a, rows_a, rows_b, mtrx_b );
    print_mtrx( mtrx_b, rows_b, cols_b );

    return 0;
}