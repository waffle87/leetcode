// 1802. Maximum Value at a Given Index in a Bounded Array
#include <stdio.h>

/*
 * given three positive integers: 'n, index, and max_sum'. you want to construct
 * an array 'nums' (0-indexed) that satisfies the following conditions:
 * - nums.length == n
 * - nums[i] is a positive integer where 0 <= i < n
 * - abs(nums[i] - nums[i + 1]) <= 1 where 0 <= i < n - 1
 * - the sum of all the elements of 'nums' does not exceed 'max_sum'
 * - nums[index] is maximised
 * return 'nums[index]' of the constructed array. note that 'abs(x)' equals 'x'
 * if 'x >= 0' and '-x' otherwise
 */

int maxValue(int n, int index, int max_sum) {
  long long sum;
  int cnl = index, cnr = n - cnl - 1;
  int left = 1, right = max_sum, mid;
  while (left < right) {
    sum = 0;
    mid = right - (right - left) / 2;
    if (cnl) {
      if (mid > cnl)
        sum += ((long long)((mid - 1) + (mid - cnl)) * cnl / 2);
      else {
        sum += ((long long)((mid - 1) + 1) * (mid - 1) / 2);
        sum += (cnl - (mid - 1));
      }
    }
    if (cnr) {
      if (mid > cnr)
        sum += ((long long)((mid - 1) + (mid - cnr)) * cnr / 2);
      else {
        sum += ((long long)((mid - 1) + 1) * (mid - 1) / 2);
        sum += (cnr - (mid - 1));
      }
    }
    sum += mid;
    if (sum <= max_sum)
      left = mid;
    else
      right = mid - 1;
  }
  return left;
}

int main() {
  printf("%d\n", maxValue(4, 2, 6));  // expect: 2
  printf("%d\n", maxValue(6, 1, 10)); // expect: 3
}
