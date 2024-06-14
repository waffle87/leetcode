// 34. Find First and Last Position of Element in Sorted Array
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of integers 'nums' sorted in non-decreasing order, find the
 * starting ending position of a given 'target' value. if target is not found in
 * the array, return '[-1, -1]'. you must write an algorithm with O(log n)
 * runtime complexity
 */

int *searchRange(int *nums, int nums_size, int target, int *return_size) {
  int l = 0, r = nums_size - 1, mid = r / 2;
  *return_size = 2;
  int *ans = malloc(sizeof(int) * 2);
  ans[0] = -1;
  ans[1] = -1;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (target == nums[mid]) {
      int mid2 = mid;
      while (l < mid) {
        int l_mid = (mid + l) / 2;
        if (nums[l_mid] < target)
          l = l_mid + 1;
        else
          mid = l_mid;
      }
      while (mid2 < r) {
        int r_mid = (mid2 + r + 1) / 2;
        if (nums[r_mid] > target)
          r = r_mid - 1;
        else
          mid2 = r_mid;
      }
      ans[0] = l;
      ans[1] = r;
      return ans;
    } else if (target < nums[mid])
      r = mid - 1;
    else if (target > nums[mid])
      l = mid + 1;
  }
  return ans;
}

int main() {
  int n1[] = {5, 7, 7, 8, 8, 10}, n2[] = {5, 7, 7, 8, 8, 10}, n3[] = {};
  int *sr1 = searchRange(n1, 6, 8, NULL);
  int *sr2 = searchRange(n2, 6, 6, NULL);
  int *sr3 = searchRange(n3, 0, 0, NULL);
  for (int i = 0; i < 2; i++)
    printf("%d ", sr1[i]); // expect: 3 4
  printf("\n");
  for (int i = 0; i < 2; i++)
    printf("%d ", sr2[i]); // expect: -1 -1
  printf("\n");
  for (int i = 0; i < 2; i++)
    printf("%d ", sr3[i]); // expect: -1 -1
  printf("\n");
}
