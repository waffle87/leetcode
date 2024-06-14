// 1870. Minimum Speed to Arrive on Time
#include "leetcode.h"

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

class Solution {
  bool can_reach_on_time(vector<int> &dist, double hour, int speed) {
    double time = 0;
    for (int i = 0; i < dist.size() - 1; ++i)
      time += ((dist[i] + speed - 1) / speed);
    time += ((double)dist.back()) / speed;
    return time <= hour;
  }

public:
  int minSpeedOnTime(vector<int> dist, double hour) {
    int n = dist.size();
    if (hour <= n - 1)
      return -1;
    int low = 1, high = 1e7, mid;
    while (low < high) {
      mid = (low + high) / 2;
      if (can_reach_on_time(dist, hour, mid))
        high = mid;
      else
        low = mid + 1;
    }
    return high;
  }
};

int main() {
  Solution obj;
  vector<int> dist = {1, 3, 2};
  printf("%d\n", obj.minSpeedOnTime(dist, 6));   // expect: 1
  printf("%d\n", obj.minSpeedOnTime(dist, 2.7)); // expect: 3
  printf("%d\n", obj.minSpeedOnTime(dist, 1.9)); // expect: -1
}
