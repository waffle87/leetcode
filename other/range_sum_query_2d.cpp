// 304. Range Sum Query 2D - Immutable
#include "leetcode.h"

/*
 * given a 2d matrix 'matrix', handle multiple queries of the following type:
 * calculate the sum of the elements of 'matrix' inside the rectangle defined by
 * its upper left corner '(row1, col1)' and lower right corer '(row2, col2)'.
 * you must design an algorithm where 'sumRegion' works on 'O(1)' time
 * complexity.
 */

class NumMatrix {
public:
  vector<vector<int>> sum;
  NumMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    sum = vector<vector<int>>(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                    matrix[i - 1][j - 1];
  }
  int sumRegion(int row1, int col1, int row2, int col2) {
    row1++, col1++, row2++, col2++;
    return sum[row2][col2] - sum[row2][col1 - 1] - sum[row1 - 1][col2] +
           sum[row1 - 1][col1 - 1];
  }
};

int main() {
  vvd matrix = {{3, 0, 1, 4, 2},
                     {5, 6, 3, 2, 1},
                     {1, 2, 0, 1, 5},
                     {4, 1, 0, 1, 7},
                     {1, 0, 3, 0, 5}};
  NumMatrix *obj = new NumMatrix(matrix);
  printf("%d\n", obj->sumRegion(2, 1, 4, 3)); // expect: 8
  printf("%d\n", obj->sumRegion(1, 1, 2, 2)); // expect: 11
  printf("%d\n", obj->sumRegion(1, 2, 2, 4)); // expect: 12
}
