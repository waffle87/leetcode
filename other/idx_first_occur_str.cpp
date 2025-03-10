// 28. Find the Index of the First Occurrence in a String
#include "leetcode.h"
#include <vector>

/*
 * given two strings 'needle' and 'haystack', return index of the first
 * occurrence of 'needle' in 'haystack', or -1 if 'needle' is not part of
 * 'haystack'
 */

class Solution {
public:
  int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    if (!n)
      return 0;
    vector<int> lps = kmp(needle);
    for (int i = 0, j = 0; i < m;) {
      if (haystack[i] == needle[j])
        i++, j++;
      if (j == n)
        return i - j;
      if (i < m && haystack[i] != needle[j])
        j ? j = lps[j - 1] : i++;
    }
    return -1;
  }

private:
  // kmp algorithm:
  // http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
  vector<int> kmp(string needle) {
    int n = needle.size();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;) {
      if (needle[i] == needle[len])
        lps[i++] = ++len;
      else if (len)
        len = lps[len - 1];
      else
        lps[i++] = 0;
    }
    return lps;
  }
};

int main() {
  Solution obj;
  cout << obj.strStr("sadbutsad", "sad") << endl;  // expect: 0
  cout << obj.strStr("leetcode", "leeto") << endl; // expect: -1
}
