#include "leetcode.h"

class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    int n = nums.size(), minI[n];
    stack<int> s;
    minI[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
      minI[i] = min(minI[i - 1], nums[i]);
    for (int i = nums.size() - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= minI[i])
        s.pop();
      if (!s.empty() && s.top() < nums[i])
        return true;
      s.push(nums[i]);
    }
    return false;
  }
};

int main() {
  vector<int> nums = {1, 3, 2, 4};
  Solution obj;
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << ' ';
  cout << endl << "searching for '132'...\n";
  if (obj.find132pattern(nums))
    cout << "found";
  else
    cout << "not found";
}
