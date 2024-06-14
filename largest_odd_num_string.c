// 1903. Largest Odd Number in String
#include "leetcode.h"

/*
 * given a string 'num' representing a large integer. return the largest-valued
 * odd integer as a string is a non-empty substring of 'num', or an empty string
 * "" if no odd integer exists. a substring is a contiguous sequence of
 * characters within a string
 */

char *largestOddNumber(char *num) {
  int n = strlen(num);
  for (int i = n - 1; i >= 0; i--)
    if ((num[i] - '0') % 2 == 1) {
      num[i + 1] = '\0';
      return num;
    }
  return "";
}

int main() {
  char *n1 = "52", *n2 = "4206", *n3 = "35427";
  printf("%s\n", largestOddNumber(n1)); // expect: 5
  printf("%s\n", largestOddNumber(n2)); // expect: NULL
  printf("%s\n", largestOddNumber(n3)); // expect: 35427
}
