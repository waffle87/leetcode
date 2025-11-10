// 3542. Minimum Operations to Convert All Elements to Zero
#include "leetcode.h"

/*
 * you are given an array 'nums' of size 'n' consisting of non-negative
 * integers. your task is to apply some (possibly zero) operations on the array
 * so that all elements become 0. in one operation, you can select a subarray
 * '[i, j]' where '0 <= i <= j < n' and set all occurences of the minimum
 * non-negative integer in that subarray to zero. return the minimum number of
 * operations required to make all elements in the array 0
 */

int minOperations(int *nums, int numsSize) {
  int *stack = (int *)malloc(numsSize * sizeof(int));
  int top = 0, ans = 0;
  for (int i = 0; i < numsSize; ++i) {
    int curr = nums[i];
    while (top > 0 && stack[top - 1] > curr)
      --top;
    if (!curr)
      continue;
    if (!top || stack[top - 1] < curr) {
      ans++;
      stack[top++] = curr;
    }
  }
  free(stack);
  return ans;
}

int main() {
  int n1[] = {0, 2}, n2[] = {3, 1, 2, 1}, n3[] = {1, 2, 1, 2, 1, 2};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2))); // expect: 3
  printf("%d\n", minOperations(n3, ARRAY_SIZE(n3))); // expect: 4
}
