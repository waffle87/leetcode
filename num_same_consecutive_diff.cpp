#include "leetcode.h"

class Solution {
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> ans;
    for (int i = 1; i < 10; i++)
      findNum(i, n, k, ans);
    return ans;
  }

private:
  int digits(int x) {
    int count = 0;
    while (x) {
      count++;
      x /= 10;
    }
    return count;
  }
  void findNum(int curr, int n, int k, vector<int> &ans) {
    if (digits(curr) == n) {
      ans.push_back(curr);
      return;
    }
    for (int i = 0; i < 10; i++) {
      int last = curr % 10;
      if (abs(last - i) == k)
        findNum((curr * 10 + i), n, k, ans);
    }
  }
};
