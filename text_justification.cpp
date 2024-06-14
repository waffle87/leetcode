#include "leetcode.h"

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> ans, taken;
    int lineLen = 0;
    for (auto word : words) {
      if (lineLen + word.size() + taken.size() > maxWidth) {
        ans.push_back(lineBegin(taken, maxWidth - lineLen));
        taken.clear();
        taken.push_back(word);
        lineLen = word.size();
      } else {
        taken.push_back(word);
        lineLen += word.size();
      }
    }
    ans.push_back(lineEnd(taken, maxWidth - lineLen));
    return ans;
  }

private:
  string lineBegin(vector<string> &v, int toFill) {
    string ans = "";
    if (v.size() == 1) {
      ans += v[0];
      while (toFill--)
        ans += ' ';
      return ans;
    }
    int space = toFill / (v.size() - 1);
    int extras = toFill % (v.size() - 1);
    ans += v[0];
    for (int i = 1; i < v.size(); i++) {
      for (int j = 0; j < space; j++)
        ans += ' ';
      if (extras) {
        extras--;
        ans += ' ';
      }
    }
    return ans;
  }
  string lineEnd(vector<string> &v, int toFill) {
    string ans = v[0];
    for (int i = 1; i < v.size(); i++) {
      toFill--;
      ans += ' ';
      ans += v[i];
    }
    while (toFill--)
      ans += ' ';
    return ans;
  }
};
