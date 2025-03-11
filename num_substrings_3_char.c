// 1358. Number of Substrings Containing All Three Characters
#include "leetcode.h"

/*
 * given a string 's' consisting only of characters 'a', 'b', and 'c'. return
 * the number of substrings containing at least one occurence of all these
 * characters 'a', 'b', and 'c'.
 */

int numberOfSubstrings(char *s) {
  int cnt[3] = {0}, ans = 0, i = 0, n = strlen(s);
  for (int j = 0; j < n; ++j) {
    ++cnt[s[j] - 'a'];
    while (cnt[0] && cnt[1] && cnt[2])
      --cnt[s[i++] - 'a'];
    ans += i;
  }
  return ans;
}

int main() {
  char *s1 = "abcabc", *s2 = "aaacb", *s3 = "abc";
  printf("%d\n", numberOfSubstrings(s1)); // expect: 10
  printf("%d\n", numberOfSubstrings(s2)); // expect: 3
  printf("%d\n", numberOfSubstrings(s3)); // expect: 1
}
