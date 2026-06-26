// 3739. Count Subarrays With Majority Element II
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'target'. return the
 * number of subarrays of 'nums' in which 'target' is the majority element. the
 * majority element of a subarray is the element that appears strictly more than
 * half of the times in that subarray.
 */

long long countMajoritySubarrays(int *nums, int numsSize, int target) {
  int balance = 0, shift = numsSize, smaller = 0;
  long long ans = 0;
  int *freq = (int *)calloc(numsSize * 2 + 1, sizeof(int));
  freq[shift] = 1;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == target) {
      smaller += freq[balance + shift];
      balance++;
    } else {
      balance--;
      smaller -= freq[balance + shift];
    }
    ans += smaller;
    freq[balance + shift]++;
  }
  free(freq);
  return ans;
}

int main() {
  int n1[] = {1, 2, 2, 3};
  int n2[] = {1, 1, 1, 1};
  int n3[] = {1, 2, 3};
  long long r1 = countMajoritySubarrays(n1, ARRAY_SIZE(n1), 2);
  long long r2 = countMajoritySubarrays(n2, ARRAY_SIZE(n2), 1);
  long long r3 = countMajoritySubarrays(n3, ARRAY_SIZE(n3), 4);
  printf("%lld\n", r1);
  assert(r1 == 5);
  printf("%lld\n", r2);
  assert(r2 == 10);
  printf("%lld\n", r3);
  assert(r3 == 0);
}
