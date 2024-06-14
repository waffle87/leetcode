// 2270. Number of Ways to Split Array
#include <stdio.h>
#include <stdlib.h>

/*
 * given a 0-indexed integer array 'nums' of length 'n'. 'nums' contains a valid
 * split at index 'i' if the following are true:
 * - the sum of the first 'i + 1' elements is greater than or equal to the sum
 * of the last 'n - i - 1' elements
 * - there is at least one element to the right of 'i'. that is, 0 <= i < n - 1
 * return the number of valid splits in 'nums'
 */

int waysToSplitArray(int *nums, int nums_size) {
  int n = nums_size, ans = 0;
  long long *presum = malloc(n * sizeof(long long));
  presum[0] = nums[0];
  for (int i = 1; i < n; i++)
    presum[i] = presum[i - 1] + nums[i];
  long long half = presum[n - 1] / 2;
  if (presum[n - 1] % 2)
    if (presum[n - 1])
      half++;
  for (int i = 0; i < n - 1; i++)
    if (presum[i] >= half)
      ans++;
  return ans;
}

int main() {
  int n1[] = {10, 4, -8, 7}, ns1 = 4;
  int n2[] = {2, 3, 1, 0}, ns2 = 4;
  printf("%d\n", waysToSplitArray(n1, ns1)); // expect: 2
  printf("%d\n", waysToSplitArray(n2, ns2)); // expect: 2
}
