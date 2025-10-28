// 3354. Make Array Elements Equal to Zero
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. start by selecting a starting position
 * 'curr' such that 'nums[curr] == 0' and choose a movement direction of either
 * left or right. after that, you repeat the following process: if 'curr' is out
 * of the range '[0, n - 1]', this process ends. if 'nums[curr] == 0', move in
 * the current direction by incrementing 'curr' if you are moving right, or
 * decrmenting 'curr' if you are moving left. else if 'nums[curr] > 0',
 * decrement 'nums[curr] by 1', reverse your movement direction, take a step in
 * the new direction. a selection of the initial position 'curr' and movement
 * direction is considered valid if every element in 'nums' becomes 0 by the end
 * of the process. return the number of possible valid sections.
 */

int countValidSelections(int *nums, int numsSize) {
  int sum = 0, ans = 0, curr = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  for (int i = 0; i < numsSize; i++) {
    curr += nums[i];
    if (!nums[i]) {
      if (curr * 2 == sum)
        ans += 2;
      else if (abs(sum - 2 * curr) == 1)
        ans++;
    }
  }
  return ans;
}

int main() {
  int n1[] = {1, 0, 2, 0, 3}, n2[] = {2, 3, 4, 0, 4, 1, 0};
  printf("%d\n", countValidSelections(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", countValidSelections(n2, ARRAY_SIZE(n2))); // expect: 0
}
