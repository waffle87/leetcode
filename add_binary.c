// 67. Add Binary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b) {
  int i = strlen(a), j = strlen(b), carry = 0;
  int k = i > j ? i : j;
  char *ans = malloc(k + 2);
  ans[k + 1] = '\0';
  while (i || j) {
    if (i)
      carry += (a[--i] - '0');
    if (j)
      carry += (b[--j] - '0');
    ans[k--] = (carry & 1) + '0';
    carry >>= 1;
  }
  ans[0] = carry + '0';
  return ans + (carry ^ 1);
}

int main() {
  char a1[] = "11", b1[] = "1";
  char a2[] = "1010", b2[] = "1011";
  printf("%c\n" * addBinary(a1, b1)); // expect: 100
  printf("%c\n" * addBinary(a2, b2)); // expect: 100
}
