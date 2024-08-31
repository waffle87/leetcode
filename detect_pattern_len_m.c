// 1566. Detect Pattern of Length M Repeated K or More Times
#include "leetcode.h"

/*
 * given an array of positive integers 'arr', find a pattern of length 'm' that
 * is repeated 'k' or more times. a pattern is a subarray (consecutive
 * subsequence) that consists of one or more values repeated multiple times
 * consecutively without overlapping. a pattern is defined by its length and the
 * number of repetitions. return true if there exists a pattern of length 'm'
 * that is repeated 'k' or more times, otherwise return false
 */

static inline int get_fnv(int *arr, int arrSize) {
  int FNV_32_INIT = 0xCAFEEE, FNV_32_PRIME = 0x721;
  if (!arr)
    return 0;
  int64_t hash = FNV_32_INIT;
  for (int d = 0; d < arrSize; d++) {
    hash ^= arr[d];
    hash = (hash * FNV_32_PRIME) & 0xFFFFFFFF;
  }
  return (int)hash;
}

bool containsPattern(int *arr, int arrSize, int m, int k) {
  int n[m], prev = 0, hash = 0, cnt = 0, cnt_max = 0;
  for (int u = 0; u <= arrSize; u++) {
    cnt = 1, prev = 0, hash = 0;
    for (int i = u; i <= arrSize - m; i += m)
      for (int j = i; j < m + i; j++)
        n[j - i] = arr[j];
    prev = hash;
    hash = get_fnv(n, m);
    if (hash == prev)
      cnt++;
    else
      cnt = 1;
    if (cnt >= k)
      return true;
  }
  return false;
}

int main() {
  int a1[] = {1, 2, 4, 4, 4, 4}, a2[] = {1, 2, 1, 2, 1, 1, 1, 3},
      a3[] = {1, 2, 1, 2, 1, 3};
  printf("%d\n", containsPattern(a1, ARRAY_SIZE(a1), 1, 3)); // expect: 1
  printf("%d\n", containsPattern(a2, ARRAY_SIZE(a2), 2, 2)); // expect: 1
  printf("%d\n", containsPattern(a3, ARRAY_SIZE(a3), 2, 3)); // expect: 0
}
