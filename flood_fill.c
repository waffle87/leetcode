// 733. Flood Fill
#include "leetcode.h"

/*
 * you are given an image represented by an 'm x n' grid of integers 'image',
 * where 'image[i][j]' represents the pixel value of the image. you are also
 * given three integers 'sr', 'sc', and 'color'. your task is to perform a flood
 * fill on the image starting from the pixel 'image[sr][sc]'. return the
 * modified image after performing the flood fill
 */

void dfs(int **image, int imageSize, int *imageColSize, int sr, int sc, int new,
         int old) {
  if (sr < 0 || sr >= imageSize)
    return;
  if (sc < 0 || sc >= imageColSize[0])
    return;
  if (image[sr][sc] == old) {
    image[sr][sc] = new;
    dfs(image, imageSize, imageColSize, sr - 1, sc, new, old);
    dfs(image, imageSize, imageColSize, sr + 1, sc, new, old);
    dfs(image, imageSize, imageColSize, sr, sc - 1, new, old);
    dfs(image, imageSize, imageColSize, sr, sc + 1, new, old);
  }
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc,
                int color, int *returnSize, int **returnColumnSizes) {
  int i;
  *returnSize = imageSize;
  *returnColumnSizes = (int *)malloc(imageSize * sizeof(int));
  for (int i = 0; i < imageSize; i++)
    (*returnColumnSizes)[i] = imageColSize[i];
  if (color != image[sr][sc])
    dfs(image, imageSize, imageColSize, sr, sc, color, image[sr][sc]);
  return image;
}

int main() {
  int i1i[3][3] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}},
      i2i[2][3] = {{0, 0, 0}, {0, 0, 0}};
  struct two_d_arr *i1 =
      two_d_arr_init(ARRAY_SIZE(i1i), ARRAY_SIZE(i1i[0]), i1i);
  struct two_d_arr *i2 =
      two_d_arr_init(ARRAY_SIZE(i2i), ARRAY_SIZE(i2i[0]), i2i);
  int rs1, rs2, *rcs1, *rcs2;
  int **ff1 =
      floodFill(i1->arr, i1->row_size, i1->col_size, 1, 1, 2, &rs1, &rcs1);
  int **ff2 =
      floodFill(i2->arr, i2->row_size, i2->col_size, 0, 0, 0, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", ff1[i][j]); // expect: [[2,2,2],[2,2,0],[2,0,1]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", ff2[i][j]); // expect: [[0,0,0],[0,0,0]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(ff1[i]);
  free(ff1), free(rcs1);
  for (int i = 0; i < rs2; i++)
    free(ff2[i]);
  free(ff2);
  free(rcs2);
  two_d_arr_free(i1);
  two_d_arr_free(i2);
}
