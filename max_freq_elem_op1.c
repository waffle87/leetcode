// 3346. Maximum Frequency of an Element After Performing Operations I
#include "leetcode.h"
#include <math.h>

/*
 * you are given an integer array 'nums' and two integers 'k' and
 * 'numOperations'. you must perform an operation 'numOperations' times on
 * 'nums', where in each operation you select an index 'i' that was not selected
 * in any previous operations, and add an integer in the range '[-k, k]' to
 * nums. return the maximum possible frequency of any element in 'nums' after
 * performing the operations.
 */

int maxFrequency(int *nums, int numsSize, int k, int numOperations) {
  int max = nums[0], ans = 0;
  for (int i = 1; i < numsSize; i++)
    if (nums[i] > max)
      max = nums[i];
  int n = max + k + 2, *freq = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < numsSize; i++)
    freq[nums[i]]++;
  int *pre = (int *)calloc(n, sizeof(int));
  pre[0] = freq[0];
  for (int i = 1; i < n; i++)
    pre[i] = pre[i - 1] + freq[i];
  for (int i = 0; i < n; i++) {
    if (!freq[i] && !numOperations)
      continue;
    int l = fmax(0, i - k), r = fmin(n - 1, i + k);
    int total = pre[r] - (l > 0 ? pre[l - 1] : 0);
    int adj = total - freq[i];
    int val = freq[i] + fmin(numOperations, adj);
    ans = fmax(ans, val);
  }
  free(freq);
  free(pre);
  return ans;
}

int main() {
  int n1[] = {1, 4, 5}, n2[] = {5, 11, 20, 20};
  printf("%d\n", maxFrequency(n1, ARRAY_SIZE(n1), 1, 2)); // expect: 2
  printf("%d\n", maxFrequency(n2, ARRAY_SIZE(n2), 5, 1)); // expect: 2
}
