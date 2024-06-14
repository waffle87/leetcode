#include "leetcode.h"

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    int len = words[0].size(), n = words.size(), sSize = s.size(), left, found;
    vector<int> result;
    unordered_map<string, int> freq, temp;
    for (auto word : words)
      freq[word]++;
    for (int i = 0; i < len; i++) {
      temp.clear();
      left = i, found = 0;
      for (int j = i; j <= sSize - len; j += len) {
        string curr = s.substr(j, len);
        if (freq.find(curr) != freq.end()) {
          temp[curr]++;
          found++;
          while (freq[curr] < temp[curr]) {
            temp[s.substr(left, len)]--;
            found--;
            left += len;
          }
          if (found == n)
            result.push_back(left);
        } else {
          temp.clear();
          found = 0;
          left = j + len;
        }
      }
    }
    return result;
  }
};

int main() {}
