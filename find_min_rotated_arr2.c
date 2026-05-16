// 154. Find Minimum in Rotated Sorted Array II
#include "leetcode.h"

/*
 * suppose an array of length 'n' sorted in ascending order is rotated between 1
 * and 'n' times. given the sorted rotated array 'nums' that may contain
 * duplicates, return the minimum changes of this array. you must decrease the
 * overall operation steps as much as possible.
 */

int findMin(int *nums, int numsSize) {
  int left = 0, right = numsSize - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[right])
      left = mid + 1;
    else if (nums[mid] < nums[right])
      right = mid;
    else
      right--;
  }
  return nums[left];
}

int main() {
  int n1[] = {1, 3, 5}, n2[] = {2, 2, 2, 0, 1};
  int r1 = findMin(n1, ARRAY_SIZE(n1));
  int r2 = findMin(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 0);
}
