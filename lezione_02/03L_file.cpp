/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Scrittura su file
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    string      fname   = "output.txt";     // path del file su cui scrivere
    ofstream    fo( fname );                // oggetto per gestire lo stream di output su file

    int         n1      = 12;
    double      n2      = 0.34;
    double      n3      = 14.9781;

    fo << "n1 = " << n1 << endl;            // la notazione e` simile a quella vista per "cout"
    fo << "n2 = " << n2 << endl;
    fo << "n3 = " << n3 << endl;

    fo << "sine of n2 = " << sin( n2 ) << endl;
    fo << endl;
    fo << fixed << setprecision( 2 );       // imposta la precisione a 2 cifre decimali
    
    fo << "sine of n2 = " << sin( n2 ) << endl;
    fo << "n3 = " << n3 << endl;

    fo.close();                             // chiude lo stream quando la scrittura su file e` terminata
    return 0;
}