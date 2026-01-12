// 1595. Minimum Cost to Connect Two Groups of Points
#include "leetcode.h"

/*
 * you are given two groups of points where the first group has 'size_i' points,
 * the second group has 'size_j' points, and 'size_i >= size_j'. the 'cost' of
 * the connection between any two points are giveen in 'size_i * size_j' matrix
 * where 'cost[i][j]' is the cost of connecting point 'i' of the first group and
 * point 'j' of the second group. the groups are connected if each oint in both
 * groups is connected to one or more points in the opposite group. in other
 * words, each point in the first group must be connected to at least one pooint
 * in the second group. return the minimum cost it takes to connect the two
 * groups.
 */

int connectTwoGroups(int **cost, int costSize, int *costColSize) {
  int n = costSize, m = costColSize[0];
  int *dp0 = (int *)malloc((1 << m) * sizeof(int));
  for (int i = 0; i < (1 << m); i++)
    dp0[i] = INT_MAX;
  dp0[0] = 0;
  for (int i = 0; i < n; ++i) {
    int *dp1 = (int *)malloc((1 << m) * sizeof(int));
    for (int j = 0; j < (1 << m); j++)
      dp1[i] = INT_MAX;
    for (int j = 0; j < (1 << m); ++j) {
      for (int k = j;; k = (k - 1) & j) {
        int total = 0;
        if (j == k) {
          total = INT_MAX;
          for (int l = 0; l < m; ++l)
            if (k & (1 << l))
              total = fmin(total, cost[i][l]);
        } else {
          for (int l = 0; l < m; ++l) {
            if (k & (1 << l)) {
              if (!(j & (1 << l))) {
                total = INT_MAX;
                break;
              }
            } else if (j & (1 << l))
              total += cost[i][l];
          }
        }
        dp1[j] = fmin(dp1[j], dp0[k] + total);
        if (!k)
          break;
      }
    }
    memcpy(dp0, dp1, (1 << m) * sizeof(int));
    free(dp1);
  }
  int ans = dp0[(1 << m) - 1];
  free(dp0);
  return ans;
}

int main() {
  int c1i[2][2] = {{15, 96}, {36, 2}};
  int c2i[3][3] = {{1, 3, 5}, {4, 1, 1}, {1, 5, 3}};
  int c3i[5][3] = {{2, 5, 1}, {3, 4, 7}, {8, 1, 2}, {6, 2, 4}, {3, 8, 8}};
  struct two_d_arr *c1 =
      two_d_arr_init(ARRAY_SIZE(c1i), ARRAY_SIZE(c1i[0]), c1i);
  struct two_d_arr *c2 =
      two_d_arr_init(ARRAY_SIZE(c2i), ARRAY_SIZE(c2i[0]), c2i);
  struct two_d_arr *c3 =
      two_d_arr_init(ARRAY_SIZE(c3i), ARRAY_SIZE(c3i[0]), c3i);
  printf("%d\n",
         connectTwoGroups(c1->arr, c1->row_size, c1->col_size)); // expect: 17
  printf("%d\n",
         connectTwoGroups(c2->arr, c2->row_size, c2->col_size)); // expect: 4
  printf("%d\n",
         connectTwoGroups(c3->arr, c3->row_size, c3->col_size)); // expect: 10
  two_d_arr_free(c1);
  two_d_arr_free(c2);
  two_d_arr_free(c3);
}
