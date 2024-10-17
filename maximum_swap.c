// 670. Maximum Swap
#include "leetcode.h"

/*
 * you are given an integer 'num'. you can swap two digits at most once to get
 * the maximum valued number. return the maximum valued number you can get.
 */

int maximumSwap(int num) {
  int digits[9] = {0}, idx = 8;
  while (num) {
    digits[idx--] = num % 10;
    num /= 10;
  }
  idx++;
  for (int i = idx; i < 9; i++) {
    int max_idx = i;
    for (int j = i + 1; j < 9; j++)
      if (digits[j] >= digits[max_idx])
        max_idx = j;
    if (digits[i] < digits[max_idx]) {
      digits[i] ^= digits[max_idx];
      digits[max_idx] ^= digits[i];
      digits[i] ^= digits[max_idx];
      break;
    }
  }
  num = 0;
  for (; idx < 9; idx++) {
    num *= 10;
    num += digits[idx];
  }
  return num;
}

int main() {
  printf("%d\n", maximumSwap(2736)); // expect: 7236
  printf("%d\n", maximumSwap(9973)); // expect: 9973
}
