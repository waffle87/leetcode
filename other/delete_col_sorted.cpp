#include "leetcode.h"

class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    int ans = 0;
    if (strs.empty())
      return ans;
    for (auto i = 0; i < strs[0].size(); ++i)
      for (auto j = 1; j < strs.size(); ++j)
        if (strs[j - 1][i] > strs[j][i]) {
          ++ans;
          break;
        }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<string> strs1 = {"cba", "daf", "ghi"}, strs2 = {"a", "b"},
                 strs3 = {"zyx", "wvu", "tsr"};
  cout << obj.minDeletionSize(strs1) << endl;
  cout << obj.minDeletionSize(strs2) << endl;
  cout << obj.minDeletionSize(strs3) << endl;
}
