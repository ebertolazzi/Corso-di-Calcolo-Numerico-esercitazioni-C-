/*
(1) Generare delle MatrixXi "A" di dimensioni R^{n x m} con elementi randomici
    interi. Provare con n = 2, 5, 10 e m = 3, 6, 9.
(2) Generare una matrice "Q" R^{p x r} a piacere. Provare con p = 2, 3, 4 e
    r = 2, 3, 4.
(3) Moltplicare le matrici create in (1) con quela creata in (2) nel seguente
    modo:
    - data A, trovare tutti i blocchi di dimensioni p x r e sommarli a Q
    - ogni elemento di A che non è contenuto in un blocco di dimensioni p x r
      va invertito di segno
    - se A non ha nessun elemento che non è contenuto in un blocco di dimensioni
      p x r, allora invertire il segno di tutti gli elementi di A
    - salvare questo risultato in una matrice "B"
*/

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

void special_multiply(MatrixXi &A, MatrixXi &Q, MatrixXi &B) {
  // Inizializziamo la matrice B
  B = A;

  // Se A ha dimensioni minori di Q, allora cambiamo il segno di tutti gli
  // elementi di A
  if (A.rows() < Q.rows() || A.cols() < Q.cols()) {
    B = -A;
    return;
  }

  // Sommiamo tutti i blocchi di dimensioni Q.rows() x Q.cols() di A a Q
  for (int i = 0; i < A.rows() - Q.rows() + 1; i += Q.rows()) {
    for (int j = 0; j < A.cols() - Q.cols() + 1; j += Q.cols()) {
      B.block(i, j, Q.rows(), Q.cols()) += Q;
    }
  }

  // Invertiamo il segno di tutti gli elementi di A che non sono contenuti in
  // un blocco di dimensioni Q.rows() x Q.cols()
  int remaining_rows = A.rows() % Q.rows();
  int remaining_cols = A.cols() % Q.cols();
  for (int i = A.rows() - remaining_rows; i < A.rows(); ++i) {
    B.row(i) = -A.row(i);
  }
  for (int j = A.cols() - remaining_cols; j < A.cols(); ++j) {
    B.col(j) = -A.col(j);
  }

  return;
}

int main()
{
  double n = 2; // 2, 5, 10
  double m = 3; // 3, 6, 9
  double p = 2; // 2, 3, 4
  double r = 2; // 2, 3, 4

  // (1)
  MatrixXi A = MatrixXi::Random(n, m);

  cout << "A = \n" << A << endl;

  // (2)
  MatrixXi Q = MatrixXi::Random(p, r);

  cout << "Q = \n" << Q << endl;

  // (3)
  MatrixXi B;
  special_multiply(A, Q, B);
  cout << "B = \n" << B << endl;

  return 0;
}
