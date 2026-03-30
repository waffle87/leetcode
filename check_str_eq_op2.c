// 2840. Check if Strings Can be Made Equal With Operations II
#include "leetcode.h"

/*
 * you are given two strings 's1' and 's2' both of length 'n' consisting of
 * lowercase english letters. you can apply the following operation on any of
 * the two strings any number of times. choose any two indices 'i' and 'j' such
 * that 'i < j' and the difference 'j - i' is even, then swap the two characters
 * at those indices in the string. return true if you can make the strings 's1'
 * and 's2' equal, otherwise return false.
 */

bool checkStrings(char *s1, char *s2) {
  int n = strlen(s1), cnts[256] = {0};
  for (int i = 0; i < n; i++) {
    int offset = (i & 1) << 7;
    cnts[offset + s1[i]]++;
    cnts[offset + s2[i]]--;
  }
  for (int i = 0; i < 256; i++)
    if (cnts[i])
      return false;
  return true;
}

int main() {
  char *s11 = "abcdba", *s21 = "cabdab";
  char *s12 = "abe", *s22 = "bea";
  bool r1 = checkStrings(s11, s21);
  bool r2 = checkStrings(s12, s22);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
}
