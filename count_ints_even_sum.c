// 2180. Count Integers With Even Digit Sum
#include <stdio.h>

/*
 * given a positive integer 'num', return the number of positive integersless
 * than or equal to 'num' whose digit sums are event. the digitsum of a positive
 * integer is the sum of all of its digits.
 */

int countEven(int num) {
  int ans = 0;
  for (int i = 1; i <= num; i++) {
    int val = i, d = 0;
    while (val) {
      d += val % 10;
      val /= 10;
    }
    if (d % 2 == 0)
      ans++;
  }
  return ans;
}

int main() {
  printf("%d\n", countEven(4));  // expect: 2
  printf("%d\n", countEven(30)); // expect: 14
}
