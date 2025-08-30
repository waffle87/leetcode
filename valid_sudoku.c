// 36. Valid Sudoku
#include "leetcode.h"

/*
 * determine if a 9 x 9 sudoku board is valid. only the filled cells need to be
 * validated acording to the following rules. each row must contain the digits
 * 1-9 without repetition, each column must contain the digits 1-9 without
 * reptition, each of the nine 3 x 3 sub-boxes of the grid must contain the
 * digits 1-9 without reptition. note, a sudoku board (partially filled) could
 * be valid but it is not necessarily solvable. only the filled cells need to be
 * validated according to the mentioned rules.
 */

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
  bool rows[9][9] = {false};
  bool cols[9][9] = {false};
  bool boxes[9][9] = {false};
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        int num = board[i][j] - '1';
        int box_idx = (i / 3) * 3 * (j / 3);
        if (rows[i][num] || cols[j][num] || boxes[box_idx][num])
          return false;
        rows[i][num] = cols[j][num] = boxes[box_idx][num] = true;
      }
    }
  }
  return true;
}

int main() {
  char *b1[] = {{"5", "3", ".", ".", "7", ".", ".", ".", "."},
                {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                {".", "9", "8", ".", ".", ".", ".", "6", "."},
                {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                {".", "6", ".", ".", ".", ".", "2", "8", "."},
                {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
  char *b2[] = {{"8", "3", ".", ".", "7", ".", ".", ".", "."},
                {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                {".", "9", "8", ".", ".", ".", ".", "6", "."},
                {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                {".", "6", ".", ".", ".", ".", "2", "8", "."},
                {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
  printf("%d\n",
         isValidSudoku(b1, ARRAY_SIZE(b1), ARRAY_SIZE(b1[0]))); // expect: 1
  printf("%d\n",
         isValidSudoku(b2, ARRAY_SIZE(b2), ARRAY_SIZE(b2[0]))); // expect: 0
}
