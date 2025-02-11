// 1910. Remove All Occurrences of a Substring
#include "leetcode.h"

/*
 * given two strings 's' and 'part', perform the following operation on 's'
 * until all occurrences of the substring 'part' are removed; find the leftmost
 * occurrence of the substring 'part' and remove it from 's'. return 's' after
 * removing all occurrences of 'part'. a substring is a contiguous sequence of
 * characters in a string
 */

class Solution {
public:
  string removeOccurrences(string s, string part) {
    while (s.size() && s.find(part) < s.size())
      s.erase(s.find(part), part.size());
    return s;
  }
};

int main() {
  Solution obj;
  cout << obj.removeOccurrences("daabcbaabcbc", "abc") << endl; // expect: dab
  cout << obj.removeOccurrences("axxxxyyyyb", "xy") << endl;    // expect: ab
}
