// 2187. Minimum Time to Complete Trips
#include <limits.h>
#include <stdio.h>

/*
 * given array 'time' where 'time[i]' denotes the time taken by the 'i'th bus to
 * complete one trip. each bus can make multiple trips successively; that is,
 * the next trip can start immediately after completing the current trip. also,
 * each bus operates independently; that is, the trips of one bus do not
 * influence the trips of any other bus. also given an integer 'totalTrips',
 * which denotes the number of trips all buses should make in total. return the
 * minimum time required to complete all trips.
 */

long long minimumTime(int *time, int time_size, int total_trips) {
  long long l = 0, r = LLONG_MAX / time_size;
  while (l < r) {
    long long m = (l + r) / 2, trips = 0;
    for (int i = 0; i < time_size; i++)
      trips += m / time[i];
    if (trips < total_trips)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int main() {
  int t1[] = {1, 2, 3}, t2[] = {2};
  printf("%lld\n", minimumTime(t1, 3, 5)); // expect: 3
  printf("%lld\n", minimumTime(t2, 1, 1)); // expect: 2
}
