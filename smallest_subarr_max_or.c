// 2411. Smallest Subarrays With Maximum Bitwise OR
#include "leetcode.h"

/*
 * you are given a 0-indexed array 'nums' of length 'n', consisting of
 * non-negative integers. for each index 'i' from 0 to 'n - 1', you must
 * determine the size of the minimum sized non-empty subarray of 'nums' starting
 * at 'i' that has the maximum possible bitwise or. the bitwosee or of an array
 * is the bitwise or of all the numbers in it. return an integer array 'answer'
 * of size 'n' where 'answer[i]' is the length of the minimum sized subarray
 * starting at 'i' with maximum bitwise or. a subarray is a contiguous non-empty
 * sequence of elements within an array.
 */

int *smallestSubarrays(int *nums, int numsSize, int *returnSize) {
  int prev[30], *ans = (int *)malloc(numsSize * sizeof(int));
  memset(ans, 1, numsSize * sizeof(int));
  *returnSize = numsSize;
  for (int i = numsSize - 1; i >= 0; --i)
    for (int j = 0; j < 30; ++j) {
      if (nums[i] & (1 << j))
        prev[j] = i;
      ans[i] = fmax(ans[i], prev[j] - i + 1);
    }
  return ans;
}

int main() {
  int n1[] = {1, 0, 2, 1, 3}, rs1;
  int n2[] = {1, 2}, rs2;
  int *sb1 = smallestSubarrays(n1, ARRAY_SIZE(n1), &rs1);
  int *sb2 = smallestSubarrays(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", sb1[i]); // expect: 3 3 2 2 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", sb2[i]); // expect: 2 1
  printf("\n");
  free(sb1);
  free(sb2);
}
