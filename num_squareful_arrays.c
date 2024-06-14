// 996. Number of Squareful Arrays
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * an array is squareful if the sum of every pair of adjacent elements is a
 * perfect square. given an intger array nums, return the number of permutations
 * of 'nums' that are squareful. two permutations 'perm1' and 'perm2' are
 * different if there is some index 'i' such that 'perm1[i] != perm2[i]'.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void process(int *idx, int *data, int pos, int *nums, int nums_size,
             int *nums_cnt, int n) {
  if (pos == n) {
    (*idx)++;
    return;
  }
  for (int i = 0; i < nums_size; i++) {
    if (nums_cnt[i])
      if (pos) {
        int sum = data[pos - 1] + nums[i];
        int sq = (int)sqrt(sum);
        if (sum != sq * sq)
          continue;
      }
    data[pos] = nums[i];
    pos++;
    nums_cnt[i]--;
    process(idx, data, pos, nums, nums_size, nums_cnt, n);
    pos--;
    nums_cnt[i]++;
  }
}

int numSquarefulPerms(int *nums, int nums_size) {
  qsort(nums, nums_size, sizeof(int), cmp);
  int *new_nums = malloc(nums_size * sizeof(int));
  int *nums_cnt = malloc(nums_size * sizeof(int));
  new_nums[0] = nums[0];
  nums_cnt[0] = 1;
  int new_nums_size = 1;
  for (int i = 1; i < nums_size; i++) {
    if (nums[i] == nums[i - 1])
      nums_cnt[new_nums_size - 1]++;
    else {
      new_nums[new_nums_size] = nums[i];
      nums_cnt[new_nums_size] = 1;
      new_nums_size++;
    }
  }
  new_nums = realloc(new_nums, sizeof(int) * new_nums_size);
  nums_cnt = realloc(nums_cnt, new_nums_size * sizeof(int));
  int *idx = calloc(1, sizeof(int));
  int *data = malloc(nums_size * sizeof(int));
  process(idx, data, 0, new_nums, new_nums_size, nums_cnt, nums_size);
  int ans = *idx;
  free(idx), free(data), free(new_nums), free(nums_cnt);
  return ans;
}

int main() {
  int n1[] = {1, 17, 8}, n2[] = {2, 2, 2};
  printf("%d\n", numSquarefulPerms(n1, 3)); // expect: 2
  printf("%d\n", numSquarefulPerms(n2, 3)); // expect: 1
}
