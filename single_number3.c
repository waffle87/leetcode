// 260. Single Number III
#include "leetcode.h"

/*
 * given an integer array 'nums' in which exactly two elements appear only once
 * and all the otherelements appear exactly twice. find the two elements that
 * appear only once. you can return the answer in any order. you must write an
 * algorithm that runs linear runtime complexity and uses only constant extra
 * space.
 */

int *singleNumber(int *nums, int numsSize, int *returnSize) {
  *returnSize = 2;
  int *ans = (int *)calloc(2, sizeof(int));
  long long tmp = 0;
  for (int i = 0; i < numsSize; i++)
    tmp ^= nums[i];
  tmp &= -tmp;
  for (int i = 0; i < numsSize; i++)
    if (!(tmp & nums[i]))
      ans[0] ^= nums[i];
    else
      ans[1] ^= nums[i];
  return ans;
}

int main() {
  int n1[] = {1, 2, 1, 3, 2, 5}, n2[] = {-1, 0}, n3[] = {0, 1}, rs1, rs2, rs3;
  int *sn1 = singleNumber(n1, ARRAY_SIZE(n1), &rs1); // expect: 3 5
  int *sn2 = singleNumber(n2, ARRAY_SIZE(n2), &rs2); // expect: -1 0
  int *sn3 = singleNumber(n3, ARRAY_SIZE(n3), &rs3); // expect: 1 0
  for (int i = 0; i < rs1; i++)
    printf("%d ", sn1[i]);
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", sn2[i]);
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", sn3[i]);
  printf("\n");
  free(sn1), free(sn2), free(sn3);
}
