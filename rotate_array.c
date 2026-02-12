// 189. Rotate Array
#include "leetcode.h"

/*
 * given an integer array 'nums', rotate the array to the right by 'k' stops,
 * where 'k' is non-negative.
 */

void reverse(int *nums, int start, int end) {
  while (start < end) {
    nums[start] ^= nums[end];
    nums[end] ^= nums[start];
    nums[start++] ^= nums[end--];
  }
}

void rotate(int *nums, int numsSize, int k) {
  int start = 0, end = numsSize - 1;
  k %= numsSize;
  reverse(nums, start, end - k);
  reverse(nums, numsSize - k, end);
  reverse(nums, start, end);
}

int main() {
  int n1[] = {1, 2, 3, 4, 5, 6, 7}, r1[] = {5, 6, 7, 1, 2, 3, 4};
  int n2[] = {-1, -100, 3, 99}, r2[] = {3, 99, -1, -100};
  rotate(n1, ARRAY_SIZE(n1), 3);
  rotate(n2, ARRAY_SIZE(n2), 2);
  for (int i = 0; i < ARRAY_SIZE(n1); i++) {
    printf("%d ", n1[i]);
    assert(r1[i] == n1[i]);
  }
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(n2); i++) {
    printf("%d ", n2[i]);
    assert(r2[i] == n2[i]);
  }
  printf("\n");
}
