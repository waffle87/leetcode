// 912. Sort an Array
#include "leetcode.h"
#include <vector>

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int end_idx, curr_idx, n = nums.size();
    if (n <= 1)
      return {};
    for (int i = n - 1; i; i--)
      for (int j = 0; j < i; j++)
        if (nums[j] > nums[j + 1])
          swap(nums[j], nums[j + 1]);
    return nums;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {5, 2, 3, 1}, n2 = {5, 1, 1, 2, 0, 0};
  for (auto i : obj.sortArray(n1))
    cout << i << ' '; // expect: 1,2,3,5
  cout << endl;
  for (auto i : obj.sortArray(n2))
    cout << i << ' '; // expect: 0,0,1,1,2,5
}
