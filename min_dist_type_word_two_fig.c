// 1320. Minimum Distance to Type a Word Using Two Fingers
#include "leetcode.h"

/*
 * you have a keyboard layout shown above in the xy plane, where each english
 * uppercase letter is located at some coordinate. for example, the letter 'A'
 * is located at coordinate '(0, 0)'. given the string 'word', return the
 * minimum total distance to type such string use only two fingers. the distance
 * between coordinates '(x1, y1)' and '(x2, y2)' is '|x1 - x2| + |y1 - y2|'.
 * note that the initial positions of your two fingers are considered free so do
 * not count twoards your total distance. aslso your two fingers do no have to
 * start at he first letter or the first two letters
 */

int dist(int p, int q) {
  int x1 = p / 6, y1 = p % 6;
  int x2 = q / 6, y2 = q % 6;
  return abs(x1 - x2) + abs(y1 - y2);
}

int minimumDistance(char *word) {
  int n = strlen(word);
  int ***dp = (int ***)malloc(n * sizeof(int **));
  for (int i = 0; i < n; ++i) {
    dp[i] = (int **)malloc(26 * sizeof(int *));
    for (int j = 0; j < 26; ++j) {
      dp[i][j] = (int *)malloc(26 * sizeof(int));
      for (int k = 0; k < 26; ++k)
        dp[i][j][k] = INT_MAX / 2;
    }
  }
  for (int i = 0; i < 26; ++i) {
    dp[0][i][word[0] - 'A'] = 0;
    dp[0][word[0] - 'A'][i] = 0;
  }
  for (int i = 1; i < n; ++i) {
    int curr = word[i] - 'A';
    int prev = word[i - 1] - 'A';
    int d = dist(prev, curr);
    for (int j = 0; j < 26; ++j) {
      dp[i][curr][j] = fmin(dp[i][curr][j], dp[i - 1][prev][j] + d);
      dp[i][j][curr] = fmin(dp[i][j][curr], dp[i - 1][j][prev] + d);
      if (prev == j) {
        for (int k = 0; k < 26; ++k) {
          int d0 = dist(k, curr);
          dp[i][curr][j] = fmin(dp[i][curr][j], dp[i - 1][k][j] + d0);
          dp[i][j][curr] = fmin(dp[i][j][curr], dp[i - 1][j][k] + d0);
        }
      }
    }
  }
  int ans = INT_MAX / 2;
  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j)
      if (ans > dp[n - 1][i][j])
        ans = dp[n - 1][i][j];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j)
      free(dp[i][j]);
    free(dp[i]);
  }
  free(dp);
  return ans;
}

int main() {
  char *w1 = "CAKE";
  char *w2 = "HAPPY";
  int r1 = minimumDistance(w1);
  int r2 = minimumDistance(w2);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 6);
}
