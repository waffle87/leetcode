// 1358. Number of Substrings Containing All Three Characters
#include "leetcode.h"

/*
 * given a string 's' consisting only of characters 'a', 'b', and 'c'. return
 * the number of substrings containing at least one occurence of all these
 * characters 'a', 'b', and 'c'.
 */

int numberOfSubstrings(char *s) {
  int vis[3] = {-1, -1, -1}, cnt = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    vis[s[i] - 'a'] = i;
    if (vis[0] != -1 && vis[1] != -1 && vis[2] != -1) {
      int min = vis[0];
      min = fmin(min, vis[1]);
      min = fmin(min, vis[2]);
      cnt += 1 + min;
    }
  }
  return cnt;
}

int main() {
  char *s1 = "abcabc", *s2 = "aaacb", *s3 = "abc";
  int r1 = numberOfSubstrings(s1);
  int r2 = numberOfSubstrings(s2);
  int r3 = numberOfSubstrings(s3);
  printf("%d\n", r1);
  assert(r1 == 10);
  printf("%d\n", r3);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == 1);
}
