// 1925. Count Square Sum Triples
#include "leetcode.h"

/*
 * a square triple '(a, b, c)' is a triple where 'a', 'b', and 'c' are integers
 * and 'a^2 + b^2 = c^2'. given an integer 'n', return the number of square
 * triples such that '1 <= a, b, c <= n'.
 */

int gcd(int a, int b) {
  while (b != 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int countTriples(int n) {
  int ans = 0;
  for (int u = 2; u <= sqrt(n); u++) {
    for (int v = 1; v < u; v++) {
      if (~(u - v) & 1 || gcd(u, v) != 1)
        continue;
      int c = u * u + v * v;
      if (c > n)
        continue;
      ans += (n / c) << 1;
    }
  }
  return ans;
}

int main() {
  printf("%d\n", countTriples(5));  // expect: 2
  printf("%d\n", countTriples(10)); // expect: 4
}
