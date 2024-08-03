// 1460. Make Two Arrays Equal by Reversing Subarrays
#include "leetcode.h"

/*
 * you are given two integer arrays of equal length 'target' and 'arr'. in one
 * step, you can select any non empty subarray of 'arr' and reverse it. you are
 * allowed to make any number of steps. return true if you can make 'arr' equal
 * to 'target' or false otherwise.
 */

bool canBeEqual(int *target, int targetSize, int *arr, int arrSize) {
  if (targetSize != arrSize)
    return false;
  int cnt[1001] = {0};
  for (int i = 0; i < targetSize; i++) {
    cnt[target[i]]++;
    cnt[arr[i]]--;
  }
  for (int i = 0; i < 1001; i++)
    if (cnt[i])
      return false;
  return true;
}

int main() {
  int t1[] = {1, 2, 3, 4}, a1[] = {2, 4, 1, 3}, t2[] = {7}, a2[] = {7},
      t3[] = {3, 7, 9}, a3[] = {3, 7, 11};
  printf("%d\n",
         canBeEqual(t1, ARRAY_SIZE(t1), a1, ARRAY_SIZE(a1))); // expect: 1
  printf("%d\n",
         canBeEqual(t2, ARRAY_SIZE(t2), a2, ARRAY_SIZE(a2))); // expect: 1
  printf("%d\n",
         canBeEqual(t3, ARRAY_SIZE(t3), a3, ARRAY_SIZE(a3))); // expect: 0
}
