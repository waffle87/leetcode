// 1318. Minimum Flips to Make a OR b Equal to c
#include "leetcode.h"

/*
 * given three positive numbers 'a, b, c'. return the minimum flips required in
 * some bits of 'a | b == c'. flip operation consists of changing any single bit
 * 1 to 0 or changing the bit 0 to 1 in their binary representation
 */

class Solution {
public:
  int minFlips(int a, int b, int c) {
    return __builtin_popcount(c ^= a | b) + __builtin_popcount(a & b & c);
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.minFlips(2, 6, 5)); // expect: 3
  printf("%d\n", obj.minFlips(4, 2, 7)); // expect: 1
  printf("%d\n", obj.minFlips(1, 2, 3)); // expect: 0
}
