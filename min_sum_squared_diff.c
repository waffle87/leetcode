// 2333. Minimum Sum of Squared Difference
#include "leetcode.h"

/*
 * you are given two positive 0-indexed integer arrays 'nums1' and 'nums2', both
 * of length 'n'. the sum of square difference of arrays is defined as the sum
 * of '(nums1[i] - nums2[i])^2' for each '0 <= i < n'. you are also given two
 * positive integers 'k1' and 'k2'. you can modify any of the lements of 'nums1'
 * by +1 or -1 at most 'k1' times. Similarly such for 'k2' and 'nums2'. return
 * the minimum sum o squared difference after modifiying array 'nums1' at most
 * 'k1' times and modifying array 'nums2' at most 'k2' times.
 */

long long minSumSquareDiff(int *nums1, int nums1Size, int *nums2, int nums2Size,
                           int k1, int k2) {
  long long k = (long long)k1 + k2, total = 0;
  int n = nums1Size, m = 0;
  int *diff = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    int d = abs(nums1[i] - nums2[i]);
    diff[i] = d;
    total += d;
    m = fmax(m, d);
  }
  if (total <= k) {
    free(diff);
    return 0;
  }
  long long *cnt = (long long *)calloc(m + 1, sizeof(int));
  for (int i = 0; i < n; i++)
    cnt[diff[i]]++;
  for (int v = m; v > 0 && k > 0; v--) {
    long long c = cnt[v];
    if (!c)
      continue;
    if (k >= c) {
      cnt[v] = 0;
      cnt[v - 1] += c;
      k -= c;
    } else {
      cnt[v] -= k;
      cnt[v - 1] += k;
      k = 0;
    }
  }
  long long ans = 0;
  for (int v = 0; v <= m; v++)
    ans += cnt[v] * (long long)v * v;
  free(cnt);
  free(diff);
  return ans;
}

int main() {
  int n11[] = {1, 2, 3, 4}, n21[] = {2, 10, 20, 19};
  int n12[] = {1, 4, 10, 12}, n22[] = {5, 8, 6, 9};
  long long r1 =
      minSumSquareDiff(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21), 0, 0);
  long long r2 =
      minSumSquareDiff(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22), 1, 1);
  printf("%lld\n", r1);
  assert(r1 == 579);
  printf("%lld\n", r2);
  assert(r2 == 43);
}
