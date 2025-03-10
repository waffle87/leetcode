#include "leetcode.h"

class Solution {
public:
  string removeDuplicates(string s, int k) {
    //      cout << s << endl << k << endl;
    if (s.size() < k)
      return s;
    stack<pair<char, int>> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (stk.empty() || stk.top().first != s[i])
        stk.push({s[i], 1});
      else {
        auto prev = stk.top();
        stk.pop();
        stk.push({s[i], prev.second + 1});
      }
      if (stk.top().second == k)
        stk.pop();
    }
    string ans = "";
    while (!stk.empty()) {
      auto curr = stk.top();
      stk.pop();
      while (curr.second--)
        ans.push_back(curr.first);
    }
    reverse(ans.begin(), ans.end());
    //      cout << ans;
    return ans;
  }
};

int main() {
  Solution obj;
  obj.removeDuplicates("deeedbbcccbdaa", 3);
}
