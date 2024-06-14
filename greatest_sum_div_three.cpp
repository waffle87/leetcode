// 1262. Greatest Sum Divisible by Three
#include "leetcode.h"

/*
 * given an integer array 'nums', return the maximum possible sum of elements of
 * the array such that it is divisible by three
 */

class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    int f1 = 10001, s1 = 10001, f2 = 10001, s2 = 10001, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (nums[i] % 3 == 1) {
        if (nums[i] < f1) {
          s1 = f1;
          f1 = nums[i];
        } else if (nums[i] < s1)
          s1 = nums[i];
      } else if (nums[i] % 3 == 2) {
        if (nums[i] < f2) {
          s2 = f2;
          f2 = nums[i];
        } else if (nums[i] < s2)
          s2 = nums[i];
      }
    }
    if (!(sum % 3))
      return sum;
    if (sum % 3 == 1)
      return sum - min(f1, f2 + s2);
    return sum - min(f2, f1 + s1);
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {3, 6, 5, 1, 8}, n2 = {4}, n3 = {1, 2, 3, 4, 4};
  printf("%d\n", obj.maxSumDivThree(n1)); // expect: 18
  printf("%d\n", obj.maxSumDivThree(n2)); // expect: 0
  printf("%d\n", obj.maxSumDivThree(n3)); // expect: 12
}
