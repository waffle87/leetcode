// 168. Excel Sheet Column Title
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given an integer 'column_number', return its corresponding column title as it
 * appears in an excel sheet. for example: A -> 1 B -> 2 C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * ...
 */

int get_len(int n) {
  int i = 0;
  while (n) {
    if (!(n % 26))
      n = (n - 1) / 26;
    else
      n /= 26;
    i++;
  }
  return i;
}

char *convertToTitle(int n) {
  int len = get_len(n);
  char *ans = (char *)malloc(sizeof(*ans) * (len + 1));
  memset(ans, 0, len + 1);
  while (n) {
    --len;
    if (!(n % 26)) {
      ans[len] = 'Z';
      n = (n - 1) / 26;
    } else {
      ans[len] = 'A' + (n % 26) - 1;
      n /= 26;
    }
  }
  return ans;
}

int main() {
  printf("%s\n", convertToTitle(1));   // expect: A
  printf("%s\n", convertToTitle(28));  // expect: AB
  printf("%s\n", convertToTitle(701)); // expect: ZY
}
