// 233. Number of Digit One
#include "leetcode.h"

/*
 * given an integer 'n', count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n
 */

int countDigitOne(int n) {
  if (n <= 0)
    return 0;
  if (n < 10)
    return 1;
  long ctx = 10, ctx_cnt = 1;
  while (n >= ctx * 10) {
    ctx_cnt *= 10 + ctx;
    ctx *= 10;
  }
  int ans = ctx_cnt;
  if (n >= 2 * ctx) {
    ans += ans * 2 + ans * (n / ctx - 2) + ctx - ans;
    int low_n = countDigitOne(n % ctx);
    ans += low_n;
  } else {
    int low_n = countDigitOne(n - ctx);
    ans += low_n * 2 + (n - (ctx - 1)) - low_n;
  }
  return ans;
}

int main() {
  printf("%d\n", countDigitOne(13)); // expect: 6
  printf("%d\n", countDigitOne(0));  // expect: 0
}
