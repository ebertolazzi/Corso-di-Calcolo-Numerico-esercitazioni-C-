/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Array
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;


int main() {
    int     a[ 6 ]  = { 10, 20, 140, 6, 3843, 101 };    // array di 6 interi
    double  b[]     = { 0.1, 0.38563, 12.9 };           // array di 3 decimali
    int     c[ 10 ];                                    // array di 10 interi

    int     d[ 2 ] [ 3 ]    = { { 1, 2, 3 }, { 11, 22, 33 } };  // array bidimensionale, 2 righe, 3 colonne

    cout << "Il primo elemento di 'a' e` " << a[ 0 ] << endl;   // il primo elemento ha indice 0
    cout << "L'ultimo elemento di 'a' e` " << a[ 5 ] << endl;

    // 'a' contiene solo 6 numeri
    // se si prova ad accedere al 38esimo elemento di 'a', non avviene nessun errore del tipo "array out of bounds"
    // si genera solo un warning, e viene stampato un numero indefinito
    /*
    cout << "Numero misterioso: " << a[ 38 ] << endl;
    */

    // 'c' non e` stato inizializzato
    // il compilatore avra` assegnato dei valori random oppure 0
    cout << "Numero misterioso: " << c[ 4 ] << endl;

    for ( int i = 0; i < 10; ++i ) {
        c[ i ]  = i * ( i + 1 );        // assegna valori ad ogni elemento dell'array
    }
    cout << "Numero non piu` misterioso: " << c[ 4 ] << endl;   // c[ 4 ] = 3 * 4

    // questo tipo di loop chiamato "ranged for" si usa specificatamente con gli array e i vettori
    // ---> NOTA: il ranged for e` disponibile con lo standard C++11 <---
    for ( int val : c ) {
        cout << val << " ";             // ad ogni iterazione, 'val' corrisponde ad un elemento dell'array
    }
    cout << endl;

    // versione piu` efficiente del ranged for scritto sopra
    // anziche` copiare ad ogni passo gli elementi di 'c', 'val' adesso e` un riferimento agli elementi di 'c'
    // inoltre, dato che non si vuole modificare gli elementi di 'c', i riferimenti possono essere delle costanti
    /*
    for ( const int &val : c ) {
        cout << val << " ";
    }
    cout << endl;
    */

   // loop su un array bidimensionale
    for ( int r = 0; r < 2; ++r ) {         // itera sulle righe
        for ( int c = 0; c < 3; ++c ) {     // itera sulle colonne
            cout << d[ r ][ c ] << " ";
        }
        cout << endl;
    }

    return 0;
}