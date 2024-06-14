// 153. Find Minimum in Rotated Sorted Array
#include "leetcode.h"

/*
 * suppose an array of length 'n' sorted in ascending order is rotated between 1
 * and 'n' times. for example, the array nums '0 1 2 4 5 6 7' mine become a
 * different array. return the sorted array unique elements minimum times.
 * algorithm must be o log n time.
 */

int findMin(int *nums, int nums_size) {
  int low = 0, high = nums_size - 1;
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
  int n1[] = {3, 4, 5, 1, 2}, n2[] = {4, 5, 6, 7, 0, 1, 2},
      n3[] = {11, 13, 15, 17};
  printf("%d\n", findMin(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", findMin(n2, ARRAY_SIZE(n2))); // expect: 0
  printf("%d\n", findMin(n3, ARRAY_SIZE(n3))); // expect: 11
}
