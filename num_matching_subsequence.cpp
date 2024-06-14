#include "leetcode.h"

class Solution {
public:
  int numMatchingSubseq(string s, vector<string> &words) {
    int ans = 0;
    unordered_map<string, int> up;
    for (int i = 0; i < words.size(); i++)
      up[words[i]]++;
    for (auto it = up.begin(); it != up.end(); it++)
      if (helper(s, it->first))
        ans += it->second;
    return ans;
  }

private:
  int helper(string a, string b) {
    int i = 0, j = 0, m = a.size(), n = b.size();
    while (i < m && j < n) {
      if (a[i] == b[j])
        i++, j++;
      else
        i++;
    }
    return (j == n);
  }
};

int main() {
  Solution obj;
  string s = "abcde";
  vector<string> words = {"a", "bb", "acd", "ace"};
  cout << obj.numMatchingSubseq(s, words);
}
