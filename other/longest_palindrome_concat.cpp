#include "leetcode.h"

class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> um;
    for (auto w : words)
      ++um[w];
    int ans = 0, center = 0, sz = 2;
    for (auto [w, cnt] : um) {
      auto reversed = string(rbegin(w), rend(w));
      if (w == reversed) {
        ans += 2 * (cnt / 2);
        center |= cnt % 2;
      } else {
        auto it = um.find(reversed);
        if (it != end(um))
          ans += min(cnt, it->second);
      }
    }
    return sz * ans + (center ? sz : 0);
  }
};

int main() {
  Solution obj;
  vector<string> words = {"lc", "cl", "gg"};
  cout << obj.longestPalindrome(words);
}
