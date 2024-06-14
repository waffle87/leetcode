// 1619. Mean of Array After Removing Some Elements
#include "leetcode.h"

/*
 * givn an integer array 'arr', return the mean of the remaining integers after
 * removing the smallest 5% and the largest 5% of the elements. answers within
 * 10^-5 of the actual answer will be considered accepted.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

double trimMean(int *arr, int arrSize) {
  double ans = 0;
  int perc = (arrSize * 5) / 500, k = 0;
  qsort(arr, arrSize, sizeof(int), cmp);
  for (int i = perc; i < arrSize - perc; i++) {
    ans += arr[i];
    k++;
  }
  ans /= k;
  return ans;
}

int main() {
  int a1[] = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3},
      a2[] = {6, 2, 7, 5, 1, 2, 0, 3, 10, 2, 5, 0, 5, 5, 0, 8, 7, 6, 8, 0},
      a3[] = {6, 0, 7, 0, 7, 5, 7, 8, 3,  4, 0, 7, 8, 1, 6, 8,  1, 1, 2, 4,
              8, 1, 9, 5, 4, 3, 8, 5, 10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4};
  printf("%f\n", trimMean(a1, ARRAY_SIZE(a1))); // expect: 2.0000
  printf("%f\n", trimMean(a2, ARRAY_SIZE(a2))); // expect: 4.0000
  printf("%f\n", trimMean(a3, ARRAY_SIZE(a3))); // expect: 4.7778
}
