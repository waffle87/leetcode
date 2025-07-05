// 1394. Find Lucky Integer in an Array
#include "leetcode.h"

/*
 * given an array of integers 'arr', a lucky integer is an integer equal that
 * has a frequency in the array equal to its value. return the largest lucky
 * integer in the array. if there is no lucky integer, return -, a lucky integer
 * is an integer equal that has a frequency in the array equal to its value.
 * return the largest lucky integer in the array. if there is no lucky integer,
 * return -1
 */

int findLucky(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    arr[i] &= 0xFFFF;
    int curr = arr[i];
    if (curr <= arrSize)
      arr[curr - 1] += 0x10000;
  }
  for (int i = arrSize; i > 0; --i)
    if ((arr[i - 1] >> 16) == i)
      return i;
  return -1;
}

int main() {
  int a1[] = {2, 2, 3, 4}, a2[] = {1, 2, 2, 3, 3, 3}, a3[] = {2, 2, 2, 3, 3};
  printf("%d\n", findLucky(a1, ARRAY_SIZE(a1))); // expect: 2
  printf("%d\n", findLucky(a2, ARRAY_SIZE(a2))); // expect: 3
  printf("%d\n", findLucky(a3, ARRAY_SIZE(a3))); // expect: -1
}
