#include "leetcode.h"

class Solution {
public:
  bool detectCapitalUse(string word) {
    bool firstCaps = isupper(word[0]), allCaps = true, allLower = true;
    for (int i = 1; i < word.size(); i++) {
      if (isupper(word[i]))
        allLower = false;
      else
        allCaps = false;
    }
    return (firstCaps && allCaps) || allLower;
  }
};

int main() {
  Solution obj;
  testBool(obj.detectCapitalUse("USA"));  // true
  testBool(obj.detectCapitalUse("FlaG")); // false
}
