// 1626. Best Team With No Conflicts
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * you are manager of a basketball team. for upcoming tournament you want to
 * choose the team with the highest overall score. the score of the team is the
 * sum of scores of all the players in the team. however the basketball team is
 * not allowed to have conflicts. a conflict exists if a younger player has a
 * strictly high score than an older player. a conflict does not occur between
 * players of the same age. given two lists, 'scores', & 'ages', where each
 * 'scores[i]' and 'ages[i]' represents the score and age of the ith player
 * respectively. return highest overall score of all teams.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a;
  int *bb = *(int **)b;
  if (aa[0] == bb[0])
    return aa[1] - bb[1];
  return aa[0] - bb[0];
}

int bestTeamScore(int *scores, int scoresSize, int *ages, int agesSize) {
  int n = scoresSize;
  int **data = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    data[i] = malloc(2 * sizeof(int));
    data[i][0] = ages[i];
    data[i][1] = scores[i];
  }
  qsort(data, n, sizeof(int *), cmp);
  int *dp = malloc(n * sizeof(int));
  dp[0] = data[0][1];
  int ans = dp[0];
  for (int i = 1; i < n; i++) {
    int pre = INT_MIN;
    dp[i] = data[i][1];
    for (int j = 0; j < i; j++)
      if (data[j][i] <= data[i][1])
        pre = fmax(pre, dp[j]);
    if (pre != INT_MIN)
      dp[i] += pre;
    ans = fmax(ans, dp[i]);
  }
  free(dp);
  for (int i = 0; i < n; i++)
    free(data[i]);
  free(data);
  return ans;
}

int main() {
  int scores1[] = {1, 3, 5, 10, 15}, ages1[] = {1, 2, 3, 4, 5};
  int scores2[] = {4, 5, 6, 5}, ages2[] = {2, 1, 2, 1};
  int scores3[] = {1, 2, 3, 5}, ages3[] = {8, 9, 10, 1};
  printf("%d\n", bestTeamScore(scores1, 5, ages1, 5)); // expect: 34
  printf("%d\n", bestTeamScore(scores2, 4, ages1, 4)); // expect: 16
  printf("%d\n", bestTeamScore(scores3, 4, ages1, 4)); // expect: 6
}
