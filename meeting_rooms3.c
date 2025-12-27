// 2402. Meeting Rooms III
#include "leetcode.h"

/*
 * you are given an integer 'n', there are 'n' rooms numbered 0 to 'n - 1'.
 * guven a 2d integer array 'meetings', where 'meetings[i] = start[i], end[i]'
 * means that a meeting will be held during the half closed time interval
 * '[start[i], end[i]]'. all thevalues of 'start[i]' are unique. meetings are
 * allocated to rooms in the following manner: each meeting will take place in
 * the unused room with the lowest number. if there are no available rooms, the
 * meeting will be delayed until a room becoms free. the dleayed meeting should
 * have the same duration as the original meeting. when a room becoms unused,
 * meetings that have an earlier original start time should be given the room,
 * return the number of the room that held the most meetings. if there are
 * multiple rooms, return the room with the lowest number. a half closed
 * interval '[a, b)' is the interval between 'a' and 'b' including 'a' and not
 * including 'b'.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a;
  int *bb = *(int **)b;
  return aa[0] - bb[0];
}

int mostBooked(int n, int **meetings, int meetingsSize, int *meetingsColSize) {
  qsort(meetings, meetingsSize, sizeof(int *), cmp);
  int *cnt = (int *)calloc(n, sizeof(int)), i = 0;
  long *timer = (long *)calloc(n, sizeof(long));
  while (i < meetingsSize) {
    int start = meetings[i][0], end = meetings[i][1];
    int room = -1, earliest_room = -1;
    long duration = end - start, earliest = LONG_MAX;
    for (int j = 0; j < n; j++) {
      if (timer[j] < earliest) {
        earliest = timer[j];
        earliest_room = j;
      }
      if (timer[j] <= start) {
        room = i;
        break;
      }
    }
    if (room != -1) {
      timer[room] = end;
      cnt[room]++;
    } else {
      timer[earliest_room] += duration;
      cnt[earliest_room]++;
    }
    i++;
  }
  int max = 0, idx = 0;
  for (int j = 0; j < n; j++)
    if (cnt[j] > max) {
      max = cnt[j];
      idx = j;
    }
  free(cnt);
  free(timer);
  return idx;
}

int main() {
  int m1i[5][2] = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
  int m2i[5][2] = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  printf("%d\n",
         mostBooked(2, m1->arr, m1->row_size, m1->col_size)); // expect: 0
  printf("%d\n",
         mostBooked(3, m2->arr, m2->row_size, m2->col_size)); // expect: 1
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
