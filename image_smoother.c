// 661. Image Smoother
#include "leetcode.h"

/*
 * an image smoother is a filter of the size 3 x 3 that can be applied to each
 * cell of an image by rounding down the average of the cell and the eight
 * surrounding cells (ie. the average of the nine cells in the blue smoother).
 * if one or more of the surrounding cells of a cell is not present, we do not
 * consider it in the average (ie. the average of the four cells in the red
 * smoother). given an m x n integer matrix 'img' representing the grayscale of
 * an image, return the image after applying the smoother on each cell of it
 */

int **imageSmoother(int **M, int MRowSize, int MColSize, int **columnSizes,
                    int *returnSize) {
  int **ans = calloc(MColSize, sizeof(int));
  *returnSize = MColSize;
  *columnSizes = calloc(MColSize, sizeof(int));
  for (int i = 0; i < MColSize; i++) {
    (*columnSizes)[i] = MColSize;
    ans[i] = calloc(MColSize, sizeof(int));
  }
  int cnt;
  for (int i = 0; i < MRowSize; i++)
    for (int j = 0; j < MColSize; j++) {
      cnt = 0;
      for (int x = i - 1; x <= i + 1; x++)
        for (int y = j - 1; y <= j + 1; y++)
          if (x >= 0 && x < MRowSize && y >= 0 && y < MColSize) {
            ans[i][j] += M[x][y];
            cnt++;
          }
      ans[i][j] /= cnt;
    }
  return ans;
}
