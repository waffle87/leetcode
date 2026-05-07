// 3660. Jump Game IX
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. from any index 'i', you can jump to
 * another index 'j' under the following rules: jump to index 'j' where 'j > i'
 * is allowed only if 'nums[j] < nums[i]', and vice versa. for each index 'i',
 * find the maximum value in 'nums' that can be reached by following any
 * sequence of valid jumps starting at 'i'. return an array 'ans' where 'ans[i]'
 * is the maximum value reachable starting from index 'i'.
 */

struct item {
  int val;
  int idx;
};

void process(int *nums, int *res, struct item *prev_max, int r, int right_min,
             int right_max) {
  int p_max = prev_max[r].val;
  int p_idx = prev_max[r].idx;
  int curr_max = p_max <= right_min ? p_max : right_max;
  int next_right_min = p_max < right_min ? p_max : right_min;
  for (int i = p_idx; i <= r; i++) {
    res[i] = curr_max;
    next_right_min = fmax(next_right_min, nums[i]);
  }
  if (!p_idx)
    return;
  process(nums, res, prev_max, p_idx - 1, next_right_min, curr_max);
}

int *maxValue(int *nums, int numsSize, int *returnSize) {
  int *ans = (int *)calloc(numsSize, sizeof(int));
  *returnSize = numsSize;
  struct item *prev_max = (struct item *)malloc(numsSize * sizeof(int));
  struct item prev = {INT_MIN, -1};
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > prev.val) {
      prev.val = nums[i];
      prev.idx = i;
    }
    prev_max[i] = prev;
  }
  process(nums, ans, prev_max, numsSize - 1, INT_MAX, 0);
  free(prev_max);
  return ans;
}

int main() {
  int n1[] = {2, 1, 3}, r1[] = {2, 2, 3}, rs1;
  int n2[] = {2, 3, 1}, r2[] = {3, 3, 3}, rs2;
  int *mv1 = maxValue(n1, ARRAY_SIZE(n1), &rs1);
  int *mv2 = maxValue(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", mv1[i]);
    assert(mv1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", mv2[i]);
    assert(mv2[i] == r2[i]);
  }
  printf("\n");
  free(mv1);
  free(mv2);
}
