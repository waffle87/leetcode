// 2923. Find Champion I
#include "leetcode.h"

/*
 * there are 'n' teams numbered from 0 to 'n - 1' in a tournament. given
 * 0-indexed 2d boolean matrix 'grid' of size 'n * n'. for all 'i, j' that '0 <=
 * i, j <= n - 1' and 'i != j' team 'i' is stronger than team 'j' if 'grid[i][j]
 * == 1' otherwise team 'j' is stronger tham team 'i'. team 'a' will be the
 * champion of the tournament if there is no team 'b' that is stronger than team
 * 'a'. return the team that will be the champion of the tournament.
 */

int findChampion(int **grid, int gridSize, int *gridColSize) {
  int max_idx = 0, max_cnt = 0;
  for (int i = 0; i < gridSize; i++) {
    int curr_cnt = 0;
    for (int j = 0; j < gridColSize[i]; j++)
      curr_cnt += grid[i][j];
    if (curr_cnt > max_cnt) {
      max_cnt = curr_cnt;
      max_idx = i;
    }
  }
  return max_idx;
}

int main() {
  int g1[2][2] = {{0, 1}, {0, 0}}, g2[3][3] = {{0, 0, 1}, {1, 0, 1}, {0, 0, 0}};
  int gcs1 = 2, gcs2 = 3;
  printf("%d\n", findChampion((int **)g1, ARRAY_SIZE(g1), &gcs1)); // expect: 0
  printf("%d\n", findChampion((int **)g2, ARRAY_SIZE(g2), &gcs2)); // expect: 1
}
