// 762. Prime Number of Set Bits in Binary Representation
#include "leetcode.h"

/*
 * given two integers 'left' and 'right', return the count of numbers in the
 * inclusive range '[left, right]' having a prime number of set bits in their
 * binary representation. recall that the number of set bits an integer has is
 * the number of 1's present when written in binary.
 */

int countPrimeSetBits(int left, int right) {
  int primes = 0b10100010100010101100, cnt = 0;
  while (left <= right)
    cnt += primes >> __builtin_popcount(left++) & 1;
  return cnt;
}

int main() {
  printf("%d\n", countPrimeSetBits(6, 10));  // expect:
  printf("%d\n", countPrimeSetBits(10, 15)); // expect: 5
}
