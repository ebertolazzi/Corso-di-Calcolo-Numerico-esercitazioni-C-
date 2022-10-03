/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Esempio: serie di Fibonacci con costrutti for e while
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

// ESERCIZIO 1: Stampa la serie di Fibonacci fino al numero N
int main() {
    int n;              // massimo numero della serie da non superare
    int term_1  = 0;    // primo termine della serie
    int term_2  = 1;    // secondo termine della serie
    int term_s;         // variabile di supporto per calcolare il termine successivo

    // chiede da terminale di digitare il valore di N
    cout << "Inserisci il numero massimo da raggiungere: ";
    cin >> n;

    cout << "Serie di Fibonacci: ";
    cout << term_1;                 // stampa fuori dal loop il primo termine della serie
    term_s  = term_1 + term_2;      // aggiorna il termine successivo

    // usiamo un loop while poiche` non sappiano in anticipo il numero di iterazioni
    // da compiere per raggiungere il valore N
    while ( term_s <= n ) {
        cout << ", " << term_s;     // stampa ad ogni iterazione il termine successivo

        term_s  = term_1 + term_2;  // aggiorna i valori dei termini correnti
        term_1  = term_2;
        term_2  = term_s; 
    }
    cout << endl;

    return 0;
}

// ESERCIZIO 2: Stampa i primi N termini della serie di Fibonacci
/* (per eseguire questa parte, decommenta questo main e commenta il main precedente)
int main() {
    int n;              // numero di termini della serie da stampare
    int term_1  = 0;    // primo termine della serie
    int term_2  = 1;    // secondo termine della serie
    int term_s;         // variabile di supporto per calcolare il termine successivo

    // chiede da terminale di digitare il valore di N
    cout << "Inserisci il numero di termini da visualizzare: ";
    cin >> n;

    // usiamo un loop for poiche` il numero di iterazioni da compiere
    // e` definito dal valore N
    for ( int i = 1; i <= n; ++i ) {
        if ( i==1 ) {                   // alla prima iterazione del loop...
            cout << "Serie di Fibonacci: ";
            cout << term_1;             // ...stampa solo il primo termine...
            continue;                   // ...e passa direttamente alla prossima iterazione
        }
        if ( i==2 ) {                   // alla seconda iterazione del loop...
            cout << ", " << term_2;     // ...stampa solo il secondo termine...
            continue;                   // ...e passa direttamente alla prossima iterazione
        }
        term_s  = term_1 + term_2;      // aggiorna i valori dei termini correnti
        term_1  = term_2;
        term_2  = term_s;

        cout << ", " << term_s;         // stampa ad ogni iterazione il termine successivo
    }
    cout << endl;

    return 0;
}
*/
