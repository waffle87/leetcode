// 2492. Minimum Score of a Path Between Two Cities
#include "leetcode.h"

/*
 * you are given a positive integer 'n' representing 'n' cities numbered from 1
 * to 'n'. you are also given a 2d array 'roads' where 'roads[i] = [a_i, b_i,
 * distance_i]' indicates that there is a bidirectional road between cities
 * 'a_i' and 'b_i' with a distance equal to 'distance_i'. the cities graph is
 * not necessarily connected. the score of a path between two cities is defined
 * as the minimum distance of a road in this path. return the minimum possible
 * score of a path between cities 1 and 'n'.
 */

int find(int *root, int x) {
  if (root[x] != x)
    root[x] = find(root, root[x]);
  return root[x];
}

int minScore(int n, int **roads, int roadsSize, int *roadsColSize) {
  int *root = (int *)malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; i++)
    root[i] = i;
  for (int i = 0; i < roadsSize; i++) {
    int x = roads[i][0], y = roads[i][1];
    root[find(root, x)] = find(root, y);
  }
  int ans = INT_MAX, target = find(root, 1);
  for (int i = 0; i < roadsSize; i++) {
    int x = roads[i][0], d = roads[i][2];
    if (find(root, x) == target)
      ans = fmin(ans, d);
  }
  free(root);
  return ans;
}

int main() {
  int r1i[4][3] = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
  int r2i[3][3] = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
  struct two_d_arr *r1 =
      two_d_arr_init(ARRAY_SIZE(r1i), ARRAY_SIZE(r1i[0]), r1i);
  struct two_d_arr *r2 =
      two_d_arr_init(ARRAY_SIZE(r2i), ARRAY_SIZE(r2i[0]), r2i);
  int ms1 = minScore(4, r1->arr, r1->row_size, r1->col_size);
  int ms2 = minScore(4, r2->arr, r2->row_size, r2->col_size);
  printf("%d\n", ms1);
  assert(ms1 == 5);
  printf("%d\n", ms2);
  assert(ms2 == 2);
  two_d_arr_free(r1);
  two_d_arr_free(r2);
}
