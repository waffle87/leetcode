// 1207. Unique Number of Occurrences
#include "leetcode.h"

/*
 * given an array of integers 'arr', return 'true' if the number of occurences
 * of each value in the array is unique or 'false' otherwise
 */

int cmp(const void *a, const void *b) {
  return *(const int *)b - *(const int *)a;
}

int find_size(int *arr, int arr_size, int *min) {
  int max = arr[0];
  for (int i = 1; i < arr_size; i++) {
    max = arr[i] > max ? arr[i] : max;
    *min = arr[i] < *min ? arr[i] : *min;
  }
  return *min < 0 ? max + abs(*min) + 1 : max + 1;
}

bool uniqueOccurences(int *arr, int arr_size) {
  int shift = arr[0], size = find_size(arr, arr_size, &shift);
  shift = (shift > 0) ? 0 : abs(shift);
  int *hash = (int *)calloc(size, sizeof(int));
  for (int i = 0; i < arr_size; i++)
    hash[arr[i] + shift]++;
  qsort(hash, size, sizeof(int), cmp);
  for (int i = 0; i + 1 < size; i++) {
    if (!hash[i + 1])
      break;
    if (hash[i] == hash[i + 1]) {
      free(hash);
      return false;
    }
  }
  free(hash);
  return true;
}

int main() {
  int a1[] = {1, 2, 2, 1, 1, 3}, a2[] = {1, 2},
      a3[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
  printf("%d\n", uniqueOccurences(a1, ARRAY_SIZE(a1))); // expect: 1
  printf("%d\n", uniqueOccurences(a2, ARRAY_SIZE(a2))); // expect: 0
  printf("%d\n", uniqueOccurences(a3, ARRAY_SIZE(a3))); // expect: 1
}
