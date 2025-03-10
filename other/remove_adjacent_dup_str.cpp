#include "leetcode.h"

class Solution {
public:
  string removeDuplicates(string s) {
    string ans;
    for (char &c : s) {
      if (ans.size() && c == ans.back())
        ans.pop_back();
      else
        ans.push_back(c);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.removeDuplicates("abbaca");
}
