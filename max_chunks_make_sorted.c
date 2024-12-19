// 769. Max Chunks To Make Sorted
#include "leetcode.h"

/*
 * you are given an integer array 'arr' of length 'n' that represents a
 * permutation of the integers in the range '[0, n - 1]'. we split 'arr' into
 * some number of chunks (ie. partitions), and individually sort each chunk.
 * after concatenating them, the result should equal the sorted array. return
 * the largest number of chunks we can make to sort the array.
 */

int maxChunksToSorted(int *arr, int arrSize) {
  int cnt = 0, sum = 0, ans = 0;
  for (int i = 0; i < arrSize; i++) {
    sum += i;
    cnt += arr[i];
    if (sum == cnt)
      ans++;
  }
  return ans;
}

int main() {
  int a1[] = {4, 3, 2, 1, 0}, a2[] = {1, 0, 2, 3, 4};
  printf("%d\n", maxChunksToSorted(a1, ARRAY_SIZE(a1))); // expect: 1
  printf("%d\n", maxChunksToSorted(a2, ARRAY_SIZE(a2))); // expect: 4
}
