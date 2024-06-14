#include "leetcode.h"

class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    /*
     * important to assign vector values first:
     * vector... var(size, vals)
     */
    vector<int> ans(nums.size(), 0);

    /*
     * start at first element (0)
     * end at "last" element minus 1
     * because arrays initialize at 0
     */
    int start = 0, end = nums.size() - 1;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 1)
        /*
         * odd
         * assign "last" array value to current nums value
         * and incrementally decrease end when necessary
         */
        ans[end--] = nums[i];
      else
        /*
         * even
         * assign "first" array value to current nums value
         * and incrementally increase start when necessary
         */
        ans[start++] = nums[i];
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {3, 1, 2, 4};
  Solution obj;
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << ' ';
  cout << endl;
  obj.sortArrayByParity(nums);
}
