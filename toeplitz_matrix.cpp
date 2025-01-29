#include "leetcode.h"

class Solution {
public:
  bool isToeplitzMatrix(vvd & matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        if (matrix[i][j] != matrix[i - 1][j - 1])
          return false;
    return true;
  }
};

int main() {
  Solution obj;
  // true - all diagonals have the same elements
  vvd matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  // false - diagonals do not share same elements
  vvd matrix2 = {{1, 2}, {2, 2}};

  if (obj.isToeplitzMatrix(matrix))
    cout << "true";
  else
    cout << "false";
  if (obj.isToeplitzMatrix(matrix2))
    cout << "\ntrue";
  else
    cout << "\nfalse";
}
