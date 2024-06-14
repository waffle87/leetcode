// 1758. Minimum Changes To Make Alternating Binary String
#include "leetcode.h"

/*
 * given a string 's' consisting only of the characters '0' and '1', in one
 * operation, you can change any '0' to '1' or vice versa. the string is called
 * alternating if no two adjacent characters are equal. for example the string
 * "010" is alternating, while the string "0100" is not. return the minimum
 * number of operations needed to make 's' alternating.
 */

int minOperations(char *s) {
  int n = strlen(s), cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!(i % 2) && s[i] == '1')
      cnt++;
    else if (i % 2 && s[i] == '0')
      cnt++;
  }
  return fmin(cnt, n - cnt);
}

int main() {
  char *s1 = "0100", *s2 = "10", *s3 = "1111";
  printf("%d\n", minOperations(s1)); // expect: 1
  printf("%d\n", minOperations(s2)); // expect: 0
  printf("%d\n", minOperations(s3)); // expect: 2
}
