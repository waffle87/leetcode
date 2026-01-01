// 66. Plus One
#include "leetcode.h"

/*
 * you are given a large integer represented as an integer array 'digits', where
 * each 'digits[i]' is the i'th digit of thee integer. the digits are ordered
 * from most significant to least signifcant in left to right order. the large
 * does not contain any leading zeros. increment the large integer by one and
 * return the resulting  array of digits.
 */

int *plusOne(int *digits, int digitsSize, int *returnSize) {
  for (int i = digitsSize - 1; i >= 0; i--) {
    if (digits[i] < 9) {
      digits[i]++;
      *returnSize = digitsSize;
      return digits;
    }
    digits[i] = 0;
  }
  int *ans = (int *)malloc((digitsSize + 1) * sizeof(int));
  ans[0] = 1;
  for (int i = 1; i <= digitsSize; i++)
    ans[i] = 0;
  *returnSize = digitsSize + 1;
  return ans;
}

int main() {
  int d1[] = {1, 2, 3}, d2[] = {4, 3, 2, 1}, d3[] = {9};
  int rs1, *po1 = plusOne(d1, ARRAY_SIZE(d1), &rs1);
  int rs2, *po2 = plusOne(d2, ARRAY_SIZE(d2), &rs2);
  int rs3, *po3 = plusOne(d3, ARRAY_SIZE(d3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", po1[i]); // expect: 1 2 4
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", po2[i]); // expect: 4 3 2 2
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", po3[i]); // expect: 1 0
  printf("\n");
  if (po1)
    free(po1);
  if (po2)
    free(po2);
  if (po3)
    free(po3);
}
