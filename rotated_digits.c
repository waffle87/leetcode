// 788. Rotated Digits
#include "leetcode.h"

/*
 * an integer 'x' is good if after rotating each digit individually by 180
 * degrees, we get a valid number that is different from 'x'. each digit must be
 * rotated - we cannot choose to leave it alone. a number is valid if each digit
 * remains after rotation. given the integer 'n', return the number of good
 * integers in the range '[1, n]'.
 */

int rotatedDigits(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int check = i;
    bool valid = true, changed = false;
    while (check > 0 && valid) {
      int digit = check % 10;
      if (digit == 3 || digit == 4 || digit == 7)
        valid = false;
      else if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
        changed = true;
      check /= 10;
    }
    if (valid && changed)
      cnt++;
  }
  return cnt;
}

int main() {
  int r1 = rotatedDigits(10);
  int r2 = rotatedDigits(1);
  int r3 = rotatedDigits(2);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 1);
}
