// 1886. Determine Whether Matrix Can Be Obtained By Rotation
#include "leetcode.h"

/*
 * given two 'n x n' binary matrices 'mat' and 'target', return 'true' if it is
 * possible to make 'mat' equal to 'target' by rotating 'mat' in 90-degree
 * increments, or 'false' otherwise.
 */

bool findRotation(int **mat, int matSize, int *matColSize, int **target,
                  int targetSize, int *targetColSize) {
  int n = matSize;
  uint8_t rot = 15;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      uint8_t curr = 0;
      curr |= (mat[i][j] == target[i][j]);
      curr |= ((mat[j][n - 1 - i] == target[i][j]) << 1);
      curr |= ((mat[n - 1 - i][n - 1 - j] == target[i][j]) << 2);
      curr |= ((mat[n - 1 - j][i] == target[i][j]) << 3);
      rot &= curr;
    }
  return rot != 0;
}

int main() {
  int m1i[2][2] = {{0, 1}, {1, 0}}, t1i[2][2] = {{1, 0}, {0, 1}};
  int m2i[2][2] = {{0, 1}, {1, 1}}, t2i[2][2] = {{1, 0}, {0, 1}};
  int m3i[3][3] = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}},
      t3i[3][3] = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  struct two_d_arr *m3 =
      two_d_arr_init(ARRAY_SIZE(m3i), ARRAY_SIZE(m3i[0]), m3i);
  struct two_d_arr *t1 =
      two_d_arr_init(ARRAY_SIZE(t1i), ARRAY_SIZE(t1i[0]), t1i);
  struct two_d_arr *t2 =
      two_d_arr_init(ARRAY_SIZE(t2i), ARRAY_SIZE(t2i[0]), t2i);
  struct two_d_arr *t3 =
      two_d_arr_init(ARRAY_SIZE(t3i), ARRAY_SIZE(t3i[0]), t3i);
  bool r1 = findRotation(m1->arr, m1->row_size, m1->col_size, t1->arr,
                         t1->row_size, t1->col_size);
  bool r2 = findRotation(m2->arr, m2->row_size, m2->col_size, t2->arr,
                         t2->row_size, t2->col_size);
  bool r3 = findRotation(m3->arr, m3->row_size, m3->col_size, t3->arr,
                         t3->row_size, t3->col_size);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == true);
  two_d_arr_free(m1);
  two_d_arr_free(m2);
  two_d_arr_free(m3);
  two_d_arr_free(t1);
  two_d_arr_free(t2);
  two_d_arr_free(t3);
}
