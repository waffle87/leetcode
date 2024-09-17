// 565. Array Nesting
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' where 'nums' is a
 * permutation of the numbers in the range '[0, n - 1]'. you should bild a set
 * 's[k] = {nums[k], nums[nums[k]], ... }' subjected to the following rules: the
 * first element in 's[k]' starts with the selection of the element 'nums[k]' of
 * 'index = k'. the next element in 's[k]' should be 'nums[nums[k]]', and so on.
 * we stop adding right before a duplication element occurs in 's[k]'. return
 * the longest set of 's[k]'
 */

int arrayNesting(int *nums, int numsSize) {
  int max = 0, cnt = 0;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] != -1) {
      int j = nums[i];
      cnt = 0;
      while (j != i) {
        cnt++;
        int tmp = nums[j];
        nums[j] = -1;
        j = tmp;
      }
      cnt++;
      if (cnt > max)
        max = cnt;
    }
  return max;
}

int main() {
  int n1[] = {5, 4, 0, 3, 1, 6, 2}, n2[] = {0, 1, 2};
  printf("%d\n", arrayNesting(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", arrayNesting(n2, ARRAY_SIZE(n2))); // expect: 1
}
