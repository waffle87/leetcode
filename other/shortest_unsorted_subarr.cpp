#include "leetcode.h"

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int end = -1, start = 0;
    int max = nums[0], min = nums[nums.size() - 1];
    for (int i = 1; i < nums.size(); i++) {
      if (max > nums[i])
        end = i;
      else
        max = nums[i];
    }
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (min < nums[i])
        start = i;
      else
        min = nums[i];
    }
    return end - start + 1;
  }
};

int main() {
  vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  Solution obj;
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << ' ';
  cout << endl << obj.findUnsortedSubarray(nums);
}
