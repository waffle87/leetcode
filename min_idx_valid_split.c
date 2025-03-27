// 2780. Minimum Index of a Valid Split
#include "leetcode.h"

/*
 * an element 'x' of an integer array 'arr' of length 'm' is dominant if more
 * than half the elements of 'arr' have a value of 'x'. you are given a
 * 0-indexed integer array 'nums' of length 'n' with one dominant element. you
 * can split 'nums' at an index 'i' into two arrays 'nums[0, ..., i]' and
 * 'nums[i + 1, ..., n - 1]', but the split is only valid if '0 <= i < - 1' and
 * the two arrays have the same dominant element. return the minimum index of a
 * valid split. if no split exists, return -1.
 */

int minimumIndex(int *nums, int numsSize) {
  int dominant = nums[0], cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    cnt = nums[i] == dominant ? cnt + 1 : cnt - 1;
    if (!cnt) {
      dominant = nums[i];
      cnt = 1;
    }
  }
  int left = 0;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] == dominant)
      left++;
  cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == dominant)
      cnt++;
    if (cnt * 2 > (i + 1) && (left - cnt) * 2 > (numsSize - i - 1))
      return i;
  }
  return -1;
}

int main() {
  int n1[] = {1, 2, 2, 2}, n2[] = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1},
      n3[] = {3, 3, 3, 3, 7, 2, 2};
  printf("%d\n", minimumIndex(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", minimumIndex(n2, ARRAY_SIZE(n2))); // expect: 4
  printf("%d\n", minimumIndex(n3, ARRAY_SIZE(n3))); // expect: -1
}
