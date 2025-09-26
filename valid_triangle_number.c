// 611. Valid Triangle Number
#include "leetcode.h"

/*
 * given an integer array 'nums', return the number of triplets chosen from the
 * array that can make triangles if we take them as side lengths of a triangle
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int triangleNumber(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = 0;
  for (int k = 2; k < numsSize; ++k) {
    int i = 0, j = k - 1;
    while (i < j) {
      if (nums[i] + nums[j] > nums[k]) {
        ans += j - i;
        j--;
      } else
        i++;
    }
  }
  return ans;
}

int main() {
  int n1[] = {2, 2, 3, 4}, n2[] = {4, 2, 3, 4};
  printf("%d\n", triangleNumber(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", triangleNumber(n2, ARRAY_SIZE(n2))); // expect: 4
}
