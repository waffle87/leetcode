// 3363. Find the Maximum Number of Fruits Collected
#include "leetcode.h"

/*
 * there is a game dungeon comprised of 'n x n' rooms arranged in a grid. you
 * are given a 2d array 'fruits' of size 'n x n' where 'fruits[i][j]' represents
 * the number of fruits in the room '(i, j)'. three children will play in the
 * game dungeon, with initial positions at the corner rooms '(0, 0)', '(0, n -
 * 1)', and '(n - 1, 0)'. when a child enters a room, they will collect all the
 * fruits there. if two or more children enter the same room, only one child
 * will collect the fruits and the room will be emptied after they leave. return
 * the maximum number of fruits the children can collect from the dungeon.
 */

int maxCollectedFruits(int **fruits, int fruitsSize, int *fruitsColSize) {
  int ans = 0;
  int *dp1 = (int *)malloc((fruitsSize + 1) * sizeof(int));
  int *dp2 = (int *)malloc((fruitsSize + 1) * sizeof(int));
  int *curr = dp1, *prev = dp2, *swap;
  for (int i = 0; i < fruitsSize; i++)
    ans += fruits[i][i];
  memset(prev, 0, (fruitsSize + 1) * sizeof(int));
  memset(curr, 0, (fruitsSize + 1) * sizeof(int));
  for (int i = 0; i < fruitsSize - 1; i++) {
    for (int j = fmax(i + 1, fruitsSize - 1 - i); j < fruitsSize; j++)
      curr[j] = fmax(prev[j - 1], fmax(prev[j], prev[j + 1])) + fruits[i][j];
    swap = curr;
    curr = prev;
    prev = swap;
  }
  ans += prev[fruitsSize - 1];
  memset(prev, 0, (fruitsSize + 1) * sizeof(int));
  memset(curr, 0, (fruitsSize + 1) * sizeof(int));
  for (int i = 0; i < fruitsSize - 1; i++) {
    for (int j = fmax(i + 1, fruitsSize - 1 - i); j < fruitsSize; j++)
      curr[j] = fmax(prev[j - 1], fmax(prev[j], prev[j + 1])) + fruits[j][i];
    swap = curr;
    curr = prev;
    prev = swap;
  }
  ans += prev[fruitsSize - 1];
  free(dp1), free(dp2);
  return ans;
}

int main() {
  int f1i[4][4] = {
      {1, 2, 3, 4}, {5, 6, 8, 7}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int f2i[2][2] = {{1, 1}, {1, 1}};
  struct two_d_arr f1, f2;
  two_d_arr_init(&f1, ARRAY_SIZE(f1i), ARRAY_SIZE(f1i[0]), f1i);
  two_d_arr_init(&f2, ARRAY_SIZE(f2i), ARRAY_SIZE(f2i[0]), f2i);
  printf("%d\n",
         maxCollectedFruits(f1.arr, f1.row_size, f1.col_size)); // expect: 100
  printf("%d\n",
         maxCollectedFruits(f2.arr, f2.row_size, f2.col_size)); // expect: 4
  two_d_arr_free(&f1);
  two_d_arr_free(&f2);
}
