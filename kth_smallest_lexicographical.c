// 440. K-th Smallest in Lexicographical Order
#include "leetcode.h"

// given two integers 'n' and 'k', return the k'th lexicographically smallest
// integer

long long count_step(long long prefix, long long n) {
  long long curr = prefix, next = prefix + 1, steps = 0;
  while (curr <= n) {
    steps += (next <= n) ? next - curr : n - curr + 1;
    curr *= 10;
    next *= 10;
  }
  return steps;
}

int findKthNumber(int n, int k) {
  int curr = 1;
  k--;
  while (k) {
    long long steps = count_step(curr, n);
    if (steps <= k) {
      curr++;
      k -= steps;
    } else {
      curr *= 10;
      k--;
    }
  }
  return curr;
}

int main() {
  printf("%d\n", findKthNumber(13, 2)); // expect: 10
  printf("%d\n", findKthNumber(1, 1));  // expect: 1
}
