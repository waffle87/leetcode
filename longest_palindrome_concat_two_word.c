// 2131. Longest Palindrome by Concatenating Two Letter Words
#include "leetcode.h"

/*
 * you are given an array of strings 'words'. each element of 'words' consists
 * of two lowercase english letters. create the longest possible palindrome by
 * selecting some elements from 'words' and concatenating them in any order.
 * each element can be select at most once. return the length of the longest
 * palindrome you can create. if it is impossible, return 0. a palindrome is a
 * string that reads the same forward and backward.
 */

int longestPalindrome(char **words, int wordsSize) {
  int freq[26][26] = {0}, ans = 0;
  for (int i = 0; i < wordsSize; i++) {
    if (freq[words[i][1] - 'a'][words[i][0] - 'a']) {
      freq[words[i][1] - 'a'][words[i][0] - 'a']--;
      ans += 4;
    } else
      freq[words[i][0] - 'a'][words[i][1] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
    if (freq[i][i]) {
      ans += 2;
      break;
    }
  return ans;
}

int main() {
  char *w1[] = {"lc", "cl", "gg"}, *w2[] = {"ab", "ty", "yt", "lc", "cl", "ab"},
       *w3[] = {"cc", "ll", "xx"};
  printf("%d\n", longestPalindrome((char **)w1, ARRAY_SIZE(w1))); // expect: 6
  printf("%d\n", longestPalindrome((char **)w2, ARRAY_SIZE(w2))); // expect: 8
  printf("%d\n", longestPalindrome((char **)w3, ARRAY_SIZE(w3))); // expect: 2
}
