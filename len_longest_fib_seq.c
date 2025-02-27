// 873. Length of Longest Fibonacci Subsequence
#include "leetcode.h"

/*
 * a sequence 'x1, x2, ..., xn' is fibonacci like if 'n >= 3' and 'x_i + x_i + 1
 * == x_i + 2' for all 'i + 2 <= n'. given a strictly increasing 'arr' of
 * positive integers forming a sequence, return the length of the longest
 * fibonacci like subsequence of 'arr'. if one does not exist, return 0. a
 * subsequence is derived from another sequence 'arr' by deleting any number of
 * elements (including none) from 'arr', without changing the order of the
 * remaining elements.
 */

static int a_max;

int helper(int *arr, int *map, int i, int j, int sum) {
  int cnt = 0;
  while (sum <= a_max) {
    if (!map[sum])
      break;
    cnt++;
    i = j;
    j = map[sum] - 1;
    sum = arr[i] + arr[j];
  }
  return cnt;
}

int lenLongestFibSubseq(int *arr, int arrSize) {
  a_max = arr[arrSize - 1];
  int map_size = a_max + 1;
  int *map = (int *)calloc(map_size, sizeof(int));
  int cnt = 0, i, j, sum, tmp;
  for (int i = 0; i < arrSize; i++)
    map[arr[i]] = i + 1;
  for (int i = 0; i < arrSize; i++) {
    for (int j = i + 1; j < arrSize; j++) {
      sum = arr[i] + arr[j];
      if (sum > a_max)
        break;
      if (!map[sum])
        continue;
      tmp = helper(arr, map, i, j, sum);
      cnt = fmax(cnt, tmp);
    }
  }
  cnt += 2;
  free(map);
  return cnt > 2 ? cnt : 0;
}

int main() {
  int a1[] = {1, 2, 3, 4, 5, 6, 7, 8}, a2[] = {1, 3, 7, 11, 12, 14, 18};
  printf("%d\n", lenLongestFibSubseq(a1, ARRAY_SIZE(a1))); // expect: 5
  printf("%d\n", lenLongestFibSubseq(a2, ARRAY_SIZE(a2))); // expect: 3
}
