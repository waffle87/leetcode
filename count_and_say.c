// 38. Count and Say
#include "leetcode.h"

/*
 * the count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 * - countAndSay(1) = "1"
 * - countAndSay(n) is the way you would "say" the digit string from
 * 'countAndSay(n - 1)', which is then converted into a different digit string
 * to determine how you "say" a digit string, split it into minimal number of
 * substrings such that each substring contains exactly one unique digit. then
 * for each substring, say the number of digits, then say the digit, finally,
 * concatenate every said digit. given a positive integer 'n', return the n'th
 * term of the count and say sequence.
 */

char *countAndSay(int n) {
  if (n == 1)
    return "1";
  char *s = countAndSay(n - 1), curr = *s;
  char *ans = (char *)malloc(4463 * sizeof(char));
  int m = strlen(s), idx = 0, cnt = 1;
  for (int i = 1; i < m; i++) {
    char c = *(s + i);
    if (c == curr)
      cnt++;
    else {
      *(ans + idx++) = ('0' + cnt);
      *(ans + idx++) = curr;
      curr = c;
      cnt = 1;
    }
  }
  *(ans + idx++) = ('0' + cnt);
  *(ans + idx++) = curr;
  *(ans + idx) = '\0';
  return ans;
}

int main() {
  char *cas1 = countAndSay(4), *cas2 = countAndSay(1);
  printf("%s\n", cas1); // expect: 1211
  printf("%s\n", cas2); // expect: 1
  free(cas1);
  free(cas2);
}
