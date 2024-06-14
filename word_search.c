// 79. Word Search
#include "leetcode.h"

/*
 * given an 'm * n' grid of characters 'board' and a string 'word', return 1 if
 * the word exists in the grid. the word can be constructed from letters of
 * sequentially adjacent cells, where adjacent cells are horizontally or
 * vertically neighbouring the same letter cell may not be used more than once.
 */

bool dfs(char **board, int r_size, int c_size, int r, int c, char *word,
         int s_len, int k) {
  if (k == s_len)
    return 1;
  if (r < 0 || c < 0 || r > r_size - 1 || c > c_size - 1 ||
      board[r][c] != word[k])
    return 0;
  char tmp = board[r][c];
  bool res = dfs(board, r_size, c_size, r + 1, c, word, s_len, k + 1) |
             dfs(board, r_size, c_size, r - 1, c, word, s_len, k + 1) |
             dfs(board, r_size, c_size, r, c + 1, word, s_len, k + 1) |
             dfs(board, r_size, c_size, r, c - 1, word, s_len, k + 1);
  board[r][c] = tmp;
  return res;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
  int r_size = boardSize, c_size = boardColSize[0], s_len = strlen(word);
  for (int r = 0; r < r_size; r++)
    for (int c = 0; c < c_size; c++)
      if (dfs(board, r_size, c_size, r, c, word, s_len, 0))
        return 1;
  return 0;
}
