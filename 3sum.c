// 15. 3Sum
#include "leetcode.h"

/*
 * given an integer array 'nums', return all the triplets '[nums[i], nums[j],
 * nums[k]]' such that 'i != j', 'i != k', 'j != k', and 'nums[i] + nums[j] +
 * nums[k] == 0'. notice that the solution set must not contain duplicate
 * triplets
 */

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), cmp);
  (*returnSize) = 0;
  (*returnColumnSizes) = (int *)malloc(sizeof(int) * numsSize * numsSize);
  int **ans = (int **)malloc(numsSize * numsSize * sizeof(int *));
  for (int i = 0; i < numsSize - 2; i++)
    if (!i || nums[i] != nums[i - 1]) {
      int l = i + 1, r = numsSize - 1;
      while (l < r) {
        if (nums[i] + nums[l] + nums[r] < 0)
          l++;
        else if (nums[i] + nums[l] + nums[r] > 0)
          r--;
        else {
          ans[(*returnSize)] = (int *)malloc(3 * sizeof(int));
          (*returnColumnSizes)[(*returnSize)] = 3;
          ans[(*returnSize)][0] = nums[i];
          ans[(*returnSize)][1] = nums[l];
          ans[(*returnSize)][2] = nums[r];
          (*returnSize)++;
          l++;
          while (l < r && nums[l] == nums[l - 1])
            l++;
        }
      }
    }
  return ans;
}

int main() {
  int n1[] = {-1, 0, 1, 2, -1, -4}, rs1, *rcs1;
  int n2[] = {0, 1, 1}, rs2, *rcs2;
  int n3[] = {0, 0, 0}, rs3, *rcs3;
  int **ts1 = threeSum(n1, ARRAY_SIZE(n1), &rs1, &rcs1);
  int **ts2 = threeSum(n2, ARRAY_SIZE(n2), &rs2, &rcs2);
  int **ts3 = threeSum(n3, ARRAY_SIZE(n3), &rs3, &rcs3);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < *rcs1; j++)
      printf("%d ", ts1[i][j]); // expect: [[-1,-1,2],[-1,0,1]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < *rcs2; j++)
      printf("%d ", ts2[i][j]); // expect: null
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    for (int j = 0; j < *rcs3; j++)
      printf("%d ", ts3[i][j]); // expect: [[0,0,0]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(ts1[i]);
  free(ts1);
  for (int i = 0; i < rs2; i++)
    free(ts2[i]);
  free(ts2);
  for (int i = 0; i < rs3; i++)
    free(ts3[i]);
  free(ts3);
}
