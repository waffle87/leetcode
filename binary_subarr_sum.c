// 930. Binary Subarrays With Sum
#include "leetcode.h"

/*
 * given a binary array 'nums' and an integer 'goal', return the number o
 * non-empty subarrays with a sum 'goal'. a subarray is a contiguous part of the
 * array
 */

int numSubarraysWithSum(int *nums, int numsSize, int goal) {
  int n = numsSize, m = n + 1, sum = 0, rm, d, ans = 0;
  int **hash = calloc(m, sizeof(int *));
  hash[0] = malloc(2 * sizeof(int));
  hash[0][0] = 0;
  hash[0][1] = 1;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    rm = sum - goal;
    d = rm;
    while (1 && rm >= 0) {
      if (hash[d % n] == NULL)
        break;
      else if (hash[d % n][0] == rm) {
        ans += hash[d % n][1];
        break;
      } else {
        d++;
      }
    }
    d = sum;
    while (1) {
      if (hash[d % n] == NULL) {
        hash[d % n] = malloc(2 * sizeof(int));
        hash[d % n][0] = sum;
        hash[d % n][1] = 1;
        break;
      } else if (hash[d % n][0] == sum) {
        hash[d % n][1]++;
        break;
      } else {
        d++;
      }
    }
  }
  return ans;
}

int main() {
  int n1[] = {1, 0, 1, 0, 1}, n2[] = {0, 0, 0, 0, 0};
  printf("%d\n", numSubarraysWithSum(n1, ARRAY_SIZE(n1), 2)); // expect: 4
  printf("%d\n", numSubarraysWithSum(n2, ARRAY_SIZE(n2), 0)); // expect: 15
}
