#include "leetcode.h"

class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
      if (freq[k - nums[i]] > 0) {
        ans++;
        freq[k - nums[i]]--;
      } else
        freq[nums[i]]++;
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution obj;
  cout << obj.maxOperations(nums, 5);
}
