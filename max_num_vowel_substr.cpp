// 1456. Maximum Number of Vowels in a Substring of Given Length
#include "leetcode.h"

/*
 * given a string 's' and an integer 'k', return the maximum
 * number of vowel letters in any substring of 's' with length
 * 'k'. vowel letters in english are 'a e i o u'
 */

class Solution {
public:
  int maxVowels(string s, int k) {
    int count = 0, counting = 0;
    unordered_set<char> bag = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0, local = 0; i < s.size(); i++) {
      local += bag.count(s[i]);
      if (i - k >= 0)
        local -= bag.count(s[i - k]);
      count = max(count, local);
    }
    return count;
  }
};

int main() {
  Solution obj;
  cout << obj.maxVowels("abciiidef", 3); // expect: 3
  cout << obj.maxVowels("aeiou", 2);     // expect: 2
  cout << obj.maxVowels("leetcode", 3);  // expect: 2
}
