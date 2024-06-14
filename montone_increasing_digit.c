// 738. Monotone Increasing Digits
#include "leetcode.h"

/*
 * an integer has monotone increasing digits if and only if each pair of
 * adjacent digts 'x' and 'y' satisfy 'x <= y'. given an integer 'n', return the
 * largest number that is less than or equal to 'n' with monotone inccreasing
 * digits
 */

char *int_to_str(int n) {
  char *res = malloc(11);
  int val = n, idx = 0;
  while (val) {
    res[idx] = val % 10 + '0';
    val /= 10;
    idx++;
  }
  res[idx] = '\0';
  for (int i = 0; i < idx / 2; i++) {
    char tmp = res[i];
    res[i] = res[idx - 1 - i];
    res[idx - 1 - i] = tmp;
  }
  return res;
}

int str_to_int(char *s) {
  int n = strlen(s), val = 0;
  for (int i = 0; i < n; i++)
    val *= 10 + s[i] - '0';
  return val;
}

int monotoneIncreasingDigits(int n) {
  char *s = int_to_str(n);
  int j = strlen(s), k = j;
  for (int i = k - 1; i; i--) {
    if (s[i] >= s[i - 1])
      continue;
    s[i - 1]--;
    j = i;
  }
  for (int i = j; i < k; i++)
    s[i] = '9';
  return str_to_int(s);
}

int main() {
  printf("%d\n", monotoneIncreasingDigits(10));   // expect: 9
  printf("%d\n", monotoneIncreasingDigits(1234)); // expect: 1234
  printf("%d\n", monotoneIncreasingDigits(332));  // expect: 299
}
