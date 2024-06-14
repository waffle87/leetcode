// 547. Number of Provinces
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * dthere are 'n' cities. some of them are connected, while some are not. if
 * city 'a' is connected directly with city 'b', and city 'b' is connected
 * directly with city 'c', then city 'a' is connected indirectly with city 'c'.
 * a province is a group of directly or indirectly connected cities and no other
 * cities outside of the group. given an 'n x n' matrix 'is_connected' where
 * 'is_connected[i][j] = 1' if the i'th city and the j'th city are directly
 * connected, and 'is_connected[i][j] = 0' otherwise. return the total number of
 * provinces
 */

void dfs(int **is_connected, bool *vis, int n, int i) {
  for (int j = 0; j < n; j++) {
    if (is_connected[i][j] && !vis[j]) {
      is_connected[i][j] = 0;
      vis[j] = true;
      dfs(is_connected, vis, n, j);
    }
  }
}

int findCircleNum(int **is_connected, int is_connected_size,
                  int *is_connected_col_size) {
  int ans = 0;
  bool *vis = calloc(is_connected_size, sizeof(bool));
  for (int i = 0; i < is_connected_size; i++) {
    if (is_connected[i][i] && !vis[i]) {
      ans++;
      vis[i] = true;
      is_connected[i][i] = 0;
      dfs(is_connected, vis, is_connected_size, i);
    }
  }
  free(vis);
  return ans;
}

int main() {
  int ic1[3][3] = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, ics1 = 3, *iccs1;
  int ic2[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, ics2 = 3, *iccs2;
  printf("%d\n", findCircleNum(ic1, ics1, iccs1)); // expect: 2
  printf("%d\n", findCircleNum(ic2, ics2, iccs2)); // expect: 3
}
