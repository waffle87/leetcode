#include "leetcode.h"

class Solution {
public:
  int totalNQueens(int n) {
    vector<bool> col(n, true);
    vector<bool> anti(2 * n - 1, true);
    vector<bool> main(2 * n - 1, true);
    vector<int> row(n, 0);
    int count = 0;
    helper(0, row, col, main, anti, count);
    return count;
  }

private:
  void helper(int i, vector<int> &row, vector<bool> &col, vector<bool> &main,
              vector<bool> &anti, int &count) {
    if (i == row.size()) {
      count++;
      return;
    }
    for (int j = 0; j < col.size(); j++)
      if (col[j] && main[i + j] && anti[i + col.size() - 1 - j]) {
        row[i] = j;
        col[j] = main[i + j] = anti[i + col.size() - 1 - j] = false;
        helper(i + 1, row, col, main, anti, count);
        col[j] = main[i + j] = anti[i + col.size() - 1 - j] = true;
      }
  }
};

int main() {
  Solution obj;
  cout << obj.totalNQueens(4);
}
