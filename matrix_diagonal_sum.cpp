// 1572. Matrix Diagonal Sum
#include "leetcode.h"

/*
 * given a square matrix 'mat', return the sum of the matrix
 * diagonals. only include the sum of all the elements on the
 * primary diagonal and all the elements on the secondary
 * diagonal that are not part of the primary
 */

class Solution {
public:
  int diagonalSum(vvd(int) & mat) {
    int n = mat.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      if (i != n - i - 1)
        ans += mat[i][i] + mat[i][n - i - 1];
      else
        ans += mat[i][i];
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vvd(int) m2 = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
  vvd(int) m3 = {{5}};
  printf("%d\n", obj.diagonalSum(m1)); // expect: 25
  printf("%d\n", obj.diagonalSum(m2)); // expect: 8
  printf("%d\n", obj.diagonalSum(m3)); // expect: 5
}
