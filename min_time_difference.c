// 539. Minimum Time Difference
#include "leetcode.h"

/*
 * given a list of 24 hour clock time points in 'HH:MM' format, return the
 * minimum minutes difference between any two time points in the list
 */

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int findMinDifference(char **timePoints, int timePointsSize) {
  int *minutes = (int *)malloc(timePointsSize * sizeof(int));
  for (int i = 0; i < timePointsSize; i++) {
    minutes[i] = (timePoints[i][0] - '0') * 10 * 60 +
                 (timePoints[i][1] - '0') * 60 + (timePoints[i][3] - '0') * 10 +
                 (timePoints[i][4] - '0');
  }
  qsort(minutes, timePointsSize, sizeof(int), cmp);
  int ans = INT_MAX;
  for (int i = 0; i < timePointsSize - 1; i++)
    ans = fmin(ans, minutes[i + 1] - minutes[i]);
  ans = fmin(ans, (24 * 60 - minutes[timePointsSize - 1]) + minutes[0]);
  free(minutes);
  return ans;
}

int main() {
  char *tp1[] = {"23:59", "00:00"}, *tp2[] = {"00:00", "23:59", "00:00"};
  printf("%d\n", findMinDifference((char **)tp1, ARRAY_SIZE(tp1))); // expect: 1
  printf("%d\n", findMinDifference((char **)tp2, ARRAY_SIZE(tp2))); // expect: 0
}
