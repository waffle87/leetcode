// 1877. Minimize Maximum Pair Sum in Array
#include "leetcode.h"

/*
 * the pair sum of pair '(a, b)' is equal to 'a + b'. the maximum pair sum is
 * the largest pair sum in a list of pairs. given an array 'nums' of even length
 * 'n', pair up the lements of 'nums' into 'n / 2' pairs such that each element
 * of 'nums' is in exactly one pair and the maximum pair sum is minimised.
 * return the minimised maximium pair sum after optimally pairing up the
 * elements.
 */

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int minPairSum(int *nums, int nums_size) {
  qsort(nums, nums_size, sizeof(int), cmp);
  int start = 0, end = nums_size - 1, ans = 0;
  while (start < end) {
    int tmp = nums[start++] + nums[end--];
    ans = tmp > ans ? tmp : ans;
  }
  return ans;
}

int main() {
  int n1[] = {3, 5, 2, 3}, n2[] = {3, 5, 4, 2, 4, 6};
  printf("%d\n", minPairSum(n1, ARRAY_SIZE(n1))); // expect: 7
  printf("%d\n", minPairSum(n2, ARRAY_SIZE(n2))); // expect: 8
}
