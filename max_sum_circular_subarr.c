// 918. Maximum Sum Circular Subarray
#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/*
 * given: circular int array 'nums' of length 'n', return the max possible
 * sum of non-empty subarray of 'nums'
 *
 * a circular array means the end of the array connects to the beginning.
 * formally, the previous element of 'nums[i]' is 'nums[(i -/+ 1) % n]'
 *
 * a subarray may only include each element of the fixed buffer 'nums' at
 * most once. formally, for a subarray 'nums[i], nums[i + 1], ..., nums[j]'
 * there does not exist i <= k1, k2 <= j with k1 % n == k2 % n
 */

int helper(int *a, int n) {
  // kadane's dp algorithm
  // [https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d]
  int currMax, sum;
  sum = currMax = a[0];
  for (int i = 1; i < n; i++) {
    currMax = MAX(a[i], currMax + a[i]);
    sum = MAX(currMax, sum);
  }
  return sum;
}

int maxSubarraySumCircular(int *nums, int numsSize) {
  int k1, k2, total = 0;
  k1 = helper(nums, numsSize);
  for (int i = 0; i < numsSize; i++) {
    total += nums[i];
    nums[i] *= -1;
  }
  k2 = helper(nums, numsSize);
  int ans = total + k2;
  return (ans > k1 && ans != 0) ? ans : k1;
}

int main() {
  int nums1[] = {1, -2, 3, -2}, nums2[] = {5, -3, 5}, nums3[] = {-3, -2, -3};
  printf("%d\n", maxSubarraySumCircular(nums1, 4)); // expect: 3
  printf("%d\n", maxSubarraySumCircular(nums2, 3)); // expect: 3
  printf("%d\n", maxSubarraySumCircular(nums3, 3)); // expect: 3
}
