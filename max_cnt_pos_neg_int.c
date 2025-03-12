// 2529. Maximum Count of Positive Integer and Negative Integer
#include "leetcode.h"

/*
 * given an array 'nums' sorted in non-decreasing order, return the maximum
 * between the number of positive integers and he number of negative integers.
 * note that '0' is neither positive nor negative.
 */

int pos(long cnt) { return (int)(cnt >> 32); }

int neg(long cnt) { return (int)(cnt & 0x0000FFFFL); }

long sum(int n) {
  if (n > 0)
    return 1L << 32;
  else if (n < 0)
    return 1L;
  else
    return 0L;
}

int maximumCount(int *nums, int numsSize) {
  long cnt = 0;
  for (int i = 0; i < numsSize; i++)
    cnt += sum(nums[i]);
  return fmax(pos(cnt), neg(cnt));
}

int main() {
  int n1[] = {-2, -1, -1, 1, 2, 3}, n2[] = {-3, -2, -1, 0, 0, 1, 2},
      n3[] = {5, 20, 66, 1314};
  printf("%d\n", maximumCount(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", maximumCount(n2, ARRAY_SIZE(n2))); // expect: 3
  printf("%d\n", maximumCount(n3, ARRAY_SIZE(n3))); // expect: 4
}
