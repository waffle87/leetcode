// 118. Pascal's Triangle
#include "leetcode.h"

/*
 * given an integer 'numRows', return the first numrows of pascal's triangle.
 * in pascal's triangle, each number is the sum of the two number direction
 * above it as show [gif]
 */

int **generate(int numRows, int *returnSize, int **returnColumnsSizes) {
  *returnSize = numRows;
  int **ans = (int **)calloc(1, sizeof(int *[numRows]));
  *returnColumnsSizes = (int *)calloc(1, sizeof(int[numRows]));
  for (int i = 0; i < numRows; i++) {
    (*returnColumnsSizes)[i] = i + 1;
    ans[i] = (int *)calloc(1, sizeof(int[i + 1]));
  }
  ans[0][0] = 1;
  for (int i = 1; i < numRows; i++) {
    ans[i][0] = 1;
    for (int j = 1; j < i; j++)
      ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
    ans[i][i] = 1;
  }
  return ans;
}

int main() {
  int rs1, *rcs1, **g1 = generate(5, &rs1, &rcs1);
  int rs2, *rcs2, **g2 = generate(1, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ",
             g1[i][j]); // expect: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ",
             g2[i][j]); // expect: [[1]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(g1[i]);
  free(g1), free(rcs1);
  for (int i = 0; i < rs2; i++)
    free(g2[i]);
  free(g2), free(rcs2);
}
