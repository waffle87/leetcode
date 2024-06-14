// 440. K-th Smallest in Lexicographical Order
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// given two integers 'n' and 'k', return the k'th lexicographically smallest
// integer

int count_prefix(int n, long long prefix) {
  long long offset = 10, target = n;
  int total = 0;
  for (int i = 1; i <= 9; i++) {
    long long min = prefix * offset;
    long long max = min + offset - 1;
    if (target < min)
      break;
    total += fmin(target, max) - min + 1;
  }
  return total + 1;
}

int findKthNumber(int n, int k) {
  int prefix = 0;
  if (k)
    for (int i = !prefix ? 1 : 0; i <= 9; i++) {
      int prefix_cnt = count_prefix(n, 10 * prefix + i);
      if (k <= prefix_cnt)
        return findKthNumber(n, k - 1);
      k -= prefix_cnt;
    }
  return prefix;
}

int main() {
  printf("%d\n", findKthNumber(13, 2)); // expect: 10
  printf("%d\n", findKthNumber(1, 1));  // expect: 1
}
