// 1306. Jump Game III
#include "leetcode.h"

/*
 * given an array of non-negative integers 'arr', you are initially positioned
 * at 'start' index of the array. when you are at index 'i', you can jump to 'i
 * + arr[i]' or 'i - arr[i]', check if you can reach any index with value 0.
 * notice that you cannot jump outside of the array at any time.
 */

bool canReach(int *arr, int arrSize, int start) {
  return 0 <= start && start < arrSize && arr[start] >= 0 &&
         (!(arr[start] = -arr[start]) ||
          canReach(arr, arrSize, start + arr[start]) ||
          canReach(arr, arrSize, start - arr[start]));
}

int main() {
  int a1[] = {4, 2, 3, 0, 3, 1, 2};
  int a2[] = {4, 2, 3, 0, 3, 1, 2};
  int a3[] = {3, 0, 2, 1, 2};
  bool r1 = canReach(a1, ARRAY_SIZE(a1), 5);
  bool r2 = canReach(a2, ARRAY_SIZE(a2), 0);
  bool r3 = canReach(a3, ARRAY_SIZE(a3), 2);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == true);
  printf("%d\n", r3);
  assert(r3 == false);
}
