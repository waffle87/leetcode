// 1803. Count Pairs With XOR in a Range
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'numss' and two integers 'low' and 'high',
 * return the numsber of nice pairs. a nice pair is a pair '(i, j)' where '0 <=
 * i < j < numss.len' and 'low <= (numss[i] ^ numss[j]) <= high'.
 */

#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <x86intrin.h>

/*
 * the following code is heavily optimised with avx2 intrinsics and has zero
 * branching. the general structure follows an intuitive brute force approach:
 *
 * int pairs = 0;
 * for (int i = 0; i < numsSize - 1; i++)
 *   for (int j = i + 1; j < n; j++)
 *     if ((nums[i] ^ nums[j]) >= low && (nums[i] ^ nums[j]) <= high)
 *       pairs++;
 * return pairs;
 */

int countPairs(int *nums, int numsSize, int low, int high) {
  int pairs = 0;

  /*
   * store input as 16-bit integers, allowing 16 pairs to be processed per
   * iteration. 32 bytes of extra entries are added to avoid kludge for last
   * entries. the inner loop will process the array in chunks of 16 shorts per
   * execution
   */
  unsigned short __attribute__((aligned(32))) d[numsSize + 16];
  for (int i = 0; i < numsSize; i++)
    d[i] = nums[i];
  for (int i = numsSize; i < numsSize + 16; i++)
    d[i] = 0xFFFF;

  /*
   * create arrays for lower and upper bound. the '_m256i' type is a 256-bit
   * register that can hold 16 shorts at a time. two registers are allocated
   * with each 16-bit value set to low and high respectively
   */
  const __m256i low_mask = _mm256_set1_epi16((short)low);
  const __m256i high_mask = _mm256_set1_epi16((short)high);

  for (int i = 0; i < numsSize - 1; i++) {
    // iterate through elements and create a register array 'a[i]' where 16
    // elements are set to 'd[i]'
    __m256i ai = _mm256_set1_epi16(d[i]);

    // critical section
    for (int j = i + 1; j < numsSize; j += 16) {
      // read 16 numbers to array 'a[j]'
      __m256i aj = _mm256_lddqu_si256((__m256i *)(d + j));

      // XOR them with array 'a[i]', essentially creating array of '{d[j] ^
      // d[i], d[j + 1] ^ d[i], ..., d[j + 15] ^ d[i]}'
      __m256i xij = _mm256_xor_si256(ai, aj);

      /*
       * compare XOR results with upper and lower bounds. the 'cmpgt' intrinsic
       * creates an array of compare results, where an element is set to
       * '0xFFFF' when the corresponding element in 'xij' is greater than the
       * corresponding element in 'high_mask'
       */
      __m256i high_ans = _mm256_cmpgt_epi16(xij, high_mask);
      __m256i low_ans = _mm256_cmpgt_epi16(low_mask, xij);

      /*
       * OR the comparison results to mask, count the number of high bits set,
       * and add it to 'pairs'. note, the comparison sets bits when the XOR is
       * outside the '[low, high]' interval
       */
      __m256i ans = _mm256_or_si256(high_ans, low_ans);
      pairs += 32 - __builtin_popcount(_mm256_movemask_epi8(ans));
    }
  }
  return pairs >> 1;
}

int main() {
  int n1[] = {1, 4, 2, 7}, n2[] = {9, 8, 4, 2, 1};
  printf("%d\n", countPairs(n1, ARRAY_SIZE(n1), 2, 6));  // expect: 6
  printf("%d\n", countPairs(n2, ARRAY_SIZE(n2), 5, 14)); // expect: 8
}
