// 3264. Final Array State After K Multiplication Operations I
#include "leetcode.h"

/*
 * you are given an integer array 'nums', an integer 'k', and an integer
 * 'multiplier'. you need to perform 'k' operations on 'nums'. in each
 * operation, find the minimum value 'x' in 'nums'. if there are multiple
 * occurences of the minimum value, select the one that appears first. replace
 * the selected minimum value 'x' with 'x * multiplier'. return an integer array
 * denoting the final state of 'nums' after performing all 'k' operations
 */

int *getFinalState(int *nums, int numsSize, int k, int multiplier,
                   int *returnSize) {
  int *ans = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++)
    ans[i] = nums[i];
  for (int i = 0; i < k; i++) {
    int min = 0;
    for (int j = 1; j < numsSize; j++)
      if (ans[j] < ans[min])
        min = j;
    ans[min] *= multiplier;
  }
  *returnSize = numsSize;
  return ans;
}

int main() {
  int n1[] = {2, 1, 3, 5, 6}, n2[] = {1, 2}, rs1, rs2;
  int *gfs1 = getFinalState(n1, ARRAY_SIZE(n1), 5, 2, &rs1);
  int *gfs2 = getFinalState(n2, ARRAY_SIZE(n2), 3, 4, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", gfs1[i]); // expectd: 8 4 6 5 6
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", gfs2[i]); // expectd: 16 8
  printf("\n");
  free(gfs1), free(gfs2);
}
