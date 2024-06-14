// 2306. Naming a Company
#include "leetcode.h"

/*
 * you are given an array of strings 'ideas' that represents a list of names to
 * be used in the process o naming a company. the process of naming a company is
 * as follows: chose 2 distinct names from 'ideas', call them 'ideaa, ideab'.
 * swap the first letters of 'ideaa & ideab' with each other.
 * if both the new names are not found in the original 'ideas', then the name
 * 'ideaa ideab' (concatenated, separated by space) is a valid company name.
 */

class Solution {
public:
  long long distinctNames(vector<string> &ideas) {
    long long ans = 0, cnt[26][26] = {};
    unordered_set<string> us[26];
    for (auto &i : ideas)
      us[i[0] - 'a'].insert(i.substr(1));
    for (int i = 0; i < 26; ++i)
      for (auto &suffix : us[i])
        for (int j = 0; j < 26; ++j)
          cnt[i][j] += us[j].count(suffix) == 0;
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j)
        ans += cnt[i][j] * cnt[j][i];
    return ans;
  }
};

int main() {
  Solution obj;
  vector<string> ideas1 = {"coffee", "donuts", "time", "toffee"},
                 ideas2 = {"lack", "back"};
  cout << obj.distinctNames(ideas1) << endl; // expect: 6
  cout << obj.distinctNames(ideas2) << endl; // expect: 0
}
