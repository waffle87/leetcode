// 2566. Maximum Difference by Remapping a Digit
#include "leetcode.h"

/*
 * you are given an integer 'num'. you know that bob will sneakily remap one of
 * the 10 possible digits to another digit. return the difference between the
 * maximum and minimum values bob can make by remapping exactly one digit in
 * nums.
 */

int minMaxDifference(int num) {
  int min = num, max = num;
  for (int i = 0; i < 10; ++i) {
    int low = 0, high = 0, mult = 1;
    for (int j = num; j; j /= 10) {
      bool replace = j % 10 == i;
      low += (replace ? 0 : j % 10) * mult;
      high += (replace ? 9 : j % 10) * mult;
      mult *= 10;
    }
    min = fmin(min, low);
    max = fmax(max, high);
  }
  return max - min;
}

int main() {
  printf("%d\n", minMaxDifference(11891)); // expect: 99009
  printf("%d\n", minMaxDifference(90));    // expect: 99
}
