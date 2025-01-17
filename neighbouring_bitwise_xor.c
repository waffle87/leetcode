// 2683. Neighboring Bitwise XOR
#include "leetcode.h"

/*
 * a 0-indexed array 'derived' with length 'n' is derived by computing the
 * bitwise xor of adjacnet values in a binary array 'original' of length 'n'.
 * specifically, for each index 'i' in the range '[0, n - 1]' if 'i = n - 1'
 * then 'derived[i] = original[i] ^ original[0]', otherwise 'derived[i] =
 * original[i] ^ original[i + 1]'. given an array 'derived', your task is to
 * determine whether there exists a valid binary array 'original' that could
 * have formed 'derived'. return true if such an array exists or false
 * otherwise.
 */

bool doesValidArrayExist(int *derived, int derivedSize) {
  int ans = 0;
  for (int i = 0; i < derivedSize; i++)
    ans ^= derived[i];
  return !ans;
}

int main() {
  int d1[] = {1, 1, 0}, d2[] = {1, 1}, d3[] = {1, 0};
  printf("%d\n", doesValidArrayExist(d1, ARRAY_SIZE(d1))); // expect: 1
  printf("%d\n", doesValidArrayExist(d2, ARRAY_SIZE(d2))); // expect: 1
  printf("%d\n", doesValidArrayExist(d3, ARRAY_SIZE(d3))); // expect: 0
}
