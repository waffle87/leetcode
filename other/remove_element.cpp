#include "leetcode.h"

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int idx = 0, k = nums.size();
    while (idx < k) {
      if (nums[idx] == val) {
        //          cout << "idx " << idx << endl;
        //          cout << "k " << k << endl;
        nums[idx] = nums[k - 1];
        --k;
      } else
        ++idx;
    }
    return k;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << ' ';
  cout << endl << nums.size() << endl;
  cout << obj.removeElement(nums, val);
}
