// 287. Find the Duplicate Number
#include "leetcode.h"

/* given an integer array 'nums' containing 'n + 1' integers where each integer
 * is in the range '[1, n]' inclusive. there is only one repeated number in
 * 'nums', return this repeated number. you must solve the problem without
 * modifying the array 'nums' and uses only constant extra space.
 */

int findDuplicate(int *nums, int nums_size) {
  int *cnt = (int *)calloc(nums_size, sizeof(int));
  for (int i = 0; i < nums_size; i++)
    cnt[nums[i] - 1]++;
  for (int i = 0; i < nums_size; i++)
    if (cnt[i] >= 2)
      return i + 1;
  free(cnt);
  return -1;
}

int main() {
  int n1[] = {1, 3, 4, 2, 2}, n2[] = {3, 1, 3, 4, 2};
  printf("%d\n", findDuplicate(n1, 5)); // expect: 2
  printf("%d\n", findDuplicate(n2, 5)); // expect: 3
}
