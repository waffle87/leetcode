#include "leetcode.h"

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};
    vector<string> ans;
    ans.push_back("");
    for (auto digit : digits) {
      vector<string> tmp;
      for (auto candidate : nums[digit - '0'])
        for (auto s : ans)
          tmp.push_back(s + candidate);
      ans.swap(tmp);
    }
    for (int i = 0; i < digits.size(); i++)
      cout << ans[i];
    return ans;
  }

private:
  const vector<string> nums = {"",    "",    "abc",  "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main() {
  string digits = "23";
  cout << digits << endl;
  Solution obj;
  obj.letterCombinations(digits);
}
