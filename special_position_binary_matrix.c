// 1582. Special Positions in a Binary Matrix
#include "leetcode.h"

/*
 * given an 'm * n' binary matrix 'mat', return the number of special positions
 * in 'mat'. a position '(i, j)' is called special  if 'mat[i][j] == 1'  and all
 * other elements in a row and column are 0
 */

// int numSpecial(int **mat, int mat_size, int *mat_col_size) {
int numSpecial(int r, int c, int mat[r][c], int mat_size, int *mat_col_size) {
  int cnt = 0;
  for (int rows = 0; rows < mat_size; rows++)
    for (int cols = 0; cols < *mat_col_size; cols++)
      if (mat[rows][cols]) {
        bool match = 1;
        for (int i = 0; i < *mat_col_size; i++)
          if (mat[rows][i] && i != cols) {
            match = 0;
            break;
          }
        if (!match)
          break;
        for (int i = 0; i < mat_size; i++)
          if (mat[i][cols] && i != rows) {
            match = 0;
            break;
          }
        if (match)
          cnt++;
      }
  return cnt;
}

int main() {
  int m1[3][3] = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}},
      m2[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  int mcs1[] = {}, mcs2[] = {};
  printf("%d\n", numSpecial(3, 3, m1, 3, mcs1)); // expect: 1
  printf("%d\n", numSpecial(3, 3, m1, 3, mcs2)); // expect: 3
}
