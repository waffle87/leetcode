// 3439. Reschedule Meetings for Maximum Free Time I
#include "leetcode.h"

/*
 * you are given an integer 'eventTime' denoting the duration of an event, where
 * the event occurs from time 't = 0' to time 't = eventTime'. you are also
 * given two integer arrays 'startTime' and 'endTime' each of length 'n'. these
 * represent the start and end time of 'n' non-overlapping meetings where the
 * i'th meeting occurs during the time '[startTime[i], endTime[i]]'. you can
 * reschedule at most 'k' meetings by moving their start time while maintaining
 * the same duration, to maximise the longest continuous period of free time
 * during the event. the relative order of all the meetings should stay the same
 * and they should remain non-overlapping. return the maximum amount of free
 * time possible after rearranging the meetings. note that the meetings can not
 * be rescheduled to a time outside of the event.
 */

int maxFreeTime(int eventTime, int k, int *startTime, int startTimeSize,
                int *endTime, int endTimeSize) {
  int ans = 0, n = startTimeSize;
  int *gap = (int *)malloc((n + 1) * sizeof(int));
  int *pre = (int *)malloc((n + 2) * sizeof(int));
  gap[0] = startTime[0];
  for (int i = 1; i < n; i++)
    gap[i] = startTime[i] - endTime[i - 1];
  gap[n] = eventTime - endTime[n - 1];
  pre[0] = 0;
  for (int i = 1; i < n + 2; i++)
    pre[i] = pre[i - 1] + gap[i - 1];
  for (int i = k + 1; i < n + 2; i++)
    ans = fmax(ans, pre[i] - pre[i - k - 1]);
  free(pre), free(gap);
  return ans;
}

int main() {
  int st1[] = {1, 3}, et1[] = {2, 5};
  int st2[] = {0, 2, 9}, et2[] = {1, 4, 10};
  int st3[] = {0, 1, 2, 3, 4}, et3[] = {1, 2, 3, 4, 5};
  printf("%d\n", maxFreeTime(5, 1, st1, ARRAY_SIZE(st1), et1,
                             ARRAY_SIZE(et1))); // expect: 2
  printf("%d\n", maxFreeTime(10, 1, st2, ARRAY_SIZE(st2), et2,
                             ARRAY_SIZE(et2))); // expect: 6
  printf("%d\n", maxFreeTime(5, 2, st3, ARRAY_SIZE(st3), et3,
                             ARRAY_SIZE(et3))); // expect: 0
}
