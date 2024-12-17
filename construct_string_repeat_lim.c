// 2182. Construct String With Repeat Limit
#include "leetcode.h"

/*
 * you are given a string 's' and an integer 'repeatLimit'. construct a new
 * string 'repeatLimitedString' using the characters of 's' such that no letter
 * appears more than 'repeatLimit' times in a row. you do not have to use all
 * characters from 's'. return the lexicographically largest
 * 'repeatLimitedString' possible. a string 'a' is lexicographically larger than
 * string 'b' if in the first position where 'a' and 'b' differ, string 'a' has
 * a letter that appears later in the alphabet than the corresponding letter  in
 * 'b'. if the first 'min(a.len, b.len)' characters do not differ, then the
 * longer string is the lexicographically larger one
 */

int *get_cnt(char *s) {
  int n = strlen(s);
  int *cnt = (int *)calloc(26, sizeof(int));
  for (int i = 0; i < n; i++)
    cnt[s[i] - 'a']++;
  return cnt;
}

char *repeatLimitedString(char *s, int repeatLimit) {
  int n = strlen(s), *cnt = get_cnt(s), idx = 0;
  char *ans = (char *)calloc(n + 1, sizeof(char));
  for (int i = 'z' - 'a'; i >= 0;) {
    if (!cnt[i]) {
      i--;
      continue;
    }
    char c = i + 'a';
    if (!idx || ans[idx - 1] != c) {
      int copy = cnt[i] <= repeatLimit ? cnt[i] : repeatLimit;
      memset(&ans[idx], c, copy);
      idx += copy;
      cnt[i] -= copy;
    } else {
      int next = i - 1;
      while (next >= 0 && !cnt[next])
        next--;
      if (next < 0)
        break;
      else {
        ans[idx++] = next + 'a';
        cnt[next]--;
      }
    }
  }
  ans[idx] = '\0';
  return ans;
}

int main() {
  char *s1 = "cczazcc", *s2 = "aababab";
  char *rls1 = repeatLimitedString(s1, 3);
  char *rls2 = repeatLimitedString(s2, 2);
  printf("%s\n", rls1); // expect: "zzcccac"
  printf("%s\n", rls2); // expect: "bbabaa"
  free(rls1), free(rls2);
}
