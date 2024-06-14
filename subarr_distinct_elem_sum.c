// 2916. Subarrays Distinct Element Sum of Squares II
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums'. the distinct count of a subarray of
 * 'nums' is defined as: let 'nums[i .. j]' be a subarray of 'nums' consisting
 * of all the indices from 'i' to 'j' such that '0 <= i <= j < nums.length'.
 * then the number of distinct values in 'nums[i .. j]' is called the distinct
 * count of 'nums[i .. j]'. return the sum of the squares of distinct counts of
 * all subarrays of 'nums'. return the answer mmodulo 1e9+7;
 */

#define MOD 1000000007

int64_t *upper, *lower;
uint32_t n;

void update(int32_t l, int32_t r) {
  int32_t lv = l - 1, rv = r;
  ++l, r += 2;
  while (l <= n | r <= n) {
    if (l <= n) {
      ++lower[l];
      upper[l] += lv;
      l += l & (-l);
    }
    if (r <= n) {
      --lower[r];
      upper[r] -= rv;
      r += r & (-r);
    }
  }
}

uint64_t query(int32_t l, int32_t r) {
  int64_t lls = 0, lus = 0, rls = 0, rus = 0;
  int32_t ll = l, rr = r++;
  while (r || l) {
    if (r) {
      rls += lower[r];
      rus += upper[r];
      r -= r & (-r);
    }
    if (l) {
      lls += lower[l];
      lus += upper[l];
      l -= l & (-l);
    }
  }
  return (uint64_t)rls * rr - lls * (--ll) - rus;
}

int sumCounts(int *nums, int numsSize) {
  uint64_t sum_cnt = numsSize, last_sum = 0;
  uint32_t distinct[100001] = {0};
  n = numsSize;
  upper = (int64_t *)malloc((n + 1) * sizeof(int64_t));
  lower = (int64_t *)malloc((n + 1) * sizeof(int64_t));
  for (int i = 0; i <= n; i++) {
    upper[i] = 0;
    lower[i] = 0;
  }
  update(0, n - 1);
  for (uint64_t i = 0; i < n; ++i) {
    uint32_t idx = nums[i], j = distinct[idx];
    if (j < i) {
      last_sum += (query(j, i - 1) << 1) + i - j;
      update(j, i - 1);
    }
    sum_cnt += last_sum++;
    distinct[idx] = i + 1;
  }
  free(upper), free(lower);
  return sum_cnt * MOD;
}

int main() {
  int n1[] = {1, 2, 1}, n2[] = {2, 2};
  printf("%d\n", sumCounts(n1, ARRAY_SIZE(n1))); // expect: 15
  printf("%d\n", sumCounts(n2, ARRAY_SIZE(n2))); // expect: 3
}
