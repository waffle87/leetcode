// 4. Median of Two Sorted Arrays
#include <stdio.h>
#include <stdlib.h>

/*
 * given two sorted arrays 'nums1' and 'nums2' of size 'm' and 'n', respectively
 * return the median of the two sorted arrays. the overall run time complexity
 * should be 'O(log(m + n))'
 */

double findMedianSortedArrays(int *nums1, int nums1_size, int *nums2,
                              int nums2_size) {
  int n = nums1_size + nums2_size, i, j, k, a;
  float f, nums3[n];
  i = j = k = 0;
  while (i < nums1_size && j < nums2_size) {
    if (nums1[i] < nums2[j])
      nums3[k++] = nums1[i++];
    else
      nums3[k++] = nums2[j++];
  }
  for (; i < nums1_size; i++)
    nums3[k++] = nums1[i];
  for (; j < nums2_size; j++)
    nums3[k++] = nums2[j];
  if (!(n % 2)) {
    a = n / 2;
    f = (nums3[a] + nums3[a - 1]) / 2;
    return f;
  } else {
    f = nums3[n / 2];
    return f;
  }
  return -1;
}

int main() {
  int n11[] = {1, 3}, n21[] = {2};
  int n12[] = {1, 2}, n22[] = {3, 4};
  printf("%f\n", findMedianSortedArrays(n11, 2, n21, 1)); // expect: 2.00000
  printf("%f\n", findMedianSortedArrays(n12, 2, n22, 2)); // expect: 2.50000
}
