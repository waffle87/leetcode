// 1323. Maximum 69 Number
#include "leetcode.h"

/*
 * you are given a positive integer 'num' consisting only of digit 6 and 9.
 * return the maximum number you can get by changing at most one digit. (6
 * becomes 9, and 9 becomes 6).
 */

int maximum69Number(int num) {
  int right = -1, cnt = 0, tmp = num;
  while (tmp > 0) {
    int digits = tmp % 10;
    if (digits == 6)
      right = cnt;
    cnt++;
    tmp /= 10;
  }
  if (right == -1)
    return num;
  int ans = num + (3 * pow(10, right));
  return ans;
}

int main() {
  printf("%d\n", maximum69Number(9669)); // expect: 9969
  printf("%d\n", maximum69Number(9996)); // expect: 9999
  printf("%d\n", maximum69Number(9999)); // expect: 9999
}
