// 1331. Rank Transform of an Array
#include "leetcode.h"

/*
 * given an array of integers 'arr', replace each element with its rank. the
 * rank reprsents how large the element is. the rank has the following rules.
 * rank is an integer starting from 1. the larger the element, the larger the
 * rank. if two elements are equal, their rank must be the same. rank should be
 * as small as possible.
 */

int cmp(const void *a, const void *b) {
  int *x = (int *)a, *y = (int *)b;
  return *x - *y;
}

int search(int *a, int size, int v) {
  int l = 0, r = size;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (a[m] == v)
      return m;
    else if (a[m] > v)
      r = m;
    else
      l = m;
  }
  return -1;
}

int *arrayRankTransform(int *arr, int arrSize, int *returnSize) {
  *returnSize = arrSize;
  int *ans = (int *)malloc(arrSize * sizeof(int));
  if (!arrSize)
    return ans;
  int vals[arrSize], ranks[arrSize];
  memcpy(vals, arr, sizeof(vals));
  qsort(vals, arrSize, sizeof(int), cmp);
  for (int i = 1; i < arrSize; i++)
    ranks[i] = vals[i] == vals[i - 1] ? ranks[i - 1] : ranks[i - 1] + 1;
  for (int i = 0; i < arrSize; i++) {
    int j = search(vals, arrSize, arr[i]);
    ans[i] = ranks[j];
  }
  return ans;
}

int main() {
  int a1[] = {40, 10, 20, 30}, a2[] = {100, 100, 100},
      a3[] = {37, 12, 28, 9, 100, 56, 80, 5, 12}, rs1, rs2, rs3;
  int *art1 = arrayRankTransform(a1, ARRAY_SIZE(a1), &rs1);
  int *art2 = arrayRankTransform(a2, ARRAY_SIZE(a2), &rs2);
  int *art3 = arrayRankTransform(a3, ARRAY_SIZE(a3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", art1[i]); // expect: 4 1 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", art2[i]); // expect: 1 1 1
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", art3[i]); // expect: 5 3 4 2 8 6 7 1 3
  printf("\n");
  free(art1), free(art2), free(art3);
}
