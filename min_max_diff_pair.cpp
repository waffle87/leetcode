// 2616. Minimize the Maximum Difference of Pairs
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums' and an integer 'p'. find 'p' pairs of
 * indices of 'nums' such that the maximum difference amongst all the pairs is
 * minimised. also, ensure no index appears more than once amongst that 'p'
 * pairs. note that for a pair of elements at the index 'i' and 'j'. the
 * difference of this pair is '|nums[i] - nums[j]|', where '|x|' represents the
 * absolute value of 'x'. return the minimum maximum difference among all 'p'
 * pairs. we define the maximum of an empty set to be zero.
 */

class Solution {
  bool can_form_pair(vector<int> &nums, int p, int mid) {
    int cnt = 0;
    for (int i = 0; i < nums.size() - 1 && cnt < p;) {
      if (nums[i + 1] - nums[i] <= mid) {
        cnt++;
        i += 2;
      } else
        i++;
    }
    return cnt >= p;
  }

public:
  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.end() - nums.begin();
    while (left < right) {
      int mid = (left + right) / 2;
      if (can_form_pair(nums, p, mid))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {10, 1, 2, 7, 1, 3}, n2 = {4, 2, 1, 2};
  printf("%d\n", obj.minimizeMax(n1, 2)); // expect: 1
  printf("%d\n", obj.minimizeMax(n2, 1)); // expect: 0
}
