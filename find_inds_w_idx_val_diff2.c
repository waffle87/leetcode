// 2905. Find Indices With Index and Value Difference II
#include "leetcode.h"

/*
 * you are given a 0 indexed integer array 'nums' having length 'n', an integer
 * 'indexDifference', and an integer 'valueDifference'. your task is to find two
 * indices 'i' and 'j', both in the range '[0, n - 1]' that satisfy the
 * following conditions: 'abs(i - j) >= indexDifference' and 'abs(nums[i] -
 * nums[j]) >= valueDifference'. return an integer array 'answer' where 'answer
 * = [i, j]' if there are two such indces, and 'answer = [-1, -1]' otherwise. if
 * there are multiple choices for the two indices, returnany of them.
 */

int *findIndices(int *nums, int numsSize, int indexDifference,
                 int valueDifference, int *returnSize) {
  int *ans = (int *)malloc(2 * sizeof(int));
  *returnSize = 2;
  int mini = 0, maxi = 0;
  for (int i = indexDifference; i < numsSize; i++) {
    if (nums[i - indexDifference] < nums[mini])
      mini = i - indexDifference;
    if (nums[i - indexDifference] > nums[maxi])
      maxi = i - indexDifference;
    if (nums[i] - nums[mini] >= valueDifference) {
      ans[0] = mini;
      ans[1] = i;
      return ans;
    }
    if (nums[maxi] - nums[i] >= valueDifference) {
      ans[0] = maxi;
      ans[1] = i;
      return ans;
    }
  }
  ans[0] = ans[1] = -1;
  return ans;
}

int main() {
  int n1[] = {5, 1, 4, 1}, rs1, r1[] = {0, 3};
  int n2[] = {2, 1}, rs2, r2[] = {0, 0};
  int n3[] = {1, 2, 3}, rs3, r3[] = {-1, -1};
  int *fi1 = findIndices(n1, ARRAY_SIZE(n1), 2, 4, &rs1);
  int *fi2 = findIndices(n2, ARRAY_SIZE(n2), 0, 0, &rs2);
  int *fi3 = findIndices(n3, ARRAY_SIZE(n3), 2, 4, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", fi1[i]);
    assert(fi1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", fi2[i]);
    assert(fi2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", fi3[i]);
    assert(fi3[i] == r3[i]);
  }
  printf("\n");
  free(fi1);
  free(fi2);
  free(fi3);
}
