#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    vector<int> waysX = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> waysY = {1, -1, 1, -1, 0, 0, 1, -1};
    for (int row = 0; row < board.size(); row++) {
      for (int col = 0; col < board[0].size(); col++) {
        int live = 0;
        for (int i = 0; i < 8; i++) {
          int currX = row + waysX[i], currY = col + waysY[i];
          if (isNeighbor(currX, currY, board) && abs(board[currX][currY]) == 1)
            live++;
        }
        if (board[row][col] == 1 && (live < 2 || live > 3))
          board[row][col] = -1;
        if (board[row][col] == 0 && live == 3)
          board[row][col] = 2;
      }
    }
    for (int row = 0; row < board.size(); row++)
      for (int col = 0; col < board[0].size(); col++)
        if (board[row][col] >= 1)
          board[row][col] = 1;
        else
          board[row][col] = 0;
  }

private:
  bool isNeighbor(int x, int y, vector<vector<int>> &board) {
    return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
  }
};

int main() {}
