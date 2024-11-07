// 2275. Largest Combination With Bitwise AND Greater Than Zero
#include "leetcode.h"

/*
 * the bitwise and of an array 'nums' is the bitwise nd of all integers in
 * 'nums'. you are given an array of positive integers 'candidates'. evaluate
 * the bitwise and of every combination of numbers of 'candidates'. each number
 * in 'candidates' may only be used once in each combination. return the size of
 * the largest combination of 'candidates' with a bitwise and greater than zero.
 */

int largestCombination(int *candidates, int candidatesSize) {
  int ans = 0, curr;
  for (int i = 0; i < 30; ++i, curr = 0)
    for (int j = 0; j < candidatesSize; ++j) {
      curr += (candidates[j] >> i) & 1;
      ans = fmax(ans, curr);
    }
  return ans;
}

int main() {
  int c1[] = {16, 17, 71, 62, 12, 24, 14}, c2[] = {8, 8};
  printf("%d\n", largestCombination(c1, ARRAY_SIZE(c1))); // expect: 4
  printf("%d\n", largestCombination(c2, ARRAY_SIZE(c2))); // expect: 2
}
