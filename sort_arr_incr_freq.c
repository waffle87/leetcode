// 1636. Sort Array by Increasing Frequency
#include "leetcode.h"

/*
 * given an array of integers 'nums', sort the array in increasing order based
 * on the frequency of the values. if multiple values have the same frequency,
 * sort them in decreasing order. return the sorted array.
 */

int cmp(const void *a, const void *b, void *cnt) {
  int *cnt_arr = (int *)cnt;
  int a_val = *(int *)a, b_val = *(int *)b;
  return cnt_arr[a_val + 100] == cnt_arr[b_val + 100]
             ? b_val - a_val
             : cnt_arr[a_val + 100] - cnt_arr[b_val + 100];
}

int *frequencySort(int *nums, int numsSize, int *returnSize) {
  int cnt[201] = {0};
  for (int i = 0; i < numsSize; ++i)
    ++cnt[nums[i] + 100];
  qsort_r(nums, numsSize, sizeof(int), cmp, cnt); // requires _GNU_SOURCE
  return nums;
}

int main() {
  int n1[] = {1, 1, 2, 2, 2, 3}, n2[] = {2, 3, 1, 3, 2},
      n3[] = {-1, 1, -6, 4, 5, -6, 1, 4, 1}, rs1, rs2, rs3;
  int *fs1 = frequencySort(n1, ARRAY_SIZE(n1), &rs1);
  int *fs2 = frequencySort(n2, ARRAY_SIZE(n2), &rs2);
  int *fs3 = frequencySort(n3, ARRAY_SIZE(n3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fs1[i]); // expect: 3,1,1,2,2,2
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fs2[i]); // expect: 1,3,3,2,2
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", fs3[i]); // expect: 5,-1,4,4,-6,-6,1,1,1
  printf("\n");
  free(fs1), free(fs2), free(fs3);
}
