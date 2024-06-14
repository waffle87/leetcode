// 2492. Minimum Score of a Path Between Two Cities
#include <limits.h>
#include <math.h>
#include <stdlib.h>

int find_father(int **u, int val) {
  int k = val;
  while (k != u[k][0])
    k = u[k][0];
  return k;
}

int minScore(int n, int **roads, int roads_size, int *roads_col_size) {
  int **u = malloc((n + 1) * sizeof(int *));
  for (int i = 1; i <= n; i++) {
    u[i] = malloc(3 * sizeof(int));
    u[i][0] = i;
    u[i][1] = 1;
    u[i][2] = INT_MAX;
  }
  for (int i = 0; i < roads_size; i++) {
    int a = find_father(u, roads[i][0]);
    int b = find_father(u, roads[i][1]);
    int min = fmin(roads[i][2], fmin(u[a][2], u[b][2]));
    if (a == b) {
      u[a][2] = min;
      continue;
    }
    if (u[a][1] >= u[b][1]) {
      u[b][0] = a;
      u[a][2] = min;
      u[a][1] += u[b][1];
    } else {
      u[a][0] = b;
      u[b][2] = min;
      u[b][1] += u[a][1];
    }
  }
  int first = find_father(u, 1), last = find_father(u, n), ans;
  if (first != last)
    ans = -1;
  else
    ans = u[first][2];
  for (int i = 1; i <= n; i++)
    free(u[i]);
  free(u);
  return ans;
}
