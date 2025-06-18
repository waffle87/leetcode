// 2966. Divide Array Into Arrays With Max Difference
#include "leetcode.h"

/*
 * given an integer array 'nums' of size 'n' and a positive integer 'k'. divide
 * the array into one or more arrays of size 3 satisfying the following
 * conditions. each element of 'nums' should be in exactly one array. the
 * different between any two elements in one array is less than or equal to 'k'.
 * return a 2d array containing all the arrays if it is impossible to satisfy
 * the conditions, return an empty array. and if there are multiple answers,
 * return any of them
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int **divideArray(int *nums, int numsSize, int k, int *returnSize,
                  int **returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int **ans = (int **)malloc((numsSize / 3) * sizeof(int *)), rs = 0;
  for (int i = 2; i < numsSize; i += 3) {
    if (nums[i] - nums[i - 2] > k) {
      *returnSize = 0;
      return NULL;
    }
    ans[rs] = (int *)malloc(3 * sizeof(int));
    ans[rs][0] = nums[i - 2];
    ans[rs][1] = nums[i - 1];
    ans[rs][2] = nums[i];
    rs++;
  }
  *returnSize = rs;
  *returnColumnSizes = (int *)malloc(rs * sizeof(int));
  for (int i = 0; i < rs; i++)
    (*returnColumnSizes)[i] = 3;
  return ans;
}

int main() {
  int n1[] = {1, 3, 4, 8, 7, 9, 3, 5, 1}, rs1, *rcs1;
  int n2[] = {2, 4, 2, 2, 5, 2}, rs2, *rcs2;
  int n3[] = {4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11}, rs3,
      *rcs3;
  int **da1 = divideArray(n1, ARRAY_SIZE(n1), 2, &rs1, &rcs1);
  int **da2 = divideArray(n2, ARRAY_SIZE(n2), 2, &rs2, &rcs2);
  int **da3 = divideArray(n3, ARRAY_SIZE(n3), 14, &rs3, &rcs3);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", da1[i][j]); // expect: [[1,1,3],[3,4,5],[7,8,9]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", da2[i][j]); // expect: null
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    for (int j = 0; j < rcs3[i]; j++)
      printf(
          "%d ",
          da3[i][j]); // expect:
                      // [[2,2,12],[4,8,5],[5,9,7],[7,8,5],[5,9,10],[11,12,2]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(da1[i]), free(rcs1);
  free(da1);
  for (int i = 0; i < rs2; i++)
    free(da2[i]), free(rcs2);
  free(da1);
  for (int i = 0; i < rs3; i++)
    free(da3[i]), free(rcs3);
  free(da1);
}
