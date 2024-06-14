// 60. Permutation Sequence
#include "leetcode.h"

/*
 * the set '[1,2,3, ..., n]' contains a total of 'n!' unique permutations. by
 * listing and labeling all of the permutations in order, we get the following
 * sequence for 'n = 3' 123, 132, 213, 231, 312, 321 given 'n' and 'k', return
 * the k'th permutation sequence
 */

int cmp(const void *a, const void *b) { return *(char *)a - *(char *)b; }

void next_permutation(char *nums, int nums_size) {
  for (int i = nums_size - 2; i >= 0; i--)
    if (nums[i] < nums[i + 1]) {
      qsort(&nums[i + 1], nums_size - (i + 1), sizeof(char), cmp);
      for (int j = i + 1; j < nums_size; j++)
        if (nums[j] > nums[i]) {
          char tmp = nums[i];
          nums[i] = nums[j];
          nums[j] = tmp;
          return;
        }
    }
  qsort(nums, nums_size, sizeof(char), cmp);
}

char *getPermutation(int n, int k) {
  char *ans = malloc((n + 1) * sizeof(char));
  ans[n] = '\0';
  for (int i = 0; i < n; i++)
    ans[i] = '1' + i;
  for (int i = 1; i < k; i++)
    next_permutation(ans, n);
  return ans;
}

int main() {
  printf("%s\n", getPermutation(3, 3)); // expect: 213
  printf("%s\n", getPermutation(4, 9)); // expect: 2314
  printf("%s\n", getPermutation(3, 1)); // expect: 123
}
