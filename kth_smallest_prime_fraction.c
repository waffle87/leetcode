// 786. K-th Smallest Prime Fraction
#include "leetcode.h"

/*
 * given a sorted integer array 'arr' containing '1' and  prime numbers where
 * all the integers of 'arr' are unique. you are also given an integer 'k'. for
 * every 'i' and 'j' where '0 <= i < j < arr.len', we consider the fraction
 * 'arr[i] / arr[j]'. return the k'th smallest fraction considered. return your
 * answer as an array of integers of size '2'.
 */

int less_equal_position(int *nums, int n, int i, double val) {
  int left = i + 1, right = n - 1, mid;
  if (val < (double)nums[i] / nums[n - 1])
    return n;
  while (left < right) {
    mid = left + (right - left) / 2;
    double tmp = (double)nums[i] / nums[mid];
    if (tmp == val)
      return mid;
    if (tmp < val)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int *kthSmallestPrimeFraction(int *arr, int arrSize, int k, int *returnSize) {
  double left = 0, right = 1, mid;
  while (left < right) {
    mid = (left + right) / 2;
    int cnt = 0;
    for (int i = 0; i < arrSize - 1; i++) {
      int pos = less_equal_position(arr, arrSize, i, mid);
      cnt += (arrSize - pos);
    }
    if (cnt == k)
      break;
    if (cnt > k)
      right = mid;
    else
      left = mid;
  }
  double val = 0;
  int x = 0, y = 0;
  for (int i = 0; i < arrSize; i++)
    for (int j = i + 1; j < arrSize; j++) {
      double tmp = (double)arr[i] / arr[j];
      if (tmp <= mid) {
        if (val < tmp) {
          val = tmp;
          x = arr[i];
          y = arr[j];
        }
        break;
      }
    }
  int *ans = (int *)malloc(2 * sizeof(int));
  ans[0] = x;
  ans[1] = y;
  *returnSize = 2;
  return ans;
}

int main() {
  int a1[] = {1, 2, 3, 5}, a2[] = {1, 7}, rs1, rs2;
  int *ksmpf1 = kthSmallestPrimeFraction(a1, ARRAY_SIZE(a1), 3, &rs1);
  int *ksmpf2 = kthSmallestPrimeFraction(a2, ARRAY_SIZE(a2), 1, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ksmpf1[i]); // expect: 2 5
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ksmpf2[i]); // expect: 1 7
  printf("\n");
}
