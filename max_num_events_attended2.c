// 1751. Maximum Number of Events That Can Be Attended II
#include "leetcode.h"

/*
 * you are given an array of 'events' where 'events[i] = [startday_i, endday_i,
 * value_i]'. the i'th event starts at 'startday_i' and ends at 'endday_i', and
 * if you attend this event, you will receive a value of 'value_i'. you are also
 * given an integer 'k', which represents the maximum number of events you can
 * attend. you can only attend one event at a time. if you choose to attend an
 * event, you must attend the entire event. note that the end day is inclusive:
 * that is, you cannot attend two events where one of them starts and the other
 * ends on the same day. return the maximum sum of the values that you can
 * receive by attending events
 */

int cmp(const void *a, const void *b) {
  return (*(int **)a)[1] - (*(int **)b)[1];
}

int prev_event(int **events, int size, int deadline) {
  int start = 0, end = size - 1;
  while (start < end) {
    int mid = start + (end - start + 1) / 2, curr = events[mid][1];
    if (curr < deadline)
      start = mid;
    else
      end = mid - 1;
  }
  return events[start][1] < deadline ? start : -1;
}

int maxValue(int **events, int eventsSize, int *eventsColSize, int k) {
  qsort(events, eventsSize, sizeof(*events), cmp);
  int **vals = (int **)malloc((k + 1) * sizeof(int *));
  for (int i = 0; i < k + 1; i++)
    vals[i] = (int *)malloc(eventsSize * sizeof(int));
  int *prev = (int *)malloc(eventsSize * sizeof(int)), max = 0;
  for (int i = 0; i != k + 1; ++i) {
    for (int j = 0; j != eventsSize; ++j) {
      if (!i) {
        vals[i][j] = 0;
        prev[j] = prev_event(events, j, events[j][0]);
      } else {
        int prev_max = !j ? 0 : vals[i][j - 1];
        int curr = events[j][2] + (prev[j] >= 0 ? vals[i - 1][prev[j]] : 0);
        vals[i][j] = prev_max > curr ? prev_max : curr;
      }
    }
  }
  int ans = vals[k][eventsSize - 1];
  for (int i = 0; i < k + 1; i++)
    free(vals[i]);
  free(vals), free(prev);
  return ans;
}

int main() {
  int e1i[3][3] = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
  int e2i[3][3] = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
  int e3i[4][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  struct two_d_arr *e3 =
      two_d_arr_init(ARRAY_SIZE(e3i), ARRAY_SIZE(e3i[0]), e3i);
  printf("%d\n", maxValue(e1->arr, e1->row_size, e1->col_size, 2)); // expect: 7
  printf("%d\n",
         maxValue(e2->arr, e2->row_size, e2->col_size, 2)); // expect: 10
  printf("%d\n", maxValue(e3->arr, e3->row_size, e3->col_size, 3)); // expect: 9
  two_d_arr_free(e1);
  two_d_arr_free(e2);
  two_d_arr_free(e3);
}
