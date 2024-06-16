// 330. Patching Array
#include "leetcode.h"

/*
 * given a sorted integer array 'nums' and an integer 'n', add/patch elements to
 * the array such that any number in the range '[1, n]' inclusive can be formed
 * by the sum of some elements in the array. return the minimum number of
 * patches required.
 */

int leading_bit(int n) {
  int pos = -1;
  for (int i = 0; i < 32; i++) {
    if ((n & 1) == 1)
      pos = i;
    n >>= 1;
  }
  return pos;
}

int minPatches(int *nums, int numsSize, int n) {
  int cnt = 0;
  long long reachable = 1;
  if (!numsSize)
    return leading_bit(n) + 1;
  if (numsSize == 1)
    return leading_bit(n);
  if (nums[0] != 1)
    cnt++;
  int i = 1 - cnt;
  while (i < numsSize && reachable < n) {
    if (nums[i] <= reachable + 1) {
      reachable += nums[i];
      i++;
    } else {
      cnt++;
      reachable += reachable + 1;
    }
    if (reachable >= n)
      return cnt;
  }
  while (reachable < n) {
    reachable += reachable + 1;
    cnt++;
  }
  return cnt;
}

int main() {
  int n1[] = {1, 3}, n2[] = {1, 5, 10}, n3[] = {1, 2, 2};
  printf("%d\n", minPatches(n1, ARRAY_SIZE(n1), 6));  // expect: 1
  printf("%d\n", minPatches(n2, ARRAY_SIZE(n2), 20)); // expect: 2
  printf("%d\n", minPatches(n3, ARRAY_SIZE(n3), 5));  // expect: 0
}
