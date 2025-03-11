// 397. Integer Replacement
#include "leetcode.h"

/*
 * given a positive integer 'n', you can apply one of the following operations:
 * if 'n' is even, replace 'n' witn 'n / 2'. if 'n' is odd, replace 'n' with
 * either 'n + 1' or 'n - 1'. return the minimum number of operations needed for
 * 'n' to become 1
 */

int integerReplacement(int n) {
  int ans = 0;
  while (n > 1) {
    if (n == 3)
      return ans + 2;
    else if (!(n & 1))
      n = (n >> 1) & 0x7FFFFFFF;
    else if (!((n + 1) % 4))
      n++;
    else
      n--;
    ans++;
  }
  return ans;
}

int main() {
  printf("%d\n", integerReplacement(8)); // expect: 3
  printf("%d\n", integerReplacement(7)); // expect: 4
  printf("%d\n", integerReplacement(4)); // expect: 2
}
