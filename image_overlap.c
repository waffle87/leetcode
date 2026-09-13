// 835. Image Overlap
#include "leetcode.h"

/*
 * you are given two images 'img1' and 'img2', represented as binary square
 * matrices of size 'n x n'. a binary matrix has only 0s and 1s as values. we
 * translate one image however we choose by sliding all the 1 bits left, right,
 * up and down any number of units. we then place it on top of the other image
 * .we can then calcluate the overlap by counting the number of positions that
 * have a 1 in both images. return the largest possible overlap.
 */

int largestOverlap(int **img1, int img1Size, int *img1ColSize, int **img2,
                   int img2Size, int *img2ColSize) {
  int n = img1Size, ans = 0, curr_overlap;
  unsigned int *a = (unsigned int *)calloc(n, sizeof(int));
  unsigned int *b = (unsigned int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      a[i] = (a[i] << 1) | img1[i][j];
      b[i] = (b[i] << 1) | img2[i][j];
    }
  for (int i = 1 - n; i < n; i++)
    for (int j = 1 - n; j < n; j++) {
      curr_overlap = 0;
      for (int k = 0, l = i; k < n; k++, l++) {
        if (l >= 0 && l < n) {
          if (j < 0)
            curr_overlap += __builtin_popcount(a[k] & (b[l] << -j));
          else
            curr_overlap += __builtin_popcount(a[k] & (b[l] >> j));
        }
      }
      ans = fmax(ans, curr_overlap);
    }
  free(a);
  free(b);
  return ans;
}

int main() {
  int i1i1[3][3] = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}},
      i2i1[3][3] = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
  int i1i2[1][1] = {{1}}, i2i2[1][1] = {{1}};
  int i1i3[1][1] = {{0}}, i2i3[1][1] = {{0}};
  struct two_d_arr *i11 =
      two_d_arr_init(ARRAY_SIZE(i1i1), ARRAY_SIZE(i1i1), i1i1);
  struct two_d_arr *i21 =
      two_d_arr_init(ARRAY_SIZE(i2i1), ARRAY_SIZE(i2i1), i2i1);
  struct two_d_arr *i12 =
      two_d_arr_init(ARRAY_SIZE(i1i2), ARRAY_SIZE(i1i2), i1i2);
  struct two_d_arr *i22 =
      two_d_arr_init(ARRAY_SIZE(i2i2), ARRAY_SIZE(i2i2), i2i2);
  struct two_d_arr *i13 =
      two_d_arr_init(ARRAY_SIZE(i1i3), ARRAY_SIZE(i1i3), i1i3);
  struct two_d_arr *i23 =
      two_d_arr_init(ARRAY_SIZE(i2i3), ARRAY_SIZE(i2i3), i2i3);
  int r1 = largestOverlap(i11->arr, i11->row_size, i11->col_size, i21->arr,
                          i21->row_size, i21->col_size);
  int r2 = largestOverlap(i12->arr, i12->row_size, i12->col_size, i22->arr,
                          i22->row_size, i22->col_size);
  int r3 = largestOverlap(i13->arr, i13->row_size, i13->col_size, i23->arr,
                          i23->row_size, i23->col_size);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == 0);
  two_d_arr_free(i11);
  two_d_arr_free(i21);
  two_d_arr_free(i12);
  two_d_arr_free(i22);
  two_d_arr_free(i13);
  two_d_arr_free(i23);
}
