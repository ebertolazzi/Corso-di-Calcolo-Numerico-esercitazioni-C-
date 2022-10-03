/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Esempio: calcola il fattoriale di un numero
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

int main() {
    int     n;
    cout << "Calcola il fattoriale del seguente numero: ";
    cin >> n;

    int     fact    = 1;        // variabile che mantiene il risultato parziale

    // se il numero passato da terminale e` negativo
    if ( n < 0 ) {
        cout << "Errore! Il fattoriale di un numero negativo non esiste" << endl;
        exit( 0 );              // termina il programma
    }

    // il primo elemento del fattoriale e` 1
    cout << "Il risultato e` " << n << "! = 1";

    // moltiplica la variabile 'fact' per i numeri da 1 a n
    for ( int i = 2; i <= n; ++i ) {
        fact    *= i;
        cout << " * " << i;     // stampa i prodotti
    }
    // al termine del for, 'fact' contiene il risultato
    cout << " = " << fact << endl;

    return 0;
}