// 1481. Least Number of Unique Integers after K Removals
#include "leetcode.h"

/*
 * given an array of integers 'arr' and an integer 'k', find the least number of
 * unique integers after removing exactly 'k' elements.
 */

int cmp(const void *a, const void *b) {
  return *(const int *)a > *(const int *)b;
}

int findLeastNumOfUniqueInts(int *arr, int arr_size, int k) {
  qsort(arr, arr_size, sizeof(int), cmp);
  int idx = 0, cnt = 0, ans = 0;
  int *tmp = (int *)malloc(arr_size * sizeof(int));
  for (int i = 0; i < arr_size; i++) {
    int j = i;
    while (j < arr_size && arr[j] == arr[i])
      cnt++, j++;
    tmp[idx++] = cnt;
    i = j - 1;
    cnt = 0;
  }
  qsort(tmp, idx, sizeof(int), cmp);
  for (int i = 0; i < idx; i++) {
    ans += tmp[i];
    if (ans >= k) {
      ans = (ans == k) ? idx - i - 1 : idx - i;
      break;
    }
  }
  free(tmp);
  return ans;
}

int main() {
  int a1[] = {5, 5, 4}, a2[] = {4, 3, 1, 1, 3, 3, 2};
  printf("%d\n", findLeastNumOfUniqueInts(a1, ARRAY_SIZE(a1), 1)); // expect: 1
  printf("%d\n", findLeastNumOfUniqueInts(a2, ARRAY_SIZE(a2), 3)); // expect: 2
}
