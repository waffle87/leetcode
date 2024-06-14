// 1137. N-th Tribonacci Number
#include "leetcode.h"

/*
 * the tribonacci sequence t^n is defined as follows
 * t0 = 0, t1 = 1, t2 = 1, & tn+3 = tn + tn+1 + tn+2 for n >= 0
 * given n, return value of tn
 * eg.
 * n = 4, output: 4
 * t3 = 0 + 1 + 1 = 2
 * t4 = 1 + 1 + 2 = 4
 */

typedef long long ll;
struct Matrix {
  vvd(ll) a;
  int rows, cols;
  Matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) {
    a.resize(rows);
    for (int i = 0; i < rows; ++i)
      a[i].assign(cols, 0);
  }
  Matrix(const vvd(ll) & matrix)
      : a(matrix), rows(matrix.size()), cols(matrix[0].size()) {}
};

Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix res(a.rows, b.cols);
  for (int i = 0; i < a.rows; ++i)
    for (int j = 0; j < b.cols; ++j)
      for (int k = 0; k < a.cols; ++k)
        res.a[i][j] += a.a[i][k] * b.a[k][j];
  return res;
}

Matrix fastPow(const Matrix &matrix, int pow) {
  if (pow == 1)
    return matrix;
  Matrix half = fastPow(matrix, pow / 2);
  if (pow & 1)
    return half * half * matrix;
  return half * half;
}

class Solution {
public:
  int tribonacci(int n) {
    if (n == 0)
      return 0;
    Matrix m({{0, 1, 0}, {0, 0, 1}, {1, 1, 1}});
    Matrix m0({{0}, {1}, {1}});
    Matrix mn = fastPow(m, n) * m0;
    return mn.a[0][0];
  }
};

int main() {
  Solution obj;
  cout << obj.tribonacci(4) << endl;  // expect: 4
  cout << obj.tribonacci(25) << endl; // expect: 1389537
}
