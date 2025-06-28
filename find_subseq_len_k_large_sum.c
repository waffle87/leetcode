// 2099. Find Subsequence of Length K With the Largest Sum
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. you want to find a
 * subsequence of 'nums' of length 'k' that has the largest sum. return any such
 * subsequence as an integer array of length 'k'. a subsequence is an array that
 * can be derived from another array by deleting some or no elements without
 * changing the order of the remaining elements.
 */

struct pair {
  int idx;
  int val;
};

int cmp_idx(const void *a, const void *b) {
  struct pair aa = *(const struct pair *)a;
  struct pair bb = *(const struct pair *)b;
  return aa.idx - bb.idx;
}

int cmp_val(const void *a, const void *b) {
  struct pair aa = *(const struct pair *)a;
  struct pair bb = *(const struct pair *)b;
  return aa.val - bb.val;
}

int *maxSubsequence(int *nums, int numsSize, int k, int *returnSize) {
  struct pair *pairs = (struct pair *)malloc(numsSize * sizeof(struct pair));
  for (int i = 0; i < numsSize; i++) {
    pairs[i].idx = i;
    pairs[i].val = nums[i];
  }
  qsort(pairs, numsSize, sizeof(struct pair), cmp_val);
  qsort(pairs, k, sizeof(struct pair), cmp_idx);
  int *ans = (int *)malloc(k * sizeof(int));
  *returnSize = k;
  for (int i = 0; i < k; i++)
    ans[i] = nums[pairs[i].idx];
  free(pairs);
  return ans;
}

int main() {
  int n1[] = {2, 1, 3, 3}, n2[] = {-1, -2, 3, 4}, n3[] = {3, 4, 3, 3};
  int rs1, *ms1 = maxSubsequence(n1, ARRAY_SIZE(n1), 2, &rs1);
  int rs2, *ms2 = maxSubsequence(n2, ARRAY_SIZE(n2), 3, &rs2);
  int rs3, *ms3 = maxSubsequence(n3, ARRAY_SIZE(n3), 2, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ms1[i]); // expect: 3 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ms2[i]); // expect: -1 3 4
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", ms3[i]); // expect: 3 4
  printf("\n");
  free(ms1);
  free(ms2);
  free(ms3);
}
