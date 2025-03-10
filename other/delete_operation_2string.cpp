#include "leetcode.h"

class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    if (m < n) {
      swap(word1, word2);
      swap(n, m);
    }
    vector<int> last(n + 1, 0), curr(n + 1, 0);
    for (char char1 : word1) {
      for (int i = 0; i < n; i++)
        curr[i + 1] =
            char1 == word2[i] ? last[i] + 1 : max(curr[i], last[i + 1]);
      swap(last, curr);
    }
    return m + n - 2 * last[n];
  }
};

int main() {
  Solution obj;
  string word1 = "sea", word2 = "eat";
  cout << obj.minDistance(word1, word2);
}
