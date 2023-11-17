// Date 2 matrici A e B costruire le matrici C e D che mescolano le matrici A e B come segue:
//
// A = | 1  2 |   B = | 5  6 |
//     | 3  4 |       | 7  8 |
//
// risultato
//
// C = | 1  6 |   D = | 5  2 |
//     | 7  4 |       | 3  8 |
//
// Cioè:
// - La matrice C contiene gli elementi A con i+j pari e gli elementi B con i+j dispari.
// - La matrice D contiene gli elementi A con i+j dispari e gli elementi B con i+j pari.
//
// Le matrici devono essere compatibili cioè avere lo stesso numero di righe e di colonne.
// La funzione ha il seguente prototipo:
//
// typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
// void checkboard( MatrixXd const & A, MatrixXd const & B, MatrixXd & C, MatrixXd & D );
//
// Esempio: date le matrici
// A = |1|    B = |11|
//     |2|        |22|
//
// checkboard( A, B, C, D );
//
// ritorna le matrici:
//
// C = | 1|  D = |11|
//     |22|      | 2|
//
// Matrici da usare come possibile test:
//
// A = |1  4  7  10|    B = |1   6  7  12|
//     |2  5  8  11|        |1   5 -9  11|
//     |3  6  9  12|        |3   4  9  10|
//     |1 -6 -9 -12|        |2  -6  8 -12|

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

void checkboard(MatrixXd const &A, MatrixXd const &B, MatrixXd &C, MatrixXd &D)
{
  if (A.rows() != B.rows() || A.cols() != B.cols())
  {
    cout << "Matrici non compatibili" << endl;
    return;
  }

  C.resize(A.rows(), A.cols());
  D.resize(A.rows(), A.cols());

  for (int i = 0; i < A.rows(); i++)
  {
    for (int j = 0; j < A.cols(); j++)
    {
      if ((i + j) % 2 == 0)
      {
        C(i, j) = A(i, j);
        D(i, j) = B(i, j);
      }
      else
      {
        C(i, j) = B(i, j);
        D(i, j) = A(i, j);
      }
    }
  }
}

int main()
{
  MatrixXd A(2, 2);
  A << 1, 2,
      3, 4;

  MatrixXd B(2, 2);
  B << 5, 6,
      7, 8;

  //MatrixXd A(4, 4);
  //A << 1, 4, 7, 10,
  //     2, 5, 8, 11,
  //     3, 6, 9, 12,
  //     1, -6, -9, -12;

  //MatrixXd B(4, 4);
  //B << 1, 6, 7, 12,
  //     1, 5, -9, 11,
  //     3, 4, 9, 10,
  //     2, -6, 8, -12;

  MatrixXd C, D;

  checkboard(A, B, C, D);

  cout << "C = " << endl << C << endl;
  cout << "D = " << endl << D << endl;

  return 0;
}
