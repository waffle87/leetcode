// 2594. Minimum Time to Repair Cars
#include "leetcode.h"

/*
 * you are given an integer array 'ranks' representing the ranks of some
 * mechanics. 'ranks[i]' is the rank of the i'th mechanic. a mechanic with a
 * rank 'r' can repair 'n' cars in 'r * n^2' minutes. you are also given an
 * integer 'cars' representing the total number of cars waiting in the garage to
 * be repaired. return the minimum time taken to repair all the cars. note: all
 * the mechanics can repair the cars simultaneously.
 */

long long repairCars(int *ranks, int ranksSize, int cars) {
  long long left = 0, right = 1e14;
  while (left < right) {
    long long mid = left + (right - left) / 2, cnt = 0;
    for (int i = 0; i < ranksSize; i++)
      cnt += sqrt(mid / ranks[i]);
    if (cnt < cars)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int main() {
  int r1[] = {4, 2, 3, 1}, r2[] = {5, 1, 8};
  printf("%lld\n", repairCars(r1, ARRAY_SIZE(r1), 10)); // expect: 16
  printf("%lld\n", repairCars(r2, ARRAY_SIZE(r2), 6));  // expect: 16
}
