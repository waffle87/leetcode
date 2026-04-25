// 3464. Maximize the Distance Between Points on a Square
#include "leetcode.h"

/*
 * you are given an integer 'side', representing the edge length of a square
 * with corners at '(0, 0)', '(0, side)', '(side, 0)', and '(side, side)' on a
 * cartesian plane. you are also given a positive integer 'k' and a 2d integer
 * array 'points' where 'points[i] = [x_i, y_i]' represents the coordinate of a
 * point lying on the boundary of the square. you need to select 'k' elements
 * among 'points' such that the minimum manhattan distance between any two
 * points in maximised.
 */

int cmp(const void *a, const void *b) {
  long long aa = *(long long *)a;
  long long bb = *(long long *)b;
  if (aa < bb)
    return -1;
  else if (aa > bb)
    return 1;
  else
    return 0;
}

bool can_place(long long d, int k, int n, long long *ext, long long l) {
  for (int start = 0; start < n; start++) {
    int curr = start, limit = start + n;
    long long prev = ext[start];
    bool valid = true;
    for (int step = 1; step < k; step++) {
      long long target = prev + d;
      int low = curr + 1, high = limit;
      while (low < high) {
        int mid = (low + high) / 2;
        if (ext[mid] < target)
          low = mid + 1;
        else
          high = mid;
      }
      if (low == limit) {
        valid = false;
        break;
      }
      curr = low;
      prev = ext[curr];
    }
    if (valid && (ext[start] + l - prev >= d))
      return true;
  }
  return false;
}

int maxDistance(int side, int **points, int pointsSize, int *pointsColSize,
                int k) {
  int n = pointsSize;
  long long *pos = (long long *)malloc(n * sizeof(long long));
  for (int i = 0; i < n; i++) {
    int x = points[i][0], y = points[i][1];
    long long p;
    if (!y)
      p = x;
    else if (x == side)
      p = side + y;
    else if (y == side)
      p = 2LL * side + (side - x);
    else
      p = 3LL * side + (side - y);
    pos[i] = p;
  }
  qsort(pos, n, sizeof(long long), cmp);
  long long l = 2LL * side;
  int total = n * 2;
  long long *ext = (long long *)malloc(total * sizeof(long long));
  for (int i = 0; i < n; i++) {
    ext[i] = pos[i];
    ext[i + n] = pos[i] + l;
  }
  long long low = 0, high = 2LL * side;
  while (low < high) {
    long long mid = (low + high + 1) / 2;
    if (can_place(mid, k, n, ext, l))
      low = mid;
    else
      high = mid - 1;
  }
  free(pos);
  free(ext);
  return (int)low;
}

int main() {
  int p1i[4][2] = {{0, 2}, {2, 0}, {2, 2}, {0, 0}};
  int p2i[5][2] = {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
  int p3i[7][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
  struct two_d_arr *p1 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p2 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p3 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  int r1 = maxDistance(2, p1->arr, p1->row_size, p1->col_size, 4);
  int r2 = maxDistance(2, p2->arr, p2->row_size, p2->col_size, 4);
  int r3 = maxDistance(2, p3->arr, p3->row_size, p3->col_size, 5);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == 1);
  two_d_arr_free(p1);
  two_d_arr_free(p2);
  two_d_arr_free(p3);
}
