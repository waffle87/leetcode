// 832. Flipping an Image
#include "leetcode.h"

/*
 * given an 'n x n' binary matrix 'image', flip the image horizontally, then
 * invert it and return the resulting image. to flip an image horizontally means
 * that each row of the image is reversed. to invert an image means that each 0
 * is replaced by 1, and each 1 is replaced by 0.
 */

int **flipAndInvertImage(int **image, int imageSize, int *imageColSize,
                         int *returnSize, int **returnColumnSizes) {
  int n = imageSize, m = imageColSize[0], tmp = 0;
  *returnColumnSizes = (int *)malloc(n * sizeof(int));
  *returnSize = n;
  for (int i = 0; i < n; i++)
    (*returnColumnSizes)[i] = m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m / 2; j++) {
      tmp = image[i][n - 1 - j];
      image[i][n - 1 - j] = image[i][j];
      image[i][j] = tmp;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      image[i][j] = !image[i][j];
  return image;
}

int main() {
  int i1i[3][3] = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}}, rs1, *rcs1;
  int i2i[4][4] = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}}, rs2,
      *rcs2;
  struct two_d_arr *i1 =
      two_d_arr_init(ARRAY_SIZE(i1i), ARRAY_SIZE(i1i[0]), i1i);
  struct two_d_arr *i2 =
      two_d_arr_init(ARRAY_SIZE(i2i), ARRAY_SIZE(i2i[0]), i2i);
  int **faii1 =
      flipAndInvertImage(i1->arr, i1->row_size, i1->col_size, &rs1, &rcs1);
  int **faii2 =
      flipAndInvertImage(i2->arr, i2->row_size, i2->col_size, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", faii1[i][j]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", faii2[i][j]);
    printf("\n");
  }
  printf("\n");
  free(rcs1);
  two_d_arr_free(i1);
  free(rcs2);
  two_d_arr_free(i2);
}
