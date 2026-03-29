// 2839. Check if Strings Can be Made Equal With Operations I
#include "leetcode.h"

/*
 * you are given two strings 's1' and 's2' both of length 4, consisting of
 * lowercase english letters. you can apply the following operation on any of
 * the two strings any number of times: choose any two indices 'i' and 'j' such
 * that 'j - i = 2' then swap the two characters at those indices in the string.
 * return true if you make the strings 's1' and 's2' equal and false otherwise.
 */

bool canBeEqual(char *s1, char *s2) {
  return ((s1[0] == s2[0] && s1[2] == s2[2]) ||
          (s1[0] == s2[2] && s1[2] == s2[0])) &&
         ((s1[1] == s2[1] && s1[3] == s2[3]) ||
          (s1[1] == s2[3] && s1[3] == s2[1]));
}

int main() {
  char *s11 = "abcd", *s21 = "cdab";
  char *s12 = "abcd", *s22 = "dacb";
  bool r1 = canBeEqual(s11, s21);
  bool r2 = canBeEqual(s12, s22);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r1);
  assert(r2 == false);
}
