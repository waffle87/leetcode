// 567. Permutation in String
#include "leetcode.h"

/*
 * given two strings 's1 s2' return true if 's2' contains a permutation of 's1'
 * or false otherwise. in other words, return true if one of 's1's permutations
 * is in the substring of 's2'
 */

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size())
      return false;
    vector<int> freq1(26, 0), freq2(26, 0);
    for (char c : s1)
      freq1[c - 'a']++;
    int i = 0, j = 0;
    while (j < s2.size()) {
      freq2[s2[j] - 'a']++;
      if (j - i + 1 == s1.size())
        if (cmp(freq1, freq2))
          return true;
      if (j - i + 1 < s1.size())
        j++;
      else {
        freq2[s2[i] - 'a']--;
        i++, j++;
      }
    }
    return false;
  }

private:
  bool cmp(vector<int> a, vector<int> b) {
    for (int i = 0; i < 26; i++)
      if (a[i] != b[i])
        return false;
    return true;
  }
};

int main() {
  Solution obj;
  cout << obj.checkInclusion("ab", "eidbaooo") << endl; // expect: 1
  cout << obj.checkInclusion("ab", "eidboaoo") << endl; // expect: 0
}
