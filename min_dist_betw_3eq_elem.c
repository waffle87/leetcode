// 3740. Minimum Distance Between Three Equal Elements I
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a tuple '(i, j, k)' of 3 distinct
 * indices is good if 'nums[i] == nums[j] == nums[k]'. the distance of a good
 * tuple is 'abs(i - j) + abs(j - k) + abs(k - k)', where 'abs(x)' denotes the
 * absolute value of 'x'. return an integer denoting the minimum possible
 * distance of a good tuple. if no good tuples exist, return -1.
 */

int minimumDistance(int *nums, int numsSize) {
  int ans = INT_MAX;
  for (int i = 0; i < numsSize; i++)
    for (int j = i + 1; j < numsSize - 1; j++) {
      if (nums[j] != nums[i])
        continue;
      for (int k = j + 1; k < numsSize; k++) {
        if (nums[j] == nums[k])
          ans = fmin(ans, (j - i) + (k - j) + (k - i));
      }
    }
  if (ans == INT_MAX)
    return -1;
  return ans;
}

int main() {
  int n1[] = {1, 2, 1, 1, 3}, n2[] = {1, 1, 2, 3, 2, 1, 2}, n3[] = {1};
  int r1 = minimumDistance(n1, ARRAY_SIZE(n1));
  int r2 = minimumDistance(n2, ARRAY_SIZE(n2));
  int r3 = minimumDistance(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 6);
  printf("%d\n", r2);
  assert(r2 == 8);
  printf("%d\n", r3);
  assert(r3 == -1);
}
