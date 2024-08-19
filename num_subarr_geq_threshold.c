// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to
// Threshold
#include "leetcode.h"

/*
 * given an array of integers 'arr' and two integers 'k' and 'threshold', return
 * the numberof subarrays of size 'k' and average greater than or equal to
 * 'threshold'
 */

int numOfSubarrays(int *arr, int arrSize, int k, int threshold) {
  int sum = 0, cnt = 0;
  for (int i = 0; i < k; i++)
    sum += arr[i];
  if (sum / k >= threshold)
    cnt++;
  for (int i = k; i < arrSize; i++) {
    sum += arr[i] - arr[i - k];
    if (sum / k >= threshold)
      cnt++;
  }
  return cnt;
}

int main() {
  int a1[] = {2, 2, 2, 2, 5, 5, 5, 8},
      a2[] = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  printf("%d\n", numOfSubarrays(a1, ARRAY_SIZE(a1), 3, 4)); // expect: 3
  printf("%d\n", numOfSubarrays(a2, ARRAY_SIZE(a2), 3, 5)); // expect: 6
}
