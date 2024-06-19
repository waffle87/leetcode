// 1283. Find the Smallest Divisor Given a Threshold
#include "leetcode.h"

/*
 * given an array of integers 'nums' and an integer 'threshold', we will choose
 * a positive integer 'divisor', divide all the array by it and sum the
 * divisions result. find the smallest divisor such that the result mentioned
 * above is less than or equal to 'threshold'. each result of the division is
 * rounded to the nearest integer greater than or equal to that element. the
 * test cases are generated so that there will be an answer
 */

int divide(int *nums, int numsSize, double k) {
  int res = 0;
  for (int i = 0; i < numsSize; i++)
    res += ceil(nums[i] / k);
  return res;
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int smallestDivisor(int *nums, int numsSize, int threshold) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int left = 1, right = 1000000, mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (divide(nums, numsSize, mid) <= threshold)
      right = mid;
    else
      left = mid + 1;
  }
  mid = (left + right) / 2;
  return mid;
}

int main() {
  int n1[] = {1, 2, 5, 9}, n2[] = {44, 22, 33, 11, 1};
  printf("%d\n", smallestDivisor(n1, ARRAY_SIZE(n1), 6)); // expect: 5
  printf("%d\n", smallestDivisor(n2, ARRAY_SIZE(n2), 5)); // expect: 44
}
