// 2845. Count of Interesting Subarrays
#include <stdio.h>
#include <stdlib.h>

/*
 * given a 0-indexed integer array 'nums' an integer 'modulo' and an integer
 * 'k'. your task is to find the count of subarrays that are interesting. a
 * subarray 'nums[l...r]' is interesting if the following condition holds: let
 * 'cnt' be the number of indices  'i' in the range '[l, r]' such that 'nums[i]
 * % modulo == k'. then 'cnt % modulo == k'. return an integer denoting thecount
 * of interesting subarrays. note a subarray is contiguous non-empty sequence of
 * elements within an array.
 */

long long countInterestingSubarrays(int *nums, int nums_size, int modulo,
                                    int k) {}

int main() {
  int n1[] = {3, 2, 4}, n2[] = {3, 1, 9, 6};
  printf("%lld\n", countInterestingSubarrays(n1, 3, 2, 1)); // expect: 3
  printf("%lld\n", countInterestingSubarrays(n2, 4, 3, 0)); // expect: 2
}
