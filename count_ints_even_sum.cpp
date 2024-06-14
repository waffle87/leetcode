// 2180. Count Integers With Even Digit Sum
#include "leetcode.h"

/*
 * given a positive integer 'num', return the number of positive integersless
 * than or equal to 'num' whose digit sums are event. the digitsum of a positive
 * integer is the sum of all of its digits.
 */

class Solution {
public:
  int countEven(int num) {
    int tmp = num, sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum % 2 == 0 ? tmp / 2 : (tmp - 1) / 2;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.countEven(4));  // expect: 2
  printf("%d\n", obj.countEven(30)); // expect: 14
}
