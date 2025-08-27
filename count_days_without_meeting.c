// 3169. Count Days Without Meetings
#include "leetcode.h"

/*
 * you are given a positive integer 'days' representing the total number of days
 * an employee is available for work (starting from day 1). you are given a 2d
 * integer array 'meetings' of size 'n' where 'meetings[i] = [start_i, end_i]'
 * represents the starting and ending days of meeting 'i' (inclusive). return
 * the count of days when the employee is available for work, but no meetings
 * are scheduled.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  return aa[0] == bb[0] ? aa[1] - bb[1] : aa[0] - bb[0];
}

int countDays(int days, int **meetings, int meetingsSize,
              int *meetingsColSize) {
  qsort(meetings, meetingsSize, sizeof(int *), cmp);
  int idx = 0, start = meetings[idx][0], end = meetings[idx++][1];
  while (idx < meetingsSize) {
    if (meetings[idx][0] > end) {
      days -= (end - start + 1);
      start = meetings[idx][0];
      end = meetings[idx][1];
    } else
      end = end > meetings[idx][1] ? end : meetings[idx][1];
    ++idx;
  }
  return days - (end - start + 1);
}

int main() {
  int m1i[3][2] = {{5, 7}, {1, 3}, {9, 10}}, m2i[2][2] = {{2, 4}, {1, 3}},
      m3i[1][2] = {{1, 6}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  struct two_d_arr *m3 =
      two_d_arr_init(ARRAY_SIZE(m3i), ARRAY_SIZE(m3i[0]), m3i);
  printf("%d\n",
         countDays(10, m1->arr, m1->row_size, m1->col_size)); // expect: 2
  printf("%d\n",
         countDays(5, m2->arr, m2->row_size, m2->col_size)); // expect: 1
  printf("%d\n",
         countDays(6, m3->arr, m3->row_size, m3->col_size)); // expect: 0
  two_d_arr_free(m1);
  two_d_arr_free(m2);
  two_d_arr_free(m3);
}
