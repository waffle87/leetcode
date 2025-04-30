// 2749. Minimum Operations to Make the Integer Zero
#include "leetcode.h"

/*
 * you are given two integers 'nums1' and 'nums2'. in one operation you can
 * choose integer 'i' in the range '[0, 60]' and subtract '2^i + num2' from
 * 'num1'. return the integer denoting the minimum number of operations needed
 * to make 'nums1' equal to 0. if it is impossible to make 'nums1' equal to 0,
 * return -1.
 */

int bit_cnt(long long num) {
  int cnt = 0;
  while (num > 0) {
    cnt += num & 1;
    num >>= 1;
  }
  return cnt;
}

int makeTheIntegerZero(int num1, int num2) {
  if (num1 < num2)
    return -1;
  for (int i = 0; i <= 100; i++) {
    long long diff = num1 - 1LL * num2 * i;
    int bits = bit_cnt(diff);
    if (bits <= i && i <= diff)
      return i;
  }
  return -1;
}

int main() {
  printf("%d\n", makeTheIntegerZero(3, -2)); // expect: 3
  printf("%d\n", makeTheIntegerZero(5, 7));  // expect: -1
}
