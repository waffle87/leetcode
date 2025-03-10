#include "leetcode.h"

class Solution {
public:
  string findLongestWord(string s, vector<string> &dictionary) {
    string ans;
    for (auto d : dictionary)
      if (canForm(d, s))
        if (d.size() > ans.size() || (d.size() == ans.size() && d < ans))
          ans = d;
    return ans;
  }

private:
  bool canForm(string w, string s) {
    int w1 = 0, s1 = 0;
    while (w1 < w.size() && s1 < s.size()) {
      if (w[w1] == s[s1])
        w1++;
      s1++;
    }
    return w1 == w.size();
  }
};

int main() {
  Solution obj;
  string s = "abpcplea";
  vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
  cout << obj.findLongestWord(s, dictionary);
}
