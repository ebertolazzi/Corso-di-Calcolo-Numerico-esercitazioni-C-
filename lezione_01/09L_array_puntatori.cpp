/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Array insieme a puntatori e funzioni
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;


// funzione che prende un array come parametro
double ultimo1( double arr[], int lung ) {
    // non e` possibile ricavare la lunghezza dell'array, e` necessario passarla come parametro
    return arr[ lung - 1 ];
}

// equivalente alla funzione sopra
double ultimo2( double *arr, int lung ) {
    return arr[ lung - 1 ];
}

// funzione che restituisce un puntatore ad un array
int* def_arr( int a, int b ) {
    // 'arr' deve essere static altrimenti verrebbe distrutta al termine della funzione
    static int  arr[]   = { a, b };
    return arr;
}


int main() {
    int     a[ 6 ]  = { 10, 20, 140, 6, 3843, 101 };
    double  b[]     = { 0.12, 3.45, 34.009 };

    // la variabile 'a' corrisponde all'indirizzo di memoria in cui inizia l'array
    cout << "L'indirizzo del primo elemento di 'a': " << a << endl;         // a = &a[ 0 ]

    int     *p;
    p       = a;    // il puntatore 'p' punta al primo elemento di 'a'

    cout << "L'indirizzo del primo elemento di 'a': " << p << endl;         // p        = a         = &a[ 0 ]
    cout << "L'indirizzo del secondo elemento di 'a': " << p + 1 << endl;   // p + 1    = a + 1     = &a[ 1 ]
    cout << "L'indirizzo del terzo elemento di 'a': " << a + 2 << endl;     // p + 2    = a + 2     = &a[ 2 ]

    cout << "Il primo elemento di 'a': " << *p << endl;                     // *p       = *a        = a[ 0 ]
    cout << "Il secondo elemento di 'a': " << *( p + 1 ) << endl;           // *( p+1 ) = *( a+1 )  = a[ 1 ]
    cout << "Il terzo elemento di 'a': " << *( a + 2 ) << endl;             // *( p+2 ) = *( a+2 )  = a[ 2 ]

    // stampa tutti gli elementi di 'a' usanto il puntatore 'p'
    for ( int i = 0; i < 6; ++i, ++p ) {    // l'indirizzo a cui punta 'p' viene incrementato qui
        cout << *p << " ";
    }
    cout << endl;

    // inizializza un array con valori passati da terminale
    int     c[ 4 ];
    cout << "Scrivi quattro numeri:" << endl;
    for ( int i = 0; i < 4; ++i ) {
        cin >> *( c + i );                  // uguale a scrivere b[ i ]
    }

    cout << "Ultimo elemento di 'b': " << ultimo1( b, 3 ) << endl;
    cout << "Ultimo elemento di 'b': " << ultimo2( b, 3 ) << endl;

    int     *d  = def_arr( 79, 56 );
    cout << "Elementi di 'd': " << d[ 0 ] << ", " << d[ 1 ] << endl;

    return 0;
}