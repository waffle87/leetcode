// 2598. Smallest Missing Non-negative Integer After Operations
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' and an integer 'value'. in one
 * operation, you can add or subtract 'value' from any element of 'nums'. the
 * mex (minimum excluded) of an array is the smallest non-negative integer in
 * it. return the mex of 'nums' after applying the mentioned operation any
 * number of times.
 */

int findSmallestInteger(int *nums, int numsSize, int value) {
  long long x, ans = 0;
  int *rem = (int *)calloc(value, sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    x = ((nums[i] % value) + value) % value;
    rem[x]++;
  }
  while (rem[ans % value]--)
    ans++;
  free(rem);
  return ans;
}

int main() {
  int n1[] = {1, -10, 7, 13, 6, 8};
  int n2[] = {1, -10, 7, 13, 6, 8};
  printf("%d\n", findSmallestInteger(n1, ARRAY_SIZE(n1), 5)); // expect: 4
  printf("%d\n", findSmallestInteger(n2, ARRAY_SIZE(n2), 7)); // expect: 2
}
