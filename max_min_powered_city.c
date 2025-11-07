// 2528. Maximize the Minimum Powered City
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'stations' of length 'n' where
 * 'stations[i]' represents the number of power stations in the i'th city. each
 * power station can provide every city in a fixed rang.e in other words, if the
 * range is denoted by 'r', then a power station at city 'i' can provide power
 * to all cities 'j' such that '|i - j| <= r' and '0 <= i, j <= n - 1'. the
 * power of a city is the total number of actions being provided power from. the
 * government has sanctioned building 'k' more power stations, each of which can
 * be built in any cit, and have the same range as the pre-existing one. given
 * the two integers 'r' and 'k', return the maximum possible minimum power of a
 * city, if the additional power stations are build optimally.
 */

static bool possible(long long x, int *stations, long long *power, int n, int r,
                     long long k) {
  long long *diff = (long long *)calloc(n + 1, sizeof(long long)), added = 0;
  for (int i = 0; i < n; i++) {
    added += diff[i];
    long long curr = power[i] + added;
    if (curr < x) {
      long long need = x - curr;
      if (need > k) {
        free(diff);
        return false;
      }
      k -= need;
      added += need;
      int end = i + 2 * r + 1;
      if (end < n)
        diff[end] -= need;
    }
  }
  free(diff);
  return true;
}

long long maxPower(int *stations, int stationsSize, int r, int k) {
  long long *prefix = (long long *)calloc(stationsSize + 1, sizeof(long long));
  long long *power = (long long *)malloc(stationsSize * sizeof(long long));
  for (int i = 0; i < stationsSize; i++)
    prefix[i + 1] = prefix[i] + stations[i];
  for (int i = 0; i < stationsSize; i++) {
    int left = (i - r < 0) ? 0 : i - r;
    int right = (i + r >= stationsSize) ? stationsSize - 1 : i + r;
    power[i] = prefix[right + 1] - prefix[left];
  }
  long long low = 0, high = prefix[stationsSize] + k, ans = 0;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    if (possible(mid, stations, power, stationsSize, r, k)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  free(prefix);
  free(power);
  return ans;
}

int main() {
  int s1[] = {1, 2, 4, 5, 0}, s2[] = {4, 4, 4, 4};
  printf("%lld\n", maxPower(s1, ARRAY_SIZE(s1), 1, 2)); // expect: 5
  printf("%lld\n", maxPower(s2, ARRAY_SIZE(s2), 0, 3)); // expect: 4
}
