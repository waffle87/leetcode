// 3296. Minimum Number of Seconds to Make Mountain Height Zero
#include "leetcode.h"

/*
 * you are given an integer 'mountainHeight' denoting the height of a mountain.
 * you are also given an integer array 'workerTimes' representing the work time
 * of workers in seconds. the workers simultaneously work to reduce the height
 * of a mountain. return an integer representing the minimum number of seconds
 * required foor the workers to make the height of the mountain 0.
 */

long long max_height(long long time, int worker_time) {
  long long left = 0, right = 2e9, res = 0;
  while (left <= right) {
    long long mid = left + (right - left) / 2;
    long long val = mid * (mid + 1) / 2;
    if (worker_time > 0 && val > LLONG_MAX / worker_time) {
      right = mid - 1;
      continue;
    }
    long long required = worker_time * val;
    if (required <= time) {
      res = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  return res;
}

bool can_reduce_zero(long long total_time, int *worker_times, int n,
                     int height) {
  long long total = 0;
  for (int i = 0; i < n; i++)
    total += max_height(total, worker_times[i]);
  return total >= height;
}

long long minNumberOfSeconds(int mountainHeight, int *workerTimes,
                             int workerTimesSize) {
  long long left = 0, right = 1e18, ans = right;
  while (left <= right) {
    long long mid = left + (right - left) / 2;
    if (can_reduce_zero(mid, workerTimes, workerTimesSize, mountainHeight)) {
      ans = mid;
      right = mid - 1;
    } else
      left = mid + 1;
  }
  return ans;
}

int main() {
  int wt1[] = {2, 1, 1}, wt2[] = {3, 2, 2, 4}, wt3[] = {2};
  long long r1 = minNumberOfSeconds(4, wt1, ARRAY_SIZE(wt1));
  long long r2 = minNumberOfSeconds(10, wt2, ARRAY_SIZE(wt2));
  long long r3 = minNumberOfSeconds(5, wt3, ARRAY_SIZE(wt3));
  printf("%lld\n", r1); // expect: 3
  assert(r1 == 3);
  printf("%lld\n", r2); // expect: 12
  assert(r2 == 12);
  printf("%lld\n", r3); // expect: 15
  assert(r3 == 15);
}
