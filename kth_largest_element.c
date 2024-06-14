// 215. Kth Largest Element in an Array
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'nums' and an integer 'k', return the k'th largest
 * element in the array. note that it is the k'th largest elemented in sorted
 * order, not the k'th distinct element. can you solve without sorting?
 */

int max(int *a, int n, int i, int j, int k) {
  int m = i;
  if (j < n && a[j] > a[m])
    m = j;
  if (k < n && a[k] > a[m])
    m = k;
  return m;
}

void down_heap(int *a, int n, int i) {
  while (1) {
    int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
    if (j == i)
      break;
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
    i = j;
  }
}

void heapsort(int *a, int n) {
  for (int i = (n - 2) / 2; i >= 0; i--)
    down_heap(a, n, i);
  for (int i = 0; i < n; i++) {
    int t = a[n - i - 1];
    a[n - i - 1] = a[0];
    a[0] = t;
    down_heap(a, n - i - 1, 0);
  }
}

int findKthLargest(int *nums, int nums_size, int k) {
  if (!nums_size || k > nums_size)
    return 0;
  heapsort(nums, nums_size);
  return nums[nums_size - k];
}

int main() {
  int n1[] = {3, 2, 1, 5, 6, 4}, n2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  printf("%d\n", findKthLargest(n1, 6, 2)); // expect: 5
  printf("%d\n", findKthLargest(n2, 9, 4)); // expect: 4
}
