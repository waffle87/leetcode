#include "leetcode.h"

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j])
        nums1[k--] = nums1[i--];
      else
        nums1[k--] = nums2[j--];
    }
    while (j >= 0)
      nums1[k--] = nums2[j--];
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  int m = 3, n = 3;
  cout << "nums1:\n";
  for (auto i : nums1)
    cout << i;
  cout << "\nnums2:\n";
  for (auto i : nums2)
    cout << i;
  obj.merge(nums1, m, nums2, n);
  cout << "\nnums1 & nums2 merged:\n";
  for (auto i : nums1)
    cout << i;
}
