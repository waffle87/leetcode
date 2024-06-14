#include "leetcode.h"
#include <vector>

class Solution {
public:
  bool isValidSudoku(vvd(char) & board) {
    vector<set<char>> rows(9), cols(9), blck(9);
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (board[i][j] != '.') {
          int m = board[i][j], n = (i / 3) * 3 + j / 3;
          if (!rows[i].emplace(m).second) // rows
            return false;
          if (!cols[j].emplace(m).second) // columns
            return false;
          if (!blck[n].emplace(m).second) // blocks
            return false;
        }
    return true;
  }
};

int main() {
  Solution obj;
  vvd(char) board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  if (obj.isValidSudoku(board))
    cout << "true";
  else
    cout << "false";
}
