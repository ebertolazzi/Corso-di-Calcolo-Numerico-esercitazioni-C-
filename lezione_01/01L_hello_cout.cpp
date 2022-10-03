/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                  Alice Plebe

    Primo programma "Hello World"
\* --------------------------------------------------------------------------------- */

// include la header della Standard Library chiamata "iostream"
// per stampare in output dal terminale
#include <iostream>

// l'esecuzione di ogni programma parte dalla funzione chiamata "main"
int main() {
    // gli oggetti "cout" e "endl" definiti in <iostream> appartengono al namespace chiamato "std"
    std::cout << "Hello there geeks!" << std::endl;
    // oltre alla sintassi '::' e` possibile indicare il namespace esplicitamente (VEDI main SOTTO)

    // al termine del main, il programma restituisce 0 per indicare 
    // al sistema operativo che l'esecuzione e` terminata correttamente
    return 0;
}

// Un modo alternativo di indicare l'uso di un namespace e` tramite keyword "using"
/*
#include <iostream>
using namespace std;        // indica di usare il namespace std

int main() {
    // adesso "cout" e "endl" non hanno piu` bisogno del prefisso "std::"
    cout << "Hello there geeks!" << endl;
    return 0;
}
*/