// 3737. Count Subarrays With Majority Element I
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'target'. return the
 * number of subarrays of 'nums' in which 'target' is the majority element. the
 * majority element of a subarray is the element that appears strictly more than
 * half of the times in that subarray.
 */

int countMajoritySubarrays(int *nums, int numsSize, int target) {
  int max = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != target)
      nums[i] = 0;
    else {
      nums[i] = 1;
      max++;
    }
  }
  if (max <= 1)
    return max;
  int ans = max;
  max = (max << 1) - 1;
  int *pre = (int *)malloc((numsSize + 1) * sizeof(int));
  pre[0] = 0;
  for (int i = 0; i < numsSize; i++)
    pre[i + 1] = pre[i] + nums[i];
  for (int i = 2; i <= max; i++) {
    int val = (i >> 1) + 1;
    for (int j = 0; j + i <= numsSize; j++) {
      int end = j + i;
      int sum = pre[end] - pre[j];
      if (sum >= val)
        ans++;
    }
  }
  free(pre);
  return ans;
}

int main() {
  int n1[] = {1, 2, 2, 3};
  int n2[] = {1, 1, 1, 1};
  int n3[] = {1, 2, 3};
  int r1 = countMajoritySubarrays(n1, ARRAY_SIZE(n1), 2);
  int r2 = countMajoritySubarrays(n2, ARRAY_SIZE(n2), 1);
  int r3 = countMajoritySubarrays(n3, ARRAY_SIZE(n3), 4);
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 10);
  printf("%d\n", r3);
  assert(r3 == 0);
}
