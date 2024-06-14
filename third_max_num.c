// 414. Third Maximum Number
#include "leetcode.h"

/*
 * given an integer array 'nums', return the third distinct maximum number in
 * this array. if the third maximum number does not exist, return the maximum
 * number.
 */

int thirdMax(int *nums, int numsSize) {
  int m1, m2, m3, cnt = 0;
  m1 = m2 = m3 = INT_MIN;
  for (int i = 0; i < numsSize; i++)
    if (m1 <= nums[i])
      m1 = nums[i];
  for (int i = 0; i < numsSize; i++)
    if (m2 <= nums[i] && nums[i] < m1)
      m2 = nums[i];
  for (int i = 0; i < numsSize; i++)
    if (m3 <= nums[i] && nums[i] < m2) {
      m3 = nums[i];
      cnt++;
    }
  if (!cnt)
    return m1;
  return m3;
}

int main() {
  int n1[] = {3, 2, 1}, n2[] = {1, 2}, n3[] = {2, 2, 3, 1};
  printf("%d\n", thirdMax(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", thirdMax(n2, ARRAY_SIZE(n2))); // expect: 2
  printf("%d\n", thirdMax(n3, ARRAY_SIZE(n3))); // expect: 1
}
