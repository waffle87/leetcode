// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
#include "leetcode.h"

/*
 * a decimal number is called deci-binary if each of its digits is either 0 or 1
 * without any leading zeros. for example, 101 and 1100 are deci-binary while
 * 112 and 3001 are not. given a string 'n' that represents a positive decimal
 * integer, return the minimum number of possible deci-binary numbers needed so
 * that they sum up to 'n'.
 */

int minPartitions(char *n) {
  char max_char = '0';
  for (int i = 0; n[i] != '\0'; i++)
    max_char = fmax(max_char, n[i]);
  return max_char - '0';
}

int main() {
  char *n1 = "32", *n2 = "82734", *n3 = "27346209830709182346";
  int r1 = minPartitions(n1);
  int r2 = minPartitions(n2);
  int r3 = minPartitions(n3);
  printf("%d\n", r1); // expect: 3
  assert(r1 == 3);
  printf("%d\n", r2); // expect: 8
  assert(r2 == 8);
  printf("%d\n", r3); // expect: 9
  assert(r3 == 9);
}
