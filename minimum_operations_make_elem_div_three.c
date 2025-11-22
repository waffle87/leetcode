// 3190. Find Minimum Operations to Make All Elements Divisible by Three
#include "leetcode.h"

/*
 * you are given an ineger array 'nums'. in one operation, you can add or
 * subtract 1 from any element of 'nums' return the minimum number of operations
 * to make all elements of 'nums' divisible by 3
 */

int minimumOperations(int *nums, int numsSize) {
  // mask where numbers not divisble by 3 have bit set
  const unsigned long long mask = 0x6DB6DB6DB6DB6DB6ULL;
  int ans = 0;
  for (int i = 0; i < numsSize; i++)
    if ((mask >> nums[i]) & 1)
      ans++;
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4}, n2[] = {3, 6, 9};
  printf("%d\n", minimumOperations(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", minimumOperations(n2, ARRAY_SIZE(n2))); // expect: 0
}
