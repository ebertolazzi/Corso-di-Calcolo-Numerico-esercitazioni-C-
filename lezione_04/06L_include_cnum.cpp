/* --------------------------------------------------------------------------------- *\
    CALCOLO NUMERICO E PROGRAMMAZIONE C++ (AA 2022/23)                Davide Stocco

    Inclusione della libreria cnum
\* --------------------------------------------------------------------------------- */

#include "cnum.h"
#include <iostream>

using namespace std;

using cnum::Real;
using cnum::Integer;

int
main() {
  // Cnum library build on Windows/Mac
  cout
    << endl
    << "BUILD CNUM LIBRARY WITH CMAKE" << endl
    << "mkdir build" << endl
    << "cd build" << endl
    << "Windows/Mac: cmake -G ""Ninja"" .." << endl
    << "Linux/Mac: cmake -G ""Unix Makefiles"" .." << endl
    << endl;

  // Modifications for tasks.json
  cout
    << "ADD TO YOUR TASKS.JSON" << endl
    << "-I${fileDirname}/../cnum_examples/include" << endl
    << "-I${fileDirname}/../cnum_examples/eigen3" << endl
    << "-L${fileDirname}/../cnum_examples/build" << endl
    << "-lcnum_osx_static" << endl;

  cout 
    << endl
    << "All done folks!"
    << endl;
  return 0;
}
