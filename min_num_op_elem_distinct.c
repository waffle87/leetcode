// 3396. Minimum Number of Operations to Make Elements in Array Distinct
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. you need to ensure that the elements
 * in the array are distinct. to achieve this, you can remove 3 elements from
 * the beginning of the array. if the array has fewer than 3 elements, remove
 * all remaining elements. note that an empty array is considered to have
 * distinct elements. return the minimum number of operations needed to make the
 * elements in the array distinct.
 */

int minimumOperations(int *nums, int numsSize) {
  char prev[101], max = -1;
  memset(prev, -1, sizeof(prev));
  for (int i = 0; i < numsSize; i++) {
    if (prev[nums[i]] != -1 && max < prev[nums[i]])
      max = prev[nums[i]];
    prev[nums[i]] = i;
  }
  return (int)(max + 1) / 3 + ((max + 1) % 3 > 0);
}

int main() {
  int n1[] = {1, 2, 3, 4, 2, 3, 3, 5, 7}, n2[] = {4, 5, 6, 4, 4},
      n3[] = {6, 7, 8, 9};
  printf("%d\n", minimumOperations(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", minimumOperations(n2, ARRAY_SIZE(n2))); // expect: 2
  printf("%d\n", minimumOperations(n3, ARRAY_SIZE(n3))); // expect: 0
}
