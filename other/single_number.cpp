#include "leetcode.h"

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans;
    /*
     * unordered_map to track frequency
     * unordered_map<key data type, value data type>
     * both are int in this case.
     */
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++)
      /*
       * store frequency
       * given 4, 1, 2, 1, 2
       * 4 -> once
       * 1 -> twice
       * 2 -> twice
       * output: 4
       */
      freq[nums[i]]++;
    for (auto i : freq)    // traverse map
      if (i.second == 1) { // if frequency of any element is 1...
        ans = i.first;     // that's the answer
        break;             // exit loop because we have our answer
      }
    return ans;
  }
};

int main() {
  vector<int> nums = {4, 1, 2, 1, 2};
  Solution obj;
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << ' ';
  cout << endl << obj.singleNumber(nums);
}
