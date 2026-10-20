// 3886. Sum of Sortable Integers
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n'. an integer 'k' is called
 * sortable if 'k' divides 'n' and you can sort 'nums' in non-decreasing order
 * by sequentially performing the following operations: partition 'nums' into
 * consectutive subarrays of length 'k', cyclically rotate each subarray
 * independently any number of times to the left or to the right. return an
 * integer denoting the sum of all possible sortable integers 'k'.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

bool check(int *a, int n, int *b, int m) {
  if (n != m)
    return false;
  int l = n;
  for (int i = 0; i < l - 1; i++) {
    if (a[i] > a[i + 1]) {
      int *rotated = (int *)malloc(l * sizeof(int));
      memcpy(rotated, a + i + 1, (l - i - 1) * sizeof(int));
      memcpy(rotated + l - i - 1, a, (i + 1) * sizeof(int));
      bool res = !memcmp(rotated, b, l * sizeof(int));
      free(rotated);
      return res;
    }
  }
  return !memcmp(a, b, l * sizeof(int));
}

int sortableIntegers(int *nums, int numsSize) {
  int n = numsSize, m = 0, ans = 0;
  int *fact = (int *)malloc(n * sizeof(int));
  for (int x = 1; x * x <= n; x++)
    if (!(n % x)) {
      fact[m++] = x;
      if (n / x != x)
        fact[m++] = n / x;
    }
  int *target = (int *)malloc(n * sizeof(int));
  memcpy(target, nums, n * sizeof(int));
  qsort(target, n, sizeof(int), cmp);
  for (int i = 0; i < m; i++) {
    int d = fact[i];
    bool good = true;
    for (int left = 0; left < n; left += d) {
      if (!check(nums + left, d, target + left, d)) {
        good = false;
        break;
      }
    }
    if (good)
      ans += d;
  }
  free(fact);
  free(target);
  return ans;
}

int main() {
  int n1[] = {3, 1, 2};
  int n2[] = {7, 6, 5};
  int n3[] = {5, 8};
  int r1 = sortableIntegers(n1, ARRAY_SIZE(n1));
  int r2 = sortableIntegers(n2, ARRAY_SIZE(n2));
  int r3 = sortableIntegers(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 3);
}
