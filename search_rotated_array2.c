// 81. Search in Rotated Sorted Array II
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * there is an integer array 'nums' sorted in non-decreasing order (not
 * necessarily with distinct values). before being passed to your function,
 * 'nums' is rotated at an unknown pivot index 'k(0 <= k < nums.length)' such
 * that the resulting array is '[nums[k], nums[k + 1], ..., nums[n - 1],
 * nums[0], nums[1], ..., nums[k - 1]]' (0-indexed). for example
 * '[0,1,2,4,4,4,5,6,6,7]' might be rotated at a pivot index 5 and become
 * '[4,5,6,6,7,0,1,2,4,4]'. given the array 'nums' after the rotation and an
 * integer 'target', return true if 'target' is in 'nums' of 'false' if it is
 * not in 'nums'. you must decrease the overall operation steps as much as
 * possible.
 */

int find_min(int *nums, int nums_size) {
  int min_idx = 0;
  for (int i = 0; i + 1 < nums_size; i++)
    if (nums[i + 1] < nums[i]) {
      min_idx = i + 1;
      break;
    }
  return min_idx;
}

bool search(int *nums, int nums_size, int target) {
  if (nums_size == 1)
    return nums[0] == target ? 1 : 0;
  int start = find_min(nums, nums_size), end = start + nums_size;
  int arr_size = 2 * nums_size;
  int *arr = (int *)malloc(arr_size * sizeof(int));
  for (int i = 0; i < arr_size; i++)
    arr[i] = nums[i % nums_size];
  bool is_find = false;
  while (start < end) {
    int mid = start + (end - start) / 2;
    if (target == arr[mid]) {
      is_find = true;
      break;
    } else if (target < arr[mid])
      end = mid;
    else
      start = mid + 1;
  }
  free(arr);
  return is_find;
}

int main() {
  int nums[] = {2, 5, 6, 0, 0, 1, 2}, nums_size = 7;
  printf("%d\n", search(nums, nums_size, 0)); // expect: 1
  printf("%d\n", search(nums, nums_size, 3)); // expect: 0
}
