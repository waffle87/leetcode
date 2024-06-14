// 137. Single Number II
#include <stdio.h>

/*
 * given an integer array 'nums' where every element appears three times except
 * for one, which appears exactly once. find the single element and return it.
 * you must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 */

int singleNumber(int *nums, int nums_size) {
  int ans = 0, sum;
  for (int i = 0; i < 32; i++) {
    long long mask = 1 << i;
    sum = 0;
    for (int j = 0; j < nums_size; j++)
      if (mask & nums[j])
        sum++;
    if (sum % 3)
      ans |= mask;
  }
  return ans;
}

int main() {
  int n1[] = {2, 2, 3, 2};
  int n2[] = {0, 1, 0, 1, 0, 1, 99};
  printf("%d\n", singleNumber(n1, 4)); // expect: 3
  printf("%d\n", singleNumber(n2, 7)); // expect: 99
}
