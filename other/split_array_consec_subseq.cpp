#include "leetcode.h"

class Solution {
public:
  bool isPossible(vector<int> &nums) {
    unordered_map<int, int> um;
    for (auto &it : nums)
      um[it]++;
    for (auto &it : nums) {
      if (um[it] == 0)
        continue;
      int freq = um[it], curr = it, count = 0;
      while (um.count(curr) && um[curr] >= freq) {
        freq = fmax(freq, um[curr]);
        um[curr]--;
        count++;
        curr++;
      }
      if (count < 3)
        return false;
    }
    return true;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 4, 5};
  if (obj.isPossible(nums))
    cout << "true";
  else
    cout << "false";
}
