// 7. Reverse Integer
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a signed 32-bit integer 'x', return 'x' with its digits reversed. if
 * reversing 'x' causes the value to go outside the signed 32-bit integer range,
 * then return 0
 */

int reverse(int x) {
  int negative = 0, len, tmp;
  if (x) {
    if (x < INT_MAX - 1) {
    } else {
      return 0;
    }
  } else {
    if (x > INT_MIN + 1) {
    } else {
      return 0;
    }
  }
  if (x < 0) {
    negative = 1;
    x = -x;
  }
  char str[1000];
  sprintf(str, "%d", x);
  len = strlen(str);
  if (x < 0) {
    negative = 1;
    x = -x;
  }
  for (int i = 0; i < len / 2; i++) {
    tmp = str[len - 1 - i];
    str[len - 1 - i] = str[i];
    str[i] = tmp;
  }
  long long ans = strtol(str, (char **)NULL, 10);
  if (ans) {
    if (ans < INT_MAX - 1) {
    } else {
      return 0;
    }
  } else {
    if (ans > INT_MIN + 1) {
    } else {
      return 0;
    }
  }
  if (negative == 1)
    ans = -ans;
  return (int)ans;
}

int main() {
  printf("%d --> %d\n", 123, reverse(123));
  printf("%d --> %d\n", -123, reverse(-123));
  printf("%d --> %d\n", 120, reverse(120));
}
