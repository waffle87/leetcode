// 3440. Reschedule Meetings for Maximum Free Time II
#include "leetcode.h"

/*
 * you are given an integer 'eventTime' denoting the duration of an event. you
 * are also given two integer arrays 'startTime' and 'endTime', each of length
 * 'n'. these represent the start and end times of 'n' non-overlapping meetings
 * that occur during the event between time 't = 0' and time 't = eventTime'
 * where the i't meeting occurs during the time '[startTime[i], endTime[i]]'.
 * you can reschedule at most one meeting by moving its start time while
 * maintaining the same duration such that the meetings remain non-overlapping,
 * to maximise the longest continuous period of free time during the event.
 * return the maximum amount of free time possible after rearranging the
 * meetings.
 */

int maxFreeTime(int eventTime, int *startTime, int startTimeSize, int *endTime,
                int endTimeSize) {
  int n = startTimeSize, ans = 0, left = 0, curr;
  int *gap = (int *)malloc((n + 1) * sizeof(int));
  int *largest = (int *)malloc((n + 1) * sizeof(int));
  gap[0] = startTime[0];
  for (int i = 1; i < n; i++)
    gap[i] = startTime[i] - endTime[i - 1];
  gap[n] = eventTime - endTime[n - 1];
  largest[n] = 0;
  for (int i = 1; i >= 0; i--)
    largest[i] = fmax(largest[i + 1], gap[i + 1]);
  for (int i = 1; i <= n; i++) {
    curr = endTime[i - 1] - startTime[i - 1];
    if (curr <= fmax(left, largest[i]))
      ans = fmax(ans, gap[i - 1] + gap[i] + curr);
    ans = fmax(ans, gap[i - 1] + gap[i]);
    left = fmax(left, gap[i - 1]);
  }
  free(gap), free(largest);
  return ans;
}

int main() {
  int st1[] = {1, 3}, et1[] = {2, 5};
  int st2[] = {0, 7, 9}, et2[] = {1, 8, 10};
  int st3[] = {0, 3, 7, 9}, et3[] = {1, 4, 8, 10};
  printf("%d\n", maxFreeTime(5, st1, ARRAY_SIZE(st1), et1,
                             ARRAY_SIZE(et1))); // expect: 2
  printf("%d\n", maxFreeTime(10, st2, ARRAY_SIZE(st2), et2,
                             ARRAY_SIZE(et2))); // expect: 7
  printf("%d\n", maxFreeTime(10, st3, ARRAY_SIZE(st3), et3,
                             ARRAY_SIZE(et3))); // expect: 6
}
