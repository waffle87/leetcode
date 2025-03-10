// 215. Kth Largest Element in an Array
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k', return the k'th largest
 * element in the array. note that it is the k'th largest elemented in sorted
 * order, not the k'th distinct element. can you solve without sorting?
 */

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 1; i < k; i++)
      pq.pop();
    return pq.top();
  }
};

int main() {
  Solution obj;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  cout << obj.findKthLargest(nums, k);
}
