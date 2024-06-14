// 1326. Minimum Number of Taps to Open to Water a Garden
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * there is a one-dimensional garden on the x-axis. the garden starts at the
 * point 0 and ends at the point 'n'. (ie. the length of the garden is 'n')
 * there are 'n +  q' taps located at points '[0, 1, ..., n]' in the garden.
 * given an integer 'n' and an integer array 'ranges' of length 'n + 1' where
 * 'ranges[i]' (0-indexed) means the i'th tap can water the area '[i -
 * ranges[i], i + ranges[i]]' if it was open. return the minimum number of taps
 * that should be open to water the whole garden. if the garden cannot be
 * watered, return -1
 */

int minTaps(int n, int *ranges, int ranges_size) {
  int i, j;
  int *new_ranges = (int *)malloc(sizeof(int) * ranges_size);
  for (i = 0; i < ranges_size; i++)
    new_ranges[i] = ranges[i];
  for (i = ranges_size - 1; i >= 1; i--)
    for (j = 1; j <= ranges[i]; j++) {
      if (i - j == -1)
        break;
      new_ranges[i - j] = fmax(new_ranges[i - j], j + ranges[i]);
    }
  int min_jump;
  int *dp = (int *)malloc(sizeof(int) * ranges_size);
  dp[ranges_size - 1] = 0;
  for (i = 0; i < ranges_size - 1; i++)
    dp[i] = 999999;
  for (i = ranges_size - 2; i >= 0; i--) {
    min_jump = 999999;
    for (j = 1; j <= ranges[i]; j++) {
      if (i + j == ranges_size)
        break;
      min_jump = fmin(min_jump, dp[i + j]);
    }
    dp[i] = min_jump + 1;
  }
  return (dp[0] < 999999) ? dp[0] : -1;
}

int main() {
  int r1[] = {3, 4, 1, 1, 0, 0}, r2[] = {0, 0, 0, 0};
  printf("%d\n", 1);                 // expect: 1
  printf("%d\n", minTaps(3, r2, 4)); // expect: -1
}
