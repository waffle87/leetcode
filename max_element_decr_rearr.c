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

int maximumElementAfterDecrementingAndRearranging(int *arr, int arrSize) {
  int *cnts = (int *)calloc(arrSize + 1, sizeof(int)), ans = 1;
  for (int i = 0; i < arrSize; i++)
    cnts[arr[i] < arrSize ? arr[i] : arrSize]++;
  for (int i = 2; i <= arrSize; i++)
    ans = (ans + cnts[i] < i) ? ans + cnts[i] : i;
  free(cnts);
  return ans;
}

int main() {
  int a1[] = {2, 2, 1, 2, 1};
  int a2[] = {100, 1, 1000};
  int a3[] = {1, 2, 3, 4, 5};
  int r1 = maximumElementAfterDecrementingAndRearranging(a1, ARRAY_SIZE(a1));
  int r2 = maximumElementAfterDecrementingAndRearranging(a2, ARRAY_SIZE(a2));
  int r3 = maximumElementAfterDecrementingAndRearranging(a3, ARRAY_SIZE(a3));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == 5);
}
