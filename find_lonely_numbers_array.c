// 2150. Find All Lonely Numbers in the Array
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a number 'x' is lonely when it appears
 * only once, and no adjacent numbers (ie. 'x + 1' and 'x - 1') appear in the
 * array. return all lonely numbers in 'nums'. you may return the answer in any
 * order
 */

int *findLonely(int *nums, int numsSize, int *returnSize) {
  int arr[1000002] = {0};
  for (int i = 0; i < numsSize; i++)
    arr[nums[i]]++;
  *returnSize = 0;
  int *ans = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    if (!nums[i] && arr[nums[i]] == 1 && !arr[nums[i] + 1]) {
      ans[(*returnSize)++] = nums[i];
      continue;
    }
    if (arr[nums[i]] == 1 && !arr[nums[i] + 1] && !arr[nums[i] - 1])
      ans[(*returnSize)++] = nums[i];
  }
  return ans;
}

int main() {
  int n1[] = {10, 6, 5, 8}, n2[] = {1, 3, 5, 3}, rs1, rs2;
  int *fl1 = findLonely(n1, ARRAY_SIZE(n1), &rs1);
  int *fl2 = findLonely(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fl1[i]); // expect: 10 8
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fl2[i]); // expect: 1 5
  printf("\n");
  free(fl1), free(fl2);
}
