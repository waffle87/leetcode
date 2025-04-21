// 2145. Count the Hidden Sequences
#include "leetcode.h"

/*
 * you are given a 0-indexed array of 'n' integers 'differences', which
 * describes the differences between each pair of consecutive integers of a
 * hidden sequence of length '(n + 1)'. you are further given two integers
 * 'lower' and 'upper' that describe the inclusive range of values '[lower,
 * upper]' that the hidden sequence can contain. return the number of possible
 * hidden sequences there are. if there are no possible sequences, return 0.
 */

int numberOfArrays(int *differences, int differencesSize, int lower,
                   int upper) {
  long long cnt = 0, a = 0, b = 0;
  for (int i = 0; i < differencesSize; i++) {
    cnt += differences[i];
    a = fmax(a, cnt);
    b = fmin(b, cnt);
  }
  return fmax(0L, (upper - lower) - (a - b) + 1);
}

int main() {
  int d1[] = {1, -3, 4}, d2[] = {3, -4, 5, 1, -2}, d3[] = {4, -7, 2};
  printf("%d\n", numberOfArrays(d1, ARRAY_SIZE(d1), 1, 6));  // expect: 2
  printf("%d\n", numberOfArrays(d2, ARRAY_SIZE(d2), -4, 5)); // expect: 4
  printf("%d\n", numberOfArrays(d3, ARRAY_SIZE(d3), 3, 6));  // expect: 0
}
