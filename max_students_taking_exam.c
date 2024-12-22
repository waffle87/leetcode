// 1349. Maximum Students Taking Exam
#include "leetcode.h"

/*
 * given an 'm x n' matrix 'seats' that represent seats distributions in a
 * classroom. if a seat is broken, it is denoted by '#' character otherwise it
 * is denoted by a '.' character. students can see theanswers of those sitting
 * next to the left, right, upper left, and upper right, but cannot see the
 * answers of the student sitting directly in front of or behind them. return
 * the maximum number of students that can take the exam together without any
 * cheating being possible. students must be placed in seats in good condition.
 */

int maxStudents(char **seats, int seatsSize, int *seatsColSize) {
  int n = seatsSize, m = *seatsColSize, ans = 0, dp[9][(1 << 8) + 2], avail[9];
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++)
      if (seats[i - 1][j] == '.')
        avail[i] |= (1 << j);
  for (int mask = 0; mask < (1 << m); mask++)
    dp[0][mask] = 0;
  for (int i = 1; i <= n; i++)
    for (int pre = 0; pre < (1 << m); pre++) {
      if (dp[i - 1][pre] == -1)
        continue;
      for (int mask = 0; mask < (1 << m); mask++) {
        if ((mask & avail[i]) != mask)
          continue;
        if (mask & (mask >> 1))
          continue;
        if (mask & (pre << 1) || mask & (pre >> 1))
          continue;
        dp[i][mask] =
            fmax(dp[i][mask], dp[i - 1][pre] + __builtin_popcount(mask));
      }
    }
  for (int mask = 0; mask < (1 << m); mask++)
    ans = fmax(ans, dp[n][mask]);
  return ans;
}

int main() {
  char *s1[] = {"#", ".", "#", "#", ".", "#", ".", "#", "#",
                "#", "#", ".", "#", ".", "#", "#", ".", "#"};
  int ss1 = 3, scs1 = 6;
  char *s2[] = {".", "#", "#", "#", "#", ".", "#", "#", ".", "#"};
  int ss2 = 5, scs2 = 2;
  char *s3[] = {"#", ".", ".", ".", "#", ".", "#", ".", "#", ".", ".", ".", "#",
                ".", ".", ".", "#", ".", "#", ".", "#", ".", ".", ".", "#"};
  int ss3 = 5, scs3 = 5;
  printf("%d\n", maxStudents((char **)s1, ss1, &scs1)); // expect: 4
  printf("%d\n", maxStudents((char **)s2, ss2, &scs2)); // expect: 3
  printf("%d\n", maxStudents((char **)s3, ss3, &scs3)); // expect: 10
}
