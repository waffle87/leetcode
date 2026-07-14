// 3336. Find the Number of Subsequences With Equal GCD
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. your task is to find the number of
 * pairs of non-empty subsequences '(seq1, seq2)' of 'nums' that satisfy the
 * following conditions. the subsequences 'seq1' and 'seq2' are disjoint,
 * meaning no index of 'nums' is common between them. the gcd of the element of
 * 'seq1' is equal to the gcd of the elements of 'seq2'. return the total number
 * of such pairs. since the answer may be very large, return it modulo 10^9 + 7.
 */

int gcd(int a, int b) {
  while (b) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

int subsequencePairCount(int *nums, int numsSize) {
  static int mod = 1e9 + 7;
  int m = 0;
  for (int i = 0; i < numsSize; i++)
    m = fmax(m, nums[i]);
  int n = m + 1;
  int **dp0 = (int **)malloc(n * sizeof(int *));
  int **dp1 = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    dp0[i] = (int *)calloc(n, sizeof(int));
    dp1[i] = (int *)calloc(n, sizeof(int));
  }
  dp0[0][0] = 1;
  for (int i = 0; i < numsSize; i++) {
    int num = nums[i];
    for (int g1 = 0; g1 <= m; g1++)
      for (int g2 = 0; g2 <= m; g2++)
        dp1[g1][g2] = 0;
    for (int g1 = 0; g1 <= m; g1++) {
      int next_gcd1 = gcd(g1, num);
      for (int g2 = 0; g2 <= m; g2++) {
        int ways = dp0[g1][g2];
        if (!ways)
          continue;
        int next_gcd2 = gcd(g2, num);
        dp1[g1][g2] = (dp1[g1][g2] + ways) % mod;
        dp1[next_gcd1][g2] = (dp1[next_gcd1][g2] + ways) % mod;
        dp1[g1][next_gcd2] = (dp1[g1][next_gcd2] + ways) % mod;
      }
    }
    int **tmp = dp0;
    dp0 = dp1;
    dp1 = tmp;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++)
    ans = (ans + dp0[i][i]) % mod;
  for (int i = 0; i < n; i++) {
    free(dp0[i]);
    free(dp1[i]);
  }
  free(dp0);
  free(dp1);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4};
  int n2[] = {10, 20, 30};
  int n3[] = {1, 1, 1, 1};
  int r1 = subsequencePairCount(n1, ARRAY_SIZE(n1));
  int r2 = subsequencePairCount(n2, ARRAY_SIZE(n2));
  int r3 = subsequencePairCount(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 10);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 50);
}
