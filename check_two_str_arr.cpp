#include "leetcode.h"

class Solution {
public:
  bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
    int i = 0, j = 0, m = 0, n = 0;
    while (i < word1.size() && j < word2.size()) {
      if (word1[i][m++] != word2[j][n++])
        return false;
      if (m >= word1[i].size())
        i++, m = 0;
      if (n >= word2[j].size())
        j++, n = 0;
    }
    return i == word1.size() && j == word2.size();
  }
};

int main() {
  Solution obj;
  vector<string> word1 = {"ab", "c"}, word2 = {"a", "bc"};
  if (obj.arrayStringsAreEqual(word1, word2))
    cout << "true";
  else
    cout << "false";
}
