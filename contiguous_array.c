// 525. Contiguous Array
#include "leetcode.h"

/*
 * given a binary array 'nums' return the maximum length of a contiguous
 * subarray with an equal number of 0 and 1.
 */

int findMaxLength(int *nums, int numsSize) {
  int max = 0, bl = 0, arr[2 * numsSize + 1];
  for (int i = 0; i < 2 * numsSize + 1; i++)
    arr[i] = -2;
  arr[numsSize] = -1;
  for (int i = 0; i < numsSize; i++) {
    nums[i] ? bl++ : bl--;
    if (arr[numsSize + bl] < -1)
      arr[numsSize + bl] = i;
    max = fmax(max, i - arr[numsSize + bl]);
  }
  return max;
}

int main() {
  int n1[] = {0, 1}, n2[] = {0, 1, 0};
  printf("%d\n", findMaxLength(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", findMaxLength(n2, ARRAY_SIZE(n2))); // expect: 2
}
