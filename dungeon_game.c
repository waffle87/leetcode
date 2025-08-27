// 174. Dungeon Game
#include "leetcode.h"

/*
 * the demons had captured the princess and imprisoned her in the bottom right
 * corner of a dungeon. the 'dungeon' consists of 'm x n' rooms laid out in a 2d
 * grid. our valiant knight was initially positioned in the top left room and
 * must fight his way through the 'dungeon' to rescue the princess. return the
 * knight's minimum initial health so that he can rescue the princess. note that
 * any romm can contain threats or power ups even the first room the knight
 * enters and the bottom right room where the princess is imprisoned
 */

int calculateMinimumHP(int **dungeon, int dungeonSize, int *dungeonColSize) {
  int m = dungeonSize, n = *dungeonColSize;
  int **dp = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++)
    dp[i] = (int *)malloc(n * sizeof(int));
  for (int i = m - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--) {
      if (i == m - 1 && j == n - 1)
        dp[i][j] = 1;
      else if (i == m - 1)
        dp[i][j] = dp[i][j + 1] - dungeon[i][j + 1];
      else if (j == n - 1)
        dp[i][j] = dp[i + 1][j] - dungeon[i + 1][j];
      else
        dp[i][j] = fmin(dp[i][j + 1] - dungeon[i][j + 1],
                        dp[i + 1][j] - dungeon[i + 1][j]);
      dp[i][j] = fmax(1, dp[i][j]);
    }
  int ans = dp[0][0] - dungeon[0][0];
  for (int i = 0; i < m; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int d1i[3][3] = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}}, d2i[1][1] = {{0}};
  struct two_d_arr *d1 = two_d_arr_init(3, 3, d1i);
  struct two_d_arr *d2 = two_d_arr_init(1, 1, d2i);
  printf("%d\n",
         calculateMinimumHP(d1->arr, d1->row_size, d1->col_size)); // expect: 7
  printf("%d\n",
         calculateMinimumHP(d2->arr, d2->row_size, d2->col_size)); // expect: 1
  two_d_arr_free(d1);
  two_d_arr_free(d2);
}
