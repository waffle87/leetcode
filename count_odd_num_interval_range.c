// 1523. Count Odd Numbers in an Interval Range
#include "leetcode.h"

// given two non-negative integers 'low' and 'high' return the
// count of odd numbers  * between 'low' and 'high' (incusively)

int countOdds(int low, int high) { return (high - (low & ~1) + 1) >> 1; }

int main() {
  printf("%d\n", countOdds(3, 7));  // expect: 3
  printf("%d\n", countOdds(8, 10)); // expect: 1
}
