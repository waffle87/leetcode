// 2997. Minimum Number of Operations to Make Array XOR Equal to K
#include "leetcode.h"

/*
 * given a 0-indexed array 'nums' and a positive integer 'k'. you can apply the
 * following operation on the array any number of times: choose any element of
 * the array and flip a bit in its binary representation. flipping a bit means
 * chaning a 0 to a 1 or vice versa. return the minimum number of operations
 * required to make the bitwise xor of all elements in the array equal to 'k'.
 * note that you can flip leading zero bits in the binary representation of the
 * elements. for example, for the number of '101_2' you can flip the fouth bit
 * and obtain '1101_2'
 */

int minOperations(int *nums, int numsSize, int k) {
  int xor = 0, ops = 0;
  for (int i = 0; i < numsSize; i++)
    xor ^= nums[i];
  if (xor == k)
    return 0;
  while (k || xor) {
    if (k % 2 != xor % 2)
      ops++;
    k /= 2;
    xor /= 2;
  }
  return ops;
}

int main() {
  int n1[] = {2, 1, 3, 4}, n2[] = {2, 0, 2, 0};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1), 1)); // expect: 2
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2), 0)); // expect: 0
}
