#include "leetcode.h"

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size())
      return false;
    vector<int> c1(26), c2(26);
    for (auto i = 0; i < word1.size(); ++i) {
      ++c1[word1[i] - 'a'];
      ++c2[word2[i] - 'a'];
    }
    if (!equal(begin(c1), end(c1), begin(c2), end(c2),
               [](int a, int b) { return (bool)a == bool(b); }))
      return false;
    sort(begin(c1), end(c1));
    sort(begin(c2), end(c2));
    return c1 == c2;
  }
};

int main() {
  Solution obj;
  if (obj.closeStrings("abc", "bca"))
    cout << "true";
  else
    cout << "false";
}
