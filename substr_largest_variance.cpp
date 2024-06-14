// 2272. Substring With Largest Variance
#include "leetcode.h"

/*
 * the variance of a string is defined as the largest difference between the
 * number of ocurrences of any '2' characters present in the string. note the
 * two characters may or may not be the same. given a string 's', consisting of
 * lowercase english letters only, return the largest variance possible among
 * all substrings 's'. a substring is a contiguous sequence of characters witin
 * a string.
 */

class Solution {
public:
  int largestVariance(string s) {
    vector<int> arr(26);
    for (auto i : s)
      arr[i - 'a']++;
    int ans = 0;
    for (char i = 'a'; i <= 'z'; i++) {
      for (char j = 'a'; j <= 'z'; j++) {
        if (j == i || !arr[i - 'a'] || !arr[j - 'a'])
          continue;
        for (int k = 1; k <= 2; k++) {
          int a1 = 0, a2 = 0;
          for (auto l : s) {
            if (l == i)
              a1++;
            if (l == j)
              a2++;
            if (a2 > a1)
              a1 = 0, a2 = 0;
            if (a1 && a2)
              ans = max(ans, a1 - a2);
          }
          reverse(s.begin(), s.end());
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.largestVariance("aababbb")); // expect: 3
  printf("%d\n", obj.largestVariance("abcde"));   // expect: 0
};
