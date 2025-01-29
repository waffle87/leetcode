// 72. Edit Distance
#include "leetcode.h"

/*
 * given two strings 'word1' and 'word2', return minimum number of operations
 * required to convert 'word1' to 'word2'. the following operations are
 * permitted: insert character, delete character, replace character
 */

class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vvd memo(m + 1, vector<int>(n + 1, -1));
    return editDistance(word1, word2, m, n, memo);
  }

private:
  int editDistance(string word1, string word2, int m, int n, vvd memo) {
    if (m == 0)
      return memo[m][n] = n;
    if (n == 0)
      return memo[m][n] = m;
    if (memo[m][n] != -1)
      return memo[m][n];
    if (word1[m - 1] == word2[n - 1])
      return memo[m][n] = editDistance(word1, word2, m - 1, n - 1, memo);
    else {
      int insertChar = editDistance(word1, word2, m, n - 1, memo);
      int deleteChar = editDistance(word1, word2, m - 1, n, memo);
      int replacChar = editDistance(word1, word2, m - 1, n - 1, memo);
      return memo[m][n] = 1 + min({insertChar, deleteChar, replacChar});
    }
  }
};

int main() {
  Solution obj;
  cout << obj.minDistance("horse", "ros") << endl;   // expect: 3
  cout << obj.minDistance("intention", "execution"); // expect: 5
}
