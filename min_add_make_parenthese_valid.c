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
  int open = 0, close = 0, n = strlen(s);
  for (int i = 0; i < n; i++)
    if (s[i] == '(')
      open++;
    else {
      if (open)
        open--;
      else
        close++;
    }
  return open + close;
}

int main() {
  char *s1 = "())", *s2 = "(((";
  printf("%d\n", minAddToMakeValid(s1)); // expect: 1
  printf("%d\n", minAddToMakeValid(s2)); // expect: 3
}
