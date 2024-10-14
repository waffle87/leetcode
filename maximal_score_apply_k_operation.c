// 2530. Maximal Score After Applying K Operations
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' and an integer 'k'. you have a
 * starting score of 0. in one operation you can choose an index 'i' such that
 * '0 <= i < nums.length', increase your score by 'nums[i]', and replace
 * 'nums[i]' with 'ceil(nums[i] / 3)'. return the maximum possible score you can
 * attain after applying exactly 'k' operations. the ceiling function
 * 'ceil(val)' is the least integer greater than or equal to 'val'.
 */

#define SWAP(x, y)                                                             \
  do {                                                                         \
    typeof(x) _x = x;                                                          \
    typeof(y) _y = y;                                                          \
    x = _y;                                                                    \
    y = _x;                                                                    \
  } while (0)

void heapify(int *arr, int n, int i) {
  int max = i, l = 2 * i + 1, r = 2 * i + 2;
  if (l < n && arr[l] > arr[max])
    max = l;
  if (r < n && arr[r] > arr[max])
    max = r;
  if (max != i) {
    SWAP(arr[i], arr[max]);
    heapify(arr, n, max);
  }
}

void build_heap(int *arr, int n) {
  for (int i = (n / 2) - 1; i >= 0; i--)
    heapify(arr, n, i);
}

long long maxKelements(int *nums, int numsSize, int k) {
  long long score = 0;
  build_heap(nums, numsSize);
  while (k--) {
    score += nums[0];
    nums[0] = ceil(nums[0] / 3.0);
    heapify(nums, numsSize, 0);
  }
  return score;
}

int main() {
  int n1[] = {10, 10, 10, 10, 10}, n2[] = {1, 10, 3, 3, 3};
  printf("%lld\n", maxKelements(n1, ARRAY_SIZE(n1), 5)); // expect: 50
  printf("%lld\n", maxKelements(n2, ARRAY_SIZE(n2), 3)); // expect: 17
}
