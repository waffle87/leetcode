// 3025. Find the Number of Ways to Place People I
#include "leetcode.h"

/*
 * you are given a 2d array 'points' of size 'n x 2' representing integer
 * coordinates of some points on a 2d plane, where 'points[i] = [x_i, y_i]'.
 * count the number of pairs of points '(a, b)' where 'a' is on the upper left
 * side of 'b' and there are no other points in the rectangle they make,
 * including the border. return the count.
 */

struct pair {
  int x;
  int y;
};

int cmp(const void *a, const void *b) {
  struct pair *aa = (struct pair *)a, *bb = (struct pair *)b;
  return aa->x != bb->x ? aa->x - bb->x : bb->y - aa->y;
}

int numberOfPairs(int **points, int pointsSize, int *pointsColSize) {
  int i, j, y, ans = 0;
  struct pair *list = (struct pair *)malloc(pointsSize * sizeof(struct pair));
  for (int i = 0; i < pointsSize; i++) {
    list[i].x = points[i][0];
    list[i].y = points[i][1];
  }
  qsort(list, pointsSize, sizeof(struct pair), cmp);
  for (int i = 0; i < pointsSize; i++) {
    int y = INT_MIN;
    for (int j = i + 1; j < pointsSize; j++) {
      if (list[i].y >= list[j].y && y < list[j].y) {
        ans++;
        y = list[j].y;
      }
    }
  }
  free(list);
  return ans;
}

int main() {
  int p1i[3][2] = {{1, 1}, {2, 2}, {3, 3}},
      p2i[3][2] = {{6, 2}, {4, 4}, {2, 6}},
      p3i[3][2] = {{3, 1}, {1, 3}, {1, 1}};
  struct two_d_arr *p1 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p2 =
      two_d_arr_init(ARRAY_SIZE(p2i), ARRAY_SIZE(p2i[0]), p2i);
  struct two_d_arr *p3 =
      two_d_arr_init(ARRAY_SIZE(p3i), ARRAY_SIZE(p3i[0]), p3i);
  printf("%d\n",
         numberOfPairs(p1->arr, p1->row_size, p1->col_size)); // expect: 0
  printf("%d\n",
         numberOfPairs(p2->arr, p2->row_size, p2->col_size)); // expect: 2
  printf("%d\n",
         numberOfPairs(p3->arr, p3->row_size, p3->col_size)); // expect: 2
  two_d_arr_free(p1);
  two_d_arr_free(p2);
  two_d_arr_free(p3);
}
