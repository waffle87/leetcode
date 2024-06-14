// 1124. Longest Well-Performing Interval
#include "leetcode.h"

/*
 * given 'hours', a list of number of hours worked per day for a given employee.
 * a day is considered to be a tiring day if and only if the number of hours
 * worked is strictly greater than 8. a well performing interval is an interval
 * of days for which the number of tiring days is strictly larger than the
 * number of non tiring days. return the length of the longest well performing
 * interval
 */

int longestWPI(int *hours, int hours_size) {
  int cnt[10001] = {0}, t = 0, max = 0;
  for (int i = 0; i <= hours_size; i++)
    cnt[i] -= 1;
  for (int i = 0; i < hours_size; i++) {
    if (hours[i] > 8)
      t++;
    else
      t--;
    if (t < 0 && cnt[abs(t - 1)] >= 0 && i - cnt[abs(t - 1)] > max)
      max = i - cnt[abs(t - 1)];
  }
  return max;
}

int main() {
  int h1[] = {9, 9, 6, 0, 6, 6, 9}, h2[] = {6, 6, 6};
  printf("%d\n", longestWPI(h1, ARRAY_SIZE(h1))); // expect: 3
  printf("%d\n", longestWPI(h2, ARRAY_SIZE(h2))); // expect: 0
}
