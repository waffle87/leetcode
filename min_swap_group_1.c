// 2134. Minimum Swaps to Group All 1's Together II
#include "leetcode.h"
#pragma GCC optimize("-O3")

/*
 * a swap is defined as taking two distinct position in an array and swapping
 * the values in them. a circular array is defined as an array where we consider
 * the first element and the last element to adjacent. given a binary circular
 * array 'nums', return the minimum number of swaps required to group all 1's
 * preent in the array together at any location.
 */

int minSwaps(int *nums, int nums_size) {
  int ones = 0, n = nums_size;
  for (int i = 0; i < n; i++)
    if (nums[i] == 1)
      ones++;
  int cnt = 0;
  for (int i = 0; i < ones; i++)
    if (nums[i] == 1)
      cnt++;
  if (cnt == ones)
    return 0;
  int max = cnt;
  for (int i = ones; i < n; i++) {
    if (nums[i] == 1)
      cnt++;
    if (nums[i - ones] == 1)
      cnt--;
    if (cnt == ones)
      return 0;
    max = fmax(max, cnt);
  }
  for (int i = n; i < n + ones; i++) {
    if (nums[i % n] == 1)
      cnt++;
    if (nums[i - ones] == 1)
      cnt--;
    if (cnt == ones)
      return 0;
    max = fmax(max, cnt);
  }
  return ones - max;
}

int main() {
  int n1[] = {0, 1, 0, 1, 1, 0, 0}, n2[] = {0, 1, 1, 1, 0, 0, 1, 1, 0},
      n3[] = {1, 1, 0, 0, 1};
  printf("%d\n", minSwaps(n1, 7)); // expect: 1
  printf("%d\n", minSwaps(n2, 9)); // expect: 2
  printf("%d\n", minSwaps(n3, 5)); // expect: 0
}
