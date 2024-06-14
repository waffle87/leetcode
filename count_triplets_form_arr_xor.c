// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
#include "leetcode.h"

/*
 * given an array of integers 'arr'. we want to select three indices 'i', 'j',
 * and 'k' where '(0 <= i < j <= k < arr.length)'. lets define 'a' and 'b' as
 * follows. 'a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]', 'b = arr[j] ^ arr[j +
 * 1] ^ ... ^ arr[k]'. note that '^' denotes the bitwise xor operation. return
 * the number of triplets (i, j, and k) where 'a == b'
 */

int countTriplets(int *arr, int arrSize) {
  if (arrSize < 2)
    return 0;
  int ans = 0;
  for (int i = 0; i < arrSize; i++) {
    int tmp = arr[i];
    for (int j = i + 1; j < arrSize; j++) {
      tmp ^= arr[j];
      if (!tmp)
        ans += j - i;
    }
  }
  return ans;
}

int main() {
  int a1[] = {2, 3, 1, 6, 7}, a2[] = {1, 1, 1, 1, 1};
  printf("%d\n", countTriplets(a1, ARRAY_SIZE(a1))); // expect: 4
  printf("%d\n", countTriplets(a2, ARRAY_SIZE(a2))); // expect: 10
}
