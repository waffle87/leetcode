// 2225. Find Players With Zero or One Losses
#include "leetcode.h"

/*
 * given an integer array 'matches' where 'matches[i] = [winner[i], loser[i]]'
 * indicates a defeated player 'loser[i]' in a match. return a list 'answer' of
 * size 2 where 'answer[0]' is a list of all players that have not lost any
 * matches. 'answer[1]' is a list of all players that have lost exactly one
 * match. the values in the two lists should be returned in increasing order.
 */

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int **findWinners(int **matches, int matches_size, int *matches_col_size,
                  int *return_size, int **return_col_size) {
  int losers[100001] = {0};
  *return_size = 2;
  int **ans = (int **)malloc((*return_size) * sizeof(int));
  *return_col_size = (int *)calloc((*return_size), sizeof(int));
  for (int i = 0; i < *return_size; i++)
    ans[i] = (int *)malloc(matches_size * sizeof(int));
  for (int i = 0; i < matches_size; i++)
    losers[matches[i][1]]++;
  for (int i = 0; i < matches_size; i++) {
    if (losers[matches[i][1]] == 1)
      ans[1][*return_col_size[1]++] = matches[i][1];
    if (losers[matches[i][0]] == 0) {
      ans[0][*return_col_size[0]++] = matches[i][0];
      losers[matches[i][0]] = -1;
    }
  }
  qsort(ans[0], *return_col_size[0], sizeof(int), cmp);
  qsort(ans[1], *return_col_size[1], sizeof(int), cmp);
  return ans;
}
