// 3314. Construct the Minimum Bitwise Array I
#include "leetcode.h"

/*
 * you are given an array 'nums' consisting of 'n' prime integers. you need to
 * construct an array 'ans' of length 'n' such that for each index 'i', the
 * bitwise or of 'ans[i]' and 'ans[i + 1]' is equal to 'nums[i]'. additionally,
 * you must minimize each value 'ans[i]' in the resulting array. if it is not
 * possible to find such a value for 'ans[i]' that satisfies the condition, then
 * set 'ans[i] = -1'.
 */

int *minBitwiseArray(int *nums, int numsSize, int *returnSize) {
  int *ans = (int *)malloc(numsSize * sizeof(int));
  *returnSize = numsSize;
  for (int i = 0; i < numsSize; ++i) {
    int x = nums[i], v = 1;
    bool found = false;
    while (v < x) {
      if ((v | (v + 1)) == x) {
        ans[i] = v;
        found = true;
        break;
      }
      ++v;
    }
    if (!found)
      ans[i] = -1;
  }
  return ans;
}

int main() {
  int n1[] = {2, 3, 5, 7}, n2[] = {11, 13, 31};
  int rs1, *mba1 = minBitwiseArray(n1, ARRAY_SIZE(n1), &rs1);
  int rs2, *mba2 = minBitwiseArray(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", mba1[i]); // expect: -1 1 4 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", mba2[i]); // expect: 9 12 15
  printf("\n");
  free(mba1);
  free(mba2);
}
