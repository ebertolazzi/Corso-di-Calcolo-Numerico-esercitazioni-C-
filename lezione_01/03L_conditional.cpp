/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Controllo del flusso di esecuzione - Condizionali
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

int main() {
    // ===== IF-ELSE =====

    // riceve un intero da command line
    int n;
    cout << "Digita un numero intero: ";
    cin >> n;

    // controlla se il numero e` positivo, negativo, o uguale a zero
    if ( n > 0 ) {
        // questa istruzione viene eseguita solo se la condizione ( n > 0 ) e` vera
        cout << "Il numero e` positivo" << endl;

        // e` possibile annidare piu` if uno dentro l'altro
        if ( ( n % 2 ) == 0 ) {
            // questa istruzione viene eseguita solo se le condizioni
            // ( n > 0 ) e ( ( n % 2 ) == 0 ) sono entrambe vere
            cout << "Il numero e` pari" << endl;
        }
        else {
            // questa istruzione viene eseguita solo se la condizione ( n > 0 ) e` vera
            // e la condizione ( ( n % 2 ) == 0 ) e` falsa
            cout << "Il numero e` dispari" << endl;
        }
    }
    else if ( n == 0 ) {
        // questa istruzione viene eseguita solo se la condizione ( n > 0 ) e` falsa
        // e la condizione ( n = 0 ) e` vera
        cout << "Il numero e` uguale a zero" << endl;
    }
    else {
        // questa istruzione viene eseguita solo se sia ( n > 0 ) e ( n == 0 ) sono false
        cout << "Il numero e` negativo" << endl;
    }
    cout << endl;


    // ===== SWITCH =====
    // si preferisce usare lo switch quando bisogna scegliere cosa eseguire tra un insieme di alternative

    char    o;
    cout << "Scegli tra A, B, o C: ";   // riceve un char da command line
    cin >> o;

    switch ( o ) {                      // chiama lo switch sulla base del valore di 'o'
        case 'A':
            // questa istruzione viene eseguita se ( o == 'A' )
            cout << "Hai scelto A" << endl;
            break;
        case 'B':
            // questa istruzione viene eseguita se ( o == 'B' )
            cout << "Hai preferito B, ottima scelta!" << endl;
            break;
        case 'C':
            // questa istruzione viene eseguita se ( o == 'C' )
            cout << "C e` la tua scelta" << endl;
            break;
        default:
            // questa istruzione viene eseguita se nessuna delle precedenti condizioni e` verificata
            cout << "Non hai scelto nessuna delle tre!" << endl;
    }

    return 0;
}