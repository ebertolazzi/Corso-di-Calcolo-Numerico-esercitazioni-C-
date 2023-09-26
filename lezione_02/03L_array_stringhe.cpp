/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Array e stringhe
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <cstring>
using namespace std;


// una funzione che prende come parametro un array di char (non e` necessario passare la lunghezza dell'array)
void stampa( char *c ) {
    cout << "Hai scritto: " << c << endl;
}

// overloading della funzione sopra che prende come parametro un oggetto string
void stampa( string c ) {
    cout << "Hai scritto: " << c << endl;
}

int main() {

    // ===== ARRAY DI CHAR =====

    char    str1[]      = { 'C', 'i', 'a', 'o', '!', '\0' };
    char    str2[]      = "Ciaooo!!";
    int     arr[]       = { 10, 20, 140, 6, 3843, 101 };

    cout << "Questo e` l'indirizzo del primo elemento di un array numerico: " << arr << endl;
    cout << "Questa invece e` una stringa: " << str1 << endl;
    cout << "Anche questa: " << str2 << endl;   // in questo caso gli array di char vengono interpretati come stringhe

    char    s[ 50 ];
    cout << "Scrivi qualcosa: ";

    // in questo caso il carattere spazio ' ' verrebbe interpretato come carattere di termine
    /*
    cin >> s;
    */
    // pertanto se si vuole accettare una stringa composta da piu` parole meglio usare la funzione get()
    cin.get( s, 50 );

    // svuota il buffer di cin
    cin.clear();
    fflush( stdin );

    stampa( s );
    cout << endl;


    // ===== OGGETTI STRING =====

    string  ss      = "Bla bleu bu";
    cout << ss << endl;

    string  zz;
    cout << "Scrivi qualcos'altro: ";
    getline( cin, zz );                     // per assegnare ad una stringa l'input da terminale
    stampa( zz );

    char    w[]     = "Bello";
    /*
    w               = "Bellissimo";         // questo causa un errore, come per un array di tipo qualsiasi
    */
    strcpy( w, "Bellissimo" );              // si puo` pero` usare la funzione strcpy() definita in <cstring>
    cout << w << endl;

    // con gli oggetti string e` invece possibile riassegnare direttamentela variabile
    string  ww      = "Bello";
    ww              = "Bellissimissimo";
    cout << ww << endl;

    return 0;
}