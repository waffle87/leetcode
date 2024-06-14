// 91. Decode Ways
#include "leetcode.h"

/*
 * a message containing letters from a - z can be encoded into numbers using the
 * following mapping: a -> 1, b -> 2, ..., z -> 26. to decode an encoded
 * message, all the digits must be grouped then mapped back into letters using
 * the reverse of the mapping above (there may be multiple ways). for example,
 * "11106" can be mapped into: "aajf" with the grouping ' 1 1 10 6', "kjf" with
 * the grouping '11 10 6'. note that the grouping '(1 11 06)' because '06'
 * cannot be mapped into "f" because '6' is different from '06'. given a string
 * 's' containing only digits, return the number of ways to decode it. the test
 * cases are generated so that the answer fits in a 32-bit integer
 */

int char_to_int(char *s) { return (s[0] - '0') * 10 + s[1] - '0'; }

int numDecodings(char *s) {
  int n = strlen(s), a = 1, b, tmp = char_to_int(s), c;
  if (s[0] == '0')
    return 0;
  if (!n || n == 1)
    return 1;
  if (tmp == 10 || tmp == 20)
    b = 1;
  else if (!(tmp % 10))
    return 0;
  else if (tmp > 26)
    b = 1;
  else
    b = 2;
  if (n == 2)
    return b;
  for (int i = 2; i < n; i++) {
    tmp = char_to_int(&s[i - 1]);
    if (!tmp)
      return 0;
    else if (tmp && tmp < 10)
      c = b;
    else if (tmp == 10 || tmp == 20)
      c = a;
    else if (!(tmp % 10))
      return 0;
    else if (tmp > 26)
      c = b;
    else
      c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main() {
  char *s1 = "12", *s2 = "226", *s3 = "06";
  printf("%d\n", numDecodings(s1)); // expepct: 2
  printf("%d\n", numDecodings(s2)); // expepct: 3
  printf("%d\n", numDecodings(s3)); // expepct: 0
}
