// 3228. Maximum Number of Operations to Move Ones to the End
#include "leetcode.h"

/*
 * you are given a binary string 's'. you can perform the followiong operation
 * on the string any number of timees: choose any index 'i' from the string
 * where 'i + 1 < s.length' such that 's[i] == 1' and 's[i + 1] == 0'. move the
 * character 's[i]' to the right until it reaches the end of the string or
 * another 1. return the maximum number of operations that you can perform.
 */

int maxOperations(char *s) {
  int ans = 0, ones = 0, n = strlen(s);
  for (int i = 0; i < n; ++i) {
    ones += s[i] - '0';
    if (i > 0 && s[i] < s[i - 1])
      ans += ones;
  }
  return ans;
}

int main() {
  char *s1 = "1001101", *s2 = "00111";
  printf("%d\n", maxOperations(s1)); // expect: 4
  printf("%d\n", maxOperations(s2)); // expect: 0
}
