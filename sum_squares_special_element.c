// 2778. Sum of Squares of Special Elements
#include "leetcode.h"

/*
 * you are given a 1-indexed integer array 'nums' of length 'n'. an element
 * 'nums[i]' of 'nums' is called special if 'i' divides 'n'. return the sum of
 * the squares of all special elements of 'nums'.
 */

int sumOfSquares(int *nums, int numsSize) {
  int sum = 0;
  for (int i = 1; i <= numsSize / i; i++) {
    if (!(numsSize % i)) {
      sum += nums[i - 1] * nums[i - 1];
      int j = numsSize / i;
      if (i != j)
        sum += nums[j - 1] * nums[j - 1];
    }
  }
  return sum;
}

int main() {
  int n1[] = {1, 2, 3, 4};
  int n2[] = {2, 7, 1, 19, 18, 3};
  int r1 = sumOfSquares(n1, ARRAY_SIZE(n1));
  int r2 = sumOfSquares(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 21);
  printf("%d\n", r2);
  assert(r2 == 63);
}
