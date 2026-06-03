// 3633. Earliest Finish Time for Land and Water Rides I
#include "leetcode.h"

/*
 * you are given two categories of theme park attractions. land rides and water
 * rides. a tourist must experience exactly one ride from each category. return
 * the earliest possible time at which the tourist can finish both rides.
 */

int solve(int *start1, int n, int *duration1, int *start2, int m,
          int *duration2) {
  int finish1 = INT_MAX, finish2 = INT_MAX;
  for (int i = 0; i < n; i++)
    finish1 = fmin(finish1, start1[i] + duration1[i]);
  for (int i = 0; i < m; i++)
    finish2 = fmin(finish2, fmax(start2[i], finish1) + duration2[i]);
  return finish2;
}

int earliestFinishTime(int *landStartTime, int landStartTimeSize,
                       int *landDuration, int landDurationSize,
                       int *waterStartTime, int waterStartTimeSize,
                       int *waterDuration, int waterDurationSize) {
  int land_water = solve(landStartTime, landStartTimeSize, landDuration,
                         waterStartTime, waterStartTimeSize, waterDuration);
  int water_land = solve(waterStartTime, waterStartTimeSize, waterDuration,
                         landStartTime, landStartTimeSize, landDuration);
  return fmin(land_water, water_land);
}

int main() {
  int lst1[] = {2, 8}, ld1[] = {4, 1}, wst1[] = {6}, wd1[] = {3};
  int lst2[] = {5}, ld2[] = {3}, wst2[] = {1}, wd2[] = {10};
  int r1 = earliestFinishTime(lst1, ARRAY_SIZE(lst1), ld1, ARRAY_SIZE(ld1),
                              wst1, ARRAY_SIZE(wst1), wd1, ARRAY_SIZE(wd1));
  int r2 = earliestFinishTime(lst2, ARRAY_SIZE(lst2), ld2, ARRAY_SIZE(ld2),
                              wst2, ARRAY_SIZE(wst2), wd2, ARRAY_SIZE(wd2));
  printf("%d\n", r1);
  assert(r1 == 9);
  printf("%d\n", r2);
  assert(r2 == 14);
}
