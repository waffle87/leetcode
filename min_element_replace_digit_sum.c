// 3300. Minimum Element After Replacement With Digit Sum
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. you replace each element in 'nums'
 * with the sum of its digits. return the minimum element in 'nums' after all
 * replacements.
 */

int minElement(int *nums, int numsSize) {
  int ans = 36;
  for (int i = 0; i < numsSize; i++) {
    int n = nums[i];
    int a = n / 10, b = n / 100, c = n / 1000, d = n / 10000;
    ans = fmin(ans, n - 9 * (a + b + c + d));
  }
  return ans;
}

int main() {
  int n1[] = {10, 12, 13, 14}, n2[] = {1, 2, 3, 4}, n3[] = {999, 19, 199};
  int r1 = minElement(n1, ARRAY_SIZE(n1));
  int r2 = minElement(n2, ARRAY_SIZE(n2));
  int r3 = minElement(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == 10);
}
