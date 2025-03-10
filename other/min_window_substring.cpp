#include "leetcode.h"

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> m1, m2;
    int check = INT_MAX;
    string ans;
    for (char &ch : t)
      m1[ch]++;
    int slow = 0, fast = 0, count = 0;
    for (; fast < s.size(); fast++) {
      char c = s[fast];
      if (m1.find(c) != m1.end()) {
        m2[c]++;
        if (m2[c] <= m1[c])
          count++;
      }
      if (count >= t.size()) {
        while (m1.find(s[slow]) == m1.end() || m2[s[slow]] > m1[s[slow]]) {
          m2[s[slow]]--;
          slow++;
        }
        if (fast - slow + 1 < check) {
          check = fast - slow + 1;
          ans = s.substr(slow, check);
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.minWindow("ADOBECODEBANC", "ABC");
}
