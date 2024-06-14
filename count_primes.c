// 204. Count Primes
#include "leetcode.h"

/*
 * given an integer 'n', return the number of prime numbers that are strictly
 * less than 'n'.
 */

int countPrimes(int n) {
  if (n < 2)
    return 0;
  if (n == 3)
    return 1;
  bool *table = (bool *)calloc(n, sizeof(bool));
  table[0] = table[1] = 1;
  for (int i = 2; i <= sqrt(n); i++) {
    if (table[i])
      continue;
    for (int j = i * i; j < n; j += i)
      table[j] = 1;
  }
  int ans = 0;
  for (int i = 2; i < n; i++)
    if (!table[i])
      ans++;
  free(table);
  return ans;
}

int main() {
  printf("%d\n", countPrimes(10)); // expect: 4
  printf("%d\n", countPrimes(0));  // expect: 0
  printf("%d\n", countPrimes(1));  // expect: 0
}
