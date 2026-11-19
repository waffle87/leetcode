// 2567. Minimum Score by Changing Two Elements
#include "leetcode.h"

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int minimizeSum(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int a = nums[numsSize - 1] - nums[2];
  int b = nums[numsSize - 2] - nums[1];
  int c = nums[numsSize - 3] - nums[0];
  return fmin(a, fmin(b, c));
}

int main() {
  int n1[] = {1, 4, 7, 8, 5};
  int n2[] = {1, 4, 3};
  int r1 = minimizeSum(n1, ARRAY_SIZE(n1));
  int r2 = minimizeSum(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
}
