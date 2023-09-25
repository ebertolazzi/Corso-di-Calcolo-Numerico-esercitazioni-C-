/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Funzioni e ricorsione
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <cmath>        // header che contiene funzioni matematiche gia` pronte, come sqrt()
using namespace std;


// definisce una funzione senza argomenti, che non restituisce nulla
void chefunz() {
    cout << "Wow, sto usando una funzione!" << endl;
}

// definisce una funzione con un argomento, che non restituisce nulla
void chenum( int n ) {
    cout << "Che bel numero: " << n << endl;
}

// definisce una funzione con due argomenti, che restituisce un double
double moltip( double a, double b ) {
    return ( a * b );   // restituisce il prodotto tra i due numeri passati come argomento
}

// definisce una funzione con un argomento, che restituisce un double
double radice( double x ) {
    double r    = sqrt( x );        // usa la funzione di libreria sqrt() definita in <cmath>
    cout << "La radice quadrata di " << x << " = " << r << endl;
    return r;
}

// questa e` una funzione ricorsiva che calcola il fattoriale di un numero
int fatt( int n ) {
    if ( n < 0 ) {
        cout << "ERRORE: Avevo chiesto un numero non negativo :(" << endl;
        exit( 1 );                      // termina il programma con un errore
    }
    if ( ( n == 0 ) || ( n == 1 ) ) {
        // senza una condizione di termine, la ricorsione andrebbe avanti all'infinito
        cout << 1 << endl;
        return 1;
    }
    cout << n << " * ";
    return n * fatt( n-1 );             // la funzione chiama se stessa
}


int main() {
    // chiama la funzione
    chefunz();

    int numerello;
    cout << "Dammi un numero: ";
    cin >> numerello;

    // chiama la funzione passando l'argomento
    chenum( numerello );

    // chiama la funzione passando gli argomenti e assegnando il risultato ad una variabile
    double  prod    = moltip( 0.5, 5 );
    double  rd      = radice( 64 );

    int numerino;
    cout << endl << "Scrivi un numero non negativo: ";
    cin >> numerino;
    int f   = fatt( numerino );
    cout << numerino << "! = " << f << endl;

    return 0;
}