// 1470. Shuffle the Array
#include "leetcode.h"

/*
 * given array 'nums' consisting of '2n' elements in the form
 * [x1, x2, ..., xn, y1, y2, ..., yn]
 * return the array in the form [x1, y1, x2, y2, ..., xn, yn]
 */

class Solution {
public:
  vector<int> shuffle(vector<int> &nums, int n) {
    int len = nums.size();
    for (int i = n; i < len; i++)
      nums[i] = (nums[i] << 10) | nums[i - n];
    int idx = 0;
    for (int i = n; i < len; i++, idx += 2) {
      nums[idx] = nums[i] & 1023;
      nums[idx + 1] = nums[i] >> 10;
    }
    return nums;
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {2, 5, 1, 3, 4, 7};
  vector<int> nums2 = {1, 2, 3, 4, 4, 3, 2, 1};
  vector<int> nums3 = {1, 1, 2, 2};
  for (auto i : obj.shuffle(nums1, 3))
    cout << i << ' '; // expect: 2,3,5,4,1,7
  cout << endl;
  for (auto i : obj.shuffle(nums2, 4))
    cout << i << ' '; // expect: 1,4,2,3,3,2,4,1
  cout << endl;
  for (auto i : obj.shuffle(nums3, 2))
    cout << i << ' '; // expect: 1,2,1,2
  cout << endl;
}
