// 350. Intersection of Two Arrays II
#include "leetcode.h"

/*
 * given two integer arrays 'nums1' and 'nums2' return an array of their
 * intersection. each element in the result must appear as many times as it
 * shows in both arrays and you may return the result in any order.
 */

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize) {
  int *hash = (int *)malloc(1001 * sizeof(int)),
      *ans = (int *)malloc(1000 * sizeof(int)), n = 0;
  for (int i = 0; i < nums1Size; i++)
    hash[nums1[i]]++;
  for (int i = 0; i < nums2Size; i++)
    if (hash[nums2[i]]) {
      ans[n++] = nums2[i];
      hash[nums2[i]]--;
    }
  *returnSize = n;
  free(hash);
  return ans;
}

int main() {
  int n11[] = {1, 2, 2, 1}, n21[] = {2, 2}, n12[] = {4, 9, 5},
      n22[] = {9, 4, 9, 8, 4}, rs1, rs2;
  int *i1 = intersect(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21), &rs1);
  int *i2 = intersect(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", i1[i]); // expect: 2 2
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", i2[i]); // expect: 4 9
  printf("\n");
  free(i1), free(i2);
}
