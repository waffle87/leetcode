// 2022. Convert 1D Array Into 2D Array
#include "leetcode.h"

/*
 * you are given a 0-indexed 1 dimensional integer array 'original' and two
 * integers 'm' and 'n'. you are tasked with creating a 2 dimensional array with
 * 'm' rows and 'n' columns using all the elements from 'original'. the elements
 * from indices 0 to 'n - 1' (inclusively) of 'original' should form the first
 * row of the constructed 2d array, the elments from indices 'n' to '2 * n - 1'
 * should form the second row of the constructed 2d array, and so on. return an
 * 'm * n' 2d array constructed according to the above procedure, or an empty 2d
 * array if it is not possible
 */

int **construct2DArray(int *original, int originalSize, int m, int n,
                       int *returnSize, int **returnColumnSizes) {
  int **ans = (int **)malloc(m * sizeof(int *));
  if (m * n != originalSize) {
    *returnSize = 0;
    free(ans);
    return NULL;
  }
  for (int i = 0; i < m; i++)
    ans[i] = (int *)malloc(sizeof(int *));
  *returnSize = m;
  *returnColumnSizes = (int *)malloc(m * sizeof(int));
  for (int i = 0, j = 0; i < m; i++) {
    for (int k = 0; k < n; k++) {
      ans[i][k] = original[j];
      j++;
    }
    (*returnColumnSizes)[i] = n;
  }
  return ans;
}

int main() {
  int o1[] = {1, 2, 3, 4}, o2[] = {1, 2, 3}, o3[] = {1, 2}, rs1, rs2, rs3,
      rcs1[] = {2, 2}, rcs2[] = {1}, rcs3[] = {};
  int **c2da1 = construct2DArray(o1, ARRAY_SIZE(o1), 2, 2, &rs1, (int **)rcs1);
  int **c2da2 = construct2DArray(o2, ARRAY_SIZE(o2), 1, 3, &rs2, (int **)rcs2);
  int **c2da3 = construct2DArray(o3, ARRAY_SIZE(o3), 1, 1, &rs3, (int **)rcs3);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", c2da1[i][j]);
    printf("\n");
    free(c2da1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", c2da2[i][j]);
    free(c2da2[i]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    for (int j = 0; j < rcs3[i]; j++)
      printf("%d ", c2da3[i][j]);
    free(c2da3[i]);
    printf("\n");
  }
  printf("\n");
  free(c2da1), free(c2da2), free(c2da2);
}
