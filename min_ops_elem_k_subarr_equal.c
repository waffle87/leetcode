// 3505. Minimum Operations to Make Elements Within K Subarrays Equal
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and two integers 'x' and 'k'. you can
 * perform the following operation any number of times (including zero):
 * increase or decrease any elements of 'nums' by 1. return the minimum number
 * of operations needed to have at least 'k' non-overlapping subarrays of size
 * exactly 'x' in 'nums', where all elements within each subarray are eqeual.
 */

static int cmp(const void *a, const void *b) {
  int aa = *(const int *)a;
  int bb = *(const int *)b;
  return (aa > bb) - (aa < bb);
}

static int lower_bound(int *a, int n, int v) {
  int l = 0, r = n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] < v)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

static void add(long long *cnt, long long *sum, int n, int p, int delta,
                int val) {
  for (; p <= n; p += p & -p) {
    cnt[p] += delta;
    sum[p] += (long long)delta * val;
  }
}

static void prefix(long long *cnt, long long *sum, int p, long long *c,
                   long long *s) {
  *c = *s = 0;
  for (; p > 0; p -= p & -p) {
    *c += cnt[p];
    *s += sum[p];
  }
}

static int kth(long long *cnt, int n, int rank) {
  int p = 0, step = 1;
  while (step <= n / 2)
    step <<= 1;
  for (; step; step >>= 1) {
    int np = p + step;
    if (np <= n && cnt[np] < rank) {
      rank -= (int)cnt[np];
      p = np;
    }
  }
  return p + 1;
}

long long minOperations(int *nums, int numsSize, int x, int k) {
  int n = numsSize, m = 0;
  ;
  if ((long long)x * k > n)
    return -1;
  int *vals = (int *)malloc(n * sizeof(int));
  memcpy(vals, nums, n * sizeof(int));
  qsort(vals, n, sizeof(int), cmp);
  for (int i = 0; i < n; i++)
    if (!m || vals[i] != vals[m - 1])
      vals[m++] = vals[i];
  long long *cnt = (long long *)calloc(m + 1, sizeof(long long));
  long long *sum = (long long *)calloc(m + 1, sizeof(long long));
  long long *ops = (long long *)calloc(n, sizeof(long long));
  long long total = 0;
  for (int i = 0; i < n; i++) {
    int p = lower_bound(vals, m, nums[i]) + 1;
    add(cnt, sum, m, p, 1, nums[i]);
    total += nums[i];
    if (i >= x) {
      int old = lower_bound(vals, m, nums[i - x]) + 1;
      add(cnt, sum, m, old, -1, nums[i - x]);
    }
    if (i >= x - 1) {
      int mid_pos = kth(cnt, m, (x + 1) / 2);
      long long mid = vals[mid_pos - 1];
      long long lc, ls;
      prefix(cnt, sum, mid_pos, &lc, &ls);
      long long rc = x - lc;
      long long rs = total - ls;
      ops[i] = mid * lc - ls + rs - mid * rc;
    }
  }
  long long *pre = (long long *)calloc(n + 1, sizeof(long long));
  long long *curr = (long long *)malloc((n + 1) * sizeof(long long));
  for (int j = 1; j <= k; j++) {
    for (int i = 0; i <= n; i++)
      curr[i] = LLONG_MAX;
    for (int i = j * x; i <= n; i++) {
      long long take = pre[i - x] + ops[i - 1];
      curr[i] = curr[i - 1] < take ? curr[i - 1] : take;
    }
    long long *tmp = pre;
    pre = curr;
    curr = tmp;
  }
  long long ans = pre[n];
  free(vals);
  free(cnt);
  free(sum);
  free(ops);
  free(pre);
  free(curr);
  return ans;
}

int main() {
  int n1[] = {5, -2, 1, 3, 7, 3, 6, 4, -1};
  int n2[] = {9, -2, -2, -2, 1, 5};
  long long r1 = minOperations(n1, ARRAY_SIZE(n1), 3, 2);
  long long r2 = minOperations(n2, ARRAY_SIZE(n2), 2, 2);
  printf("%lld\n", r1);
  assert(r1 == 8);
  printf("%lld\n", r2);
  assert(r2 == 3);
}
