#include "leetcode.h"

class Solution {
public:
  int minMutation(string start, string end, vector<string> &bank) {
    deque<pair<string, int>> dqp({{start, 0}});
    set<string> s(bank.begin(), bank.end());
    vector<char> nucleotides = {'A', 'T', 'G', 'C'};
    while (!dqp.empty()) {
      auto [g, m] = dqp.front();
      dqp.pop_front();
      if (g == end)
        return m;
      for (int i = 0; i < g.size(); ++i)
        for (char n : nucleotides) {
          string gm = g;
          gm[i] = n;
          if (s.count(gm)) {
            s.erase(gm);
            dqp.emplace_back(gm, m + 1);
          }
        }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  string start = "AACCGGTT", end = "AACCGGTA";
  vector<string> bank = {"AACCGGTA"};
  cout << obj.minMutation(start, end, bank);
}
