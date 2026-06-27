// 3020. Find the Maximum Number of Elements in Subset
#include "leetcode.h"

/*
 * you are given an array of positive integers 'nums'. you need to select a
 * subset of 'nums' which satisfies the following condition: you can place the
 * selected elements in a 0-indexed array such that it follows the pattern '[x,
 * x2, x4, ..., k k/2]'. return the maximum nnumber of elements in a subset that
 * satisfies these conditions.
 */

int cmp(const void *a, const void *b) {
  int aa = *(int *)a, bb = *(int *)b;
  return (aa > bb) - (aa < bb);
}

int lower_bound(int *nums, int n, long long target) {
  int l = 0, r = n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if ((long long)nums[mid] < target)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

int get_cnt(int *nums, int n, long long target) {
  int left = lower_bound(nums, n, target);
  int right = lower_bound(nums, n, target + 1);
  return right - left;
}

bool exists(int *nums, int n, long long target) {
  int pos = lower_bound(nums, n, target);
  return pos < n && (long long)nums[pos] == target;
}

int maximumLength(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = 0;
  for (int i = 0; i < numsSize; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    long long key = nums[i];
    int total = 0;
    if (key == 1) {
      int cnt = get_cnt(nums, numsSize, 1);
      total = (cnt % 2 == 1) ? cnt : cnt - 1;
    } else {
      while (get_cnt(nums, numsSize, key) >= 2 && key <= LLONG_MAX / key &&
             exists(nums, numsSize, key * key)) {
        total += 2;
        key *= key;
      }
      total++;
    }
    ans = fmax(ans, total);
  }
  return ans;
}

int main() {
  int n1[] = {5, 4, 1, 2, 2};
  int n2[] = {1, 3, 2, 4};
  int r1 = maximumLength(n1, ARRAY_SIZE(n1));
  int r2 = maximumLength(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 1);
}
