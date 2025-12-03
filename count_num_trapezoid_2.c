// 3625. Count Number of Trapezoids II
#include "leetcode.h"

/*
 * you are given a 2d integer array 'points' where 'points[i] = [x_i, y_i]'
 * represents the coordinates of the i'th point on the cartesian plane. return
 * the number of unique trapezoids that can be formed by choosing any four
 * distinct points from 'points'. a trapezoid is a convex quadrilateral with at
 * least one pair of parallel sides. two lines are parallel if and only if they
 * have the same slope.
 */

struct segment {
  long long dx;
  long long dy;
  long long cnt;
};

long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }

int cmp(const void *a, const void *b) {
  struct segment *aa = (struct segment *)a;
  struct segment *bb = (struct segment *)b;
  if (aa->dx != bb->dx)
    return aa->dx > bb->dx ? 1 : -1;
  if (aa->dy != bb->dy)
    return aa->dy > bb->dy ? 1 : -1;
  if (aa->cnt != bb->cnt)
    return aa->cnt > bb->cnt ? 1 : -1;
  return 0;
}

int countTrapezoids(int **points, int pointsSize, int *pointsColSize) {
  if (pointsSize < 4)
    return 0;
  int max = pointsSize * (pointsSize - 1) / 2, k = 0;
  struct segment *seg = (struct segment *)malloc(max * sizeof(struct segment));
  for (int i = 0; i < pointsSize; i++) {
    for (int j = i + 1; j < pointsSize; j++) {
      long long dx = points[j][0] - points[i][0];
      long long dy = points[j][1] - points[i][1];
      long long common = gcd(llabs(dx), llabs(dy));
      dx /= common;
      dy /= common;
      if (dx < 0 || (!dx && dy < 0)) {
        dx = -dx;
        dy = -dy;
      }
      long long cnt = dy * points[i][0] - dx * points[i][1];
      seg[k].dx = dx;
      seg[k].dy = dy;
      seg[k].cnt = cnt;
      k++;
    }
  }
  qsort(seg, k, sizeof(struct segment), cmp);
  int total_trapezoid = 0;
  for (int i = 0; i < k;) {
    int j = i, curr_slope_cnt = 0;
    while (j < k && seg[i].dx == seg[j].dx && seg[i].dy == seg[j].dy) {
      int l = j;
      while (l < k && seg[i].dx == seg[l].dx && seg[i].dy == seg[l].dy &&
             seg[j].cnt == seg[l].cnt)
        l++;
      int line_cnt = l - j;
      total_trapezoid += curr_slope_cnt * line_cnt;
      curr_slope_cnt += line_cnt;
      j = l;
    }
    i = j;
  }
  k = 0;
  for (int i = 0; i < pointsSize; i++) {
    for (int j = i + 1; j < pointsSize; j++) {
      long long dx = points[j][0] - points[i][0];
      long long dy = points[j][1] - points[i][1];
      if (dx < 0 || (!dx && dy < 0)) {
        dx = -dx;
        dy = -dy;
      }
      long long cnt = dy * points[i][0] - dx * points[i][1];
      seg[k].dx = dx;
      seg[k].dy = dy;
      seg[k].cnt = cnt;
      k++;
    }
  }
  qsort(seg, k, sizeof(struct segment), cmp);
  int parallelograms = 0;
  for (int i = 0; i < k; i++) {
    int j = i, curr_vec_cnt = 0;
    while (j < k && seg[i].dx == seg[j].dx && seg[i].dy == seg[j].dy) {
      int l = j;
      while (l < k && seg[i].dx == seg[l].dx && seg[i].dy == seg[l].dy &&
             seg[j].cnt == seg[l].cnt)
        l++;
      int line_cnt = l - j;
      parallelograms += curr_vec_cnt * line_cnt;
      curr_vec_cnt += line_cnt;
      j = l;
    }
    i = j;
  }
  free(seg);
  return total_trapezoid - (parallelograms / 2);
}

int main() {
  int p1i[5][2] = {{-3, 2}, {3, 0}, {2, 3}, {3, 2}, {2, -3}};
  int p2i[4][2] = {{0, 0}, {1, 0}, {0, 1}, {2, 1}};
  struct two_d_arr *p1 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p2 =
      two_d_arr_init(ARRAY_SIZE(p2i), ARRAY_SIZE(p2i[0]), p2i);
  printf("%d\n",
         countTrapezoids(p1->arr, p1->row_size, p1->col_size)); // expect: 2
  printf("%d\n",
         countTrapezoids(p2->arr, p2->row_size, p2->col_size)); // expect: 1
  two_d_arr_free(p1);
  two_d_arr_free(p2);
}
