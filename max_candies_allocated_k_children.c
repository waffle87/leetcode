// 2226. Maximum Candies Allocated to K Children
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'candies'. each element in the array
 * denotes a pile of candies of size 'candies[i]'. you can divide each pile into
 * any number of sub piles, but you cannot merge two piles together. you are
 * also given an integer 'k'. you should allocate piles of candies to 'k'
 * children such that each child gets the same number of candies. each child can
 * be allocated candies from only one pile of candies, and some piles of candies
 * may go unused. return the maximum number of candies each child can get
 */

int maximumCandies(int *candies, int candiesSize, long long k) {
  int l = 0, r = 1e7;
  while (l < r) {
    long long mid = (l + r + 1) / 2, cnt = 0;
    for (int i = 0; i < candiesSize && cnt < k; ++i)
      cnt += candies[i] / mid;
    if (cnt >= k)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  int c1[] = {5, 8, 6}, c2[] = {2, 5};
  printf("%d\n", maximumCandies(c1, ARRAY_SIZE(c1), 3));  // expect: 5
  printf("%d\n", maximumCandies(c2, ARRAY_SIZE(c2), 11)); // expect: 0
}
