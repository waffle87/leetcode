// 2365. Task Scheduler II
#include <stdio.h>
#include <stdlib.h>

/*
 * given a 0-indexed array of positive integers 'tasks', representing tasks that
 * need to be completed in order, where 'tasks[i]' represents the type of the
 * i'th task. you are also given a positve integer 'space' which represents the
 * minimum number of days that must pass after the completion of a task before
 * another task of the same type can be performed. each day until all tasks have
 * been completed, you must either
 * - complete the next task from 'tasks' or
 * - take a break
 * return the minimum number of days needed to complete all tasks.
 */

long long taskSchedulerII(int *tasks, int tasks_size, int space) {
  long long ans = 0;
  int n = tasks_size, m = 10 * tasks_size;
  long long **hash = calloc(m, sizeof(long long *));
  for (int i = 0; i < n; i++) {
    int val = tasks[i], d = val;
    while (1) {
      if (!hash[d % m]) {
        ans++;
        hash[d % m] = malloc(2 * sizeof(long long));
        hash[d % m][0] = tasks[i];
        hash[d % m][1] = ans;
        break;
      } else if (hash[d % m][0] == tasks[i]) {
        ans++;
        if (ans >= (hash[d % m][1] + space + 1))
          hash[d % m][1] = ans;
        else {
          hash[d % m][1] += (space + 1);
          ans = hash[d % m][1];
        }
        break;
      } else
        d++;
    }
  }
  for (int i = 0; i < m; i++)
    if (hash[i])
      free(hash[i]);
  free(hash);
  return ans;
}

int main() {
  int t1[] = {1, 2, 1, 2, 3, 1}, t2[] = {5, 8, 8, 5};
  printf("%lld\n", taskSchedulerII(t1, 6, 3)); // expect: 9
  printf("%lld\n", taskSchedulerII(t2, 4, 2)); // expect: 6
}
