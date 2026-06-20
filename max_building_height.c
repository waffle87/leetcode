// 1840. Maximum Building Height
#include "leetcode.h"

/*
 * you want to build 'n' new buildings in a city. the new buildings will be
 * built in a line and are labeled from 1 to 'n'. however, there are city
 * restrictions on the heights of the new buildings: the height of each building
 * must be a non-negative integer, the height of the first building must be 0,
 * and the height difference between any two adjacent buildings cannot exceed 1.
 * additionally, there are city restrictions on the maximum height of specific
 * buildings. these restrictions are given as 2d integer array 'restrictions'
 * where 'restrictions[i] = [id, max_height]' indicates that building 'id' must
 * have a height less than or equal to 'max_height'. return the maximum possible
 * height of the tallest building.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  return aa[0] - bb[0];
}

int maxBuilding(int n, int **restrictions, int restrictionsSize,
                int *restrictionsColSize) {
  if (!restrictionsSize)
    return n - 1;
  qsort(restrictions, restrictionsSize, sizeof(int *), cmp);
  int idx = 1, height = 0;
  for (int i = 0; i < restrictionsSize; i++) {
    int x = restrictions[i][0], y = restrictions[i][1];
    int limit = x - idx + height;
    restrictions[i][1] = y < limit ? y : limit;
    idx = x;
    height = restrictions[i][1];
  }
  for (int i = restrictionsSize - 2; i >= 0; i--) {
    int limit =
        restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0];
    restrictions[i][1] = fmin(restrictions[i][1], limit);
  }
  int ans = n - restrictions[restrictionsSize - 1][0] +
            restrictions[restrictionsSize - 1][1];
  idx = 1;
  height = 0;
  for (int i = 0; i < restrictionsSize; i++) {
    int x = restrictions[i][0], y = restrictions[i][1];
    int diff = y > height ? y - height : height - y;
    int steps = x - idx - diff;
    int higher = y > height ? y : height;
    int candidate = height + steps / 2;
    ans = fmax(ans, candidate);
    idx = x;
    height = y;
  }
  return ans;
}

int main() {
  int r1i[2][2] = {{2, 1}, {4, 1}};
  int r2i[4][2] = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
  struct two_d_arr *r1 =
      two_d_arr_init(ARRAY_SIZE(r1i), ARRAY_SIZE(r1i[0]), r1i);
  struct two_d_arr *r2 =
      two_d_arr_init(ARRAY_SIZE(r2i), ARRAY_SIZE(r2i[0]), r2i);
  int mb1 = maxBuilding(5, r1->arr, r1->row_size, r1->col_size);
  int mb2 = maxBuilding(10, r2->arr, r2->row_size, r2->col_size);
  printf("%d\n", mb1);
  assert(mb1 == 2);
  printf("%d\n", mb2);
  assert(mb2 == 5);
  two_d_arr_free(r1);
  two_d_arr_free(r2);
}
