// 2054. Two Best Non-Overlapping Events
#include "leetcode.h"

/*
 * you are given a 0-indexed 2d integer array of 'events' where 'events[i] =
 * [start_time, end_time, value]'. the i'th event starts at 'start_time' and
 * ends at 'end_time', and if you attend this event, you will receive a value of
 * 'value'. you can choose at most two non-overlapping events to ttend such that
 * the sum of their values is maximise. return this maximum sum. note that the
 * start time and end time is inclusive: that is, you cannot attend two events
 * where one of them starts and the other ends at the same time. more
 * specifically, if you attend an event with end time 't', the next event must
 * start or after 't + 1'
 */

struct event {
  int start;
  int end;
  int value;
};

int cmp_event(const void *a, const void *b) {
  struct event *e1 = (struct event *)a;
  struct event *e2 = (struct event *)b;
  if (e1->end == e2->end)
    return e1->start - e2->start;
  return e1->end < e2->end ? -1 : 1;
}

int bin_search(struct event *e, int size, int start_time) {
  int left = 0, right = size - 1, res = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (e[mid].end < start_time) {
      res = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  return res;
}

int maxTwoEvents(int **events, int eventsSize, int *eventsColSize) {
  struct event *e = (struct event *)malloc(eventsSize * sizeof(struct event));
  for (int i = 0; i < eventsSize; i++) {
    e[i].start = events[i][0];
    e[i].end = events[i][1];
    e[i].value = events[i][2];
  }
  qsort(e, eventsSize, sizeof(struct event), cmp_event);
  int *prefix_max = (int *)malloc(eventsSize * sizeof(int));
  prefix_max[0] = e[0].value;
  for (int i = 1; i < eventsSize; i++)
    prefix_max[i] =
        prefix_max[i - 1] > e[i].value ? prefix_max[i - 1] : e[i].value;
  int ans = 0;
  for (int i = 0; i < eventsSize; i++)
    if (e[i].value > ans)
      ans = e[i].value;
  for (int i = 0; i < eventsSize; i++) {
    int idx = bin_search(e, eventsSize, e[i].start);
    int prev = idx == -1 ? 0 : prefix_max[idx];
    int candidate = e[i].value + prev;
    if (candidate > ans)
      ans = candidate;
  }
  free(prefix_max), free(e);
  return ans;
}

int main() {
  int e1i[3][3] = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}},
      e2i[3][3] = {{1, 3, 2}, {4, 5, 2}, {1, 5, 5}},
      e3i[3][3] = {{1, 5, 3}, {1, 5, 1}, {6, 6, 5}};
  struct two_d_arr *e1 = two_d_arr_init(3, 3, e1i);
  struct two_d_arr *e2 = two_d_arr_init(3, 3, e2i);
  struct two_d_arr *e3 = two_d_arr_init(3, 3, e3i);
  printf("%d\n",
         maxTwoEvents(e1->arr, e1->row_size, e1->col_size)); // expect: 4
  printf("%d\n",
         maxTwoEvents(e2->arr, e2->row_size, e2->col_size)); // expect: 5
  printf("%d\n",
         maxTwoEvents(e3->arr, e3->row_size, e3->col_size)); // expect: 8
  two_d_arr_free(e1);
  two_d_arr_free(e2);
  two_d_arr_free(e3);
}
