// 1558. Minimum Numbers of Function Calls to Make Target Array
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. you have an integer array 'arr' of the
 * same length with all values set to 0 initially. you also have the following
 * 'modify' function. you want to use the modify function to covnert 'arr' to
 * 'nums' using the minimum number of calls. return the minimum number of
 * function calls to make 'nums' from 'arr'. the test cases are generated such
 * that the answer fits in a 32 bit signed integer.
 */

int minOperations(int *nums, int numsSize) {
  int ans = 0, max = 1;
  for (int i = 0; i < numsSize; i++) {
    int bits = 0;
    while (nums[i] > 0) {
      ans += nums[i] & 1;
      bits++;
      nums[i] >>= 1;
    }
    max = fmax(max, bits);
  }
  return ans + max - 1;
}

int main() {
  int n1[] = {1, 5}, n2[] = {2, 2}, n3[] = {4, 2, 5};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1))); // expect: 5
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2))); // expect: 3
  printf("%d\n", minOperations(n3, ARRAY_SIZE(n3))); // expect: 6
}
