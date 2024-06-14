// 2540. Minimum Common Value
#include "leetcode.h"

/*
 * given two integer arrays 'nums1' and 'nums2', sorted in non-decreasing order.
 * return the minimum integer common to both arrays. if there is no common
 * integer amongst 'nums1' and 'nums2', return -1. note that an integer is said
 * to be common to 'nums1' and 'nums2' if both arrays have at least one
 * occurence of that integer.
 */

int getCommon(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int p1 = 0, p2 = 0, n1 = nums1Size, n2 = nums2Size;
  while (p1 < n1 || p2 < n2) {
    if (p1 == n1) {
      if (nums2[p2] > nums1[n1 - 1])
        return -1;
      else {
        for (int i = p2; i < n2; i++)
          if (nums2[i] == nums1[n1 - 1])
            return nums2[i];
        return -1;
      }
    }
    if (p2 == n2) {
      if (nums1[p1] > nums2[n2 - 1])
        return -1;
      else {
        for (int i = p1; i < n1; i++)
          if (nums1[i] == nums2[n2 - 1])
            return nums1[i];
        return -1;
      }
    }
    if (nums1[p1] == nums2[p2])
      return nums1[p1];
    if (nums1[p1] < nums2[p2])
      p1++;
    else
      p2++;
  }
  return -1;
}

int main() {
  int n11[] = {1, 2, 3}, n21[] = {2, 4}, n12[] = {1, 2, 3, 6},
      n22[] = {2, 3, 4, 5};
  printf("%d\n",
         getCommon(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21))); // expect: 2
  printf("%d\n",
         getCommon(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22))); // expect: 2
}
