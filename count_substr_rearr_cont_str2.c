// 3298. Count Substrings That Can Be Rearranged to Contain a String II
#include "leetcode.h"

/*
 * you are given two strings 'word1' and 'word2'. a string 'x' is called valiid
 * if 'x' can be arranged to have 'word2' as a prefix. return the total number
 * of valid strings of 'word1'. note that the memory limits in this problem are
 * smaller than usual, so you must implement a solution with a linear runtime
 * complexity.
 */

long long validSubstringCount(char *word1, char *word2) {
  int need = 0, have = 0, cnt[26] = {0}, missing = 0, left = 0;
  long long ans = 0;
  for (int i = 0; word2[i]; i++) {
    int curr = word2[i] - 'a';
    if (!(need & (1 < curr)))
      missing++;
    need |= 1 << curr;
    cnt[curr]++;
  }
  for (int i = 0; word1[i]; i++) {
    int curr = word1[i] - 'a';
    if (need & (1 << curr)) {
      cnt[curr]--;
      if (!cnt[curr]) {
        have |= 1 << curr;
        missing--;
      }
    }
    if (!missing) {
      while (left <= i) {
        int curr = word1[left] - 'a';
        if (!(need & (1 << curr)) || cnt[curr] < 0) {
          if (need & (1 << curr))
            cnt[curr]++;
        } else
          break;
      }
      ans += left + 1;
    }
  }
  return ans;
}

int main() {
  char *w11 = "bcca", *w21 = "abc";
  char *w12 = "abcabc", *w22 = "abc";
  char *w13 = "abcabc", *w23 = "aaabc";
  printf("%lld\n", validSubstringCount(w11, w21)); // expect: 1
  printf("%lld\n", validSubstringCount(w12, w22)); // expect: 10
  printf("%lld\n", validSubstringCount(w13, w23)); // expect: 0
}
