// 991. Broken Calculator
#include <stdio.h>
#include <stdlib.h>

/*
 * there is a broken calculator that has the integer 'start_value' on its
 * display initially. in one operation, you can
 * - multiply thenumber on display by 2
 * - subtract 1 from number on display
 * given two integers 'start_value' and 'target', return the minimum number of
 * operations needed to display 'target' on the calculator
 */

int brokenCalc(int start_value, int target) {
  int ans = 0;
  while (target > start_value) {
    target = !(target % 2) ? target / 2 : target + 1;
    ++ans;
  }
  return ans + start_value - target;
}

int main() {
  printf("%d\n", brokenCalc(2, 3));  // expect: 2
  printf("%d\n", brokenCalc(5, 8));  // expect: 2
  printf("%d\n", brokenCalc(3, 10)); // expect: 3
}
