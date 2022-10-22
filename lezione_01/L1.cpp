
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_ROW = 10;
const int MAX_COL = 10;

void
print(
  int m[MAX_ROW][MAX_COL],
  int r,
  int c
)
{
  cout << "Matrix( " << r << "x" << c << ")" << endl;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << m[i][j] << "\t";
    }
    cout << endl;
  }
  
}


int
main(void)
{
  int r = 2;
  int c = 3;
  int mat[MAX_ROW] = {3, 3, 3};

  cout << "mat = " << *(mat+2) << endl;
}