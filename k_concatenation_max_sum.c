// 1191. K-Concatenation Maximum Sum
#include "leetcode.h"

/*
 * given an integer array 'arr' and an integer 'k', modify the array by
 * repeating it 'k' times. for example, if 'arr = [1, 2]' and 'k = 3' then the
 * modified array will be '[1, 2, 1, 2, 1, 2]'. return the maximum sub array sum
 * in the modified array. note that the length of the sub array can be 0 and its
 * sum in that case is 0. as the answer can be very large, return the answer
 * modulo 1e9+7
 */

long long max_sum(int *arr, int arrSize) {
  long long max = 0, sum = 0;
  for (int i = 0; i < arrSize; i++) {
    sum += arr[i];
    max = sum > max ? sum : max;
    if (sum < 0)
      sum = 0;
  }
  return max;
}

int kConcatenationMaxSum(int *arr, int arrSize, int k) {
  int mod = 1e9 + 7;
  long long sum = 0;
  for (int i = 0; i < arrSize; i++)
    sum += arr[i];
  if (k < 2)
    return (int)(max_sum(arr, arrSize) % mod);
  int *double_arr = (int *)malloc(arrSize * 2 * sizeof(int));
  for (int i = 0; i < arrSize; i++) {
    double_arr[i] = arr[i];
    double_arr[i + arrSize] = arr[i];
  }
  if (sum < 0)
    return (int)(max_sum(double_arr, arrSize * 2) % mod);
  return (int)((max_sum(double_arr, arrSize * 2) + (k - 2) * sum) % mod);
}

int main() {
  int a1[] = {1, 2}, a2[] = {1, -2, 1}, a3[] = {-1, -2};
  printf("%d\n", kConcatenationMaxSum(a1, ARRAY_SIZE(a1), 3)); // expect: 9
  printf("%d\n", kConcatenationMaxSum(a2, ARRAY_SIZE(a2), 5)); // expect: 2
  printf("%d\n", kConcatenationMaxSum(a3, ARRAY_SIZE(a3), 7)); // expect: 0
}
