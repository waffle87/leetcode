// 1848. Minimum Distance to the Target Element
#include "leetcode.h"

/*
 * given an integer array 'nums' and two integers 'target' and 'start', find an
 * index 'i' such that 'nums[i] == target' and 'abs(i - start)' is minimised.
 * note that 'abs(x)' is the absolute value of 'x'. return 'abs(i - start)'. it
 * is guaranteed that 'target' exists in 'nums'.
 */

int getMinDistance(int *nums, int numsSize, int target, int start) {
  int ans = INT_MAX;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] == target)
      ans = fmin(ans, abs(i - start));
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5};
  int n2[] = {1};
  int n3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int r1 = getMinDistance(n1, ARRAY_SIZE(n1), 5, 3);
  int r2 = getMinDistance(n2, ARRAY_SIZE(n2), 1, 0);
  int r3 = getMinDistance(n3, ARRAY_SIZE(n3), 1, 0);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 0);
}
