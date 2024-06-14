// 368. Largest Divisible Subset
#include "leetcode.h"

/*
 * given a set of distinct positive integers 'nums', return the largest subset
 * 'answer' such that every pair '(ans[i], ans[j])' of elements in this subset
 * satifies 'ans[i] % ans[j] == 0' or 'ans[j] % ans[i] == 0'. if there are
 * multiple solutions, return any of them.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int *largestDivisibleSubset(int *nums, int nums_size, int *return_size) {
  qsort(nums, nums_size, sizeof(int), cmp);
  int *idx = malloc(nums_size * sizeof(int));
  int *cnt = malloc(nums_size * sizeof(int));
  int max = 1, max_idx = 0, tmp;
  idx[0] = -1;
  cnt[0] = 1;
  for (int i = 1; i < nums_size; i++) {
    idx[i] = -1;
    cnt[i] = 1;
    for (int j = i - 1; j >= 0; j--)
      if (!(nums[i] % nums[j])) {
        tmp = cnt[j] + 1;
        if (tmp > cnt[i]) {
          cnt[i] = tmp;
          idx[i] = j;
        }
      }
    if (cnt[i] > max) {
      max = cnt[i];
      max_idx = i;
    }
  }
  *return_size = max;
  int *ans = malloc(max * sizeof(int));
  for (int i = max - 1; i >= 0; i--) {
    ans[i] = nums[max_idx];
    max_idx = idx[max_idx];
  }
  free(idx), free(cnt);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {1, 2, 4, 8};
  int rs1[] = {}, rs2[] = {};
  int *lds1 = largestDivisibleSubset(n1, ARRAY_SIZE(n1), rs1);
  int *lds2 = largestDivisibleSubset(n2, ARRAY_SIZE(n2), rs2);
  for (int i = 0; i < 2; i++)
    printf("%d ", lds1[i]); // expect: 1 2
  printf("\n");
  for (int i = 0; i < 4; i++)
    printf("%d ", lds2[i]); // expect: 1 2 4 8
  printf("\n");
  free(lds1), free(lds2);
}
