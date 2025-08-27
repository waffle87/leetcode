// 3394. Check if Grid can be Cut into Sections
#include "leetcode.h"

/*
 * you are given an integer 'n' representing the dimensions of an 'n * n' grid
 * with the origin at the bottom-left corner of the grid. you are also given a
 * 2d array of coordinates 'rectangles', where 'rectangles[i]' is in the form
 * '[start_x, start_y, end_x, end_y]' representing a rectangle on the grid. note
 * that the rectangles do not overlap. your task is to determine if it is
 * possible to make either two horizontal or two vertical cuts on the grid such
 * that each of the three resulting formed by the cuts contains at least one
 * rectangle. every rectangle belongs to exactly one section. return 'true' if
 * such cuts can be made. otherwise, return 'false'.
 */

int cmp_y(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  return aa[1] - bb[1];
}

int cmp_x(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  return aa[0] - bb[0];
}

bool check_x(int n, int **rectangles, int rectanglesSize) {
  qsort(rectangles, rectanglesSize, sizeof(int *), cmp_y);
  int intervals = 1, curr[2] = {rectangles[0][1], rectangles[0][3]};
  for (int i = 1; i < rectanglesSize; i++) {
    if (rectangles[i][1] >= curr[1]) {
      if (++intervals == 3)
        return true;
      curr[0] = rectangles[i][1];
      curr[1] = rectangles[i][3];
    } else if (rectangles[i][3] > curr[1])
      curr[1] = rectangles[i][3];
  }
  return false;
}

bool check_y(int n, int **rectangles, int rectanglesSize) {
  qsort(rectangles, rectanglesSize, sizeof(int *), cmp_x);
  int intervals = 1, curr[2] = {rectangles[0][0], rectangles[0][2]};
  for (int i = 1; i < rectanglesSize; i++) {
    if (rectangles[i][0] >= curr[1]) {
      if (++intervals == 3)
        return true;
      curr[0] = rectangles[i][0];
      curr[1] = rectangles[i][2];
    } else if (rectangles[i][2] > curr[1])
      curr[1] = rectangles[i][2];
  }
  return false;
}

bool checkValidCuts(int n, int **rectangles, int rectanglesSize,
                    int *rectanglesColSize) {
  return check_y(n, rectangles, rectanglesSize) ||
         check_x(n, rectangles, rectanglesSize);
}

int main() {
  int r1i[4][4] = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
  int r2i[4][4] = {{0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}};
  int r3i[5][4] = {
      {0, 2, 2, 4}, {1, 0, 3, 2}, {2, 2, 3, 4}, {3, 0, 4, 2}, {3, 2, 4, 4}};
  struct two_d_arr *r1 =
      two_d_arr_init(ARRAY_SIZE(r1i), ARRAY_SIZE(r1i[0]), r1i);
  struct two_d_arr *r2 =
      two_d_arr_init(ARRAY_SIZE(r2i), ARRAY_SIZE(r2i[0]), r2i);
  struct two_d_arr *r3 =
      two_d_arr_init(ARRAY_SIZE(r3i), ARRAY_SIZE(r3i[0]), r3i);
  printf("%d\n",
         checkValidCuts(5, r1->arr, r1->row_size, r1->col_size)); // expect: 1
  printf("%d\n",
         checkValidCuts(4, r2->arr, r2->row_size, r2->col_size)); // expect: 1
  printf("%d\n",
         checkValidCuts(4, r3->arr, r3->row_size, r3->col_size)); // expect: 0
  two_d_arr_free(r1);
  two_d_arr_free(r2);
  two_d_arr_free(r3);
}
