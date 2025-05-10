// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
#include "leetcode.h"

/*
 * you are given two arrays 'nums1' and 'nums2' consisting of positive integers.
 * you have to replace all the 0's in both arrays with strictly positive
 * integers such that the sum of elements of both arrays becomes equal. return
 * the minimum equal sum you can obtain, or -1 if it is impossible.
 */

long long minSum(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  long long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
  for (int i = 0; i < nums1Size; i++) {
    zero1 += !nums1[i];
    sum1 += fmax(nums1[i], 1);
  }
  for (int i = 0; i < nums2Size; i++) {
    zero2 += !nums2[i];
    sum2 += fmax(nums2[i], 1);
  }
  if (sum1 < sum2 && !zero1)
    return -1;
  if (sum1 > sum2 && !zero2)
    return -1;
  return fmax(sum1, sum2);
}

int main() {
  int n11[] = {3, 2, 0, 1, 0}, n21[] = {6, 5, 0};
  int n12[] = {2, 0, 2, 0}, n22[] = {1, 4};
  printf("%lld\n",
         minSum(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21))); // expect: 12
  printf("%lld\n",
         minSum(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22))); // expect: -1
}
