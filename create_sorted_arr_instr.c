// 1649. Create Sorted Array through Instructions
#include "leetcode.h"

/*
 * given an integer array 'instructions', you are asked to create a sorted array
 * from the elements in 'instructions'. you start with an empty container
 * 'nums'. for each element from left to right in 'instructions', insert it into
 * 'nums'. the cost of each insertion is the minimum of the following: the
 * number of elements currently in 'nums' that are strictly less than
 * 'instructions[i]', the number of elements currently in 'nums' that are
 * strictly greater than 'instructions[i]'. return the total cost to insert all
 * elements from 'instructions' into 'nums'. since the answer may be large,
 * return it modulo 10^9 + 7
 */

static int arr[10001];

void update(int x) {
  while (x < 10001) {
    arr[x]++;
    x += x & -x;
  }
}

int get(int x) {
  int res = 0;
  while (x > 0) {
    res += arr[x];
    x -= x & -x;
  }
  return res;
}

int createSortedArray(int *instructions, int instructionsSize) {
  memset(arr, 0, sizeof(arr));
  int ans = 0, mod = 1e9 + 7;
  for (int i = 0; i < instructionsSize; i++) {
    ans =
        (ans + fmin(get(instructions[i] - 1), i - get(instructions[i]))) % mod;
    update(instructions[i]);
  }
  return ans;
}

int main() {
  int i1[] = {1, 5, 6, 2}, i2[] = {1, 2, 3, 6, 5, 4},
      i3[] = {1, 2, 3, 3, 2, 4, 2, 1, 2};
  printf("%d\n", createSortedArray(i1, ARRAY_SIZE(i1))); // expect: 1
  printf("%d\n", createSortedArray(i2, ARRAY_SIZE(i2))); // expect: 3
  printf("%d\n", createSortedArray(i3, ARRAY_SIZE(i3))); // expect: 4
}
