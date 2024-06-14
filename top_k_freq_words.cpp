#include "leetcode.h"

struct Compare {
  bool operator()(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first)
      return a.second > b.second;
    else
      return a.first < b.first;
  }
};

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> um;
    for (int i = 0; i < words.size(); i++)
      um[words[i]]++;
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>
        pqpvpc;
    for (auto i : um)
      pqpvpc.push({i.second, i.first});
    vector<string> ans;
    while (k--) {
      ans.push_back(pqpvpc.top().second);
      pqpvpc.pop();
    }
    return ans;
  }
};
