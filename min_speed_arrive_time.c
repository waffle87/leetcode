// 1870. Minimum Speed to Arrive on Time
#include <math.h>
#include <stdio.h>

/*
 * given a floating point number 'hour', representing the amount of time you
 * have to reach the office. to commute to the office, you must take 'n' trains
 * in sequential order. you are also given an integer array 'dist' of length 'n'
 * where 'dist[i]' describes the distance in kilometres of the i'th train ride.
 * each train can only depart at an integer hour, so you may need to wait in
 * between each ride. return the minimum number speed in km/h that all the
 * trains must travel at for you to reach the office on time, or '-1' if it is
 * possible to be on time.
 */

double hours(int *dist, int dist_size, double hour) {
  double res = 0;
  for (int i = 0; i < dist_size - 1; i++)
    res += ceil(1.0 * dist[i] / hour);
  res += (((double)dist[dist_size - 1]) / hour);
  return res;
}

int minSpeedOnTime(int *dist, int dist_size, double hour) {
  if (hour <= dist_size - 1)
    return -1;
  int left = 1, right = 1e7, mid, ans;
  while (left < right) {
    mid = (left + right) / 2;
    if (hours(dist, dist_size, mid) <= hour) {
      right = mid;
      ans = mid;
    } else
      left = mid + 1;
  }
  return ans;
}

int main() {
  int dist[] = {1, 3, 2}, dist_size = 3;
  printf("%d\n", minSpeedOnTime(dist, dist_size, 6));   // expect: 1
  printf("%d\n", minSpeedOnTime(dist, dist_size, 2.7)); // expect: 6
  printf("%d\n", minSpeedOnTime(dist, dist_size, 1.9)); // expect: -1
}
