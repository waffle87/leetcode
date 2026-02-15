// 67. Add Binary
#include "leetcode.h"

/*
 * given two binary strings 'a' and 'b', return their sum as a binary string.
 */

char *addBinary(char *a, char *b) {
  int i = strlen(a), j = strlen(b);
  int k = fmax(i, j) + 2, carry = 0;
  char *ans = (char *)malloc(k * sizeof(char));
  i--;
  j--;
  ans[--k] = '\0';
  while (--k >= 0) {
    carry += i >= 0 ? a[i--] - '0' : 0;
    carry += j >= 0 ? b[j--] - '0' : 0;
    ans[k] = carry % 2 + '0';
    carry /= 2;
  }
  if (ans[0] == '0')
    memmove(ans, ans + 1, strlen(ans) * sizeof(char));
  return ans;
}

int main() {
  char *a1 = "11", *b1 = "1", *r1 = "100";
  char *a2 = "1010", *b2 = "1011", *r2 = "10101";
  char *ab1 = addBinary(a1, b1);
  char *ab2 = addBinary(a2, b2);
  printf("%s\n", ab1); // expect: 100
  assert(!strcmp(ab1, r1));
  printf("%s\n", ab2); // expect: 10101
  assert(!strcmp(ab2, r2));
  free(ab1);
  free(ab2);
}
