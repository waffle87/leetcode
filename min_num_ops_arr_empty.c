// 2870. Minimum Number of Operations to Make Array Empty
#include "leetcode.h"

/*
 * you are given a 0-indexed array 'nums' consisting of positive integers. there
 * are two types of operations that you can apply on the array any number of
 * times. choose two elements with equal values and delete them from the array.
 * choose three elements with equal values and delete them from the array.
 * return the minimum number of operations required to make the array empty, or
 * -1 if it is not possible.
 */

int minOperations(int *nums, int nums_size) {
  int ans = 0, ctr[1000001] = {0};
  for (int i = 0; i < nums_size; i++)
    ctr[nums[i]]++;
  for (int i = 0; i < 1000001; i++) {
    if (ctr[i] == 1)
      return -1;
    if (ctr[i]) {
      if (ctr[i] % 3)
        ans += ctr[i] / 3 + 1;
      else
        ans += ctr[i] / 3;
    }
  }
  return ans;
}

int main() {
  int n1[] = {2, 3, 3, 2, 2, 4, 2, 3, 4}, n2[] = {2, 1, 2, 2, 3, 3};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1))); // expect:  4
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2))); // expect: -1
}
