/*
(1) Generare delle MatrixXi "A" di dimensioni R^{n x m} con elementi randomici
    interi. Provare con n = 2, 5, 10 e m = 3, 6, 9.
(2) Generare una matrice "Q" R^{p x r} a piacere. Provare con p = 2, 3, 4 e
    r = 2, 3, 4.
(3) Moltplicare le matrici create in (1) con quela creata in (2) nel seguente
    modo:
    - data A, trovare tutti i blocchi di dimensioni p x r e sommarli a Q come
      una scacchiera
    - ogni elemento di A che non è contenuto in un blocco di dimensioni p x r
      va invertito di segno se e solo se era un blocco della scacchiera in cui
      avremmo eseguito la somma se fosse stato delle dimensioni giuste
    - se A non ha nessun elemento che non è contenuto in un blocco di dimensioni
      p x r, allora invertire il segno di tutti gli elementi di A
    - salvare questo risultato in una matrice "B"
*/

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

void special_multiply(const MatrixXi &A, const MatrixXi &Q, MatrixXi &B) {
  // Inizializziamo la matrice B
  B = A;

  // Se A ha dimensioni minori di Q, allora cambiamo il segno di tutti gli
  // elementi di A
  if (A.rows() < Q.rows() || A.cols() < Q.cols()) {
    B = -A;
    return;
  }

  // Sommiamo tutti i blocchi di dimensioni Q.rows() x Q.cols() di A a Q
  int rows_diff = A.rows() - Q.rows();
  int cols_diff = A.cols() - Q.cols();
  bool block_i  = true;
  bool block_j  = true;
  int i         = 0;
  int j         = 0;
  for (i = 0; i < rows_diff + 1; i += Q.rows())
  {
    for (j = 0; j < cols_diff + 1; j += Q.cols())
    {
      if (block_i == block_j)
      {
        B.block(i, j, Q.rows(), Q.cols()) += Q;
      }
      block_j = !block_j;
    }
    if (cols_diff != 0 && block_i == block_j)
    {
      B.block(i, j, Q.rows(), A.cols() - j) *= -1;
    }
    block_j = true;
    block_i = !block_i;
  }
  if (rows_diff != 0)
  {
    for (j = 0; j < cols_diff + 1; j += Q.cols())
    {
      if (block_i == block_j)
      {
        B.block(i, j, A.rows() - i, Q.cols()) *= -1;
      }
      block_j = !block_j;
    }
    if (cols_diff != 0 && block_i == block_j)
    {
      B.block(i, j, A.rows() - i, A.cols() - j) *= -1;
    }
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
  // MatrixXi A = MatrixXi::Random(n, m);
  MatrixXi A(5, 5);
  A << 1, 2, 3, 4, 5, 6, 7, 8, 9,
       1, 2, 3, 4, 5, 6, 7, 8, 9,
       1, 2, 3, 4, 5, 6, 7;

  cout << "A = \n" << A << endl;

  // (2)
  // MatrixXi Q = MatrixXi::Random(p, r);
  MatrixXi Q(2, 2);
  Q << 1, 2, 3, 4;

  cout << "Q = \n" << Q << endl;

  // (3)
  MatrixXi B;
  special_multiply(A, Q, B);
  cout << "B = \n" << B << endl;

  return 0;
}
