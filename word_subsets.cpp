#include "leetcode.h"

class Solution {
public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    int bFreq[26] = {0}, check[26] = {0};
    int cMax = 0;
    vector<string> ans;
    for (string word : words2) {
      for (char c : word)
        check[c - 'a']++;
      for (int j = 0; j < 26; j++) {
        int diff = check[j] - bFreq[j];
        if (diff > 0)
          cMax += diff, bFreq[j] += diff;
      }
      if (cMax > 10)
        return ans;
      fill(check, check + 26, 0);
    }
    for (string word : words1) {
      int j;
      for (char c : word)
        check[c - 'a']++;
      for (j = 0; j < 26; j++)
        if (check[j] < bFreq[j])
          break;
      if (j == 26)
        ans.push_back(word);
      fill(check, check + 26, 0);
    }
    return ans;
  }
};
