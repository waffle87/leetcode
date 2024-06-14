#include "leetcode.h"

class Solution {
public:
  int maxLength(vector<string> &arr) {
    int ans = 0;
    vector<bitset<26>> unique;
    for (auto s : arr) {
      bitset<26> b;
      for (char ch : s)
        b.set(ch - 'a');
      if (b.count() == s.size())
        unique.push_back(b);
    }
    vector<bitset<26>> concat = {bitset<26>()};
    for (auto &u : unique)
      for (int i = concat.size() - 1; i >= 0; i--)
        if ((concat[i] & u).none()) {
          concat.push_back(concat[i] | u);
          ans = max(ans, (int)(concat[i].count() + u.count()));
        }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<string> arr = {"un", "iq", "ue"};
  cout << obj.maxLength(arr);
}
