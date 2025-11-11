// 805. Split Array With Same Average
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. you should move each element of 'nums'
 * into one of the two arrays 'a' and 'b' such that 'a' and 'b' are non-empty
 * and 'average(a) == average(b)'. return true if it is possible to achieve, and
 * false otherwise. note that for an array 'arr', 'average(arr)' is the sum of
 * all the elements of the length of 'arr'.
 */

bool splitArraySameAverage(int *nums, int numsSize) {
  if (numsSize <= 1)
    return false;
  int sum = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  int *dp = (int *)calloc(sum + 1, sizeof(int));
  dp[nums[0]] = 2;
  for (int i = 1; i < numsSize; i++) {
    for (int j = sum - nums[i]; j >= 0; j--)
      if (dp[j])
        dp[j + nums[i]] |= (dp[j] << 1);
    dp[nums[i]] |= 2;
  }
  bool ans = false;
  for (int i = 1; i < numsSize; i++)
    if (!((sum * i) % numsSize) && ((1 << i) & dp[sum * i / numsSize]))
      ans = true;
  free(dp);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5, 6, 7, 8}, n2[] = {3, 1};
  printf("%d\n", splitArraySameAverage(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", splitArraySameAverage(n2, ARRAY_SIZE(n2))); // expect: 0
}
