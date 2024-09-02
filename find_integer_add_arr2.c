// 3132. Find the Integer Added to Array II
#include "leetcode.h"

/*
 * you are given two integer arrays 'nums1' and 'nums2'. from 'nums1', two
 * elements have been removed, and all other elements have been increased or
 * decreased in the case of negative by an integer, represented by the variable
 * 'x'. as a result, 'nums1' becomes equal to 'nums2'. two arrays are considered
 * equal when they contain the same integers with the same frequencies. return
 * the minimum possible integer 'x' that achieves this equivalence.
 */

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int minimumAddedInteger(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int diff, min = INT_MAX;
  qsort(nums1, nums1Size, sizeof(int), cmp);
  qsort(nums2, nums2Size, sizeof(int), cmp);
  for (int i = 0; i < nums1Size; i++)
    for (int j = i + 1; j < nums1Size; j++) {
      if (!i)
        diff = (j == 1) ? nums2[0] - nums1[2] : nums2[0] - nums1[1];
      else
        diff = nums2[0] - nums1[0];
      bool match = true;
      for (int k = 0, l = 0; k < nums2Size; l++) {
        if (l == i || l == j)
          continue;
        else if (nums1[l] + diff != nums2[k]) {
          match = false;
          break;
        }
        k++;
      }
      if (match && diff < min)
        min = diff;
    }
  return min;
}

int main() {
  int n11[] = {4, 20, 16, 12, 8}, n21[] = {14, 18, 10}, n12[] = {3, 5, 5, 3},
      n22[] = {7, 7};
  printf("%d\n", minimumAddedInteger(n11, ARRAY_SIZE(n11), n21,
                                     ARRAY_SIZE(n21))); // expect: -2
  printf("%d\n", minimumAddedInteger(n12, ARRAY_SIZE(n12), n22,
                                     ARRAY_SIZE(n22))); // expect: 2
}
