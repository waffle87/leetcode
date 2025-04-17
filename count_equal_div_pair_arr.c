// 2176. Count Equal and Divisible Pairs in an Array
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums' of length 'n' and an integer 'k',
 * return the number of pairs '(i, j)' where '0 <= i < j < n' such that 'nums[i]
 * == nums[j]' and '(i * j)' is divisble by 'k'.
 */

int countPairs(int *nums, int numsSize, int k) {
  int cnt = 0;
  for (int i = 0; i < numsSize; i++)
    for (int j = i + 1; j < numsSize; j++)
      if (nums[i] == nums[j] && !((i * j) % k))
        cnt++;
  return cnt;
}

int main() {
  int n1[] = {3, 1, 2, 2, 2, 1, 3}, n2[] = {1, 2, 3, 4};
  printf("%d\n", countPairs(n1, ARRAY_SIZE(n1), 2)); // expect: 4
  printf("%d\n", countPairs(n2, ARRAY_SIZE(n2), 1)); // expect: 0
}
