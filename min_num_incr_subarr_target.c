// 1526. Minimum Number of Increments on Subarrays to Form a Target Array
#include "leetcode.h"

/*
 * you are given an integer array 'target'. you have an integer array 'initial'
 * of the same size as 'target' with all elements initially zeros. in one
 * operation, you can choose any subarray from 'initial' and increment ach value
 * by one. return the minimum number of operations to form a 'target' array from
 * 'initial'. the test cases are generated such that the answer will fit in a
 * 32-bit integer.
 */

int minNumberOperations(int *target, int targetSize) {
  int ans = 0, prev = 0;
  for (int i = 0; i < targetSize; i++) {
    if (target[i] > prev)
      ans += target[i] - prev;
    prev = target[i];
  }
  return ans;
}

int main() {
  int t1[] = {1, 2, 3, 2, 1}, t2[] = {3, 1, 1, 2}, t3[] = {3, 1, 5, 4, 2};
  printf("%d\n", minNumberOperations(t1, ARRAY_SIZE(t1))); // expect: 3
  printf("%d\n", minNumberOperations(t2, ARRAY_SIZE(t2))); // expect: 4
  printf("%d\n", minNumberOperations(t3, ARRAY_SIZE(t3))); // expect: 7
}
