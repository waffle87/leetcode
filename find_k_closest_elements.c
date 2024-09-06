// 658. Find K Closest Elements
#include "leetcode.h"

/*
 * given a sorted integer array 'arr', two integers 'k' and 'x', return the 'k'
 * closest integers to 'x' in the array. the result should also be sorted in
 * ascending order. an integer 'a' is closer to 'x' than an integer 'b' if '|a -
 * x| < |b - x|' or '|a - x| == |b - x|' and 'a < b'.
 */

int *findClosestElements(int *arr, int arrSize, int k, int x, int *returnSize) {
  int l = 0, r = arrSize - k;
  while (l < r) {
    int m = (l + r) / 2;
    if (x - arr[m] > arr[m + k] - x)
      l = m + 1;
    else
      r = m;
  }
  int *k_closest = (int *)calloc(k, sizeof(int));
  *returnSize = k;
  for (int i = 0; i < k; i++)
    k_closest[i] = arr[l++];
  return k_closest;
}

int main() {
  int a1[] = {1, 2, 3, 4, 5}, a2[] = {1, 2, 3, 4, 5}, rs1, rs2;
  int *fce1 = findClosestElements(a1, ARRAY_SIZE(a1), 4, 3, &rs1);
  int *fce2 = findClosestElements(a2, ARRAY_SIZE(a2), 4, -1, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fce1[i]); // expect: 1 2 3 4
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fce2[i]); // expect: 1 2 3 4
  printf("\n");
  free(fce1), free(fce2);
}
