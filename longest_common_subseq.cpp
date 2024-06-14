#include "leetcode.h"

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    short ans[2][1000] = {};
    for (int i = 0; i < text1.size(); ++i)
      for (int j = 0; j < text2.size(); ++j)
        ans[!(i % 2)][j + 1] = text1[i] == text2[j]
                                   ? ans[i % 2][j] + 1
                                   : max(ans[i % 2][j + 1], ans[!(i % 2)][j]);
    return ans[text1.size() % 2][text2.size()];
  }
};

int main() {
  Solution obj;
  cout << obj.longestCommonSubsequcne("abcde", "ace");       // 3
  cout << endl << obj.longestCommonSubsequcne("abc", "abc"); // 3
}
