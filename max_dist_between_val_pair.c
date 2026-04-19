// 1855. Maximum Distance Between a Pair of Values
#include "leetcode.h"

/*
 * you are given two non-increasing 0-indexed integer arrays 'nums1' and
 * 'nums2'. a pair of indices '(i, j)' where '0 <= i < nums1.lenth' and '0 <= j
 * < nums2.lenth' is valid if both 'i <= j' and 'nums1[i] <= nums2[j]'. the
 * distance of the pair is 'j - i'. return the maximum distance of any valid
 * pair '(i, j)'. if there are no valid pairs, return 0.
 */

int maxDistance(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int i = 0, j = 0, ans = 0;
  while (i < nums1Size && j < nums2Size) {
    if (nums1[i] > nums2[j])
      ++i;
    else
      ans = fmax(ans, j++ - i);
  }
  return ans;
}

int main() {
  int n11[] = {55, 30, 5, 4, 2}, n21[] = {100, 20, 10, 10, 5};
  int n12[] = {2, 2, 2}, n22[] = {10, 10, 1};
  int n13[] = {30, 29, 19, 5}, n23[] = {25, 25, 25, 25, 25};
  int r1 = maxDistance(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21));
  int r2 = maxDistance(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22));
  int r3 = maxDistance(n13, ARRAY_SIZE(n13), n23, ARRAY_SIZE(n23));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == 2);
}
