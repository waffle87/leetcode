// 1295. Find Numbers with Even Number of Digits
#include "leetcode.h"

/*
 * given an array 'nums' of integers, return how many of them contain an even
 * number of digits.
 */

int findNumbers(int *nums, int numsSize) {
  int cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    int curr = 0;
    while (nums[i]) {
      curr++;
      nums[i] /= 10;
    }
    if (!(curr & 1))
      cnt++;
  }
  return cnt;
}

int main() {
  int n1[] = {12, 345, 2, 6, 7896}, n2[] = {555, 901, 482, 1771};
  printf("%d\n", findNumbers(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", findNumbers(n2, ARRAY_SIZE(n2))); // expect: 1
}
