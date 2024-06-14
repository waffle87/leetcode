// 1544. make the string great
#include "leetcode.h"

/*
 * given a string 's' of lower and upper case english letters. a good string is
 * a string which doesn't have two adjacent characters 's[i]' and 's[i + 1]'
 * where 0 <= i <= s.len - 2. s[i] is a lower case letter and s[i + 1] is the
 * same letter but in upper case, or vice versa. to make the string good, you
 * can choose two adjacent characters that make the string bad and remove them.
 * you can keep doing this until the string becomes good. return the string
 * after making it good. the answer is guaranteed to be unique under the given
 * constraints. notice that an empty string is also good.
 */

char *makeGood(char *s) {
  int n = strlen(s), idx = -1;
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++) {
    if (idx == -1) {
      idx++;
      ans[idx] = s[i];
    } else {
      if (fabs(s[i] - ans[idx]) == 'a' - 'A')
        idx--;
      else
        idx++, ans[idx] = s[i];
    }
  }
  idx++;
  ans[idx] = '\0';
  ans = realloc(ans, idx + 1);
  return ans;
}

int main() {
  char *s1 = "leEeetcode", *s2 = "abBAcC", *s3 = "s";
  printf("%s\n", makeGood(s1));
  printf("%s\n", makeGood(s2));
  printf("%s\n", makeGood(s3));
}
