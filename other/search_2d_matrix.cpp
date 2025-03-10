// 74. Search a 2D Matrix
#include "leetcode.h"

/*
 * given an 'm x n' integer matrix 'matrxi' with the following two properties:
 * - each row is sorted in non-decreasing order.
 * - the first integer of each row is greater than the last integer of the
 * previous row. given an integer 'target', return true if 'target' is in
 * 'matrix', or false otherwise. you must write a solution in 'O(log(m * n))'
 * time complexity
 */

class Solution {
public:
  bool searchMatrix(vvd & matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size(), row = 0, col = cols - 1;
    while (row < rows && col > -1) {
      int curr = matrix[row][col];
      if (curr == target)
        return true;
      if (target > curr)
        row++;
      else
        col--;
    }
    return false;
  }
};

int main() {
  Solution obj;
  vvd matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  printf("%d\n", obj.searchMatrix(matrix, 3));  // expect: 1
  printf("%d\n", obj.searchMatrix(matrix, 13)); // expect: 0
}
