// 1671. Minimum Number of Removals to Make Mountain Array
#include "leetcode.h"

/*
 * you may recall that an array 'arr' is a mountain array if and only if
 * 'arr.length >= 3', there exists soome index 'i' with '0 < i < arr.length - 1'
 * such that 'arr[0] < arr[1] <... < arr[i - 1]' and 'arr[i] > arr[i + 1] > ...
 * > arr[length - 1]'. given an integer array 'nums', return the minimum number
 * of elements to remove to make 'nums' a mountain array
 */

class Solution {
public:
  int minimumMountainRemovals(vector<int> &nums) {
    int n = nums.size();
    vector<int> left(n), right(n), stk;
    for (int i = 0; i < n; i++) {
      if (stk.empty() || stk.back() < nums[i]) {
        stk.push_back(nums[i]);
        left[i] = stk.size();
      } else {
        auto iter = lower_bound(stk.begin(), stk.end(), nums[i]);
        *iter = nums[i];
        left[i] = iter - stk.begin() + 1;
      }
    }
    stk.clear();
    for (int i = n - 1; i >= 0; i--) {
      if (stk.empty() || stk.back() < nums[i]) {
        stk.push_back(nums[i]);
        right[i] = stk.size();
      } else {
        auto iter = lower_bound(stk.begin(), stk.end(), nums[i]);
        *iter = nums[i];
        right[i] = iter - stk.begin() + 1;
      }
    }
    int max_item = 0;
    for (int i = 0; i < n; i++)
      if (left[i] >= 2 && right[i] >= 2)
        max_item = max(max_item, left[i] + right[i] - 1);
    return n - max_item;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 3, 1}, n2 = {2, 1, 1, 5, 6, 2, 3, 1};
  printf("%d\n", obj.minimumMountainRemovals(n1)); // expect: 0
  printf("%d\n", obj.minimumMountainRemovals(n2)); // expect: 3
}
