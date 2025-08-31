// 37. Sudoku Solver
#include "leetcode.h"

/*
 * write a program to solve a sudoku puzzle by filling the empty cells. a sudoku
 * solution must satisfy all of the following rules. each of the digits '1-9'
 * must occur exactly once in each row, each of the digits '1-9', must occur
 * exactly once in each column, and each of the digits '1-9' must occur exactly
 * once in each of the 9 3x3 sub-boxes of the grid. the '.' character indicates
 * empty cells.
 */

bool solve(char **board, bool row[9][9], bool col[9][9], bool grid[9][9], int r,
           int c) {
  if (r == 9)
    return true;
  int next_r = c == 8 ? r + 1 : r;
  int next_c = c == 8 ? 0 : c + 1;
  if (board[r][c] != '.')
    return solve(board, row, col, grid, next_r, next_c);
  int grid_idx = (r / 3) * 3 + (c / 3);
  for (int i = 0; i < 9; i++) {
    if (!row[r][i] && !col[c][i] && !grid[grid_idx][i]) {
      board[r][c] = '1' + i;
      row[r][i] = col[c][i] = grid[grid_idx][i] = true;
      if (solve(board, row, col, grid, next_r, next_c))
        return true;
      board[r][c] = '.';
      row[r][i] = col[c][i] = grid[grid_idx][i] = false;
    }
  }
  return false;
}

void solveSudoku(char **board, int boardSize, int *boardColSize) {
  if (boardSize != 9 || *boardColSize != 9)
    return;
  bool row[9][9] = {false};
  bool col[9][9] = {false};
  bool grid[9][9] = {false};
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (board[i][j] != '.') {
        int num = board[i][j] - '1';
        if (num < 0 || num >= 9)
          return;
        row[i][num] = col[j][num] = true;
        grid[(i / 3) * 3 + (j / 3)][num] = true;
      }
  solve(board, row, col, grid, 0, 0);
}

int main() {
  char *board[] = {{"5", "3", ".", ".", "7", ".", ".", ".", "."},
                   {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                   {".", "9", "8", ".", ".", ".", ".", "6", "."},
                   {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                   {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                   {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                   {".", "6", ".", ".", ".", ".", "2", "8", "."},
                   {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                   {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
  solveSudoku((char **)board, ARRAY_SIZE(board), ARRAY_SIZE(board[0]));
  for (int i = 0; i < ARRAY_SIZE(board); i++) {
    for (int j = 0; j < ARRAY_SIZE(board[0]); j++)
      printf("%c ", board[i][j]);
    printf("\n");
  }
}
