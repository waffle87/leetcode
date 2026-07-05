// 1301. Number of Paths with Max Score
#include "leetcode.h"

/*
 * you are given a square 'board' of characters. you can move on the board
 * starting at the bottom right sqaure marked with the character 'S'. you need
 * to reach the top left square marked with the character 'E'. the rest of the
 * squares are labeled either with a numeric character '1, 2, ..., 9' or with an
 * obstacle 'X'. in one move you can go up, left, or up-left (diagonally) only
 * if there is no obstacle there. return a list of two integers: the first
 * integer is the maximum sum of numeric characters you can collect and the
 * second is the number of such paths that youcan take to get that maximum sum,
 * modulo 10^9 + 7.
 */

int *pathsWithMaxScore(char **board, int boardSize, int *returnSize) {
  static int mod = 1e9 + 7;
  int n = boardSize;
  int *score = (int *)malloc((n + 1) * sizeof(int));
  int *ways = (int *)calloc(n + 1, sizeof(int));
  memset(score, -1, (n + 1) * sizeof(int));
  for (int r = n - 1; r >= 0; r--) {
    int *new_score = (int *)malloc((n + 1) * sizeof(int));
    int *new_ways = (int *)calloc(n + 1, sizeof(int));
    memset(new_score, -1, (n + 1) * sizeof(int));
    for (int c = n - 1; c >= 0; c--) {
      if (board[r][c] == 'X')
        continue;
      if (board[r][c] == 'S') {
        new_score[c] = 0;
        new_ways[c] = 1;
        continue;
      }
      int best = score[c];
      best = fmax(best, new_score[c + 1]);
      best = fmax(best, score[c + 1]);
      if (best == -1)
        continue;
      long long cnt = 0;
      if (score[c] == best)
        cnt += ways[c];
      if (new_score[c + 1] == best)
        cnt += new_ways[c + 1];
      if (score[c + 1] == best)
        cnt += ways[c + 1];
      int val = board[r][c] == 'E' ? 0 : board[r][c] - '0';
      new_score[c] = best + val;
      new_ways[c] = cnt % mod;
    }
    free(score);
    free(ways);
    score = new_score;
    ways = new_ways;
  }
  int *ans = (int *)calloc(2, sizeof(int));
  *returnSize = 2;
  if (score[0] != -1) {
    ans[0] = score[0];
    ans[1] = ways[0];
  }
  free(score);
  free(ways);
  return ans;
}

int main() {
  char *b1[] = {"E23", "2X2", "12S"};
  char *b2[] = {"E12", "1X1", "21S"};
  char *b3[] = {"E11", "XXX", "11S"};
  int rs1, r1[] = {7, 1};
  int rs2, r2[] = {4, 2};
  int rs3, r3[] = {0, 0};
  int *pwms1 = pathsWithMaxScore(b1, ARRAY_SIZE(b1), &rs1);
  int *pwms2 = pathsWithMaxScore(b2, ARRAY_SIZE(b2), &rs2);
  int *pwms3 = pathsWithMaxScore(b3, ARRAY_SIZE(b3), &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", pwms1[i]);
    assert(pwms1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", pwms2[i]);
    assert(pwms2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", pwms3[i]);
    assert(pwms3[i] == r3[i]);
  }
  printf("\n");
  free(pwms1);
  free(pwms2);
  free(pwms3);
}
