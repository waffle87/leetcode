// 169. Majority Element
#include "leetcode.h"

/*
 * given an array 'nums' of size 'n', return the majority element. the majority
 * element is the element that appears more than 'floor(n / 2)' times. you may
 * assume that the majority element always exists in the array.
 */

int majorityElement(int *nums, int nums_size) {
  int key, j;
  if (nums_size == 1)
    return nums[0];
  for (int i = 0; i < nums_size; i++) {
    key = nums[i];
    j = i - 1;
    while (j >= 0 && nums[j] > key) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = key;
  }
  return nums[nums_size / 2];
}

int main() {
  int n1[] = {3, 2, 3}, n2[] = {2, 2, 1, 1, 1, 2, 2};
  printf("%d\n", majorityElement(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", majorityElement(n2, ARRAY_SIZE(n2))); // expect: 2
}
