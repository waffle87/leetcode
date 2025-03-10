// 3306. Count of Substrings Containing Every Vowel and K Consonants II
#include "leetcode.h"

/*
 * you are given a string 'word' and a non-negative integer 'k'. return the
 * total number of substrings of 'word' that contain every vowel at least once
 * and exactly 'k' constants
 */

long long countOfSubstrings(char *word, int k) {
  int freq[2][128] = {{0}};
  freq[0]['a'] = freq[0]['e'] = freq[0]['i'] = freq[0]['o'] = freq[0]['u'] = 1;
  long long ans = 0;
  int curr = 0, cnt = 0, extra = 0, left = 0;
  for (int right = 0; word[right]; right++) {
    char r_char = word[right];
    if (freq[0][r_char]) {
      if (++freq[1][r_char] == 1)
        cnt++;
    } else
      curr++;
    while (curr > k) {
      char l_char = word[left++];
      if (freq[0][l_char]) {
        if (--freq[1][l_char] == 0)
          cnt--;
      } else
        curr--;
      extra = 0;
    }
    if (curr == k && cnt == 5)
      ans += (extra + 1);
  }
  return ans;
}

int main() {
  char *w1 = "aeioqq", *w2 = "aeiou", *w3 = "ieaouqqieaouqq";
  printf("%lld\n", countOfSubstrings(w1, 1)); // expect: 0
  printf("%lld\n", countOfSubstrings(w2, 0)); // expect: 1
  printf("%lld\n", countOfSubstrings(w3, 1)); // expect: 3
}
