// 2597. The Number of Beautiful Subsets
#include "leetcode.h"

/*
 * given an array 'nums' of positive integers and a positive integer 'k'. a
 * subset of 'nums' is beautiful if it does not contain integers with an
 * absolute difference equal to 'k'. return the number of non empty beautiful
 * subsets of the array 'nums'. a subset of 'nums' is an array that can be
 * obtained by deleting some elements from 'nums'. two subsets are different iff
 * the chosen indices to delete are different.
 */

int beautifulSubsets(int *nums, int numsSize, int k) {
  int n = 1 << numsSize, cnt = 0;
  for (int i = 1; i < n; i++) {
    int *store = (int *)malloc(numsSize * sizeof(int));
    bool flag = true;
    for (int j = 0, l = 0; j < numsSize && flag; j++)
      if (i & (1 << j)) {
        for (int m = 0; m < l && flag; m++)
          if (abs(store[m] - nums[j]) == k)
            flag = false;
        store[l++] = nums[j];
      }
    if (flag)
      cnt++;
    free(store);
  }
  return cnt;
}

int main() {
  int n1[] = {2, 4, 6}, n2[] = {1};
  printf("%d\n", beautifulSubsets(n1, ARRAY_SIZE(n1), 2)); // expect: 4
  printf("%d\n", beautifulSubsets(n2, ARRAY_SIZE(n2), 1)); // expect: 1
}
