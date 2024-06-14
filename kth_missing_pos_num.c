// 1539. Kth Missing Positive Number
#include <stdio.h>

/*
 * given array 'arr' of positive integers sorted in a strictly increasing order,
 * and an integer 'k', return 'kth' positive integer missing from array -- o(log
 * n)
 */

int findKthPositive(int *arr, int arr_size, int k) {
  int l = 0, r = arr_size, m;
  while (l < r) {
    m = (l + r) / 2;
    if (arr[m] - 1 - m < k)
      l = m + 1;
    else
      r = m;
  }
  return l + k;
}

int main() {
  int a1[] = {2, 3, 4, 7, 11}, a2[] = {1, 2, 3, 4};
  printf("%d\n", findKthPositive(a1, 5, 5)); // expect: 9
  printf("%d\n", findKthPositive(a2, 2, 4)); // expect: 6
}
