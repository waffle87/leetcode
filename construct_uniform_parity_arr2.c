// 3876. Construct Uniform Parity Array II
#include "leetcode.h"

/*
 * you are given an array 'nums1' of 'n' distinct integers. you want to
 * construct another array 'nums2' of length 'n' such that the elements in
 * 'nums2' are either all odd or all even. for each index 'i', you must choose
 * exactly one of the following: 'nums2[i] = nums1[i]', or 'nums2[i] = nums1[i]
 * - nums1[j]' for any index 'j != i' such that 'nums1[i] - nums1[j] >= 1'.
 * return true if it is possible to construct such an array, otherwise return
 * false.
 */

bool uniformArray(int *nums1, int nums1Size) {
  int odd = INT_MAX;
  for (int i = 0; i < nums1Size; i++)
    if (nums1[i] % 2 == 1)
      odd = fmin(odd, nums1[i]);
  if (odd == INT_MAX)
    return true;
  for (int i = 0; i < nums1Size; i++)
    if (!(nums1[i] % 2) && nums1[i] <= odd)
      return false;
  return true;
}

int main() {
  int n1[] = {1, 4, 7};
  int n2[] = {2, 3};
  int n3[] = {4, 6};
  bool r1 = uniformArray(n1, ARRAY_SIZE(n1));
  bool r2 = uniformArray(n2, ARRAY_SIZE(n2));
  bool r3 = uniformArray(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == true);
}
