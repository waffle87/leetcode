// 2206. Divide Array Into Equal Pairs
#include "leetcode.h"

/*
 * you are given an integer array 'nums' consisting of '2 * n' integers. you
 * need to divide 'nums' into 'n' pairs such that: each element belongs to
 * exactly one pair, and the elements present in a pair are equal. return true
 * if 'nums' can be divided into 'n' pairs, otherwise return false.
 */

bool divideArray(int *nums, int numsSize) {
  int x1 = 0, x2 = 0;
  for (int i = 0; i < numsSize; i++) {
    x1 ^= nums[i];
    x2 ^= nums[i] + 1;
  }
  return !x1 && !x2;
}

int main() {
  int n1[] = {3, 2, 3, 2, 2, 2}, n2[] = {1, 2, 3, 4};
  printf("%d\n", divideArray(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", divideArray(n2, ARRAY_SIZE(n2))); // expect: 0
}
