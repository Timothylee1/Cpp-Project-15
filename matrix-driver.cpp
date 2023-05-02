#include "matrix.hpp"
#include <string>
#include <complex>
#include <iostream>
#include <array>

// anonymous namespace to keep stuff private to this file
namespace { 
  void basic_matrix_test();
  void const_matrix_test();
  void arithmetic_matrix_test();
} // end anonymous namespace 

int main(int argc, char **argv) {
  int test_num {0};
  if (argc > 1) {
    test_num = std::stoi(argv[1]);
    // test_num must be in range [0, 3] because we've 3 tests
    // if test_num == 0, then we run all 3 tests ...
    test_num = (test_num < 0) ? 0 : (test_num > 3) ? 3 : test_num;
  }

  using TPF = void (*)();
  int constexpr num_of_tests {3};
  std::array<TPF, num_of_tests> Tests {
    basic_matrix_test,      // 1 - correct output is in basic-matrix.txt
    const_matrix_test,      // 2 - correct output is in const-matrix.txt
    arithmetic_matrix_test  // 3 - correct output is in arith-matrix.txt
  };

  if (test_num == 0) { // correct output when argv[1] is "0" is in test-all.txt
    for (TPF x : Tests) {
      x();
    }
  } else if (test_num > 0 && test_num <= num_of_tests) {
    Tests[test_num - 1]();
  }
}

