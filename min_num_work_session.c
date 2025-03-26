// 1986. Minimum Number of Work Sessions to Finish the Tasks
#include "leetcode.h"

/*
 * there are 'n' tasks assigned to you. the task times are represented as an
 * integer array 'tasks' of length 'n' where the i'th task takes 'tasks[i]'
 * hours to finish. a work session is when you work for at most 'sessionTime'
 * consecutive hours, and then take a break. given 'tasks' and 'sessionTime',
 * return the minimum number of work sessions needed to finish all the tasks
 * following the conditions. the tests are generated such that 'sessionTime' is
 * greater or equal to the maximum element in 'tasks[i]'.
 */

int work(int *tasks, int tasksSize, int completed, int sessionTime,
         int time_remaining, int **dp) {
  int cnt, min = INT_MAX;
  if (completed == (1 << tasksSize) - 1)
    return 0;
  if (dp[completed][time_remaining] != -1)
    return dp[completed][time_remaining];
  for (int i = 0; i < tasksSize; i++) {
    if (!(completed & (1 << i))) {
      completed |= (1 << i);
      if (time_remaining - tasks[i] < 0)
        cnt = work(tasks, tasksSize, completed, sessionTime,
                   sessionTime - tasks[i], dp) +
              1;
      else
        cnt = work(tasks, tasksSize, completed, sessionTime,
                   time_remaining - tasks[i], dp);
      min = fmin(min, cnt);
      completed &= ~(1 << i);
    }
  }
  dp[completed][time_remaining] = min;
  return min;
}

int minSessions(int *tasks, int tasksSize, int sessionTime) {
  int **dp = (int **)malloc((1 << tasksSize) * sizeof(int *));
  for (int i = 0; i < (1 << tasksSize); i++) {
    dp[i] = (int *)malloc((sessionTime + 1) * sizeof(int));
    for (int j = 0; j <= sessionTime; j++)
      dp[i][j] = -1;
  }
  int ans = work(tasks, tasksSize, 0, sessionTime, 0, dp);
  for (int i = 0; i < (1 << tasksSize); i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int t1[] = {1, 2, 3}, t2[] = {3, 1, 3, 1, 1}, t3[] = {1, 2, 3, 4, 5};
  printf("%d\n", minSessions(t1, ARRAY_SIZE(t1), 3));  // expect: 2
  printf("%d\n", minSessions(t2, ARRAY_SIZE(t2), 8));  // expect: 2
  printf("%d\n", minSessions(t3, ARRAY_SIZE(t3), 15)); // expect: 1
}
