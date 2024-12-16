// 782. Transform to Chessboard
#include "leetcode.h"

/*
 * you are given an 'n * n' binary grid 'board'. in each move, you can swap any
 * two rows with each other, or any two columns with each other. return the
 * minimum number of rwos to transform the board intoa chessboard board. if the
 * task is impossible, return -1. a chessboard board is a board where no 0's and
 * no 1's are 4-directionally adjacent
 */

int movesToChessboard(int **board, int boardSize, int *boardColSize) {
  int n = boardSize, row_sum = 0, col_sum = 0, row_swap = 0, col_swap = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j])
        return -1;
  for (int i = 0; i < n; ++i) {
    row_sum += board[0][i];
    col_sum += board[i][0];
    row_swap += board[i][0] == i % 2;
    col_swap += board[0][i] == i % 2;
  }
  if (row_sum != n / 2 && row_sum != (n + 1) / 2)
    return -1;
  if (col_sum != n / 2 && col_sum != (n + 1) / 2)
    return -1;
  if (n % 2) {
    if (col_swap % 2)
      col_swap = n - col_swap;
    if (row_swap % 2)
      row_swap = n - row_swap;
  } else {
    col_swap = fmin(n - col_swap, col_swap);
    row_swap = fmin(n - row_swap, row_swap);
  }
  return (col_swap + row_swap) / 2;
}

int main() {
  int b1i[4][4] = {{0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}};
  int b2i[2][2] = {{0, 1}, {1, 0}};
  int b3i[2][2] = {{1, 0}, {1, 0}};
  struct two_d_arr b1, b2, b3;
  two_d_arr_init(&b1, 4, 4, b1i);
  two_d_arr_init(&b2, 2, 2, b2i);
  two_d_arr_init(&b3, 2, 2, b3i);
  printf("%d\n",
         movesToChessboard(b1.arr, b2.row_size, b3.col_size)); // expect: 2
  printf("%d\n",
         movesToChessboard(b2.arr, b2.row_size, b2.col_size)); // expect: 0
  printf("%d\n",
         movesToChessboard(b3.arr, b3.row_size, b3.col_size)); // expect: -1
  two_d_arr_free(&b1);
  two_d_arr_free(&b2);
  two_d_arr_free(&b3);
}
