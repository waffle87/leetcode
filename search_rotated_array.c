// 33. Search in Rotated Sorted Array
#include "leetcode.h"

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

int search(int *nums, int numsSize, int target) {
  int low = 0, high = numsSize - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (nums[mid] > nums[high])
      low = mid + 1;
    else
      high = mid;
  }
  int rot = low;
  low = 0;
  high = numsSize - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int real_mid = (mid + rot) % numsSize;
    if (nums[real_mid] == target)
      return real_mid;
    if (nums[real_mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int n1[] = {4, 5, 6, 7, 0, 1, 2}, n2[] = {4, 5, 6, 7, 0, 1, 2}, n3[] = {1};
  int r1 = search(n1, ARRAY_SIZE(n1), 0);
  int r2 = search(n2, ARRAY_SIZE(n2), 3);
  int r3 = search(n3, ARRAY_SIZE(n3), 0);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == -1);
  printf("%d\n", r3);
  assert(r3 == -1);
}
