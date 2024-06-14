#include "leetcode.h"
#include <vector>

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    auto it = products.begin();
    sort(it, products.end());
    vector<vector<string>> ans;
    string curr = "";
    for (char c : searchWord) {
      curr += c;
      vector<string> suggested;
      it = lower_bound(it, products.end(), curr);
      for (int i = 0; i < 3 && it + i != products.end(); i++) {
        string &s = *(it + i);
        if (s.find(curr))
          break;
        suggested.push_back(s);
      }
      ans.push_back(suggested);
    }
    return ans;
  }
};
