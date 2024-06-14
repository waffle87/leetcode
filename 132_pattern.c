// 456. 132 Pattern
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of 'n' integers 'nums', a 132 pattern is a subsequence of
 * three integers 'nums[i], nums[j], nums[k]' such that 'i < j < k' and 'nums[i]
 * < nums[k] < nums[j]'. return true if there is a 132 pattern in 'nums', and
 * false otherwise
 */

bool find132pattern(int *nums, int nums_size) {
  int n = nums_size, third = INT_MIN, s_idx = 0;
  int *stk = malloc(n * sizeof(int));
  bool ans = false;
  for (int i = n - 1; i >= 0; i--) {
    if (nums[i] < third) {
      ans = true;
      break;
    }
    while (s_idx && nums[i] > stk[s_idx - 1]) {
      third = stk[s_idx - 1];
      s_idx--;
    }
    stk[s_idx] = nums[i];
    s_idx++;
  }
  free(stk);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4}, n2[] = {3, 1, 4, 2}, n3[] = {-1, 3, 2, 0};
  printf("%d\n", find132pattern(n1, 4)); // expect: 0
  printf("%d\n", find132pattern(n2, 4)); // expect: 1
  printf("%d\n", find132pattern(n3, 4)); // expect: 1
}
