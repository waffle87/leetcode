// 1235. Maximum Profit in Job Scheduling
#include "leetcode.h"

/*
We have n jobs, where every job is scheduled to be done from startTime[i] to
endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit
you can take such that there are no two jobs in the subset with overlapping time
range.

If you choose a job that ends at time X you will be able to start another job
that starts at time X.
*/

struct list {
  int start;
  int end;
  int point;
};

int next(int now, int finish_time, struct list *book, int start_time_size) {
  for (int i = now + 1; i < start_time_size; i++) {
    if (finish_time <= book[i].start) {
      return i;
    }
  }
  return start_time_size;
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int jobScheduling(int *start_time, int start_time_size, int *end_time,
                  int end_time_size, int *profit, int profit_size) {
  int start[50001];
  start[start_time_size] = 0;
  struct list *book = malloc(sizeof(struct list) * start_time_size);
  for (int i = 0; i < start_time_size; i++) {
    book[i].start = start_time[i];
    book[i].end = end_time[i];
    book[i].point = profit[i];
  }
  qsort(book, start_time_size, sizeof(struct list), cmp);
  for (int i = start_time_size - 1; i >= 0; i--)
    start[i] =
        fmax(book[i].point + start[next(i, book[i].end, book, start_time_size)],
             start[i + 1]);
  free(book);
  return start[0];
}

int main() {
  int st1[] = {1, 2, 3, 3}, et1[] = {3, 4, 5, 6}, p1[] = {50, 10, 40, 70};
  int st2[] = {1, 2, 3, 4, 6}, et2[] = {3, 5, 10, 6, 9},
      p2[] = {20, 20, 100, 70, 60};
  int st3[] = {1, 1, 1}, et3[] = {2, 3, 4}, p3[] = {5, 6, 4};
  printf("%d\n", jobScheduling(st1, ARRAY_SIZE(st1), et1, ARRAY_SIZE(et1), p1,
                               ARRAY_SIZE(p1))); // expect: 120
  printf("%d\n", jobScheduling(st2, ARRAY_SIZE(st2), et2, ARRAY_SIZE(et2), p2,
                               ARRAY_SIZE(p2))); // expect: 150
  printf("%d\n", jobScheduling(st3, ARRAY_SIZE(st3), et3, ARRAY_SIZE(et3), p3,
                               ARRAY_SIZE(p3))); // expect: 6
}
