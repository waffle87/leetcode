// 2289. Steps to Make Array Non-decreasing
#include <stdio.h>

/*
 * given a 0-indexed integer array 'nums'. in one step, remofe all elements
 * 'nums[i]' where 'nums[i - 1] > nums[i]' for all '0 < i < nums.size()'. return
 * the number of steps performed until 'nums' becomes non-decreasing
 */

void next(int *nums, int nums_size, int k, int *i, int time) {
  int curr = 0;
  (*i)++;
  while (*i < nums_size) {
    if (k > nums[*i]) {
      curr++;
      next(nums, nums_size, nums[*i], i, curr);
      if (curr == time)
        return;
    } else
      return;
  }
}

int totalSteps(int *nums, int nums_size) {
  int ans = 0, time = 0, k = nums[0], i = 1;
  while (i < nums_size) {
    if (k > nums[i]) {
      time++;
      next(nums, nums_size, nums[i], &i, time);
    } else {
      if (time > ans)
        ans = time;
      time = 0;
      k = nums[i];
      i++;
    }
  }
  if (time > ans)
    ans = time;
  return ans;
}

int main() {
  int n1[] = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11}, n2[] = {4, 5, 7, 7, 13};
  printf("%d\n", totalSteps(n1, 11)); // expect: 3
  printf("%d\n", totalSteps(n2, 5));  // expect: 0
}
