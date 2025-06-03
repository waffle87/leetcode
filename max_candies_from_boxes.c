// 1298. Maximum Candies You Can Get from Boxes
#include "leetcode.h"

/*
 * you have 'n' boxes labeled from 0 to 'n - 1'. you are given four arrays:
 * 'status', 'candies', 'keys', and 'containedBoxes' where 'status[i]' is 1 if
 * the i'th box is open and 0 if the i'th box is closed. 'candies[i]' is the
 * number of candies in the i'th box. 'keys[i]' is a list of the labels of the
 * boxes that you can open after opening the i'th box. 'containedBoxes[i]' is a
 * list of the boxes you found inside the i'th box. you are given an integer
 * array 'initialBoxes' that contains the labels of the boxes you initially
 * have. you can take all the candies in any open box and you can use the keys
 * in it to open new boxes and you can also use the boxes you find in it. return
 * the maximum number of candies you can get following the rules.
 */

int dfs(int box_idx, int *status, int statusSize, int *candies, int candiesSize,
        int **keys, int keysSize, int *keysColSize, int **containedBoxes,
        int containedBoxesSize, int *containedBoxesColSize, bool *accessible,
        bool *vis, bool *have_key) {
  int cnt = 0;
  if (vis[box_idx] == 1 || !accessible[box_idx] ||
      (!status[box_idx] && !have_key[box_idx]))
    return 0;
  cnt = candies[box_idx];
  vis[box_idx] = 1;
  for (int i = 0; i < keysColSize[box_idx]; i++) {
    have_key[keys[box_idx][i]] = 1;
    cnt += dfs(keys[box_idx][i], status, statusSize, candies, candiesSize, keys,
               keysSize, keysColSize, containedBoxes, containedBoxesSize,
               containedBoxesColSize, accessible, vis, have_key);
  }
  for (int i = 0; i < containedBoxesColSize[box_idx]; i++) {
    accessible[containedBoxes[box_idx][i]] = 1;
    cnt += dfs(containedBoxes[box_idx][i], status, statusSize, candies,
               candiesSize, keys, keysSize, keysColSize, containedBoxes,
               containedBoxesSize, containedBoxesColSize, accessible, vis,
               have_key);
  }
  return cnt;
}

int maxCandies(int *status, int statusSize, int *candies, int candiesSize,
               int **keys, int keysSize, int *keysColSize, int **containedBoxes,
               int containedBoxesSize, int *containedBoxesColSize,
               int *initialBoxes, int initialBoxesSize) {
  bool *accessible = (bool *)calloc(statusSize, sizeof(bool));
  bool *vis = (bool *)calloc(statusSize, sizeof(bool));
  bool *have_key = (bool *)calloc(statusSize, sizeof(bool));
  int ans = 0;
  for (int i = 0; i < initialBoxesSize; i++) {
    accessible[initialBoxes[i]] = true;
    ans += dfs(initialBoxes[i], status, statusSize, candies, candiesSize, keys,
               keysSize, keysColSize, containedBoxes, containedBoxesSize,
               containedBoxesColSize, accessible, vis, have_key);
  }
  free(accessible);
  free(vis);
  free(have_key);
  return ans;
}

int main() {
  int s1[] = {1, 0, 1, 0}, c1[] = {7, 5, 4, 100}, k1i[4][1] = {{}, {}, {1}, {}},
      cb1i[4][2] = {{1, 2}, {3}, {}, {}}, ib1[] = {0};
  int s2[] = {1, 0, 0, 0, 0, 0}, c2[] = {1, 1, 1, 1, 1, 1},
      k2i[6][5] = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}},
      cb2i[6][5] = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}}, ib2[] = {0};
  struct two_d_arr k1, k2, cb1, cb2;
  two_d_arr_init(&k1, ARRAY_SIZE(k1i), ARRAY_SIZE(k1i[0]), k1i);
  two_d_arr_init(&k2, ARRAY_SIZE(k2i), ARRAY_SIZE(k2i[0]), k2i);
  two_d_arr_init(&cb1, ARRAY_SIZE(cb1i), ARRAY_SIZE(cb1i[0]), cb1i);
  two_d_arr_init(&cb2, ARRAY_SIZE(cb2i), ARRAY_SIZE(cb2i[0]), cb2i);
  printf("%d\n", maxCandies(s1, ARRAY_SIZE(s1), c1, ARRAY_SIZE(c1), k1.arr,
                            k1.row_size, k1.col_size, cb1.arr, cb1.row_size,
                            cb1.col_size, ib1, ARRAY_SIZE(ib1))); // expect: 16
  printf("%d\n", maxCandies(s2, ARRAY_SIZE(s2), c2, ARRAY_SIZE(c2), k2.arr,
                            k2.row_size, k2.col_size, cb2.arr, cb2.row_size,
                            cb2.col_size, ib2, ARRAY_SIZE(ib2))); // expect: 6
  two_d_arr_free(&k1);
  two_d_arr_free(&k2);
  two_d_arr_free(&cb1);
  two_d_arr_free(&cb2);
}
