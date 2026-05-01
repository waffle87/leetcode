// 396. Rotate Function
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n'. assume 'arr_k' to be an
 * array obtained by rotating 'nums' by 'k' positions clockwise. we define the
 * rotation function 'F' on 'nums' as follows: 'F(k) = 0 * arr_k[0] + 1 *
 * arr_k[1] + ... + (n - 1) * arr_k[n - 1]'. return the maximum value of 'F(0),
 * F(1), ..., F(n - 1)'. the test cases are generated such that the answer fits
 * in a 32-bit integer.
 */

int maxRotateFunction(int *nums, int numsSize) {
  int f = 0, sum = 0;
  for (int i = 0; i < numsSize; i++) {
    f += i * nums[i];
    sum += nums[i];
  }
  int ans = f;
  for (int i = numsSize - 1; i > 0; i--) {
    f += sum - numsSize * nums[i];
    ans = fmax(ans, f);
  }
  return ans;
}

int main() {
  int n1[] = {4, 3, 2, 6}, n2[] = {100};
  int r1 = maxRotateFunction(n1, ARRAY_SIZE(n1));
  int r2 = maxRotateFunction(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 26);
  printf("%d\n", r2);
  assert(r2 == 0);
}
