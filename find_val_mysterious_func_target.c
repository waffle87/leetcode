// 1521. Find a Value of a Mysterious Function Closest to Target
#include "leetcode.h"

/*
 * winston was given the above mysterious function 'func'. he has an integer
 * array 'arr' and an integer 'target' and he wants to find the values 'r' and
 * 'l' that make the value '|func(arr, l, r) - target|' minimum possible. return
 * the minimum possible value of '|func(arr, l, r) - target|'. notice that
 * 'func' should be called with vaues 'l' and 'r' where '0 <= l, r <
 * arr.length'.
 */

int closestToTarget(int *arr, int arrSize, int target) {
  int ans = INT_MAX;
  for (int i = 0; i < arrSize; i++) {
    ans = fmin(ans, abs(arr[i] - target));
    for (int j = i - 1; j >= 0 && (arr[j] & arr[i]) != arr[j]; --j)
      ans = fmin(ans, abs((arr[j] &= arr[i]) - target));
  }
  return ans;
}

int main() {
  int a1[] = {9, 12, 3, 7, 15}, a2[] = {1000000, 1000000, 1000000};
  printf("%d\n", closestToTarget(a1, ARRAY_SIZE(a1), 5)); // expect: 2
  printf("%d\n", closestToTarget(a2, ARRAY_SIZE(a2), 1)); // expect: 999999
}
