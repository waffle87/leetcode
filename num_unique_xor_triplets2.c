// 3514. Number of Unique XOR Triplets II
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. an xor triplet is defined as the xor
 * of three elements 'nums[i] ^ nums[j] ^ nums[k]' where 'i <= j <= k'. return
 * the number of unique xor triplet values from all possible triplets '(i, j,
 * k)'.
 */

int uniqueXorTriplets(int *nums, int numsSize) {
  int max_num = nums[0], n = 1;
  for (int i = 1; i < numsSize; i++)
    max_num = fmax(max_num, nums[i]);
  while (n <= max_num)
    n <<= 1;
  bool *one = (bool *)calloc(n, sizeof(bool));
  bool *two = (bool *)calloc(n, sizeof(bool));
  bool *three = (bool *)calloc(n, sizeof(bool));
  for (int i = 0; i < numsSize; i++) {
    int x = nums[i];
    one[x] = true;
    for (int y = 0; y < n; y++)
      if (one[y])
        two[y ^ x] = true;
  }
  for (int i = 0; i < numsSize; i++) {
    int x = nums[i];
    for (int y = 0; y < n; y++)
      if (two[y])
        three[y ^ x] = true;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += three[i];
  free(one);
  free(two);
  free(three);
  return ans;
}

int main() {
  int n1[] = {1, 3}, n2[] = {6, 7, 8, 9};
  int r1 = uniqueXorTriplets(n1, ARRAY_SIZE(n1));
  int r2 = uniqueXorTriplets(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 4);
}
