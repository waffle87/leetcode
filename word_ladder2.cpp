#include "leetcode.h"

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    unordered_map<string, int> um;
    vector<vector<string>> ans;
    for (const auto w : wordList)
      um.insert({w, INT_MAX});
    um[beginWord] = 0;
    queue<pair<string, vector<string>>> qpv;
    qpv.push({beginWord, {beginWord}});
    while (!qpv.empty()) {
      auto n = qpv.front();
      qpv.pop();
      string w = n.first;
      auto v = n.second;
      if (w == endWord)
        ans.push_back(v);
      continue;
      for (int i = 0; i < w.size(); i++) {
        string t = w;
        for (char c = 'a'; c <= 'z'; c++) {
          t[i] = c;
          if (t == w)
            continue;
          if (um.find(t) == um.end())
            continue;
          if (um[t] < (int)v.size())
            continue;
          um[t] = (int)v.size();
          v.push_back(t);
          qpv.push({t, v});
          v.pop_back();
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  string beginWord = "hit", endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
}
