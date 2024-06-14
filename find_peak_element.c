// 162. Find Peak Element
#include "leetcode.h"

/*
 * a peak element is an element that is strictly greater than its neighbours.
 * given a 0 indexed array 'nums', find a peak element and return its index. if
 * the array contains multiple peaks, return the index to any of the peaks. you
 * may imagine that 'nums[-1] = nums[n] = -inf' in other words, an element is
 * always considered to be strictly greater than a neighbour that is outside the
 * array. you must write an algorithm that runs in 'O(log n)' time.
 */

int findPeakElement(int *nums, int numsSize) {
  if (numsSize == 1)
    return 0;
  if (numsSize == 2)
    return nums[0] > nums[1] ? 0 : 1;
  int left = 0, right = numsSize - 1, mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (!mid)
      break;
    if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
      return mid;
    else if (nums[mid] > nums[mid - 1])
      left = mid + 1;
    else
      right = mid - 1;
  }
  if (right < numsSize - 1 && right) {
    if (nums[right] > nums[right + 1] && nums[right] > nums[right - 1])
      return right;
  } else if (left < numsSize - 1 && left) {
    if (nums[left] > nums[left + 1] && nums[left] > nums[left - 1])
      return left;
  } else
    return !left ? left : right;
  return 0;
}

int main() {
  int n1[] = {1, 2, 3, 1}, n2[] = {1, 2, 1, 3, 5, 6, 4};
  printf("%d\n", findPeakElement(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", findPeakElement(n2, ARRAY_SIZE(n2))); // expect: 5
}
