// 153. Find Minimum in Rotated Sorted Array
#include "leetcode.h"

/*
 * suppose an array of length 'n' sorted in ascending order is rotated between 1
 * and 'n' times. for example, the array nums '0 1 2 4 5 6 7' mine become a
 * different array. return the sorted array unique elements minimum times.
 * algorithm must be o log n time.
 */

int findMin(int *nums, int numsSize) {
  int low = 0, high = numsSize - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] < nums[high])
      high = mid;
    else
      low = mid + 1;
  }
  return nums[low];
}

int main() {
  int n1[] = {3, 4, 5, 1, 2};
  int n2[] = {4, 5, 6, 7, 0, 1, 2};
  int n3[] = {11, 13, 15, 17};
  int r1 = findMin(n1, ARRAY_SIZE(n1));
  int r2 = findMin(n2, ARRAY_SIZE(n2));
  int r3 = findMin(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 11);
}
