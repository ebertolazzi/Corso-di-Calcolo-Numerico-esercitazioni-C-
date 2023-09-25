/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Puntatori
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

int main() {
    int     a   = 34;
    double  b   = 0.192;
    float   c   = 98.2;

    // l'operatore '&' restituisce l'indirizzo di una variabile in memoria
    cout << "L'indirizzo in esadecimale di 'a' e` " << &a << endl;
    cout << "L'indirizzo in esadecimale di 'b' e` " << &b << endl;
    cout << "L'indirizzo in esadecimale di 'c' e` " << &c << "\n\n";

    // gli indirizzi di memoria possono essere assegnati a variabili chiamate puntatori (pointers)
    // i puntatori vanno indicati col simbolo '*'
    int     *pa;
    pa      = &a;       // la variabile 'pa' contiene l'indirizzo di memoria di 'a'

    // l'operatore '*' restituisce il valore puntato dall'indirizzo contenuto in 'pa'
    cout << "*pa corrisponde a " << *pa << endl;    // che e` uguale ad 'a'
    cout << "pa corrisponde a " << pa << "\n\n";    // che e` uguale a '&a'

    // modificando il valore puntato da 'pa', si modifica anche la variabile 'a'
    *pa     = 4;
    cout << "Adesso 'a' vale: " << a << endl;

    // modificando la variabile 'a', si modifica anche il valore puntato da 'pa'
    a       = 94835;
    cout << "Adesso '*pa' vale: " << *pa << endl;


    return 0;
}