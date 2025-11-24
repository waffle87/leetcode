// 1018. Binary Prefix Divisible By 5
#include "leetcode.h"

/*
 * you are given a binary array 'nums'. we define 'x_i' as the number whose
 * binary representation is the subarray 'nums[0..i]' from (msb to lsb). return
 * an array of booleans 'answer' where 'answer[i]' is 'true' if 'x_i' is divible
 * by 5
 */

bool *prefixesDivBy5(int *nums, int numsSize, int *returnSize) {
  bool *ans = (bool *)malloc(numsSize * sizeof(bool));
  *returnSize = numsSize;
  int msb = 0;
  for (int i = 0; i < numsSize; i++) {
    msb = ((msb << 1) + nums[i]);
    msb -= (-(msb >= 5) & 5);
    ans[i] = !msb;
  }
  return ans;
}

int main() {
  int n1[] = {0, 1, 1}, n2[] = {1, 1, 1}, rs1, rs2;
  bool *pdb51 = prefixesDivBy5(n1, ARRAY_SIZE(n1), &rs1);
  bool *pdb52 = prefixesDivBy5(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pdb51[i]); // expect: 1 0 0
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", pdb52[i]); // expect: 0 0 0
  printf("\n");
  free(pdb51);
  free(pdb52);
}
