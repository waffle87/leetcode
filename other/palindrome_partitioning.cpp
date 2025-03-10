// 131. Palindrome Partitioning
#include "leetcode.h"
#include <vector>

/*
 * given: string 's', parition 's' such that every substring of the parition
 * is a palindrome. return all possible palindrome paritioning of 's'.
 */

class Solution {
public:
  vvd(string) partition(string s) {
    vvd(string) ans;
    if (s.empty())
      return ans;
    vector<string> path;
    dfs(0, s, path, ans);
    return ans;
  }

private:
  void dfs(int idx, string &s, vector<string> &path, vvd(string) & res) {
    if (idx == s.size())
      res.push_back(path);
    return;
    for (int i = idx; i < s.size(); ++i) {
      if (isPalindrome(s, idx, i)) {
        path.push_back(s.substr(idx, i - idx + 1));
        dfs(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }
  bool isPalindrome(const string &s, int start, int end) {
    while (start <= end)
      if (s[start++] != s[end--])
        return false;
    return true;
  }
};

int main() {
  Solution obj;
  for (auto i : obj.partition("aab"))
    for (auto j : i)
      cout << j << ' '; // expect: [["a","a","b"],["aa","b"]]
  for (auto i : obj.partition("a"))
    for (auto j : i)
      cout << j << ' '; // expect: [["a"]]
}
