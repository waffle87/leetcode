// 2943. Maximize Area of Square Hole in Grid
#include "leetcode.h"

/*
 * you are given the two integers 'n' and 'm' and two integer arrays 'hBars' and
 * 'vBars'. the grid has 'n + 2' horizontal and 'm + 2' vertical bars, creating
 * a 1x1 unit cells. the bars are indexed starting from 1. you can remove some
 * of the bars in 'hBars' from horizontal bars and some of the bars in 'vBars'
 * from vertical bars. note that other bars are fixed and cannot be removed.
 * return an integer denoting the maximum area of a square shaped hole in the
 * grid, after removing some bars.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int maximizeSquareHoleArea(int n, int m, int *hBars, int hBarsSize, int *vBars,
                           int vBarsSize) {
  qsort(hBars, hBarsSize, sizeof(int), cmp);
  qsort(vBars, vBarsSize, sizeof(int), cmp);
  int rem_h = 1, rem_v = 1;
  for (int i = 1, cnt = 0; i < hBarsSize; i++) {
    if (hBars[i] == hBars[i - 1] + 1) {
      cnt += !cnt ? 2 : 1;
      rem_h = fmax(rem_h, cnt);
    } else
      cnt = 0;
  }
  rem_h++;
  for (int i = 1, cnt = 0; i < vBarsSize; i++) {
    if (vBars[i] == vBars[i - 1] + 1) {
      cnt += !cnt ? 2 : 1;
      rem_v = fmax(rem_v, cnt);
    } else
      cnt = 0;
  }
  rem_v++;
  return rem_h < rem_v ? rem_h * rem_h : rem_v * rem_v;
}

int main() {
  int hb1[] = {2, 3}, vb1[] = {2};
  int hb2[] = {2}, vb2[] = {2};
  int hb3[] = {2, 3}, vb3[] = {2, 4};
  printf("%d\n", maximizeSquareHoleArea(2, 1, hb1, ARRAY_SIZE(hb1), vb1,
                                        ARRAY_SIZE(vb1))); // expect: 4
  printf("%d\n", maximizeSquareHoleArea(1, 1, hb2, ARRAY_SIZE(hb2), vb2,
                                        ARRAY_SIZE(vb2))); // expect: 4
  printf("%d\n", maximizeSquareHoleArea(2, 3, hb3, ARRAY_SIZE(hb3), vb3,
                                        ARRAY_SIZE(vb3))); // expect: 4
}
