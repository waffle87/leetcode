// 239. Sliding Window Maximum
#include "leetcode.h"

/*
 * given an array of integers 'nums', there is a sliding window of size 'k',
 * which is moving from the very left of the array to the very right. you can
 * only see the 'k' numbers in each window. each time the sliding window moves
 * right by one position. return the max sliding window.
 */

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (!dq.empty() && dq.front() == i - k)
        dq.pop_front();
      while (!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();
      dq.push_back(i);
      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 3, -1, -3, 5, 3, 6, 7}, n2 = {1};
  for (auto i : obj.maxSlidingWindow(n1, 3))
    printf("%d ", i); // expect: 3,3,5,5,6,7
  printf("\n");
  for (auto i : obj.maxSlidingWindow(n2, 1))
    printf("%d ", i); // expect: 1
  printf("\n");
}
