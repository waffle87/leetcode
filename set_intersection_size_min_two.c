// 757. Set Intersection Size At Least Two
#include "leetcode.h"

/*
 * you are given a 2d integer array 'intervals' where 'intervals[i] = [start_i,
 * end_i]' represents all the integers from 'start_i' to 'end_i' inclusively. a
 * containing set is an array 'nums' where each interval from 'intervals' has at
 * least two integers in 'nums'. return the minimum possible size of a
 * containing set.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  if (aa[1] == bb[1])
    return bb[0] - aa[0];
  return aa[1] - bb[1];
}

int intersectionSizeTwo(int **intervals, int intervalsSize,
                        int *intervalsColSize) {
  qsort(intervals, intervalsSize, sizeof(int *), cmp);
  int ans = 0, a = -1, b = -1;
  for (int i = 0; i < intervalsSize; i++) {
    int l = intervals[i][0], r = intervals[i][1];
    if (l > b) {
      a = r - 1;
      b = r;
      ans += 2;
    } else if (l > a) {
      a = b;
      b = r;
      ans++;
    }
  }
  return ans;
}

int main() {
  int i1i[3][2] = {{1, 3}, {3, 7}, {8, 9}};
  int i2i[4][2] = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
  int i3i[4][2] = {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
  struct two_d_arr *i1 =
      two_d_arr_init(ARRAY_SIZE(i1i), ARRAY_SIZE(i1i[0]), i1i);
  struct two_d_arr *i2 =
      two_d_arr_init(ARRAY_SIZE(i2i), ARRAY_SIZE(i2i[0]), i2i);
  struct two_d_arr *i3 =
      two_d_arr_init(ARRAY_SIZE(i3i), ARRAY_SIZE(i3i[0]), i3i);
  printf("%d\n",
         intersectionSizeTwo(i1->arr, i1->row_size, i1->col_size)); // expect: 5
  printf("%d\n",
         intersectionSizeTwo(i2->arr, i2->row_size, i2->col_size)); // expect: 3
  printf("%d\n",
         intersectionSizeTwo(i3->arr, i3->row_size, i3->col_size)); // expect: 5
  two_d_arr_free(i1);
  two_d_arr_free(i2);
  two_d_arr_free(i3);
}
