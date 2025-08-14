// 2264. Largest 3-Same-Digit Number in String
#include "leetcode.h"
#include <stdlib.h>
#include <string.h>

/*
 * given a string 'num' representing a large integer, an integer is good if it
 * meets the following conditions: if it is a substring of 'num' with length
 * '3', it consists of only one unique digit. return the maximum good integer as
 * a string or an empty string "" if no such integer.
 */

char *largestGoodInteger(char *num) {
  static char *patterns[] = {"999", "888", "777", "666", "555",
                             "444", "333", "222", "111", "000"};
  for (int i = 0; i < 10; i++)
    if (strstr(num, patterns[i]))
      return patterns[i];
  return "";
}

int main() {
  char *n1 = "6777133339", *lgi1 = largestGoodInteger(n1);
  char *n2 = "2300019", *lgi2 = largestGoodInteger(n2);
  char *n3 = "42352338", *lgi3 = largestGoodInteger(n3);
  printf("%s\n", lgi1); // expect: 777
  printf("%s\n", lgi2); // expect: 000
  printf("%s\n", lgi3); // expect: NULL
}
