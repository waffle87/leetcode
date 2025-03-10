#include "leetcode.h"

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> us;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
      us.insert(nums[i]);
    while (us.size() > 0) {
      int num = *us.begin();
      int count = 1;
      us.erase(num);
      int smaller = num - 1;
      int bigger = num + 1;
      while (us.count(smaller) > 0) {
        us.erase(smaller);
        smaller--;
        count++;
      }
      while (us.count(bigger) > 0) {
        us.erase(bigger);
        bigger++;
        count++;
      }
      ans = max(ans, count);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  cout << obj.longestConsecutive(nums);
}
