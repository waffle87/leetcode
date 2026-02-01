// 3010. Divide an Array Into Subarrays With Minimum Cost I
#include "leetcode.h"

/*
 * you are given an array of integers 'nums' of length 'n'. the cost of an array
 * is the value of its first element. you need to divide 'nums' into 3 disjoint
 * contiguous subarrays. return the minimum possible sum of the cost of these
 * subarrays.
 */

int minimumCost(int *nums, int numsSize) {
  int sum = nums[0], min1 = INT_MAX, min2 = INT_MAX;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] < min1) {
      min2 = min1;
      min1 = nums[i];
    } else if (nums[i] < min2 && nums[i] >= min1)
      min2 = nums[i];
  }
  return sum + min1 + min2;
}

int main() {
  int n1[] = {1, 2, 3, 12}, n2[] = {5, 4, 3}, n3[] = {10, 3, 1, 1};
  printf("%d\n", minimumCost(n1, ARRAY_SIZE(n1))); // expect: 6
  printf("%d\n", minimumCost(n2, ARRAY_SIZE(n2))); // expect: 12
  printf("%d\n", minimumCost(n3, ARRAY_SIZE(n3))); // expect: 12
}
