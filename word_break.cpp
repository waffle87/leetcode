// 139. Word Break
#include "leetcode.h"

/*
 * given a string 's' and a dictionary of strings 'word_dict', return 'true' if
 * 's' can be segmented into a space-separated sequence of one or more
 * dictionary words. note that the same word in the dictionary may be reused
 * multiple times in the segmentation.
 */

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &word_dict) {
    if (!word_dict.size())
      return false;
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++)
      for (int j = i - 1; j >= 0; j--)
        if (dp[j]) {
          string word = s.substr(j, i - j);
          if (word_dict.find(word) != word_dict.end()) {
            dp[i] = true;
            break;
          }
        }
    return dp[s.size()];
  }
};

int main() {
  Solution obj;
  unordered_set<string> wd1 = {"leet", "code"}, wd2 = {"apple", "pen"},
                        wd3 = {"cats", "dog", "sand", "and", "cat"};
  printf("%d\n", obj.wordBreak("leetcode", wd1));      // expect: 1
  printf("%d\n", obj.wordBreak("applepenapple", wd2)); // expect: 1
  printf("%d\n", obj.wordBreak("catsandog", wd3));     // expect: 0
}
