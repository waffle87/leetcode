// 3666. Minimum Operations to Equalize Binary String
#include "leetcode.h"

/*
 * you are given a binary string 's' and an integer 'k'. in one operation, you
 * mut choose exactly 'k' difference indices and flip each '0' to '1' and each
 * '1' to '0'. return the minimum number of operations required to make all
 * characters in the string equal to '1'. if it is not possible, return -1.
 */

int ceil_div(int x, int y) { return (x + y - 1) / y; }

int minOperations(char *s, int k) {
  int n = strlen(s), z = 0, ans = INT_MAX;
  for (int i = 0; i < n; i++)
    if (s[i] == '0')
      z++;
  if (n == k) {
    if (!z)
      return 0;
    if (z == n)
      return 1;
    return -1;
  }
  if (!(z % 2)) {
    int m = ceil_div(z, k), tmp = ceil_div(z, n - k);
    m = fmax(m, tmp);
    if (m % 2 == 1)
      m++;
    ans = fmin(ans, m);
  }
  if (z % 2 == k % 2) {
    int m = ceil_div(z, k), tmp = ceil_div(n - z, n - k);
    m = fmax(m, tmp);
    if (!(m % 2))
      m++;
    ans = fmin(ans, m);
  }
  return ans == INT_MAX ? -1 : ans;
}

int main() {
  char *s1 = "110", *s2 = "0101", *s3 = "101";
  int r1 = minOperations(s1, 1);
  int r2 = minOperations(s2, 3);
  int r3 = minOperations(s3, 2);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == -1);
}
