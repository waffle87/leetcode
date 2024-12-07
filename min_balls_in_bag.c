// 1760. Minimum Limit of Balls in a Bag
#include "leetcode.h"

/*
 * given an integer array 'nums' where the i'th bag contains
 * 'nums[i]' balls. also given an integer 'max_operations'.
 * you can perform the following operation at most 'max_operations'
 * times; take any bag of balls and divide it into two new bags
 * with a positive number of balls. the penalty is the maximum
 * number of balls in a bag. you want to minimise your penalty
 * after the operations. return the minimum possible penalty.
 */

bool work(int *nums, int numsSize, int operation, int min) {
  for (int i = 0; i < numsSize && operation >= 0; i++)
    operation -= (nums[i] - 1) / min;
  return operation >= 0;
}

int minimumSize(int *nums, int numsSize, int max_operations) {
  int i = 1, j = INT_MAX, k;
  while (i < j) {
    k = (i + j) / 2;
    if (work(nums, numsSize, max_operations, k))
      j = k;
    else
      i = k + 1;
  }
  return j;
}

int main() {
  int n1[] = {9}, n2[] = {2, 4, 8, 2};
  printf("%d\n", minimumSize(n1, ARRAY_SIZE(n1), 2)); // expect: 3
  printf("%d\n", minimumSize(n2, ARRAY_SIZE(n2), 4)); // expect: 2
}
