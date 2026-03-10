// 3130. Find All Possible Stable Binary Arrays II
#include "leetcode.h"

/*
 * you are given 3 positive integers 'zero', 'one', and 'limit'. a binary array
 * 'arr' is called stable is the number of occurences of 0 in 'arr' is exactly
 * 'zero', the number of occurences of  1 in 'arr' is exactly 'one', and each
 * subarray of 'arr' with a size greater than 'limit' must contain 0 and 1.
 * return the total number o stable binary arrays. since the answer may be very
 * large, return it modulo 10^9+7.
 */

static int mod = 1e9 + 7;

int ***memo_init(int zero, int one) {
  int ***memo = (int ***)malloc((zero + 1) * sizeof(int **));
  for (int i = 0; i <= zero; ++i) {
    memo[i] = (int **)malloc((one + 1) * sizeof(int *));
    for (int j = 0; j <= one; ++j) {
      memo[i][j] = (int *)malloc(2 * sizeof(int));
      memo[i][j][0] = memo[i][j][1] = -1;
    }
  }
  return memo;
}

void memo_free(int zero, int one, int ***memo) {
  for (int i = 0; i <= zero; ++i) {
    for (int j = 0; j <= one; ++j)
      free(memo[i][j]);
    free(memo[i]);
  }
  free(memo);
}

int dp(int zero, int one, int prev_bit, int limit, int ***memo) {
  if (!zero)
    return (prev_bit || one > limit) ? 0 : 1;
  else if (!one)
    return (prev_bit == 1 || zero > limit) ? 0 : 1;
  if (memo[zero][one][prev_bit] == -1) {
    int res = 0;
    if (!prev_bit) {
      res = (dp(zero - 1, one, 0, limit, memo) +
             dp(zero - 1, one, 1, limit, memo)) %
            mod;
      if (zero > limit)
        res = (res - dp(zero - limit - 1, one, 1, limit, memo) + mod) % mod;
    } else {
      res = (dp(zero, one - 1, 0, limit, memo) +
             dp(zero, one - 1, 1, limit, memo)) %
            mod;
      if (one > limit)
        res = (res - dp(zero, one - limit - 1, 0, limit, memo) + mod) % mod;
    }
    memo[zero][one][prev_bit] = res % mod;
  }
  return memo[zero][one][prev_bit];
}

int numberOfStableArrays(int zero, int one, int limit) {
  int ***memo = memo_init(zero, one);
  int ans =
      (dp(zero, one, 0, limit, memo) + dp(zero, one, 1, limit, memo)) % mod;
  memo_free(zero, one, memo);
  return ans;
}

int main() {
  int r1 = numberOfStableArrays(1, 1, 2);
  int r2 = numberOfStableArrays(1, 2, 1);
  int r3 = numberOfStableArrays(3, 3, 2);
  printf("%d\n", r1); // expect: 2
  assert(r1 == 2);
  printf("%d\n", r2); // expect: 1
  assert(r2 == 1);
  printf("%d\n", r3); // expect: 14
  assert(r3 == 14);
}
