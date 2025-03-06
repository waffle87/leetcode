// 2965. Find Missing and Repeated Values
#include "leetcode.h"

/*
 * you are given a 0-indexed 2d integer matrix 'grid' of size 'n * n' with
 * values in the range '[1, n^2]'. each integer appears exactly once except 'a'
 * which appears twice and 'b' which is missing. the task is to find the
 * repeating and missing numbers 'a' and 'b'. return a 0-indexed integer array
 * 'ans' of size '2' where 'ans[0]' equals to 'a' and 'ans[1]' equals 'b'.
 */

int *findMissingAndRepeatedValues(int **grid, int gridSize, int *gridColSize,
                                  int *returnSize) {
  int n = gridSize, repeated = 0, missing = 0;
  int *cnt = (int *)calloc((n * n + 1), sizeof(int));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < gridColSize[i]; ++j) {
      int num = grid[i][j];
      cnt[num]++;
      if (cnt[num] == 2)
        repeated = num;
    }
  for (int i = 1; i <= n * n; ++i)
    if (!cnt[i]) {
      missing = i;
      break;
    }
  int *ans = (int *)malloc(2 * sizeof(int));
  ans[0] = repeated;
  ans[1] = missing;
  *returnSize = 2;
  return ans;
}

int main() {
  int g1i[2][2] = {{1, 3}, {2, 2}},
      g2i[3][3] = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
  struct two_d_arr g1, g2;
  two_d_arr_init(&g1, ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  two_d_arr_init(&g2, ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int rs1, *fmarv1 = findMissingAndRepeatedValues(g1.arr, g1.row_size,
                                                  g1.col_size, &rs1);
  int rs2, *fmarv2 = findMissingAndRepeatedValues(g2.arr, g2.row_size,
                                                  g2.col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fmarv1[i]); // expect: 2 4
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fmarv2[i]); // expect: 9 5
  printf("\n");
  free(fmarv1);
  free(fmarv2);
  two_d_arr_free(&g1);
  two_d_arr_free(&g2);
}
