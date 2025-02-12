// 2342. Max Sum of a Pair With Equal Sum of Digits
#include "leetcode.h"

/*
 * you are given a 0-indexed array 'nums' consisting of positive integers. you
 * can choose two indices 'i' and 'j', such that 'i != j', and the sum of the
 * digits of the number 'nums[i]' is equal to that of 'nums[j]'. return the
 * maximum value of 'nums[i] + nums[j]' that you can obtain over all
 * possible indices 'i' and 'j' that satisfy the conditions.
 */

int maximumSum(int *nums, int numsSize) {
  int map[82], ans = -1;
  memset(map, -1, sizeof(map));
  for (int i = 0; i < numsSize; i++) {
    int sum = 0, tmap = nums[i];
    while (tmap) {
      sum += tmap % 10;
      tmap /= 10;
    }
    if (map[sum] != -1)
      ans = fmax(ans, nums[i] + map[sum]);
    map[sum] = fmax(map[sum], nums[i]);
  }
  return ans;
}

int main() {
  int n1[] = {18, 43, 36, 13, 7}, n2[] = {10, 12, 19, 14};
  printf("%d\n", maximumSum(n1, ARRAY_SIZE(n1))); // expect: 54
  printf("%d\n", maximumSum(n2, ARRAY_SIZE(n2))); // expect: -1
}
