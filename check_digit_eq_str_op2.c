// 3463. Check If Digits Are Equal in String After Operations II
#include "leetcode.h"

/*
 * you are given a string 's' consisting of digits. perform the following
 * operation repeatedly until the string has exactly two digits: for each pair
 * of consecutive digits in 's', starting from the first digit, calculate a new
 * digit as the sum of the two digits modulo 10. replace 's' with the sequence
 * of newly calculated digits, maintaining the order in which they are computed.
 * return 'true' if the final two digits in 's' are the same; otherwise return
 * false.
 */

static inline int gcd(int a, int b) {
  while (b) {
    a ^= b ^= a ^= b;
    b %= a;
  }
  return a;
}

static inline void fac(int a, int mod, int *r, int *cnt) {
  int num = 0;
  while (a && !(a % mod)) {
    num++;
    a /= mod;
  }
  *r = a % mod;
  *cnt = num;
}

static inline int inv_mod(int a, int mod) {
  for (int i = 1; i < mod; i++)
    if ((a * i) % mod == 1)
      return i;
  return 0;
}

static bool test(int mod, char *s) {
  int n = strlen(s), res = 0, r = 1, c = 0;
  for (int i = 0; i < n - 1; i++) {
    if (!c) {
      res = (res + r * ((s[i] - '0') - (s[i + 1] - '0'))) % mod;
      if (res < 0)
        res += mod;
    }
    int rr, cc;
    fac(n - 2 - i, mod, &rr, &cc);
    r = (r * rr) % mod;
    c += cc;
    fac(i + 1, mod, &rr, &cc);
    r = (r * inv_mod(rr, mod)) % mod;
    c -= cc;
  }
  return !(res % mod);
}

bool hasSameDigits(char *s) { return test(2, s) && test(5, s); }

int main() {
  char *s1 = "3902", *s2 = "34789";
  printf("%d\n", hasSameDigits(s1)); // expect: 1
  printf("%d\n", hasSameDigits(s2)); // expect: 0
}
