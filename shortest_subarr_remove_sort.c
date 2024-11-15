// 1574. Shortest Subarray to be Removed to Make Array Sorted
#include "leetcode.h"

/*
 * given an integer array 'arr', remove a subarray (can be empty) from 'arr'
 * such that the remaining elements in 'arr' are non-decreasing. return the
 * length of the shortest subarray to remove. a subarray is a contiguous
 * subsequence of the array.
 */

int findLengthOfShortestSubarray(int *arr, int arrSize) {
  int left = 0, right = arrSize - 1;
  while (left + 1 < arrSize && arr[left] <= arr[left + 1])
    left++;
  if (left == arrSize - 1)
    return 0;
  while (right > left && arr[right - 1] <= arr[right])
    right--;
  int ans = arrSize - left - 1 < right ? arrSize - left - 1 : right;
  int i = 0, j = right;
  while (i <= left && j < arrSize) {
    if (arr[j] >= arr[i]) {
      ans = ans < j - i - 1 ? ans : j - i - 1;
      i++;
    } else
      j++;
  }
  return ans;
}

int main() {
  int a1[] = {1, 2, 3, 10, 4, 2, 3, 5}, a2[] = {5, 4, 3, 2, 1},
      a3[] = {1, 2, 3};
  printf("%d\n", findLengthOfShortestSubarray(a1, ARRAY_SIZE(a1))); // expect: 3
  printf("%d\n", findLengthOfShortestSubarray(a2, ARRAY_SIZE(a2))); // expect: 4
  printf("%d\n", findLengthOfShortestSubarray(a3, ARRAY_SIZE(a3))); // expect: 0
}
