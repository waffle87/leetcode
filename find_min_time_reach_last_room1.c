// 3341. Find Minimum Time to Reach Last Room I
#include "leetcode.h"

/*
 * there is a dungeo with 'n x m' rooms arranged as a grid. you are given a 2d
 * array 'moveTime' of size 'n x m' where 'moveTime[i][j]' represents the
 * minimum time in seconds when you can start moving to that room. you start
 * from the room at '(0, 0)' at time 't = 0' and can move to an adjacent room.
 * moving between adjacent rooms takes exactly one second. return the minimum
 * time to reach the room 'n - 1, m - 1'.
 */

int minTimeToReach(int **moveTime, int moveTimeSize, int *moveTimeColSize) {
  int n = moveTimeSize, m = moveTimeColSize[0];
  if (!n)
    return -1;
  int total = n * m, *dp = (int *)malloc(total * sizeof(int));
  for (int i = 0; i < total; i++)
    dp[i] = INT_MAX;
  dp[0] = 0;
  int *heap = (int *)malloc(total * sizeof(int)), hsize = 0;
  heap[hsize++] = 0;
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (hsize) {
    int u = heap[0];
    heap[0] = heap[--hsize];
    int i = 0;
    while (1) {
      int l = 2 * i + 1, r = 2 * i + 2, best = i;
      if (l < hsize && dp[heap[l]] < dp[heap[best]])
        best = l;
      if (r < hsize && dp[heap[r]] < dp[heap[best]])
        best = r;
      if (best == i)
        break;
      int tmp = heap[i];
      heap[i] = heap[best];
      heap[best] = tmp;
      i = best;
    }
    if (u == total - 1)
      break;
    int t = dp[u], x = u / m, y = u % m;
    for (int d = 0; d < 4; d++) {
      int nx = x + dirs[d][0], ny = y + dirs[d][1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      int idx = nx * m + ny;
      int w = (moveTime[nx][ny] > t ? moveTime[nx][ny] : t) + 1;
      if (w < dp[idx]) {
        dp[idx] = w;
        int j = hsize;
        heap[hsize++] = idx;
        while (j > 0 && dp[heap[j]] < dp[heap[(j - 1) / 2]]) {
          int p = (j - 1) / 2, tmp = heap[j];
          heap[j] = heap[p];
          heap[p] = tmp;
          j = p;
        }
      }
    }
  }
  int ans = dp[total - 1];
  free(dp);
  free(heap);
  return ans;
}

int main() {
  int mt1i[2][2] = {{0, 4}, {4, 4}}, mt2i[2][3] = {{0, 0, 0}, {0, 0, 0}},
      mt3i[2][2] = {{0, 1}, {1, 2}};
  struct two_d_arr *mt1 =
      two_d_arr_init(ARRAY_SIZE(mt1i), ARRAY_SIZE(mt1i[0]), mt1i);
  struct two_d_arr *mt2 =
      two_d_arr_init(ARRAY_SIZE(mt2i), ARRAY_SIZE(mt2i[0]), mt2i);
  struct two_d_arr *mt3 =
      two_d_arr_init(ARRAY_SIZE(mt3i), ARRAY_SIZE(mt3i[0]), mt3i);
  printf("%d\n",
         minTimeToReach(mt1->arr, mt1->row_size, mt1->col_size)); // expect: 6
  printf("%d\n",
         minTimeToReach(mt2->arr, mt2->row_size, mt2->col_size)); // expect: 3
  printf("%d\n",
         minTimeToReach(mt3->arr, mt3->row_size, mt3->col_size)); // expect: 3
  two_d_arr_free(mt1);
  two_d_arr_free(mt2);
  two_d_arr_free(mt3);
}
