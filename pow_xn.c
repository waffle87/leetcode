// 50. Pow(x, n)50. Pow(x, n)
#include <limits.h>
#include <stdio.h>

/*
 * implement 'pow(x, n)', which calculates 'x' raised to the power 'n' (i.e.
 * x^n)
 */

double myPow(double x, int n) {
  if (x == 1.0)
    return x;
  if (x == -1.0)
    return (n % 2 ? -1.0 : 1.0);
  if (n == INT_MIN)
    return 0;
  double ans = 1;
  if (n < 0) {
    x = 1 / x;
    n = -n;
  }
  for (int i = 0; i < n && ans * x != ans; i++)
    ans *= x;
  return ans;
}

int main() {
  printf("%f\n", myPow(2, 10));  // expect: 1024.00000
  printf("%f\n", myPow(2.1, 3)); // expect: 9.26100
  printf("%f\n", myPow(2, -2));  // expect: 0.25000
}
