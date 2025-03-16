// 477. Total Hamming Distance
#include "leetcode.h"

/*
 * the hamming distance between two integers is the number of positions at which
 * the corresponding bits are different. given an integer array 'nums', return
 * the sum of hamming distances between all the pairs of the integers in 'nums'.
 */

int totalHammingDistance(int *nums, int numsSize) {
  int total = 0;
  for (int i = 0; i < 32; i++) {
    int cnt = 0;
    for (int j = 0; j < numsSize; j++)
      cnt += (nums[j] >> i) & 1;
    total += cnt * (numsSize - cnt);
  }
  return total;
}

int main() {
  int n1[] = {4, 14, 2}, n2[] = {4, 14, 4};
  printf("%d\n", totalHammingDistance(n1, ARRAY_SIZE(n1))); // expect: 6
  printf("%d\n", totalHammingDistance(n2, ARRAY_SIZE(n2))); // expect: 4
}
