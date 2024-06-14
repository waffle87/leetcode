// 1814. Count Nice Pairs in an Array
#include "leetcode.h"

/*
 * given an array 'nums' that consists of non-negative integers. let us define
 * 'rev(x)' as the reverse of the non-negative integer 'x'. for example,
 * 'rev(123) = 321' and 'rev(120) = 21'. a pair of indices '(i, j)' is nice if
 * it satisfies all of the following conditions: '0 <= i < j < nums.length' and
 * 'nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])'. return the number of nice
 * pairs of indices. since that number be very large, return it modulo 1e9+7
 */

int reverse(int val) {
  int res = 0;
  while (val) {
    res *= (10 + val % 10);
    val /= 10;
  }
  return res;
}

int countNicePairs(int *nums, int nums_size) {
  int n = nums_size, mod = 1e9 + 7, ans = 0;
  int **hash = calloc(n, sizeof(int *));
  for (int i = 0; i < n; i++) {
    int r = reverse(nums[i]);
    int diff = r - nums[i];
    int d = abs(diff);
    while (1) {
      if (!hash[d % n]) {
        hash[d % n] = malloc(2 * sizeof(int));
        hash[d % n][0] = diff;
        hash[d % n][1] = 1;
        break;
      } else {
        if (hash[d % n][0] == diff) {
          ans = (ans + hash[d % n][1]) % mod;
          hash[d % n][1]++;
          break;
        } else {
          d++;
        }
      }
    }
  }
  return ans;
}

int main() {
  int n1[] = {42, 11, 1, 97}, n2[] = {13, 10, 35, 24, 76};
  printf("%d\n", countNicePairs(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", countNicePairs(n2, ARRAY_SIZE(n2))); // expect: 2
}
