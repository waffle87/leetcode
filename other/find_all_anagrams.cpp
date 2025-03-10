// 438. Find All Anagrams in a String
#include "leetcode.h"

/*
 * given two strings 's & p', return an array of all the start indices of 'p's
 * anagrams in 's' (any order). an anagram is a word or phrase formed by
 * rearranging the letters of a different word or phrase, typically using all
 * original letters exactly one
 */

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int ssz = s.size(), psz = p.size();
    if (ssz < psz)
      return {};
    vector<int> freq(26, 0), window(26, 0), ans;
    for (int i = 0; i < psz; i++) {
      freq[p[i] - 'a']++;
      window[s[i] - 'a']++;
    }
    if (freq == window)
      ans.push_back(0);
    for (int i = psz; i < ssz; i++) {
      window[s[i - psz] - 'a']--;
      window[s[i] - 'a']++;
      if (freq == window)
        ans.push_back(i - psz + 1);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  for (auto i : obj.findAnagrams("cbaebabacd", "abc"))
    cout << i << ' '; // expect 0 6
  for (auto i : obj.findAnagrams("abab", "ab"))
    cout << i << ' '; // expect 0 1 2
}
