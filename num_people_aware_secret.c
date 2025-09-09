// 2327. Number of People Aware of a Secret
#include "leetcode.h"

/*
 * on day 1, one person discovers  decret. you are given an integer 'delay'
 * which means that each person will share the secret with a new person every
 * day starting from 'delay' days after discovering the secret. you are also
 * given an integer 'forget', which means that each person will forget the
 * secret 'forget' days after discovering it. a person cannot share the secret
 * on the same day they forgot it, or any day afterwards. given an integer 'n',
 * return the number of people who know the secret at the end of day 'n'. since
 * the answer may be very large, return it modulo 10^9+7.
 */

int peopleAwareOfSecret(int n, int delay, int forget) {
  long *dp = (long *)malloc((n + 1) * sizeof(int));
  dp[1] = 1;
  int share = 0, mod = 1e9 + 7, ans = 0;
  for (int i = 2; i <= n; ++i)
    dp[i] = share = (share + dp[(int)fmax(i - delay, 0)] -
                     dp[(int)fmax(i - forget, 0)] + mod) %
                    mod;
  for (int i = n - forget + 1; i <= n; ++i)
    ans = (ans + dp[i]) % mod;
  free(dp);
  return ans;
}

int main() {
  printf("%d\n", peopleAwareOfSecret(6, 2, 4)); // expect: 5
  printf("%d\n", peopleAwareOfSecret(4, 1, 3)); // expect: 6
}
