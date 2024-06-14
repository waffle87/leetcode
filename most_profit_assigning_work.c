// 826. Most Profit Assigning Work
#include "leetcode.h"

/*
 * you have n jobs and m workers. you are given three arrays: difficulty,
 * profit, and worker where difficulty and pofit are the difficulty and profit
 * of the i'th job and worker is the ability of the jth worker. every worker can
 * be assigned at most one job, but one job can be completed multiple times.
 * return the maximum profit we can achieve after assigning the workers to the
 * jobs.
 */

int cmp(const void **a, const void **b) {
  int *a1 = *(int **)a;
  int *b1 = *(int **)b;
  return a1[0] == b1[0] ? a1[1] - b1[1] : a1[0] - b1[0];
}

int find_profit_idx(int **set, int difficulty_size, int capability) {
  int left = 0, right = difficulty_size - 1, mid;
  while (left + 1 < right) {
    mid = (left + right) / 2;
    if (set[mid][0] <= capability)
      left = mid;
    else
      right = mid - 1;
  }
  if (set[right][0] <= capability)
    return right;
  else if (set[left][0] <= capability)
    return left;
  else
    return -1;
}

int maxProfitAssignment(int *difficulty, int difficultySize, int *profit,
                        int profitSize, int *worker, int workerSize) {
  int i, j;
  int **set = (int **)malloc(difficultySize * sizeof(int *));
  for (int i = 0; i < difficultySize; i++) {
    set[i] = malloc(2 * sizeof(int));
    set[i][0] = difficulty[i];
    set[i][1] = profit[i];
  }
  qsort(set, difficultySize, sizeof(int *), cmp);
  int *dp = malloc(difficultySize * sizeof(int));
  dp[0] = set[0][1];
  for (int i = 1; i < difficultySize; i++)
    dp[i] = set[i][1] > dp[i - 1] ? set[i][1] : dp[i - 1];
  int ans = 0, idx;
  for (int i = 0; i < workerSize; i++) {
    idx = find_profit_idx(set, difficultySize, worker[i]);
    if (idx != -1)
      ans += dp[idx];
  }
  for (int i = 0; i < difficultySize; i++)
    free(set[i]);
  free(set), free(dp);
  return ans;
}

int main() {
  int d1[] = {2, 4, 6, 8, 10}, p1[] = {10, 20, 30, 40, 50}, w1[] = {4, 5, 6, 7};
  int d2[] = {85, 47, 57}, p2[] = {24, 66, 99}, w2[] = {40, 25, 25};
  printf("%d\n", maxProfitAssignment(d1, ARRAY_SIZE(d1), p1, ARRAY_SIZE(p1), w1,
                                     ARRAY_SIZE(w1))); // expect: 100
  printf("%d\n", maxProfitAssignment(d2, ARRAY_SIZE(d2), p2, ARRAY_SIZE(p2), w2,
                                     ARRAY_SIZE(w2))); // expect: 0
}
