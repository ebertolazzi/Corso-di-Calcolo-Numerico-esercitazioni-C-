/*
(1) Generare delle MatrixXi "A" di dimensioni R^{2n x 2m} con elementi randomici
    interi. Provare con n = 1, 3, 6 e m = 5, 6, 7.
(2) Generare una matrice "Q" R^{2 x 2} a piacere.
(3) Moltplicare le matrici create in (1) con quela creata in (2) blocco a blocco
    e creare una matrice R^{2n x 2m} in output
*/

#include <iostream>
#include <Eigen/Dense>

// (3)
void block_matrix_multiplication(
  Eigen::MatrixXi &A,
  Eigen::MatrixXi &Q,
  Eigen::MatrixXi &B
)
{
  for (int i = 0; i < A.rows(); i += Q.rows())
  {
    for (int j = 0; j < A.cols(); j += Q.cols())
    {
      B.block(i, j, Q.rows(), Q.cols()) = A.block(i, j, Q.rows(), Q.cols()) * Q;
    }
  }
}

int main()
{
  double n = 6; // 1, 3, 6
  double m = 7; // 5, 6, 7

  // (1)
  Eigen::MatrixXi A = Eigen::MatrixXi::Random(2 * n, 2 * m);
  std::cout << "A = \n" << A << std::endl;

  // (2)
  Eigen::MatrixXi Q = Eigen::MatrixXi::Random(2, 2);
  std::cout << "Q = \n" << Q << std::endl;

  // (3)
  Eigen::MatrixXi B = Eigen::MatrixXi::Zero(2 * n, 2 * m);
  block_matrix_multiplication(A, Q, B);
  std::cout << "B = \n" << B << std::endl;

  return 0;
}
