/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Puntatori e funzioni
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;


// funzione con argomento passato per valore (pass-by-value)
void incr1( int n ) {
    ++n;
}

// funzione con argomento passato per riferimento (pass-by-reference)
void incr2( int &n ) {
    ++n;
}

// funzione per scambiare due valori
void swap1( int &n1, int &n2 ) {
    int tmp = n1;
    n1      = n2;     
    n2      = tmp;
}

// funzione per scambiare due valori usando puntatori
void swap2( int *n1, int *n2 ) {
    int tmp = *n1;
    *n1     = *n2;     
    *n2     = tmp;
}


int     vr;     // variabile globale
// funzione che restituisce per riferimento (return-by-reference)
int& get_vr() {
    return vr;
}


int main() {
    int num     = 3;
    cout << "num = " << num << endl;

    incr1( num );                       // non ha effetto
    cout << "Dopo incr1(), num = " << num << endl;

    incr2( num );                       // 'num' viene incrementato
    cout << "Dopo incr2(), num = " << num << "\n\n";

    int a       = 71;
    int b       = 17;

    cout << "Prima:\ta = " << a << ", b = " << b << endl;
    swap1( a, b );                      // passa le variabili alla funzione
    cout << "Dopo:\ta = " << a << ", b = " << b << "\n\n";

    cout << "Prima:\ta = " << a << ", b = " << b << endl;
    swap2( &a, &b );                    // passa gli indirizzi alla funzione
    cout << "Dopo:\ta = " << a << ", b = " << b << "\n\n";

    vr          = 43;
    cout << "vr = " << vr << endl;
    get_vr()    = 5;    // la funzione restituisce un riferimento alla variabile globale 'vr'
    cout << "vr = " << vr << endl;


    return 0;
}