#include "leetcode.h"

class Solution {
public:
  int longestStrChain(vector<string> &words) {
    vector<unordered_set<string>> vus(17);
    for (auto i : words)
      vus[i.size()].insert(i);
    unordered_map<string, int> um;
    int ans = 1;
    for (int i = 16; i; i--) {
      if (vus[i - 1].empty())
        continue;
      for (auto j : vus[i]) {
        int wVal = um[j] ? um[j] : 1;
        for (int k = 0; k < j.size(); k++) {
          string prev = j.substr(0, k) + j.substr(k + 1);
          int pVal = um[prev] ? um[prev] : 1;
          if (vus[i - 1].find(prev) != vus[i - 1].end() && wVal >= pVal) {
            um[prev] = wVal + 1;
            ans = max(ans, wVal + 1);
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
  cout << obj.longestStrChain(words);
}
