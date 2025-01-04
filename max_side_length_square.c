// 1292. Maximum Side Length of a Square with Sum Less than or Equal to
// Threshold
#include "leetcode.h"

/*
 * given a 'm x n' matrix 'mat' and an integer 'threshold', return the maximum
 * side-length of a square with a sum less than or equal to 'threshold' or
 * return 0 if there is no such square.
 */

int maxSideLength(int **mat, int matSize, int *matColSize, int threshold) {
  int w = matSize, h = matColSize[0], prefix[w][h];
  for (int x = 0; x < w; x++)
    for (int y = 0; y < h; y++)
      prefix[x][y] = mat[x][y] + (x ? prefix[x - 1][y] : 0) +
                     (y ? prefix[x][y - 1] : 0) -
                     (x && y ? prefix[x - 1][y - 1] : 0);
  int max = w > h ? w : h, best = -1;
  for (int s = 0; s < max; s++) {
    for (int x = 0; x < w - s; x++) {
      for (int y = 0; y < h - s; y++) {
        int sum = prefix[x + s][y + s] - (x ? prefix[x - 1][y + s] : 0) -
                  (y ? prefix[x + s][y - 1] : 0) +
                  (x && y ? prefix[x - 1][y - 1] : 0);
        if (sum <= threshold) {
          best = s;
          break;
        }
      }
      if (best == s)
        break;
    }
    if (best != s)
      break;
  }
  return best + 1;
}

int main() {
  int m1i[3][7] = {
      {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};
  int m2i[4][5] = {
      {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}};
  struct two_d_arr m1, m2;
  two_d_arr_init(&m1, 3, 7, m1i);
  two_d_arr_init(&m2, 4, 5, m2i);
  printf("%d\n",
         maxSideLength(m1.arr, m1.row_size, m1.col_size, 4)); // expect: 2
  printf("%d\n",
         maxSideLength(m2.arr, m2.row_size, m2.col_size, 1)); // expect: 0
  two_d_arr_free(&m1);
  two_d_arr_free(&m2);
}
