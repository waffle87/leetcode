// 3254. Find the Power of K-Size Subarrays I
#include "leetcode.h"

/*
 * you are given an array of integers 'nums' of length 'n' and a positive
 * integer 'k'. the power of an array is defined as its maximum element if all
 * its elements are consecutive and sorted in ascending order, -1 otherwise. you
 * need to find the power of all subarrays of 'nums' of size 'k'. return an
 * integer array 'results' of size 'n - k + 1' where 'results[i]' is the power
 * of 'nums[i ... (i + k - 1)]'.
 */

int *resultsArray(int *nums, int numsSize, int k, int *returnSize) {
  int *ans = (int *)malloc((numsSize - k + 1) * sizeof(int)), n = 0;
  for (int i = 0; i <= numsSize - k; i++) {
    bool consec = true;
    for (int j = 0; j < k - 1; j++)
      if (nums[i + j] + 1 != nums[i + j + 1]) {
        consec = false;
        break;
      }
    ans[n++] = consec ? nums[i + k - 1] : -1;
  }
  *returnSize = n;
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4, 3, 2, 5}, n2[] = {2, 2, 2, 2, 2},
      n3[] = {3, 2, 3, 2, 3, 2}, rs1, rs2, rs3;
  int *ra1 = resultsArray(n1, ARRAY_SIZE(n1), 3, &rs1);
  int *ra2 = resultsArray(n2, ARRAY_SIZE(n2), 4, &rs2);
  int *ra3 = resultsArray(n3, ARRAY_SIZE(n3), 2, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ra1[i]); // expect: 3 4 -1 -1 -1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ra2[i]); // expect: -1 -1
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", ra3[i]); // expect: -1 3 -1 3 -1
  printf("\n");
  free(ra1), free(ra2), free(ra3);
}
