// 1970. Last Day Where You Can Still Cross
#include "leetcode.h"

/*
 * there is a 1-based binary matrix where '0' represents land and '1' represents
 * water. you are given integers 'row' and 'col' representing the number of rows
 * and columns in the matrix, repsectively. initially, on day 0, the entier
 * matrix is land. however, each day a new cell becomes flooded with water. you
 * are given a 1-based 2d array 'cells' where 'cells[i] = [ri, ci]' represents
 * that on the i'th day, the cell on the ri'th row and the ci'th column will be
 * covered with water. you want to find the last day that it is still possible
 * to walk from the top to the bottom only by walking on land cells. you can
 * start rom any cell in the top row and end at any cell in the bottom row. you
 * can only travel in the four cardinal directions.
 */

int find(int *p, int x) {
  if (p[x] != x)
    p[x] = find(p, p[x]);
  return p[x];
}

void unite(int *p, int *r, int a, int b) {
  a = find(p, a);
  b = find(p, b);
  if (a == b)
    return;
  if (r[a] < r[b])
    p[a] = b;
  else if (r[a] > r[b])
    p[b] = a;
  else
    p[b] = a, r[a]++;
}

int latestDayToCross(int row, int col, int **cells, int cellsSize,
                     int *cellsColSize) {
  int n = row * col, top = n, bottom = n + 1, ans = 0;
  int *parent = (int *)malloc((n + 2) * sizeof(int));
  int *rank = (int *)calloc(n + 2, sizeof(int));
  bool *land = (bool *)calloc(n, sizeof(bool));
  int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (int i = 0; i < n + 2; i++)
    parent[i] = i;
  for (int d = cellsSize - 1; d >= 0; d--) {
    int r = cells[d][0] - 1;
    int c = cells[d][1] - 1;
    int id = r * col + c;
    land[id] = true;
    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0], nc = c + dir[i][1];
      if (nr >= 0 && nc >= 0 && nr < row && nc < col) {
        int nid = nr * col + nc;
        if (land[nid])
          unite(parent, rank, id, nid);
      }
    }
    if (r == 0)
      unite(parent, rank, id, top);
    if (r == row - 1)
      unite(parent, rank, id, bottom);
    if (find(parent, top) == find(parent, bottom)) {
      ans = d;
      break;
    }
  }
  free(parent);
  free(rank);
  free(land);
  return ans;
}

int main() {
  int c1i[4][2] = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};
  int c2i[4][2] = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
  int c3i[9][2] = {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1},
                   {1, 3}, {2, 3}, {3, 2}, {3, 1}};
  struct two_d_arr *c1 =
      two_d_arr_init(ARRAY_SIZE(c1i), ARRAY_SIZE(c1i[0]), c1i);
  struct two_d_arr *c2 =
      two_d_arr_init(ARRAY_SIZE(c2i), ARRAY_SIZE(c2i[0]), c2i);
  struct two_d_arr *c3 =
      two_d_arr_init(ARRAY_SIZE(c3i), ARRAY_SIZE(c3i[0]), c3i);
  printf("%d\n", latestDayToCross(2, 2, c1->arr, c1->row_size,
                                  c1->col_size)); // expect: 2
  printf("%d\n", latestDayToCross(2, 2, c2->arr, c2->row_size,
                                  c2->col_size)); // expect: 1
  printf("%d\n", latestDayToCross(3, 3, c3->arr, c3->row_size,
                                  c3->col_size)); // expect: 3
  two_d_arr_free(c1);
  two_d_arr_free(c2);
  two_d_arr_free(c3);
}
