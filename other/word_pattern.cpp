#include "leetcode.h"

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    vector<int> patMap(26, 0);
    unordered_map<string, int> strMap;
    int i = 0, n = pattern.size();
    istringstream ss(s);
    string token;
    for (string token; ss >> token; ++i) {
      if (i == n || patMap[pattern[i] - 'a'] != strMap[token])
        return false;
      patMap[pattern[i] - 'a'] = strMap[token] = i + 1;
    }
    return i == n;
  }
};

int main() {
  Solution obj;
  testBool(obj.wordPattern("abba", "dog cat cat dog"));  // true
  testBool(obj.wordPattern("abba", "dog cat cat fish")); // false
  testBool(obj.wordPattern("aaaa", "dog cat cat dog"));  // false
}
