// 33. Search in Rotated Sorted Array
#include <stdio.h>
#include <stdlib.h>

/*
 * there is an integer array 'nums' sorted in ascending order (with distinct
 * values). prior to being passed to your function, 'nums' is possibly rotated
 * at an unknown pivot index 'k(1 <= k < nums.length)' such tht the resulting
 * array is '[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ...,
 * nums[k - 1]]' (0-indxed). for example, '[0,1,2,4,5,6,7]' might be rotated at
 * pivot index 3 and become '[4,5,6,7,0,1,2]'. given the array 'nums' after the
 * possible rotation and an integer 'target', return the index of 'target' if it
 * is in 'nums', or -1 otherwise. you must write an algorithm with 'O(log n)'
 * runtime complexity
 */

int search(int *nums, int nums_size, int target) {
  int left, right;
  for (left = 0, right = nums_size - 1; left <= right;) {
    int mid = (left + right) / 2;
    if (nums[mid] == target)
      return mid;
    if (nums[left] <= nums[mid]) {
      if (nums[left] <= target && target < nums[mid])
        right = mid - 1;
      else
        left = mid + 1;
    } else {
      if (nums[mid] < target && target <= nums[right])
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  return -1;
}

int main() {
  int n1[] = {4, 5, 6, 7, 0, 1, 2}, n2[] = {4, 5, 6, 7, 0, 1, 2}, n3[] = {1};
  printf("%d\n", search(n1, 7, 0)); // expect: 4
  printf("%d\n", search(n2, 7, 3)); // expect: -1
  printf("%d\n", search(n3, 1, 0)); // expect: -1
}
