/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Template
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

const int   LEN     = 10;


// crea una funzione template chiamata 'insieme' dove 'Tipo1' e 'Tipo2' sono
// dei segnaposti che indicato i tipi (non specificati) dei parametri
template <class Tipo1, class Tipo2>
void insieme( Tipo1 a, Tipo2 b ) {
    cout << "Ecco insieme due variabili di tipo diverso: " << a << " e " << b << endl;
}


// crea una classe template chiamata 'Piramide' dove 'Tipo' e` un segnaposto
// che indica il tipo di dato (non specificato) usato all'interno della classe
template <class Tipo>
class Piramide {
    private:
        Tipo    arr[ LEN ];     // un array di dati 'Tipo' di lunghezza 'LEN'

    public:
        // inizializza l'attributo 'arr' con l'array passato come parametro (in forma di puntatore)
        Piramide( Tipo *p ) {
            for ( int i=0; i<LEN; ++i ) {
                arr[ i ]    = p[ i ];
            }
        }

        // stampa a terminale la piramide
        void print_piram() {
            cout << "   " << arr[ 0 ] << "   " << endl;
            cout << "  " << arr[ 1 ] << " " << arr[ 2 ] << "  " << endl;
            cout << " " << arr[ 3 ] << " " << arr[ 4 ] << " " << arr[ 5 ] << " " << endl;
            cout << arr[ 6 ] << " " << arr[ 7 ] << " " << arr[ 8 ] << " " << arr[ 9 ] << endl;
        }
};


int main() {
    double  v1  = 0.3753;
    string  v2  = "!@#$";
    insieme( v1, v2 );

    // crea un oggetto 'Piramide' che usa numeri interi
    int             int_arr[ LEN ]  = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Piramide<int>   int_pir( int_arr );
    int_pir.print_piram();

    // crea un oggetto 'Piramide' che usa caratteri
    char            chr_arr[ LEN ]  = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    Piramide<char>  chr_pir( chr_arr );
    chr_pir.print_piram();

    // crea un oggetto 'Piramide' che usa valori booleani
    bool            bol_arr[ LEN ]  = { true, false, false, true, true, true, false, false, false, false };
    Piramide<bool>  bol_pir( bol_arr );
    bol_pir.print_piram();

    return 0;
}