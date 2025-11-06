// 3607. Power Grid Maintenance
#include "leetcode.h"

/*
 * you are given an integer 'c' representing power stations, each with a unique
 * identifier 'id' from 1 to 'c'. these stations are interconnected via 'n'
 * bidirectional cables, represented by a 2 array 'connections' where each
 * element 'connections[i] = [u_i, v_i]' indicates a connection between station
 * 'u_i' and 'v_i'. stations that are directly or indirectly connected form a
 * power grid. initially, all stations are online (operational). you are also
 * given a 2d integer array 'quries' where each query is one of the following
 * types: '[1, x]': a maintenance check is requested for station 'x'. if station
 * 'x' is online, it resolves the check by itself. if station 'x' is offline,
 * the check is resolved by the operational station with the smallest 'id' in
 * the same power grid as 'x'. if no operational station exists in that grid,
 * return -1. '[2, x]': station 'x' goes offline. return an array of integers
 * representing the results of each query of type '[1, x]' in the order they
 * appear.
 */

int find(int *parent, int x) {
  if (parent[x] != x)
    parent[x] = find(parent, parent[x]);
  return parent[x];
}

int *processQueries(int c, int **connections, int connectionsSize,
                    int *connectionsColSize, int **queries, int queriesSize,
                    int *queriesColSize, int *returnSize) {
  int *parent = (int *)malloc((c + 1) * sizeof(int));
  for (int i = 0; i <= c; i++)
    parent[i] = i;
  for (int i = 0; i < connectionsSize; i++) {
    int a = connections[i][0], b = connections[i][1];
    int aa = find(parent, a), bb = find(parent, b);
    if (aa != bb)
      parent[bb] = aa;
  }
  int *next_node = (int *)calloc(c + 1, sizeof(int));
  int *cmp_min = (int *)calloc(c + 1, sizeof(int));
  int *prev = (int *)calloc(c + 1, sizeof(int));
  for (int i = 1; i <= c; i++) {
    int r = find(parent, i);
    if (!cmp_min[r])
      cmp_min[r] = i;
    else
      next_node[prev[r]] = i;
    prev[r] = i;
  }
  int *offline = (int *)calloc(c + 1, sizeof(int)), ri = 0;
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int t = queries[i][0], x = queries[i][1], r = find(parent, x);
    if (t == 1) {
      if (!offline[x])
        ans[ri++] = x;
      else
        ans[ri++] = cmp_min[r] ? cmp_min[r] : -1;
    } else {
      if (offline[x])
        continue;
      offline[x] = 1;
      if (cmp_min[r] == x) {
        int y = next_node[x];
        while (y && offline[y])
          y = next_node[y];
        cmp_min[r] = y;
      }
    }
  }
  free(parent);
  free(next_node);
  free(cmp_min);
  free(prev);
  free(offline);
  *returnSize = ri;
  return ans;
}

int main() {
  int c1i[4][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}},
      q1i[5][2] = {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}};
  struct two_d_arr *c1 =
      two_d_arr_init(ARRAY_SIZE(c1i), ARRAY_SIZE(c1i[0]), c1i);
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  int rs1, *pq1 = processQueries(5, c1->arr, c1->row_size, c1->col_size,
                                 q1->arr, q1->row_size, q1->col_size, &rs1);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pq1[i]); // expect: 3 2 3
  printf("\n");
  free(pq1);
  two_d_arr_free(c1);
  two_d_arr_free(q1);
}
