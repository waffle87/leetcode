// 1802. Maximum Value at a Given Index in a Bounded Array
#include "leetcode.h"

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

class Solution {
  bool check(int n, int i, int max_sum, int m) {
    for (int d = 1; max_sum >= 0 && d < m && i + d < n; ++d)
      max_sum -= m - d;
    for (int d = 1; max_sum >= 0 && d < m && i - d >= 0; ++d)
      max_sum -= m - d;
    return max_sum >= 0;
  }

public:
  int maxValue(int n, int index, int max_sum) {
    int left = 0, right = max_sum;
    while (left < right) {
      int mid = (left + right + 1) / 2;
      if (check(n, index, max_sum - n - mid, mid))
        left = mid;
      else
        right = mid - 1;
    }
    return left + 1;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.maxValue(4, 2, 6));  // expect: 2
  printf("%d\n", obj.maxValue(6, 1, 10)); // expect: 3
}
