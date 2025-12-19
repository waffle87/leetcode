// 1434. Number of Ways to Wear Different Hats to Each Other
#include "leetcode.h"

/*
 * there are 'n' people and 40 types of hats labeled from 1 to 40. given a 2d
 * integer array 'hats', where 'hats[i]' is a list of all hats preferred by the
 * i'th person. return the number of ways that 'n' people can wear different
 * hats from each other. since the answer may be too large, return it modulo
 * 10^9 + 7.
 */

int numberWays(int **hats, int hatsSize, int *hatsColSize) {
  static int mod = 1e9 + 7;
  int **hat_ppl = (int **)malloc(41 * sizeof(int *));
  for (int i = 0; i < hatsSize; i++)
    hat_ppl[i] = (int *)malloc(hatsSize * sizeof(int));
  int hat_cnt[41] = {0};
  for (int i = 0; i < hatsSize; i++)
    for (int j = 0; j < hatsColSize[i]; j++)
      hat_ppl[hats[i][j]][hat_cnt[hats[i][j]]++] = i;
  int *dp = (int *)calloc(1 << hatsSize, sizeof(int));
  dp[0] = 1;
  for (int i = 1; i <= 40; i++) {
    int *new_dp = (int *)malloc((1 << hatsSize) * sizeof(int));
    memset(new_dp, dp[i], (1 << hatsSize) * sizeof(int));
    for (int mask = 0; mask < (1 << hatsSize); mask++) {
      for (int j = 0; j < hat_cnt[i]; j++) {
        int person = hat_ppl[i][j];
        if (!(mask & (1 << person))) {
          int new_mask = mask | 1 << person;
          new_dp[new_mask] = (new_dp[new_mask] + dp[mask]) % mod;
        }
      }
    }
    memset(dp, new_dp[i], (1 << hatsSize) * sizeof(int));
    free(new_dp);
  }
  int ans = dp[(1 << hatsSize) - 1];
  for (int i = 0; i < hatsSize; i++)
    free(hat_ppl[i]);
  free(hat_ppl);
  free(dp);
  return ans;
}

int main() {
  int h1i[3][2] = {{3, 4}, {4, 5}, {5}};
  int h2i[2][3] = {{3, 5, 1}, {3, 5}};
  int h3i[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
  struct two_d_arr *h1 =
      two_d_arr_init(ARRAY_SIZE(h1i), ARRAY_SIZE(h1i[0]), h1i);
  struct two_d_arr *h2 =
      two_d_arr_init(ARRAY_SIZE(h2i), ARRAY_SIZE(h2i[0]), h2i);
  struct two_d_arr *h3 =
      two_d_arr_init(ARRAY_SIZE(h3i), ARRAY_SIZE(h3i[0]), h3i);
  printf("%d\n", numberWays(h1->arr, h1->row_size, h1->col_size)); // expect: 1
  printf("%d\n", numberWays(h2->arr, h2->row_size, h2->col_size)); // expect: 4
  printf("%d\n", numberWays(h3->arr, h3->row_size, h3->col_size)); // expect: 24
  two_d_arr_free(h1);
  two_d_arr_free(h2);
  two_d_arr_free(h3);
}
