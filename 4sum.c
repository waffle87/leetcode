// 18. 4Sum
#include <stdio.h>
#include <stdlib.h>

/*
 * given array 'nums' of 'n' integers, return an array of all
 * unique qudruplets 'nums[a], nums[b], nums[c], nums[d]'
 * - such that 0 <= a, b, c, d < n
 * - a, b, c, d are distinct
 * - 'nums[a] + nums[b] + nums[c] + nums[d]' == 'target'
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int **fourSum(int *nums, int numsSize, int target, int *returnSize,
              int **returnColumnsSizes) {
  int i, j, left, right;
  qsort(nums, numsSize, sizeof(int), cmp);
  int **ans = (int **)malloc(1000000 * sizeof(int *));
  int idx = 0;
  for (i = 0; i < numsSize - 3; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (j = i + 1; j < numsSize - 2; j++) {
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;
      left = j + 1;
      right = numsSize - 1;
      while (left < right) {
        long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
        if (sum == target) {
          ans[idx] = (int *)malloc(4 * sizeof(int));
          ans[idx][0] = nums[i];
          ans[idx][1] = nums[j];
          ans[idx][2] = nums[left];
          ans[idx][3] = nums[right];
          idx++;
          left++;
          right--;
          while (left < right && nums[left] == nums[left - 1])
            left++;
          while (right > left && nums[right] == nums[right + 1])
            right--;
        } else if (sum > target)
          right--;
        else
          left++;
      }
    }
  }
  ans = (int **)realloc(ans, idx * sizeof(int *));
  *returnSize = idx;
  returnColumnsSizes[0] = (int *)malloc(idx * sizeof(int));
  for (i = 0; i < idx; i++)
    returnColumnsSizes[0][i] = 4;
  return ans;
}

int main() {
  int nums1[] = {1, 0, -1, 0, -2, 2}, nums2[] = {2, 2, 2, 2, 2};
  int retSz1[] = {3}, retSz2[] = {1};
  int retColSz1[][3] = {}, retColSz2[][1] = {};
  printf("%d\n", fourSum(nums1, 6, 0, retSz1, retColSz1));
}
