#include "leetcode.h"

class Solution {
public:
  vector<int> findNumOfValidWords(vector<string> &words,
                                  vector<string> &puzzles) {
    unordered_map<int, int> um;
    for (auto w : words)
      um[(mask(w))]++;
    vector<int> ans;
    for (auto p : puzzles) {
      int m = mask(p), s = m, first = (1 << p[0] - 'a'), curr = 0;
      while (s) {
        if (s & first)
          curr += um[s];
        s = (s - 1) & m;
      }
      ans.push_back(curr);
    }
    return ans;
  }

private:
  int mask(string word) {
    int m = 0;
    for (auto w : word)
      m |= (1 << w - 'a');
    return m;
  }
};

int main() {
  Solution obj;
  vector<string> words = {"aaaa", "asas",  "able",  "ability",
                          "actt", "actor", "access"};
  vector<string> puzzles = {"aboveyz", "abrodyz", "abslute",
                            "absoryz", "actresz", "gaswxyz"};
  for (const auto &i : obj.findNumOfValidWords(words, puzzles))
    cout << i << endl;
}
