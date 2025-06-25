// 2040. Kth Smallest Product of Two Sorted Arrays
#include "leetcode.h"

/*
 * given two sorted 0-indexed integer arrays 'nums1' and 'nums2' as well as an
 * integer 'k', return the k'th smallest product of 'nums1[i] * nums2[i]' where
 * '0 <= i < nums1.length' and '0 <= j < nums2.length'
 */

long long kthSmallestProduct(int *nums1, int nums1Size, int *nums2,
                             int nums2Size, long long k) {
  int n1 = 0, n2 = 0;
  while (n1 < nums1Size && nums1[n1] < 0)
    n1++;
  while (n2 < nums2Size && nums2[n1] < 0)
    n2++;
  int z1 = 0, p1 = 0;
  for (int i = n1; i < nums1Size; i++) {
    if (!nums1[i])
      z1++;
    else
      p1++;
  }
  int z2 = 0, p2 = 0;
  for (int i = n2; i < nums2Size; i++) {
    if (!nums2[i])
      z2++;
    else
      p2++;
    ;
  }
  int p1_beg = n1 + z1, p2_beg = n2 + z2;
  long long start = -1e9, end = 1e9;
  while (start <= end) {
    long long mid = (start + end) / 2, total = 0;
    if (mid >= 0) {
      total += (long long)n1 * p2 + (long long)p1 * n2;
      total += (long long)z1 * nums2Size + (long long)(nums1Size - z1) * z2;
      int i = 0, j = n2 - 1;
      while (i < n1 && j >= 0) {
        if ((long long)nums1[i] * nums2[j] > mid)
          i++;
        else {
          total += n1 - i;
          j--;
        }
      }
      i = p1_beg, j = nums2Size - 1;
      while (i < nums1Size && j >= p2_beg) {
        if ((long long)nums1[i] * nums2[j] > mid)
          j--;
        else {
          total += j - p2_beg + 1;
          i++;
        }
      }
    } else {
      int i = 0, j = p2_beg;
      while (i < n1 && j < nums2Size) {
        if ((long long)nums1[i] * nums2[j] > mid)
          j++;
        else {
          total += nums2Size - j;
          i++;
        }
      }
      i = p1_beg, j = 0;
      while (i < nums1Size && j < n2) {
        if ((long long)nums1[i] * nums2[j] > mid)
          i++;
        else {
          total += nums1Size - i;
          j++;
        }
      }
    }
    if (total < k)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return start;
}

int main() {
  int n11[] = {2, 5}, n21[] = {3, 4};
  int n12[] = {-4, -2, 0, 3}, n22[] = {2, 4};
  int n13[] = {-2, -1, 0, 1, 2}, n23[] = {-3, -1, 2, 4, 5};
  printf("%lld\n", kthSmallestProduct(n11, ARRAY_SIZE(n11), n21,
                                      ARRAY_SIZE(n21), 2)); // expect: 8
  printf("%lld\n", kthSmallestProduct(n12, ARRAY_SIZE(n12), n22,
                                      ARRAY_SIZE(n22), 6)); // expect: 0
  printf("%lld\n", kthSmallestProduct(n13, ARRAY_SIZE(n13), n23,
                                      ARRAY_SIZE(n23), 3)); // expect: -6
}
