// 921. Minimum Add to Make Parentheses Valid
#include "leetcode.h"

/*
 * a parentheses string is valid if and only if it is empty string, it can be
 * written as AB (A concatenated with B), where A and B are valid strings, or it
 * can be written as (A) where A is a valid string. you are given a parentheses
 * string 's'. in one move you can insert a parentheses at any position of the
 * string. return the minimum number of moves required to make 's' valid
 */

int minAddToMakeValid(char *s) {
  int p[2] = {0}, n = strlen(s);
  for (int i = 0; i < n; i++) {
    bool left = s[i] == '(';
    p[0] += left;
    p[p[0] <= 0] += (1 - ((p[0] > 0) << 1)) * (!left);
  }
  return p[0] + p[1];
}

int main() {
  char *s1 = "())", *s2 = "(((";
  int r1 = minAddToMakeValid(s1);
  int r2 = minAddToMakeValid(s2);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 3);
}
