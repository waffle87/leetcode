// 1016. Binary String With Substrings Representing 1 To N
#include "leetcode.h"

/*
 * given a binary string 's' and a positive integer 'n', return 'true' if the
 * binary representation of all the integers in the range '[1, n]' are
 * substrings of 's' or 'false' otherwise. a substring is a contiguous sequence
 * of characters within a string.
 */

char *int_to_str(int val) {
  char *res = (char *)malloc(32 * sizeof(char));
  res[31] = '\0';
  int idx = 30;
  while (val) {
    res[idx] = val % 2 + '0';
    val /= 2;
    idx--;
  }
  return &res[idx + 1];
}

bool queryString(char *s, int n) {
  bool ans = true;
  for (int i = n; i; i--) {
    char *tmp = int_to_str(i);
    if (!strstr(s, tmp)) {
      ans = false;
      break;
    }
  }
  return ans;
}

int main() {
  char *s = "0110";
  printf("%d\n", queryString(s, 3)); // expect: 1
  printf("%d\n", queryString(s, 4)); // expect: 0
}
