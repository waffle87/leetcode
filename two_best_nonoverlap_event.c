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

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a;
  int *bb = *(int **)b;
  return aa[1] - bb[1];
}

int maxTwoEvents(int **events, int eventsSize, int *eventsColSize) {
  qsort(events, eventsSize, sizeof(int *), cmp);
  int curr_max = 0, global_max = 0;
  int *max_vals = (int *)malloc(eventsSize * sizeof(int));
  max_vals[0] = events[0][2];
  for (int i = 1; i < eventsSize; i++)
    max_vals[i] = fmax(max_vals[i - 1], events[i][2]);
  for (int i = 0; i < eventsSize; i++) {
    int start = events[i][0], value = events[i][2];
    int low = 0, high = i - 1, idx = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (events[mid][1] <= start - 1) {
        idx = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    curr_max = idx != -1 ? value + max_vals[idx] : value;
    global_max = fmax(global_max, curr_max);
  }
  free(max_vals);
  return global_max;
}

int main() {
  int e1i[3][3] = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
  int e2i[3][3] = {{1, 3, 2}, {4, 5, 2}, {1, 5, 5}};
  int e3i[3][3] = {{1, 5, 3}, {1, 5, 1}, {6, 6, 5}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  struct two_d_arr *e3 =
      two_d_arr_init(ARRAY_SIZE(e3i), ARRAY_SIZE(e3i[0]), e3i);
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