namespace {

void basic_matrix_test() {
  // create a 2 x 2 matrix of integers.
{
  hlp2::matrix<int> m1(2, 2);
  m1[0][0] = 1; m1[0][1] = 2;
  m1[1][0] = 3; m1[1][1] = 4;
  std::cout << "matrix m1(" << m1.Rows() << ", " << m1.Cols() << "):\n";
  std::cout << m1 << '\n';
  // copy construction
  hlp2::matrix<int> m2(m1);
  std::cout << "matrix m2(" << m2.Rows() << ", " << m2.Cols() << "):\n";
  std::cout << m2 << '\n';
}

{
  // create a 3 x 2 matrix of doubles.
  hlp2::matrix<double> md1(2, 3);
  md1[0][0] = 1.1; md1[0][1] = 2.2; md1[0][2] = 3.3;
  md1[1][0] = 4.4; md1[1][1] = 5.5; md1[1][2] = 6.6;
  std::cout << "matrix md1(" << md1.Rows() << ", " << md1.Cols() << "):\n";
  std::cout << md1 << '\n';
  // copy construction
  hlp2::matrix<double> md2(md1);
  std::cout << "matrix md2(" << md2.Rows() << ", " << md2.Cols() << "):\n";
  std::cout << md2 << '\n';
}

// TEST FOR STD::COMPLEX<INT>

  // create 5 complex numbers.
  std::complex<int> c1(1, 0), c2(0, 1), c3(-1, 0), c4(0, -1), c5(1, 2), c6(2, 2);
{
  // create a 2 x 2 matrix of complex<int> numbers.
  hlp2::matrix<std::complex<int>> cm(3, 2);
  cm[0][0] = c1; cm[0][1] = c2;
  cm[1][0] = c3; cm[1][1] = c4;
  cm[2][0] = c5; cm[2][1] = c6;
  std::cout << "matrix cm(" << cm.Rows() << ", " << cm.Cols() << "):\n";
  std::cout << cm << '\n';
}

{
  // create a 2 x 2 matrix of complex<double> numbers
  hlp2::matrix<std::complex<double>> cd1(2, 2);
  cd1[0][0] = std::complex<double>(1.1, 1.1); cd1[0][1] = std::complex<double>(2.2, 2.2);
  cd1[1][0] = std::complex<double>(3.3, 3.3); cd1[1][1] = std::complex<double>(4.4, 4.4);
  std::cout << "matrix cd1(" << cd1.Rows() << ", " << cd1.Cols() << "):\n";
  std::cout << cd1 << '\n';
}

// TEST FOR STD::STRINGS
{
  // create a 3 x 3 matrix of std::strings.
  hlp2::matrix<std::string> ms1(3, 3);
  std::cout << "matrix ms1:" << '\n';
  std::cout << ms1 << '\n';

  ms1[0][0] = "ab"; ms1[0][1] = "bc"; ms1[0][2] = "cd";
  ms1[1][0] = "de"; ms1[1][1] = "ef"; ms1[1][2] = "fg";
  ms1[2][0] = "gh"; ms1[2][1] = "hi"; ms1[2][2] = "ij";
  std::cout << "matrix ms1(" << ms1.Rows() << ", " << ms1.Cols() << "):\n";
  std::cout << ms1 << '\n';

  // copy construct a 3 x 3 matrix of std::strings
  hlp2::matrix<std::string> ms2(ms1);
  std::cout << "matrix ms2(" << ms2.Rows() << ", " << ms2.Cols() << "):\n";
  std::cout << ms2;
}
}

void const_matrix_test() {
{
  // create a 2 x 2 matrix of integers.
  hlp2::matrix<int> m1(2, 2);
  m1[0][0] = 1; m1[0][1] = 2;
  m1[1][0] = 3; m1[1][1] = 4;
  // copy construction
  hlp2::matrix<int> const m2(m1);
  std::cout << "const matrix m2(" << m2.Rows() << ", " << m2.Cols() << "):\n";
  std::cout << m2 << '\n';
}

{
  // create a 3 x 2 matrix of doubles.
  hlp2::matrix<double> md1(2, 3);
  md1[0][0] = 1.1; md1[0][1] = 2.2; md1[0][2] = 3.3;
  md1[1][0] = 4.4; md1[1][1] = 5.5; md1[1][2] = 6.6;
  // copy construction
  hlp2::matrix<double> const md2(md1);
  std::cout << "const matrix md2(" << md2.Rows() << ", " << md2.Cols() << "):\n";
  std::cout << md2 << '\n';
}

// TEST FOR STD::COMPLEX<INT>

  // create 5 complex numbers.
  std::complex<int> c1(1, 0), c2(0, 1), c3(-1, 0), c4(0, -1), c5(1, 2), c6(2, 2);
{
  // create a 2 x 2 matrix of complex<double> numbers
  hlp2::matrix<std::complex<double>> cd1(2, 2);
  cd1[0][0] = std::complex<double>(1.1, 1.1); cd1[0][1] = std::complex<double>(2.2, 2.2);
  cd1[1][0] = std::complex<double>(3.3, 3.3); cd1[1][1] = std::complex<double>(4.4, 4.4);
  hlp2::matrix<std::complex<double>> const cd2(cd1);
  std::cout << "const matrix cd2(" << cd2.Rows() << ", " << cd2.Cols() << "):\n";
  std::cout << cd2 << '\n';
}

// TEST FOR STD::STRINGS
{
  // create a 3 x 3 matrix of std::strings.
  hlp2::matrix<std::string> ms1(3, 3);
  ms1[0][0] = "ab"; ms1[0][1] = "bc"; ms1[0][2] = "cd";
  ms1[1][0] = "de"; ms1[1][1] = "ef"; ms1[1][2] = "fg";
  ms1[2][0] = "gh"; ms1[2][1] = "hi"; ms1[2][2] = "ij";
  // copy construct a 3 x 3 matrix of std::strings
  hlp2::matrix<std::string> const ms2(ms1);
  std::cout << "const matrix ms2(" << ms2.Rows() << ", " << ms2.Cols() << "):\n";
  std::cout << ms2;
}
}

void arithmetic_matrix_test() {
  // PART 1 - MATRIX OF int NUMBERS.

  // create a 2 x 2 matrix of integers.
  hlp2::matrix<int> m(2, 2);
  m[0][0] = 1; m[0][1] = 2;
  m[1][0] = 3; m[1][1] = 4;
  std::cout << "matrix m:" << '\n';
  std::cout << m << '\n';

  // create another 2 x 2 matrix of integers.
  hlp2::matrix<int> n(2, 2);
  n[0][0] = 3; n[0][1] = 1;
  n[1][0] = 7; n[1][1] = 2;
  std::cout << "matrix n:" << '\n';
  std::cout << n << '\n';

  // perform comparisons of matrices.
  hlp2::matrix<int> mCopy(2, 2);
  mCopy[0][0] = 1; mCopy[0][1] = 2;
  mCopy[1][0] = 3; mCopy[1][1] = 4;
  if (m == mCopy) {
    std::cout << "m and mCopy are equal." << '\n';
  } else {
    std::cout << "m and mCopy are NOT equal." << '\n';
  }
  if (m != n) {
    std::cout << "m and n are NOT equal." << '\n';
  } else {
    std::cout << "m and n are equal." << '\n';
  }
  std::cout << '\n';

  // add 2 matrices of integers.
  hlp2::matrix<int> iAdd = m + n;
  std::cout << "iAdd = m + n" << '\n';
  std::cout << iAdd << '\n';

  // subtract 2 matrices of integers.
  hlp2::matrix<int> iSub = m - n;
  std::cout << "iSub = m - n" << '\n';
  std::cout << iSub << '\n';

  // multiply 2 matrices of integers.
  hlp2::matrix<int> iMul = m * n;
  std::cout << "iMul = m * n" << '\n';
  std::cout << iMul << '\n';

  // multiply a matrix of integers with an integer.
  hlp2::matrix<int> iScalarMul = 2 * m;
  std::cout << "iScalarMul = 2 * m" << '\n';
  std::cout << iScalarMul << '\n';
  iScalarMul = n * 3;
  std::cout << "iScalarMul = n * 3" << '\n';
  std::cout << iScalarMul << '\n';

  // compound addition of matrix of integers.
  m += n;
  std::cout << "m += n" << '\n';
  std::cout << m << '\n';
  std::cout << "iAdd:" << '\n';
  std::cout << iAdd << '\n';
  if (m == iAdd) {
    std::cout << "m and iAdd are equal." << '\n';
  } else {
    std::cout << "m and iAdd are NOT equal." << '\n';
  }
  std::cout << '\n';

  // compound subtraction of matrix of integers.
  m -= 2 * n;
  std::cout << "m -= 2 * n" << '\n';
  std::cout << m << '\n';
  std::cout << "iSub:" << '\n';
  std::cout << iSub << '\n';
  if (m == iSub) {
    std::cout << "m and iSub are equal." << '\n';
  } else {
    std::cout << "m and iSub are NOT equal." << '\n';
  }
  std::cout << '\n';

  // compound addition and multiplication of matrix of integers.
  m += n;
  m *= n;
  std::cout << "m += n" << '\n';
  std::cout << "m *= n" << '\n';
  std::cout << m << '\n';
  std::cout << "iMul * 2:" << '\n';
  std::cout << iMul * 2<< '\n';
  if (m != iMul) {
    std::cout << "m and iMul are NOT equal." << '\n';
  } else {
    std::cout << "m and iMul are equal." << '\n';
  }
  std::cout << '\n';

  // compound multiplication of a matrix of integers with an integer.
  m *= 10;
  std::cout << "m *= 10" << '\n';
  std::cout << m << '\n';

  // testing multiplication of non-square integer matrices
  hlp2::matrix<int> ma(2, 2);
  ma[0][0] = 1; ma[0][1] = 2;
  ma[1][0] = 3; ma[1][1] = 4;
  hlp2::matrix<int> mb(2, 3);
  mb[0][0] = 1; mb[0][1] = 2; mb[0][2] = 3;
  mb[1][0] = 4; mb[1][1] = 5; mb[1][2] = 6;

  // multiply 2 matrices of integer numbers.
  hlp2::matrix<int> mc = ma * mb;
  std::cout << "mc = ma * mb" << '\n';
  std::cout << mc << '\n';

  // PART 2 - MATRIX OF COMPLEX NUMBERS.

  // create 5 complex numbers.
  std::complex<int> c1(1, 0), c2(0, 1), c3(-1, 0), c4(0, -1), c5(1, 2);

  // create a 2 x 2 matrix of complex numbers.
  hlp2::matrix<std::complex<int>> cm(2, 2);
  cm[0][0] = c1; cm[0][1] = c2;
  cm[1][0] = c3; cm[1][1] = c4;
  std::cout << "matrix cm:" << '\n';
  std::cout << cm << '\n';

  // create another 2 x 2 matrix of complex numbers.
  hlp2::matrix<std::complex<int>> cn(2, 2);
  cn[0][0] = c2; cn[0][1] = c3;
  cn[1][0] = c4; cn[1][1] = c5;
  std::cout << "matrix cn:" << '\n';
  std::cout << cn << '\n';

  // add 2 matrices of complex numbers.
  hlp2::matrix<std::complex<int>> cAdd = cm + cn;
  std::cout << "cAdd = cm + cn" << '\n';
  std::cout << cAdd << '\n';

  // subtract 2 matrices of complex numbers.
  hlp2::matrix<std::complex<int>> cSub = cm - cn;
  std::cout << "cSub = cm - cn" << '\n';
  std::cout << cSub << '\n';

  // multiply 2 matrices of complex numbers.
  hlp2::matrix<std::complex<int>> cMul = cm * cn;
  std::cout << "cMul = cm * cn" << '\n';
  std::cout << cMul << '\n';

  // create 2 complex numbers.
  std::complex<int> cScalar1(4, 0);
  std::complex<int> cScalar2(5, 0);
  // multiply a complex number with a matrix of complex numbers.
  hlp2::matrix<std::complex<int>> cScalarMul = cScalar1 * cm;
  std::cout << "cScalarMul = 4 * cm" << '\n';
  std::cout << cScalarMul << '\n';
  cScalarMul = cn * cScalar2;
  std::cout << "cScalarMul = cn * 5" << '\n';
  std::cout << cScalarMul << '\n';

  // compound addition of matrix of complex numbers.
  cm += cn;
  std::cout << "cm += cn" << '\n';
  std::cout << cm << '\n';
  std::cout << "cAdd:" << '\n';
  std::cout << cAdd << '\n';
  if (cm == cAdd) {
    std::cout << "cm and cAdd are equal." << '\n';
  } else {
    std::cout << "cm and cAdd are NOT equal." << '\n';
  }
  std::cout << '\n';

  // compound subtraction of matrix of complex numbers.
  std::complex<int> cScalar3 = 2;
  cm -= cScalar3 * cn;
  std::cout << "cm -= 2 * cn" << '\n';
  std::cout << cm << '\n';
  std::cout << "cSub:" << '\n';
  std::cout << cSub << '\n';
  if (cm == cSub) {
    std::cout << "cm and cSub are equal." << '\n';
  } else {
    std::cout << "cm and cSub are NOT equal." << '\n';
  }
  std::cout << '\n';

  // compound addition and multiplication of matrix of complex numbers.
  cm += cn;
  cm *= cn;
  std::cout << "cm += cn" << '\n';
  std::cout << "cm *= cn" << '\n';
  std::cout << "cm:\n" << cm << '\n';
  std::cout << "cMul:" << '\n';
  std::cout << cMul << '\n';
  if (cm != cMul) {
    std::cout << "cm and cMul are NOT equal." << '\n';
  } else {
    std::cout << "cm and cMul are equal." << '\n';
  }
  std::cout << '\n';

  // compound multiplication of matrix of complex numbers with a complex number.
  std::complex<int> cScalar4(10, 0);
  cm *= cScalar4;
  std::cout << "cm *= 10" << '\n';
  std::cout << cm << '\n';

  // PART 3 - MATRIX OF std::string

  // create a 3 x 3 matrix of std::strings.
  hlp2::matrix<std::string> ms1(3, 3);
  ms1[0][0] = "ab"; ms1[0][1] = "bc"; ms1[0][2] = "cd";
  ms1[1][0] = "de"; ms1[1][1] = "ef"; ms1[1][2] = "fg";
  ms1[2][0] = "gh"; ms1[2][1] = "hi"; ms1[2][2] = "ij";
  std::cout << "matrix ms1:" << '\n';
  std::cout << ms1 << '\n';
  std::cout << '\n';

  // copy construct a 3 x 3 matrix of std::strings
  hlp2::matrix<std::string> const ms2(ms1);
  std::cout << "ms2 has " << ms2.Rows() << " rows and " << ms2.Cols()
            << " columns.\n";
  if (ms2 == ms1) {
    std::cout << "ms1 and ms2 are equal." << '\n';
  } else {
    std::cout << "ms1 and ms2 are NOT equal." << '\n';
  }
  std::cout << '\n';

  // add two 3 x 3 matrices with elements of type std::strings
  hlp2::matrix<std::string> ms3 = ms1 + ms2;
  std::cout << "matrix ms3:" << '\n';
  std::cout << ms3;
}

} // end anonymous namespace