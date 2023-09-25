/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Controllo del flusso di esecuzione - Loop
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

int main() {
    // ===== FOR =====

    // alla prima iterazione del loop, crea un intero 'i' uguale ad 1
    for ( int i = 1; i <= 5; ++i ) {
        // ad ogni iterazione, stampa il valore di 'i'
        cout << i << endl;
        // al termine di ogni iterazione, incrementa 'i' di 1
    }   // se la condizione ( i <= 5 ) e` ancora vera, esegue una nuova iterazione
    cout << endl;

    // questa istruzione causa un errore, poiche` la variabile 'i' e` definita
    // all'interno del for, e al di fuori delle sue parentesi {} non esiste piu`
    /*
    i   = 10;
    */


    // ===== WHILE =====

    int i   = 0;                // la 'i' e` inizializzata fuori dal while
    while ( i <= 50 ) {         // se la condizione e` vera, inizia una nuova iterazione
        cout << i << endl;      // stampa il valore ad ogni iterazione
        i   += 10;              // incrementa 'i' al termine di ogni iterazione
    }
    cout << endl;

    // un altro modo equivalente
    int j   = 0;
    while ( true ) {            // la condizione del while e` sempre vera quindi inizia sempre una nuova iterazione
        if ( j > 50 ) {
            break;              // se 'j' ha superato 50, "rompe" il loop ed esce fuori dal while
        }
        cout << j << endl;      // se invece 'j' e` ancora <= 50 esegue l'iterazione normalmente
        j   += 10;
    }
    cout << endl;


    // ===== DO-WHILE =====

    int k   = 9;

    // in questo caso l'iterazione viene eseguita prima di controllare se la condizione e` vera
    do {
        // salta i numeri dispari
        if ( ( k % 2 ) != 0 ) {     // se 'k' e` dispari...
            --k;                    // ...decrementa e...
            continue;               // ...passa direttamente alla prossima iterazione
        }
        cout << k << endl;
        --k;
    }
    while ( k > 0 );
    cout << endl;


    // esempio di loop infinito; l'esecuzione di questo programma non terminerebbe mai
    /*
    int h   = 0;
    while ( h <= 9 ) {
        // salta il numero 4
        if ( h == 4 ) {
            continue;   // passa alla prossima iterazione senza modificare il valore di 'h'
        }
        cout << h << endl;
        ++h;
    }
    cout << endl;
    */

    return 0;
}