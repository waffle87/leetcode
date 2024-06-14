// 1793. Maximum Score of a Good Subarray
#include "leetcode.h"

/*
 * given an array of integers 'nums' (0-indexed) and an integer 'k'. the score
 * of a subarray '(i, j)' is defined as 'min(nums[i], nums[i + 1], ..., nums[j])
 * * (j - i + 1)'. a good subarray is a subarray where 'i <= k <= j'. return the
 * maximum possible score of a good subarray.
 */

class Solution {
public:
  int maximumScore(vector<int> &nums, int k) {
    nums.push_back(0);
    stack<int> st;
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && nums[st.top()] >= nums[i]) {
        int height = nums[st.top()];
        st.pop();
        int left = st.empty() ? -1 : st.top();
        if (k < i && k > left)
          ans = max(ans, height * (i - left - 1));
      }
      st.push(i);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 4, 3, 7, 4, 5}, n2 = {5, 5, 4, 5, 4, 1, 1, 1};
  printf("%d\n", obj.maximumScore(n1, 3)); // expect: 15
  printf("%d\n", obj.maximumScore(n2, 0)); // expect: 20
}
