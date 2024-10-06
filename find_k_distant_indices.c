// 2200. Find All K-Distant Indices in an Array
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' and two integers 'key' and 'k'
 * a k-distant index is an index 'i' of 'nums' for which there exists at least
 * one index 'j' such that '|i - j| <= k' and 'nums[j] == key'. return a list of
 * all k-distant indices sorted in increasing order
 */

int *findKDistantIndices(int *nums, int numsSize, int key, int k,
                         int *returnSize) {
  int *ans = (int *)calloc(numsSize, sizeof(int));
  int ans_idx = 0, i = 0;
  while (i < numsSize) {
    if (nums[i] == key) {
      int prev_idx = !ans_idx ? -1 : ans[ans_idx - 1];
      int start_idx = i - k > prev_idx ? i - k : prev_idx + 1;
      for (int j = start_idx; j <= i + k && j < numsSize; j++)
        ans[ans_idx++] = j;
    }
    i++;
  }
  *returnSize = ans_idx;
  return ans;
}

int main() {
  int n1[] = {3, 4, 9, 1, 3, 9, 5}, n2[] = {2, 2, 2, 2, 2}, rs1, rs2;
  int *fkdi1 = findKDistantIndices(n1, ARRAY_SIZE(n1), 9, 1, &rs1);
  int *fkdi2 = findKDistantIndices(n2, ARRAY_SIZE(n2), 2, 2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fkdi1[i]); // expect: 1 2 3 4 5 6
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fkdi2[i]); // expect: 0 1 2 3 4
  printf("\n");
  free(fkdi1), free(fkdi2);
}
