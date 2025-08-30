// 1237. Find Positive Integer Solution for a Given Equation
#include "leetcode.h"

/*
 * given a callable function 'f(x, y)' with a hidden formula and a value 'z',
 * reverse engineer the formula and return all positive integer pairs 'x' and
 * 'y' where 'f(x, y) == z'. you may return the pairs in any order. while the
 * exact formula is hidden, the function is monotonically increasing.
 */

int function_id = 0;

int customFunction(int x, int y) {
  switch (function_id) {
  case 1:
    return x + y;
  case 2:
    return x * y;
  }
}

int **findSolution(int (*customFunction)(int, int), int z, int *returnSize,
                   int **returnColumnSizes) {
  int **ans = (int **)malloc(z * sizeof(int *)), k = 0;
  int *cols = *returnColumnSizes = (int *)malloc(z * sizeof(int));
  for (int i = 1; i <= z; i++)
    for (int j = z; j >= 1; j--)
      if (customFunction(i, j) == z) {
        (ans[k] = (int *)malloc(sizeof(int[cols[k] = 2])))[0] = i;
        ans[k++][1] = j;
      }
  *returnSize = k;
  return ans;
}

int main() {
  function_id = 1;
  int rs1, *rcs1, **fs1 = findSolution(customFunction, 5, &rs1, &rcs1);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", fs1[i][j]); // expect: [[1,4],[2,3],[3,2],[4,1]]
    printf("\n");
  }
  function_id = 2;
  int rs2, *rcs2, **fs2 = findSolution(customFunction, 5, &rs2, &rcs2);
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", fs2[i][j]); // expect: [[1,5],[5,1]]
    printf("\n");
  }
  for (int i = 0; i < rs1; i++)
    free(fs1[i]);
  free(rcs1);
  free(fs1);
  for (int i = 0; i < rs2; i++)
    free(fs2[i]);
  free(rcs2);
  free(fs2);
}
