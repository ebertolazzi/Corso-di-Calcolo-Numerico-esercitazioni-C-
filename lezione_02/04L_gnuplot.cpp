/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Scrivere dati per gnuplot
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define N       20
#define D       0.2
#define PREC    3


int main() {
    // crea una stringa da stampare su file come titolo e descrizione
    // i commenti in gnuplot si indicano col simbolo '#'
    string      head        = "# --------------------------\n";
    head                   += "# data generated for gnuplot\n";
    head                   += "# --------------------------\n";
    
    // due file su cui scrivere
    string      fname1      = "output1.txt";
    string      fname2      = "output2.txt";
    ofstream    f1( fname1 );
    ofstream    f2( fname2 );

    double      *x      = new double[ N ];
    double      *y      = new double[ N ];
    double      *z      = new double[ N ];
    x[ 0 ]      = 0;
    y[ 0 ]      = 0;
    z[ 0 ]      = 0;

    for ( int i=0; i<N; ++i ) {
        x[ i ]      = i * D;
        y[ i ]      = 0.1 * x[ i ] + 0.5 * sin( x[ i ] );
        z[ i ]      = ( y[ i ] - y[ i - 1 ] ) / D;
    }

    f1 << fixed << setprecision( PREC );
    f2 << fixed << setprecision( PREC );
    f1 << head;
    f2 << head;

    // scrive una colonna di valori nel primo file
    for ( int i=0; i<N; ++i ) {
        f1 << y[ i ] << endl;
    }
    f1.close();     // chiude il file di stream

    // scrive tre colonne di valori nel secondo file
    for ( int i=0; i<N; ++i ) {
        f2 << x[ i ] << "\t" << y[ i ] << "\t" << z[ i ] << endl;
    }
    f2.close();     // chiude il file di stream

    return 0;
}