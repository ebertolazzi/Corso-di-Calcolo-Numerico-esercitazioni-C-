// Data una matrice (dim = m x n) di tipo MatrixXd e un vettore VectorXd (dim = n)
// calcolare l'output che consiste nella moltiplicazione elemento per elemento del
// vettore con ogni riga della matrice

//     |1, 2, 3|
// A = |4, 5, 6|   V = [1, 2, 3]
//     |7, 8, 9|

//     |1,  4,  9|
// B = |4, 10, 18|
//     |7, 16, 27|

// Parte 2: dividere ogni colonna di A per la sua norma utilizzando le funzioni
// Eigen

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

void my_fun(const MatrixXd & A, const VectorXd & V, MatrixXd & B){
  // Inizializzamo B
  B = A;

  // Verifichiamo che le dimensioni siano corrette
  if (A.cols() != V.size()){
    cout << "Size not adequate!" << endl;
    return;
  }

  // Calcoliamo B, senza convertire ad Array
  for (int i = 0; i < A.rows(); ++i) {
    for (int j = 0; j < A.cols(); ++j) {
      B(i,j) = A(i,j) * V(j);
    }
  }

  // Alternativa: convertiamo ad Array e poi torniamo a Matrix
  // B = (A.array().rowwise() * V.transpose().array()).matrix();

  // Normalizziamo le colonne di B
  for (int k = 0; k < B.cols(); ++k) {
    B.col(k).normalize();
  }
}

int main(void){
  VectorXd V(3);
  MatrixXd A(3,3);
  MatrixXd B;

  V << 1, 2, 3;
  A << 1, 2, 3, 4, 5, 6, 7, 8, 9;

  my_fun(A, V, B);

  cout  << "V = \n" << V << endl;
  cout  << "A = \n" << A << endl;
  cout  << "B = \n" << B << endl;

  return 0;
}




