// 1502. Can Make Arithmetic Progression From Sequence
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * a sequence of numbers is called an arithmetic progression if the difference
 * between any two consecutive elements is the same. gien an array of numbers
 * 'arr', return true if the array can rearranged to form an arithmetic
 * progression. otherwise, return false.
 */

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

bool canMakeArithmeticProgression(int *arr, int arr_size) {
  qsort(arr, arr_size, sizeof(int), cmp);
  int diff = arr[1] - arr[0];
  for (int i = 2; i < arr_size; i++)
    if (arr[i] - arr[i - 1] != diff)
      return false;
  return true;
}

int main() {
  int a1[] = {3, 5, 1}, a2[] = {1, 2, 4};
  printf("%d\n", canMakeArithmeticProgression(a1, 3)); // expect: 1
  printf("%d\n", canMakeArithmeticProgression(a2, 3)); // expect: 0
}
