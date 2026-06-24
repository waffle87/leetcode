// 3700. Number of ZigZag Arrays II
#include "leetcode.h"

/*
 * you are given three integers. a zigzag array of length 'n' is defined as
 * follows: each element lies in the range '[l, r]', no two adjacent elements
 * are equal, and no three consecutive elements form a strictly increasing or
 * decreasing sequence. return the total number of valid zigzag arrays. since
 * the answer may be large, return it modulo 10^9+7.
 */

static int mod = 1e9 + 7;

long long **matrix_init(int n) {
  long long **res = (long long **)malloc(n * sizeof(long long *));
  for (int i = 0; i < n; i++)
    res[i] = (long long *)calloc(n, sizeof(long long));
  return res;
}

void matrix_free(long long **matrix, int n) {
  for (int i = 0; i < n; i++)
    free(matrix[i]);
  free(matrix);
}

long long **matrix_multiply(long long **a, long long **b, int n) {
  long long **res = matrix_init(n);
  for (int row = 0; row < n; row++)
    for (int mid = 0; mid < n; mid++) {
      if (!a[row][mid])
        continue;
      for (int col = 0; col < n; col++)
        res[row][col] = (res[row][col] + a[row][mid] * b[mid][col]) % mod;
    }
  return res;
}

long long **matrix_power(long long **matrix, int power, int n) {
  long long **res = matrix_init(n);
  for (int row = 0; row < n; row++)
    res[row][row] = 1;
  while (power > 0) {
    if (power & 1) {
      long long **tmp = matrix_multiply(res, matrix, n);
      matrix_free(res, n);
      res = tmp;
    }
    long long **tmp = matrix_multiply(matrix, matrix, n);
    matrix_free(matrix, n);
    matrix = tmp;
    power >>= 1;
  }
  matrix_free(matrix, n);
  return res;
}

int zigZagArrays(int n, int l, int r) {
  int val_cnt = r - l + 1;
  long long *dp = (long long *)malloc(val_cnt * sizeof(long long));
  for (int i = 0; i < val_cnt; i++)
    dp[i] = i;
  long long **trans = matrix_init(val_cnt);
  for (int row = 1; row < val_cnt; row++)
    for (int col = val_cnt - row; col < val_cnt; col++)
      trans[row][col] = 1;
  long long **pow_trans = matrix_power(trans, n - 2, val_cnt);
  long long ans = 0;
  for (int row = 0; row < val_cnt; row++)
    for (int col = 0; col < val_cnt; col++)
      ans = (ans + pow_trans[row][col] * dp[col]) % mod;
  free(dp);
  matrix_free(pow_trans, val_cnt);
  return ans * 2 % mod;
}

int main() {
  int r1 = zigZagArrays(3, 4, 5);
  int r2 = zigZagArrays(3, 1, 3);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 10);
}
