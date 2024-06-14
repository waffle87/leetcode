#include "leetcode.h"

class Solution {
  string vowels = "aeiouAEIOU";

public:
  bool halvesAreAlike(string s) {
    int mid = s.size() / 2, ans = 0;
    for (int i = 0, j = mid; i < mid; i++, j++) {
      if (~vowels.find(s[i]))
        ans++;
      if (~vowels.find(s[j]))
        ans--;
    }
    return ans == 0;
  }
};

int main() {
  Solution obj;
  if (obj.halvesAreAlike("book"))
    cout << "true";
  else
    cout << "false";
}
