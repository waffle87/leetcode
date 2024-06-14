// 41. First Missing Positive
#include "leetcode.h"

/*
 * given an unsorted integer array 'nums', return the smallest missing positive
 * number. you must implement an algorithm that runs in O(n) time and uses O(1)
 * auxiliary space.
 */

int firstMissingPositive(int *nums, int nums_size) {
  int x = 0;
  for (int i = 0; i < nums_size; i++)
    if (nums[i] == 1) {
      x = 1;
      break;
    }
  if (!x)
    return 1;
  if (nums_size == 1)
    return 2;
  for (int i = 0; i < nums_size; i++)
    if (nums[i] <= 0 || nums[i] > nums_size)
      nums[i] = 1;
  for (int i = 0; i < nums_size; ++i) {
    int y = abs(nums[i]);
    if (nums[y - 1])
      nums[y - 1] *= -1;
  }
  for (int i = 0; i < nums_size; ++i)
    if (nums[i])
      return i + 1;
  return nums_size + 1;
}

int main() {
  int n1[] = {1, 2, 0}, n2[] = {3, 4, -1, 1}, n3[] = {7, 8, 9, 11, 12};
  printf("%d\n", firstMissingPositive(n1, 3)); // expect: 3
  printf("%d\n", firstMissingPositive(n2, 4)); // expect: 2
  printf("%d\n", firstMissingPositive(n3, 5)); // expect: 1
}
