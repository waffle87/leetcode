#include "leetcode.h"

class Solution {
public:
  vvd palindromePairs(vector<string> &words) {
    unordered_map<string, int> um;
    for (int i = 0; i < words.size(); i++) {
      string x = words[i];
      reverse(x.begin(), x.end());
      um[x] = i;
    }
    vvd ans;
    for (int j = 0; j < words.size(); j++) {
      string str = words[j];
      for (int i = 0; i <= str.size(); i++) {
        string prefix = str.substr(0, i), suffix = str.substr(i);
        if (!prefix.empty() && isPalindrome(prefix) && um.count(suffix) &&
            j != um[suffix])
          ans.push_back({um[suffix], j});
        if (isPalindrome(suffix) && um.count(prefix) && j != um[prefix])
          ans.push_back({j, um[prefix]});
      }
    }
    return ans;
  }

private:
  bool isPalindrome(string &str) {
    int i = 0, j = str.size() - 1;
    while (i < j) {
      if (str[i] != str[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
};
