// 1846. Maximum Element After Decreasing and Rearranging
#include "leetcode.h"

/*
 * given an array of positive integers 'arr', perform some operations on 'arr'
 * so that it satisfies these conditions:
 * - the value of the first element in 'arr' must be 1
 * - the absolute difference between any two adjacent elements must be less than
 * or equal to 1. in other words 'abs(arr[i] - arr[i - 1]) <= 1' for each i
 * where 1 <= i < arr.length (0-indexed). 'abs(x)' is the absolute value of 'x'
 * there are two types operations that you can perform any number of times:
 * decrease the value of any element of 'arr' to a smaller positive integer
 * rearrange the elements of 'arr' to be in any order
 * return the maximum possible value of an element in 'arr' after performing the
 * operations to satisfy the conditions.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int maximumElementAfterDecrementingAndRearranging(int *arr, int arr_size) {
  qsort(arr, arr_size, sizeof(int), cmp);
  int ans = 0, x = 1;
  for (int i = 0; i < arr_size; i++)
    if (arr[i] >= x) {
      ans = (ans < x) ? x : ans;
      x++;
    }
  return ans;
}

int main() {
  int a1[] = {2, 2, 1, 2, 1}, a2[] = {100, 1, 1000}, a3[] = {1, 2, 3, 4, 5};
  printf("%d\n", maximumElementAfterDecrementingAndRearranging(
                     a1, ARRAY_SIZE(a1))); // expect: 2
  printf("%d\n", maximumElementAfterDecrementingAndRearranging(
                     a2, ARRAY_SIZE(a2))); // expect: 3
  printf("%d\n", maximumElementAfterDecrementingAndRearranging(
                     a3, ARRAY_SIZE(a3))); // expect: 5
}
