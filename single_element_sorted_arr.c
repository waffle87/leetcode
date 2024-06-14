// 540. Single Element in a Sorted Array
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given a sorted array consisting of only integers where very element appears
 * exactly twice, except for one element which appears exactly once. return the
 * single element that appears only once. solution func must be o(ln) time and
 * o(1) space complexity.
 */

int singleNonDuplicate(int *nums, int nums_size) {
  if (nums_size == 1)
    return nums[0];
  if (nums[0] != nums[1])
    return nums[0];
  if (nums[nums_size - 1] != nums[nums_size - 2])
    return nums[nums_size - 1];
  int left = 2, right = nums_size - 3, mid;
  bool ptr_l, ptr_r;
  while (left < right) {
    mid = (left + right) / 2;
    ptr_l = (nums[mid] == nums[mid - 1]) ? true : false;
    ptr_r = (nums[mid] == nums[mid + 1]) ? true : false;
    // if ((ptr_l == false) && (ptr_r == false))
    if (!ptr_l && !ptr_r)
      return nums[mid];
    if (mid % 2 == 0) {
      if (ptr_l)
        right = mid - 2;
      else
        left = mid + 2;
    } else {
      if (ptr_r)
        right = mid - 1;
      else
        left = mid + 1;
    }
  }
  if (nums[left] != nums[left - 1] || nums[left] != nums[left + 1])
    return nums[left];
  else
    return nums[right];
}

int main() {
  int nums1[] = {1, 1, 2, 3, 3, 4, 4, 8, 8}, nums2[] = {3, 3, 7, 7, 10, 11, 11};
  printf("%d\n", singleNonDuplicate(nums1, 9)); // expect: 2
  printf("%d\n", singleNonDuplicate(nums2, 9)); // expect: 10
}
