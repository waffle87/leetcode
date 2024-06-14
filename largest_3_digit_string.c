// 2264. Largest 3-Same-Digit Number in String
#include "leetcode.h"

/*
 * given a string 'num' representing a large integer, an integer is good if it
 * meets the following conditions: if it is a substring of 'num' with length
 * '3', it consists of only one unique digit. return the maximum good integer as
 * a string or an empty string "" if no such integer.
 */

char *largestGoodInterger(char *num) {
  int n = strlen(num), chr = 'a', cnt = 1;
  for (int i = 1; i < n; i++) {
    if (num[i] == num[i - 1]) {
      cnt++;
      if (i < n - 1)
        continue;
    }
    if (cnt >= 3) {
      if (chr == 'a')
        chr = num[i - 1];
      else
        chr = fmax(chr, num[i - 1]);
    }
    cnt = 1;
  }
  if (chr == 'a')
    return "";
  else {
    char *ans = malloc(4);
    ans[3] = '\0';
    ans[0] = chr;
    ans[1] = chr;
    ans[2] = chr;
    return ans;
  }
}

int main() {
  char *n1 = "6777133339", *n2 = "2300019", *n3 = "42352338";
  printf("%s\n", largestGoodInterger(n1)); // expect: 777
  printf("%s\n", largestGoodInterger(n2)); // expect: 000
  printf("%s\n", largestGoodInterger(n3)); // expect: NULL
}
