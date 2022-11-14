/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Integrazione adattativa metodo dei trapezi
\* --------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;

#define         PREC        4
#define         MAX_ITER    10000
#define         N_POINTS    100
#define         ANIM        0           // genera plot 1=animato o 0=statico

int	            n_iter      = 0;        // counter per il numero di iterazioni eseguite
const string    head        = "# --------------------------\n# data generated for gnuplot\n# --------------------------\n";
const string	fname       = ANIM ? "plot_anim.txt" : "plot_data.txt";


/*-----------------------------------------------------------------------------------*\
    formula dei trapezi
        a:  estremo iniziale dell'intervallo di integrazione
        b:  estremo finale dell'intervallo di integrazione
        f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/
float trapez( float a, float b, float ( *f )( float x ) ) {
    float   m   = ( a + b ) / 2.;
    float   s   = f( a ) + 2. * f( m ) + f( b );
    return ( b - a ) * s / 4. ;
}


/*-----------------------------------------------------------------------------------*\
    formula del midpoint
        a:  estremo iniziale dell'intervallo di integrazione
        b:  estremo finale dell'intervallo di integrazione
        f:  funzione da integrare
\*-----------------------------------------------------------------------------------*/
float midpoint( float a, float b, float ( *f )( float x ) ) {
    float   d   = b - a;
    float   s   = f( a ) + f( b );
    return d * s / 2. ;
}


/*-----------------------------------------------------------------------------------*\
    algoritmo completo
        a:  estremo iniziale dell'intervallo di integrazione
        b:  estremo finale dell'intervallo di integrazione
        f:  funzione da integrare
        e:  massimo errore concesso
\*-----------------------------------------------------------------------------------*/
float adapt( float a, float b, float ( *f )( float x ), float e, ofstream &o ) {
    n_iter++;
    float   i1  = midpoint( a, b, f );
    float   i2  = trapez( a, b, f );
    float   m   = ( b + a ) / 2.;

    // oltre al criterio dell'errore vi e` anche un numero massimo di iterazioni consentite
    if( n_iter > MAX_ITER ) {
        return i2;
    }

    // termina la ricorsione se l'errore e` sotto la soglia
    if( ( abs( i2 - i1 ) / 3. ) < e ) {
        return i2;
    }

    if ( ANIM ) {
        o << "\n\n";                    // due righe vuote in gnuplot separano set di dati
    }
    o << m << "\t" << f( m ) << endl;   // scrive il nuovo intervallo nel file per il plot

    // esegue le chiamate ricorsive
    i1	= adapt( a, m, f, e / 2., o );
    i2	= adapt( m, b, f, e / 2., o );

    return i1 + i2;
}


/*-----------------------------------------------------------------------------------*\
    wrapper per scrivere i dati su file per gnuplot
\*-----------------------------------------------------------------------------------*/
float do_adapt( float a, float b, float ( *f )( float x ), float e ) {
    float   dx      = ( b - a ) / N_POINTS;
    float   res;

    ofstream	o( fname );     // stream di uscita
    o << head;                  // scrive la header
    o.precision( PREC );        // imposta la precisione

    // scrive prima i dati della funzione da integrare
    for( float x=a; x<b; ){
        o << x << "\t" << f( x ) << endl;
        x	+= dx;
    }
    o << "\n\n";                // due righe vuote in gnuplot separano set di dati

    // scrive i due estremi dell'intervallo complessivo
    o << a << "\t" << f( a ) << endl;
    o << b << "\t" << f( b ) << endl;

    res     = adapt( a, b, f, e, o );

    o.close();
    return res;
}


/*-----------------------------------------------------------------------------------*\
    Un paio di funzioni per testare l'algoritmo
\*-----------------------------------------------------------------------------------*/
// intervallo testato:              0.1, 2
// valore esatto dell'integrale:    0.464148
float fun1( float x ) {
    return sin( exp( x ) );
}

// intervallo testato:              -0.5, 1.3
// valore esatto dell'integrale:    5.29561
// (funzione di Legendre di primo tipo e ordine 9 leggermente modificata)
float fun2( float x ) {
    float x2    = x * x;
    float x4    = x2 * x2;
    float x6    = x2 * x4;
    float x8    = x4 * x4;
    return 3 + x * ( 1.1 - 18 * x2 + 72 * x4 - 102 * x6 + 42 * x8 );
}

// intervallo testato:              1, 3
// valore esatto dell'integrale:    4.32938
// (funzione inventata a caso)
float fun3( float x ) {
    float   s   = sin( x * x );
    return 0.1 + x * ( 0.5 + 0.2 / ( 0.1 + s * s ) );
}

/*-----------------------------------------------------------------------------------*/

int main() {
    float   y;
    float   e   = 0.001;

    // float   a   = 0.1;
    // float   b   = 2;
    // y           = do_adapt( a, b, fun1, e );

    // float   a   = -0.5;
    // float   b   = 1.3;
    // y           = do_adapt( a, b, fun2, e );

    float   a   = 1;
    float   b   = 3;
    y           = do_adapt( a, b, fun3, e );

    cout << "Integrale approssimato tra " << a << " e " << b << ":\t";
    cout << y << endl;
    cout << "usando " << n_iter << " iterazioni" << endl;

    return 0;
}