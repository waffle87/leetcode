// 3513. Number of Unique XOR Triplets I
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n', where 'nums' is a
 * permutation of the numbers in the range '[1, n]'. a xor triplet is defined as
 * the xor of three elements 'nums[i] ^ nums[j] ^ nums[k]' where 'i <= j <= k'.
 * return the number of unique xor triplet values from each possible triplets
 * '(i, j, k)'.
 */

int uniqueXorTriplets(int *nums, int numsSize) {
  int n = numsSize;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  return (n + 1) >> (3 / (numsSize + 1));
}

int main() {
  int n1[] = {1, 2}, n2[] = {3, 1, 2};
  int r1 = uniqueXorTriplets(n1, ARRAY_SIZE(n1));
  int r2 = uniqueXorTriplets(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 4);
}
