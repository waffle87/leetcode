#include "leetcode.h"

class maxBit {
public:
  vector<int> bit;
  maxBit(int size) { bit.resize(size + 1); }
  int get(int idx) {
    int ans = 0;
    for (; idx > 0; idx -= idx & -idx)
      ans = max(ans, bit[idx]);
    return ans;
  }
  void update(int idx, int val) {
    for (; idx < bit.size(); idx += idx & -idx)
      bit[idx] = max(bit[idx], val);
  }
};

class Solution {
public:
  int lengthOisLIS(vector<int> &nums) {
    int uniqueNum = compress(nums);
    maxBit bit(uniqueNum);
    for (int x : nums) {
      int subLongest = bit.get(x - 1);
      bit.update(x, subLongest + 1);
    }
    return bit.get(uniqueNum);
  }

private:
  int compress(vector<int> &arr) {
    vector<int> uniqueSorted(arr);
    sort(uniqueSorted.begin(), uniqueSorted.end());
    uniqueSorted.erase(unique(uniqueSorted.begin(), uniqueSorted.end()),
                       uniqueSorted.end());
    for (int &x : arr)
      x = lower_bound(uniqueSorted.begin(), uniqueSorted.end(), x) -
          uniqueSorted.begin() + 1;
    return uniqueSorted.size();
  }
};

int main() {
  Solution obj;
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << obj.lengthOisLIS(nums);
}
