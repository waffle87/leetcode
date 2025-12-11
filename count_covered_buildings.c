// 3531. Count Covered Buildings
#include "leetcode.h"

/*
 * you are given a positive integer 'n', representing an 'n x n' city. you are
 * also given a 2d grid 'buildings' where 'buildings[i] = [x, y]' denotes a
 * unique building located at coordinates '[x, y]'. a building is covered if
 * there is at least one building in all four directions. return the number of
 * covered buildings.
 */

int countCoveredBuildings(int n, int **buildings, int buildingsSize,
                          int *buildingsColSize) {
  int *max_row = (int *)calloc(n + 1, sizeof(int));
  int *max_col = (int *)calloc(n + 1, sizeof(int));
  int *min_row = (int *)malloc((n + 1) * sizeof(int));
  int *min_col = (int *)malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; i++) {
    min_row[i] = n + 1;
    min_col[i] = n + 1;
  }
  for (int i = 0; i < buildingsSize; i++) {
    int x = buildings[i][0], y = buildings[i][1];
    if (x > max_row[y])
      max_row[y] = x;
    if (x < min_row[y])
      min_row[y] = x;
    if (y > max_col[x])
      max_col[x] = y;
    if (y < min_col[x])
      min_col[x] = y;
  }
  int ans = 0;
  for (int i = 0; i < buildingsSize; i++) {
    int x = buildings[i][0], y = buildings[i][1];
    if (x > min_row[y] && x < max_row[y] && y > min_col[x] && y < max_col[x])
      ans++;
  }
  free(max_row);
  free(max_col);
  free(min_row);
  free(min_col);
  return ans;
}

int main() {
  int b1i[5][2] = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};
  int b2i[4][2] = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
  int b3i[5][2] = {{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}};
  struct two_d_arr *b1 =
      two_d_arr_init(ARRAY_SIZE(b1i), ARRAY_SIZE(b1i[0]), b1i);
  struct two_d_arr *b2 =
      two_d_arr_init(ARRAY_SIZE(b2i), ARRAY_SIZE(b2i[0]), b2i);
  struct two_d_arr *b3 =
      two_d_arr_init(ARRAY_SIZE(b3i), ARRAY_SIZE(b3i[0]), b3i);
  printf("%d\n", countCoveredBuildings(3, b1->arr, b1->row_size,
                                       b1->col_size)); // exepct: 1
  printf("%d\n", countCoveredBuildings(3, b2->arr, b2->row_size,
                                       b2->col_size)); // exepct: 0
  printf("%d\n", countCoveredBuildings(5, b3->arr, b3->row_size,
                                       b3->col_size)); // exepct: 1
  two_d_arr_free(b1);
  two_d_arr_free(b2);
  two_d_arr_free(b3);
}
