// 1376. Time Needed to Inform All Employees
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * a company has 'n' employees with a unique id for each employee from 0 to 'n -
 * 1'. the head of the company is the one with the 'head_id'. each employee has
 * one direct manager given the 'manager' array where 'manager[i]' is the direct
 * manager of the i'th employee, 'manager[head_id] = -1'. also it is guaranteed
 * that the subordination relations have a tree structure. the head of the
 * company wants to inform all the company employees of an urgent piece of new.
 * he will inform his direct subordinates, and they will inform their
 * subordinates and so on until all the employees know about the urgent news.
 * the i'th employee needs 'inform_time[i]' minutes to inform all of his direct
 * subordinates (ie. after 'inform_time[i]' minutes, all his direct subordinates
 * can start spreading the news) return the number of minutes needed to inform
 * all the employees about the urget news.
 */

int numOfMinutes(int n, int head_id, int *manager, int manager_size,
                 int *inform_time, int inform_time_size) {
  if (n == 1)
    return 0;
  int *cn = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    if (i == head_id)
      continue;
    cn[manager[i]]++;
  }
  int *min_time = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    min_time[i] = INT_MIN;
  int *stack = malloc(n * sizeof(int));
  int head = 0, idx = 0;
  for (int i = 0; i < n; i++)
    if (!cn[i]) {
      min_time[i] = 0;
      stack[idx] = i;
      idx++;
    }
  while (head < idx) {
    int emp = stack[head], mag = manager[emp];
    head++;
    if (mag >= 0) {
      cn[mag]--;
      min_time[mag] = fmax(min_time[mag], inform_time[mag] + min_time[emp]);
      if (!cn[mag]) {
        stack[idx] = mag;
        idx++;
      }
    }
  }
  int ans = min_time[head_id];
  free(cn), free(stack), free(min_time);
  return ans;
}

int main() {
  int m1[] = {-1}, m2[] = {2, 2, -1, 2, 2, 2};
  int it1[] = {0}, it2[] = {0, 0, 1, 0, 0, 0};
  printf("%d\n", numOfMinutes(1, 0, m1, 1, it1, 1)); // expect: 0
  printf("%d\n", numOfMinutes(6, 2, m2, 6, it2, 6)); // expect: 1
}
