// 118. Pascal's Triangle
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer 'num_rows', return the first numrows of pascal's triangle.
 * in pascal's triangle, each number is the sum of the two number direction
 * above it as show [gif]
 */

int **generate(int num_rows, int *return_size, int **col_size) {
  int **ans = (int **)malloc(sizeof(int *) * num_rows);
  int i, j;
  *return_size = num_rows;
  for (i = 0; i < num_rows; i++) {
    ans[i] = (int *)malloc(sizeof(int) * (i + 1));
    ans[i][0] = 1;
    ans[i][i] = 1;
  }
  *col_size = (int *)malloc(sizeof(int) * num_rows);
  for (i = 0; i < num_rows; i++)
    (*col_size)[i] = i + 1;
  i = 2;
  while (i < num_rows) {
    j = 1;
    while (j < i) {
      ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
      j++;
    }
    i++;
  }
  return ans;
}

int main() {
  int **g1 = generate(5, NULL, NULL);
  int **g2 = generate(1, NULL, NULL);
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      printf("%d ",
             g1[i][j]); // expect: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < 1; j++)
      printf("%d ", g2[i][j]); // expect: [[1]]
}
