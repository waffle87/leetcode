// 35. Search Insert Position
#include <stdio.h>
#include <stdlib.h>

/*
 * given a sorted array of distinct intergers and a target value, return the
 * index if the target is found. if not, return the index where it would be if
 * it were inserted in order. must be o(ln) compexity
 */

int searchInsert(int *nums, int numsSize, int target) {
  int left = 0, right = numsSize, mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (nums[mid] >= target)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int main() {
  int nums[] = {1, 3, 5, 6}, ns = 4;
  printf("%d\n", searchInsert(nums, ns, 5)); // expect: 2
  printf("%d\n", searchInsert(nums, ns, 2)); // expect: 1
  printf("%d\n", searchInsert(nums, ns, 7)); // expect: 4
}
