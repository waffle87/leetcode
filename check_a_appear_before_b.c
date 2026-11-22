// 2124. Check if All A's Appears Before All B's
#include "leetcode.h"

bool checkString(char *s) {
  int n = strlen(s);
  for (int i = 1; i < n; i++)
    if (s[i - 1] == 'b' && s[i] == 'a')
      return false;
  return true;
}

int main() {
  char *s1 = "aaabbb";
  char *s2 = "abab";
  char *s3 = "bbb";
  bool r1 = checkString(s1);
  bool r2 = checkString(s2);
  bool r3 = checkString(s3);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == true);
}
