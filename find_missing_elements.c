// 3731. Find Missing Elements
#include "leetcode.h"

/*
 * you are given an integer array 'nums' consisting of unique integers.
 * originally, 'nums' contained every integer within a certain range. however,
 * some integers might have gone missing from the array. the smallest and
 * largest integers of the original range are still present in 'nums'. return a
 * sorted list of all the missing integers in this range. if no integers are
 * missing, return an empty list.
 */

int *findMissingElements(int *nums, int numsSize, int *returnSize) {
  __int128 bitset = 0;
  int min = INT_MAX, max = INT_MIN;
  for (int i = 0; i < numsSize; i++) {
    bitset |= ((__int128)1 << nums[i]);
    min = fmin(min, nums[i]);
    max = fmax(max, nums[i]);
  }
  int gaps = 0;
  for (int i = min + 1; i < max; i++)
    if (!(bitset & ((__int128)1 << i)))
      gaps++;
  *returnSize = gaps;
  if (!gaps)
    return NULL;
  int *ans = (int *)malloc(gaps * sizeof(int));
  int j = 0;
  for (int i = min + 1; i < max; i++)
    if (!(bitset & ((__int128)1 << i)))
      ans[j++] = i;
  return ans;
}

int main() {
  int n1[] = {1, 4, 2, 5}, r1[] = {3};
  int n2[] = {7, 8, 6, 9}, r2[] = {};
  int n3[] = {5, 1}, r3[] = {2, 3, 4};
  int rs1, *fme1 = findMissingElements(n1, ARRAY_SIZE(n1), &rs1);
  int rs2, *fme2 = findMissingElements(n2, ARRAY_SIZE(n2), &rs2);
  int rs3, *fme3 = findMissingElements(n3, ARRAY_SIZE(n3), &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", fme1[i]);
    assert(fme1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", fme2[i]);
    assert(fme2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", fme3[i]);
    assert(fme3[i] == r3[i]);
  }
  printf("\n");
  free(fme1);
  free(fme2);
  free(fme3);
}
