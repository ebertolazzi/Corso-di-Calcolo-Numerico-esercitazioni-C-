/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2023/24)                  Alice Plebe

    Classi e oggetti
\* --------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;


// classe chiamata 'Wallet' per tenere insieme variabili e funzioni che gestiscono il portafoglio di una persona
class Wallet {
    public:
        double  money;                  // attributo pubblico che mantiene la quantita` di denaro

        void earn( double m ) {         // metodo pubblico per indicare l'aumento di denaro
            money   += m;
        }

        void spend( double m ) {        // metodo pubblico per indicare la diminuzione di denaro
            money   -= m;
        }

};      // attenzione serve il punto e virgola


// versione migliore della classe precedente
class SafeWallet {
    private:
        // stavolta l'attributo e` privato, quindi non accessibile/modificale al di fuori della classe
        double  money;

    public:
        // costruttore della classe per inizializzare l'attributo 'money'
        SafeWallet( double m ) {
            money   = m;
        }

        // il valore di 'money' puo` essere ottenuto al di fuori della classe solo tramite questo metodo
        double get_money() {
            return money;
        }

        // 'money' puo` essere incrementato solo tramite questo metodo
        void earn( double m ) {
             if ( m < 0 ) {
                cout << "ATTENTIONE! Non puoi guadagnare una quantita` negativa" << endl;
                return;
            }
            money   += m;
        }

        // 'money' puo` essere decrementato solo tramite questo metodo
        void spend( double m ) {
            if ( m > money ) {
                cout << "ATTENTIONE! Non hai abbastanza denare da spendere" << endl;
                return;
            }
            money   -= m;
        }
};


int main() {
    Wallet  w_alice;                    // crea l'oggetto 'w_alice' della classe 'Wallet'
    w_alice.money       = 2600.40;      // imposta l'attributo 'money'
    w_alice.earn( 500 );                // chiama il metodo earn() che incrementa 'money'
    w_alice.spend( 34.71 );             // chiama il metodo spend() che decrementa 'money'
    cout << "Alice possiede " << w_alice.money << " euro" << endl;

    // essendo 'money' un attributo public, e` sempre accessibile/modificabile al di fuori della classe
    w_alice.money       = 43.05;

    // crea l'oggetto chiamando il costruttore della classe
    // allo stesso tempo inizializza l'attributo 'money' col valore passato
    SafeWallet  sw_alice( 1098.35 );

    // questo causa un errore poiche` 'money' e` un attributo privato nella classe SafeWallet...
    /*
    cout << sw_alice.money << endl;
    */
    // ...bisogna invece chiamare il metodo get_money()
    cout << "Alice possiede al sicuro " << sw_alice.get_money() << " euro" << endl;

    return 0;
}