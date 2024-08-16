// 624. Maximum Distance in Arrays
#include "leetcode.h"

/*
 * you are given 'm' arrays where each array is sorted in ascending order. you
 * can pick up two integers from two different arrays (each array picks one) and
 * calculate the distance. we define the distance between two integer 'a' and
 * 'b' to be their absolute idfferent '|a - b|'. return the maximum distance
 */

int maxDistance(int **arrays, int arraysSize, int *arraysColSize) {
  if (!arraysSize)
    return -1;
  int min = arrays[0][0], max = arrays[0][arraysColSize[0] - 1], ans = 0;
  for (int i = 1; i < arraysSize; i++) {
    int curr = fmax(arrays[i][arraysColSize[i] - 1] - min, max - arrays[i][0]);
    ans = fmax(max, curr);
    min = fmin(min, arrays[i][0]);
    max = fmax(max, arrays[i][arraysColSize[i] - 1]);
  }
  return ans;
}

int main() {
  int a1[][3] = {{1, 2, 3}, {4, 5}, {1, 2, 3}}, a2[][2] = {{1}, {1}};
  int acs1[] = {3, 3, 2}, acs2[] = {1, 1};
  printf("%d\n", maxDistance((int **)a1, ARRAY_SIZE(a1), acs1)); // expect: 4
  printf("%d\n", maxDistance((int **)a2, ARRAY_SIZE(a2), acs2)); // expect: 0
}
