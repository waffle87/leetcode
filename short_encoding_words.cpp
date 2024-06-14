#include "leetcode.h"

class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    unordered_set<string> us(words.begin(), words.end());
    for (string w : us)
      for (int i = 1; i < w.size(); ++i)
        us.erase(w.substr(i));
    int ans = 0;
    for (string w : us)
      ans += w.size() + 1;
    return ans;
  }
};

int main() {
  Solution obj;
  vector<string> words = {"time", "me", "bell"};
  cout << obj.minimumLengthEncoding(words);
}
