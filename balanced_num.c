// 2048. Next Greater Numerically Balanced Number
#include "leetcode.h"

/*
 * an integer 'x' is numerically balanced if for every digit 'd' in the number
 * 'x', there are exactly 'd' occurences of that digit in 'x'. given an integer
 * 'n', return the smallest numerically balanced number strictly greater than
 * 'n'
 */

bool is_balanced(int n) {
  int *digit = calloc(10, sizeof(int));
  while (n) {
    int d = n % 10;
    n /= 10;
    digit[d]++;
    if (!d || digit[d] > d)
      return 0;
  }
  for (int i = 1; i < 10; i++)
    if (digit[i] && digit[i] != i)
      return 0;
  return 1;
}

int nextBeautifulNumber(int n) {
  n += 1;
  while (1) {
    if (is_balanced(n))
      return n;
    n++;
  }
  return -1;
}

int main() {
  printf("%d\n", nextBeautifulNumber(1));    // expect: 22
  printf("%d\n", nextBeautifulNumber(1000)); // expect: 1333
  printf("%d\n", nextBeautifulNumber(3000)); // expect: 3133
}
