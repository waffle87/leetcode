// 916. Word Subsets
#include "leetcode.h"

/*
 * you are given two string arrays 'words1' and 'words2'. a string 'b' is a
 * subset of string 'a' if every letter in 'b' occurs in 'a' including
 * multiplicity. a string 'a' from 'words1' is universal if for every string 'b'
 * in 'words2', 'b' is a subset of 'a'. return an array of all the universal
 * strins in 'words1'. you may return the answer in any order.
 */

class Solution {
public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    vector<int> cnt(26), tmp(26);
    int i;
    for (string b : words2) {
      tmp = counter(b);
      for (i = 0; i < 26; ++i)
        cnt[i] = max(cnt[i], tmp[i]);
    }
    vector<string> ans;
    for (string a : words1) {
      tmp = counter(a);
      for (i = 0; i < 26; ++i)
        if (tmp[i] < cnt[i])
          break;
      if (i == 26)
        ans.push_back(a);
    }
    return ans;
  }

private:
  vector<int> counter(string &word) {
    vector<int> cnt(26);
    for (char c : word)
      cnt[c - 'a']++;
    return cnt;
  }
};

int main() {
  Solution obj;
  vector<string> w11 = {"amazon", "apple", "facebook", "google", "leetcode"},
                 w21 = {"e", "o"};
  vector<string> w12 = {"amazon", "apple", "facebook", "google", "leetcode"},
                 w22 = {"l", "e"};
  vector<string> ws1 = obj.wordSubsets(w11, w21),
                 ws2 = obj.wordSubsets(w12, w22);
  for (auto i : ws1)
    cout << i << ' '; // expect: ["facebook","google","leetcode"]
  printf("\n");
  for (auto i : ws2)
    cout << i << ' '; // expect: ["apple","google","leetcode"]
  printf("\n");
}
