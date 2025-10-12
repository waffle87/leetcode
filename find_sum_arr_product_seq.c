// 3539. Find Sum of Array Product of Magical Sequences
#include "leetcode.h"

/*
 * you are given two integers 'm' and 'k', and an integer array 'nums'. a
 * sequence of integers 'seq' is called magical if 'seq' has a size of 'm', '0
 * <= seq[i] < nums.len', and the binary representation of '2^seq[0] + 2^seq[1]
 * + ...' has 'k' set bits. the array product of this sequence is defined as
 * 'prod(seq) = (nums[seq[0]] * nums[seq[1]] * ...)'. return the sum of the
 * array products for all valid magical sequences. since the answer may be very
 * large, return it modulo 10^9+7. a set bit refers to a bit in the binary
 * represenation of a number that has a value of 1
 */

static int mod = 1e9 + 7;

int magicalSum(int m, int k, int *nums, int numsSize) {
  int **pow_tab = (int **)malloc(numsSize * sizeof(int *));
  for (int i = 0; i < numsSize; i++) {
    pow_tab[i] = (int *)malloc((m + 1) * sizeof(int));
    pow_tab[i][0] = 1;
    for (int j = 1; j <= m; j++) {
      long long val = (1LL * pow_tab[i][j - 1] * nums[i]) % mod;
      pow_tab[i][j] = (int)val;
    }
  }
  int **cmb = (int **)malloc((m + 1) * sizeof(int *));
  for (int i = 0; i <= m; i++) {
    cmb[i] = (int *)malloc((m + 1) * sizeof(int));
    memset(cmb[i], 0, (m + 1) * sizeof(int));
  }
  for (int i = 0; i <= m; i++) {
    cmb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      cmb[i][j] = cmb[i - 1][j - 1] + cmb[i - 1][j];
      if (cmb[i][j] >= mod)
        cmb[i][j] -= mod;
    }
  }
  int ***dp = (int ***)malloc((m + 1) * sizeof(int **));
  int ***next = (int ***)malloc((m + 1) * sizeof(int **));
  for (int i = 0; i <= m; i++) {
    dp[i] = (int **)malloc((m + 1) * sizeof(int *));
    next[i] = (int **)malloc((m + 1) * sizeof(int *));
    for (int j = 0; j <= m; j++) {
      dp[i][j] = (int *)calloc(k + 1, sizeof(int));
      next[i][j] = (int *)calloc(k + 1, sizeof(int));
    }
  }
  dp[m][0][0] = 1;
  for (int i = 0; i < numsSize; i++) {
    for (int j = 0; j <= m; j++)
      for (int c = 0; c <= m; c++)
        memset(next[j][c], 0, (k + 1) * sizeof(int));
    for (int rem = 0; rem <= m; rem++) {
      for (int carry = 0; carry <= m; carry++)
        for (int ones = 0; ones <= k; ones++) {
          int base = dp[rem][carry][ones];
          if (!base)
            continue;
          for (int c = 0; c <= rem; c++) {
            int tmp = c + carry;
            int bit = tmp & 1;
            int ones2 = ones + bit;
            if (ones2 > k)
              continue;
            int carry2 = tmp >> 1;
            int rem2 = rem - c;
            long long add = base;
            add = (add * cmb[rem][c]) % mod;
            add = (add * pow_tab[i][c]) % mod;
            int curr = next[rem2][carry2][ones2] + (int)add;
            if (curr >= mod)
              curr -= mod;
            next[rem2][carry2][ones2] = curr;
          }
        }
    }
    int ***tmp = dp;
    dp = next;
    next = tmp;
  }
  long long ans = 0;
  for (int carry = 0; carry <= m; carry++) {
    int extra = __builtin_popcount(carry);
    int need = k - extra;
    if (need >= 0 && need <= k) {
      ans += dp[0][carry][need];
      if (ans >= mod)
        ans -= mod;
    }
  }
  for (int i = 0; i < numsSize; i++)
    free(pow_tab[i]);
  free(pow_tab);
  for (int i = 0; i <= m; i++)
    free(cmb[i]);
  free(cmb);
  for (int rem = 0; rem <= m; rem++) {
    for (int carry = 0; carry <= m; carry++) {
      free(dp[rem][carry]);
      free(next[rem][carry]);
    }
    free(dp[rem]);
    free(next[rem]);
  }
  free(dp);
  free(next);
  return (int)(ans % mod);
}

int main() {
  int n1[] = {1, 10, 100, 10000, 1000000};
  int n2[] = {5, 4, 3, 2, 1};
  int n3[] = {28};
  printf("%d\n", magicalSum(5, 5, n1, ARRAY_SIZE(n1))); // expect: 991600007
  printf("%d\n", magicalSum(2, 2, n2, ARRAY_SIZE(n2))); // expect: 170
  printf("%d\n", magicalSum(1, 1, n3, ARRAY_SIZE(n3))); // expect: 28
}
