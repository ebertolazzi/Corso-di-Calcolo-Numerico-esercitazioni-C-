/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Variabili, data type, e operatori
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

int main() {
    // ===== TIPI DI DATI =====
    int     a       = -13;                          // numero intero
    float   b       = 0.348;                        // numero floating-point
    double  c       = -39.000032;                   // numero decimale
    bool    d       = false;                        // valore vero o falso
    char    e       = '?';                          // singolo carattere

    unsigned int    aa    = 128;                    // numero intero positivo 
    const float     PI      = 3.14159;              // variabile il cui valore non puo` essere modificato
    /*
    PI      = 17;   // questo causerebbe un errore
    */

    // ===== OPERATORI ARITMETICI =====
    double  n1      = 5.43;
    n1              += 10;              // equivale a scrivere n1 = n1 + 10
    n1              *= 2;               // equivale a scrivere n1 = n1 * 2
    n1++;                               // equivale a scrivere n1 = n1 + 1

    // ===== CONVERSIONI DI DATATYPE =====
    double  v1      = 9.74;
    int     v2      = v1;               // la variabile vale 9!
    cout << "I valori di v1 e v2: " << v1 << "  " << v2 << endl;

    double  w1      = 5;
    int     w2      = 5;
    w1              /= 2;               // la variabile vale 2.5
    w2              /= 2;               // la variabile vale 2
    cout << "I valori di w1 e w2: " << w1 << "  " << w2 << endl;
    cout << endl;

    int     z1      = 13;
    double  z2      = ( double ) z1;    // casting da int a double

    // ===== OPERATORI LOGICI =====
    int     m1      = -45;
    int     m2      = 6;
    bool    cond1;
    bool    cond2;

    // 0 = false, 1 = true

    cond1           = ( m1 >= 0 );              // m1 e` maggiore di zero? falso
    cond2           = ( ( m2 % 2 ) == 0 );      // m2 e` pari? vero
    bool b1         = cond1 || cond2;           // almeno una delle due e` vera? si
    bool b2         = cond1 && cond2;           // sono entrambe vere? no
    bool b3         = !cond1;                   // e` vero che la condizione e` falsa? si
    cout << "cond1 OR cond2: " << b1 << endl;
    cout << "cond1 AND cond2: " << b2 << endl;
    cout << "NOT cond1: " << b3 << endl;


    return 0;
}