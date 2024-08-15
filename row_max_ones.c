// 2643. Row With Maximum Ones
#include "leetcode.h"

/*
 * given an 'm * n' binary matrix 'mat' find the 0 indexed position of the row
 * that contains the maximum count of ones and the number of ones in that row.
 * in case there are multiple rows that have the maximum count of ones, the row
 * with the smallest number should be selected. return an array containing the
 * index of the row and the number of ones in it
 */

int *rowAndMaximumOnes(int **mat, int matSize, int *matColSize,
                       int *returnSize) {
  int *ans = (int *)malloc(2 * sizeof(int));
  int sum = 0, k = 0;
  for (int i = 0; i < matSize; i++) {
    int tmp = 0;
    for (int j = 0; j < *matColSize; j++)
      if (mat[i][j])
        tmp++;
    if (sum < tmp) {
      sum = tmp;
      k = i;
    }
  }
  ans[0] = k;
  ans[1] = sum;
  *returnSize = 2;
  return ans;
}

int main() {
  int m1[2][2] = {{0, 1}, {1, 0}}, m2[2][3] = {{0, 0, 0}, {0, 1, 1}},
      m3[3][2] = {{0, 0}, {1, 1}, {0, 0}}, mcs1 = 2, mcs2 = 2, mcs3 = 3, rs1,
      rs2, rs3;
  int *ramo1 = rowAndMaximumOnes((int **)m1, ARRAY_SIZE(m1), &mcs1, &rs1);
  int *ramo2 = rowAndMaximumOnes((int **)m2, ARRAY_SIZE(m2), &mcs2, &rs2);
  int *ramo3 = rowAndMaximumOnes((int **)m3, ARRAY_SIZE(m3), &mcs3, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d\n", ramo1[i]); // expect: 0 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d\n", ramo1[i]); // expect: 1 2
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d\n", ramo1[i]); // expect: 1 2
  printf("\n");
  free(ramo1), free(ramo2), free(ramo3);
}
