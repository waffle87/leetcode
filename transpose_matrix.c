// 867. Transpose Matrix
#include "leetcode.h"

/*
 * given a 2d integer array 'matrix', return the transpose of 'matrix'. the
 * transpose of a matrix is the matrix flipped over its main diagonal switching
 * the matrix's rows and column indices
 */

int **transpose(int **A, int ARowSize, int const *AColSizes, int **columnSizes,
                int *returnSize) {
  int **ans = malloc(sizeof(int *) * (*returnSize = *AColSizes));
  *columnSizes = malloc(sizeof(int) * (*AColSizes));
  for (int i = 0; i < (*AColSizes); ++i) {
    ans[i] = malloc(sizeof(int) * (*(*columnSizes + i) = ARowSize));
    for (int j = 0; j < ARowSize; ++j)
      ans[i][j] = A[j][i];
  }
  return ans;
}
