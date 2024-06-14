// 1035. Uncrossed Lines
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given two integer arrays 'nums1' and 'num2'. we write the integers of 'nums1'
 * and 'nums2' (in the order they are given) on two separate horizontal lines.
 * we may draw connecting lines: a straight line connecting two numbers
 * 'nums1[i]' and 'nums2[j]' such thatyr
 * - 'nums1[i] == nums2[j]' and
 * - the line we draw does not intersect any other connecting (non-horizontal)
 * line note that a connecting line cannot intereset even at the endpoints.
 * return the maximum number of connecting lines we can draw in this way.
 */

int maxUncrossedLines(int *nums1, int nums1_size, int *nums2, int nums2_size) {
  int i, j;
  int **dp = (int **)malloc(nums1_size * sizeof(int *));
  for (i = 0; i < nums1_size; i++)
    dp[i] = malloc(nums2_size * sizeof(int));
  if (nums1[0] == nums2[0])
    dp[0][0] = 1;
  else
    dp[0][0] = 0;
  for (i = 1; i < nums2_size; i++) {
    if (nums1[0] == nums2[i])
      dp[0][i] = 1;
    else
      dp[0][i] = dp[0][i - 1];
  }
  for (i = 1; i < nums1_size; i++) {
    if (nums1[i] == nums2[0])
      dp[i][0] = 1;
    else
      dp[i][0] = dp[i - 1][0];
  }
  for (i = 1; i < nums1_size; i++)
    for (j = 1; j < nums2_size; j++) {
      if (nums1[i] == nums2[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
    }
  int ans = dp[nums1_size - 1][nums2_size - 1];
  for (i = 0; i < nums1_size; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int n11[] = {1, 4, 2}, n21[] = {1, 2, 4};
  int n12[] = {2, 5, 1, 2, 5}, n22[] = {10, 5, 2, 1, 5, 2};
  int n13[] = {1, 3, 7, 1, 7, 5}, n23[] = {1, 9, 2, 5, 1};
  printf("%d\n", maxUncrossedLines(n11, 3, n21, 3)); // expect: 2
  printf("%d\n", maxUncrossedLines(n12, 5, n22, 6)); // expect: 3
  printf("%d\n", maxUncrossedLines(n13, 6, n23, 5)); // expect: 2
}
