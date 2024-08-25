// 2860. Happy Students
#include "leetcode.h"

/*
 * you are given a 0 indexed integer array 'nums' of length 'n' where 'n' is the
 * total number of students in the class. the class teacher tries to select a
 * group of students so that all the students remain happy. the i'th student
 * will become happy if one of these two conditions is met: the student is
 * selected and the total number of selected students is strictly greater than
 * 'nums[i]', or the student is not selected and the total number of selected
 * students is strictly less than 'nums[i]'. return the number of ways to select
 * a group of students os that everyone remains happy
 */

static int cmp(const int *const a, const int *const b) { return *a - *b; }

int countWays(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), &cmp);
  int cnt = 0;
  if (nums[0])
    cnt++;
  for (int i = 1; i < numsSize; i++)
    if (nums[i - 1] < i && nums[i] > i)
      cnt++;
  if (nums[numsSize - 1] < numsSize)
    cnt++;
  return cnt;
}

int main() {
  int n1[] = {1, 1}, n2[] = {6, 0, 3, 3, 6, 7, 2, 7};
  printf("%d\n", countWays(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", countWays(n2, ARRAY_SIZE(n2))); // expect: 3
}
