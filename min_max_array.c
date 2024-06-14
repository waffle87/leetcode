// 2439. Minimize Maximum of Array
#include <stdio.h>
#include <stdlib.h>

/*
 * given a 0-indexed array 'nums' comprising of n unsigned integers. ine one
 * operation you must choose an integer 'i' such that '1 <= i < n' and 'nums[i]
 * > 0'. decrease 'nums[i]' by 1 or increase 'nums[i]' by 1. return minimum
 * possible value of the max integer 'nums' after performing any number of
 * operations.
 */

#define MAX(a, b) a > b ? a : b

int minmizeArrayValue(int *nums, int nums_size) {
  long long ans, pre = 0;
  for (int i = 0; i < nums_size; i++) {
    pre += nums[i];
    ans = MAX(ans, (pre + i) / (i + 1));
  }
  return ans;
}

int main() {
  int n1[] = {3, 7, 1, 6}, n2[] = {10, 1};
  printf("%d\n", minmizeArrayValue(n1, 4)); // expect: 5
  printf("%d\n", minmizeArrayValue(n2, 2)); // expect: 10
}
