// 2348. Number of Zero-Filled Subarrays
#include "leetcode.h"

// given integer array 'nums', return number of subarrays filled with zero. a
// subarray is a contiguous non-empty sequence of elements from within an array

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long ans = 0;
    short n = nums.size();
    for (int i = 0, j = 0; i < n; ++i) {
      if (nums[i] != 0)
        j = i + 1;
      ans += i - j + 1;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 3, 0, 0, 2, 0, 0, 4};
  vector<int> n2 = {0, 0, 0, 2, 0, 0};
  vector<int> n3 = {2, 10, 2019};
  printf("%lld\n", obj.zeroFilledSubarray(n1)); // expect: 6
  printf("%lld\n", obj.zeroFilledSubarray(n2)); // expect: 9
  printf("%lld\n", obj.zeroFilledSubarray(n3)); // expect: 0
}
