// 2348. Number of Zero-Filled Subarrays
#include "leetcode.h"

// given integer array 'nums', return number of subarrays filled with zero. a
// subarray is a contiguous non-empty sequence of elements from within an array

long long zeroFilledSubarray(int *nums, int numsSize) {
  long long cnt = 0, streak = 0;
  for (int i = 0; i < numsSize; i++) {
    if (!nums[i]) {
      streak++;
      cnt += streak;
    } else
      streak = 0;
  }
  return cnt;
}

int main() {
  int n1[] = {1, 3, 0, 0, 2, 0, 0, 4};
  int n2[] = {0, 0, 0, 2, 0, 0};
  int n3[] = {2, 10, 2019};
  printf("%lld\n", zeroFilledSubarray(n1, 8)); // expect: 6
  printf("%lld\n", zeroFilledSubarray(n2, 6)); // expect: 9
  printf("%lld\n", zeroFilledSubarray(n3, 3)); // expect: 0
}
