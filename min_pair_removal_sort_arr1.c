// 3507. Minimum Pair Removal to Sort Array I
#include "leetcode.h"

/*
 * given an array 'nums', you can perform the following operation any number of
 * times. select the adjacent pair with the minimum sum in 'nums'. if multiple
 * such pairs exist, choose the leftmost one. replace the pair with their sum.
 * return the minimum number of operations needed o make the array
 * non-decreasing. an array is said to be non-decreasing if each element is
 * great than or equal to its previous element (if it exists).
 */

bool sorted(int *nums, int n) {
  for (int i = 1; i < n; i++)
    if (nums[i] < nums[i - 1])
      return false;
  return true;
}

int minimumPairRemoval(int *nums, int numsSize) {
  int ans = 0;
  while (!sorted(nums, numsSize)) {
    ans++;
    int min_sum = INT_MAX, pos = -1;
    for (int i = 1; i < numsSize; i++) {
      int sum = nums[i - 1] + nums[i];
      if (sum < min_sum) {
        min_sum = sum;
        pos = i;
      }
    }
    nums[pos - 1] = min_sum;
    for (int i = pos; i < numsSize - 1; i++)
      nums[i] = nums[i + 1];
    numsSize--;
  }
  return ans;
}

int main() {
  int n1[] = {5, 2, 3, 1}, n2[] = {1, 2, 2};
  printf("%d\n", minimumPairRemoval(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", minimumPairRemoval(n2, ARRAY_SIZE(n2))); // expect: 0
}
