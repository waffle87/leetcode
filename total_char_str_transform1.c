// 3335. Total Characters in String After Transformations I
#include "leetcode.h"

/*
 * you are given a string 's' and an integer 't' representing the number of
 * transformations to perform. in one transformation, every character in 's' is
 * replaced according to the following rules: if the character is 'z', replace
 * it with the string 'ab'. otherwise, replace it with the next character in the
 * alphabet. return the length of the resulting string after exactly 't'
 * transformations. since the answer may be very large, return it modulo 10^9
 * + 7.
 */

int lengthAfterTransformations(char *s, int t) {
  const int mod = 1e9 + 7;
  int cnt[26] = {0}, n = strlen(s);
  for (int i = 0; i < n; i++)
    cnt[s[i] - 'a']++;
  for (int i = 0; i < t; i++) {
    int tmp[26] = {0};
    for (int j = 0; j < 26; j++) {
      if (j == 25) {
        tmp[0] = (tmp[0] + cnt[j]) % mod;
        tmp[1] = (tmp[1] + cnt[j]) % mod;
      } else
        tmp[j + 1] = (tmp[j + 1] + cnt[j]) % mod;
    }
    memcpy(cnt, tmp, sizeof(cnt));
  }
  int ans = 0;
  for (int i = 0; i < 26; i++)
    ans = (ans + cnt[i]) % mod;
  return ans;
}

int main() {
  char *s1 = "abcyy", *s2 = "azbk";
  printf("%d\n", lengthAfterTransformations(s1, 2)); // expect: 7
  printf("%d\n", lengthAfterTransformations(s2, 1)); // expect: 5
}
