// 3201. Find the Maximum Length of Valid Subsequence I
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a subsequence 'sub' of 'nums' with
 * length 'x' is called valid if it satisfies '(sub[0] + sub[1]) % 2 == (sub[1]
 * + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2'. return the legnth of
 * the longest valid subsequences of 'nums'. a subsequence is an array that can
 * be derived from another array by deleting some or no elements without
 * changing the order of the remaining elements.
 */

int maximumLength(int *nums, int numsSize) {
  int odd_start = 0, even_start = 0;
  for (int i = 0; i < numsSize; i++) {
    if (!(nums[odd_start] % 2) && (nums[i] % 2 == 1))
      odd_start = i;
    if ((nums[even_start] % 2 == 1) && !(nums[i] % 2))
      even_start = i;
  }
  int odd_cnt1 = 1, odd_i1 = odd_start, odd_cnt2 = 1, odd_i2 = even_start;
  int even_cnt1 = 1, even_i1 = odd_start, even_cnt2 = 1, even_i2 = even_start;
  for (int i = odd_start + 1; i < numsSize; i++) {
    if ((nums[odd_i1] + nums[i]) % 2 == 1) {
      odd_i1 = i;
      odd_cnt1++;
    }
    if (!((nums[even_i1] + nums[i]) % 2)) {
      even_i1 = i;
      even_cnt1++;
    }
  }
  for (int i = even_start + 1; i < numsSize; i++) {
    if ((nums[odd_i2] + nums[i]) % 2 == 1) {
      odd_i2 = i;
      odd_cnt2++;
    }
    if (!((nums[even_i2] + nums[i]) % 2)) {
      even_i2 = i;
      even_cnt2++;
    }
  }
  int odd_max = fmax(odd_cnt1, odd_cnt2);
  int even_max = fmaxl(even_cnt1, even_cnt2);
  return fmax(odd_max, even_max);
}

int main() {
  int n1[] = {1, 2, 3, 4}, n2[] = {1, 2, 1, 1, 2, 1, 2}, n3[] = {1, 3};
  printf("%d\n", maximumLength(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", maximumLength(n2, ARRAY_SIZE(n2))); // expect: 6
  printf("%d\n", maximumLength(n3, ARRAY_SIZE(n3))); // expect: 2
}
