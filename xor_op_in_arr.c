// 1486. XOR Operation in an Array
#include "leetcode.h"

/*
 * you are given an integer 'n' and an integer 'start'. define an array 'nums'
 * where 'nums[i] = star + 2 * i' and 'n == nums.length'. return bitwise xor of
 * all elements of 'nums'.
 */

int xor_b(int n, int start) {
  if (!(n % 2))
    return (n / 2) & 1;
  else
    return ((n / 2) & 1) ^ (start + n - 1);
}

int xor_a(int n, int start) {
  if (start & 1)
    return (start - 1) ^ xor_b(n + 1, start - 1);
  else
    return xor_b(n, start);
}

int xorOperation(int n, int start) {
  int ans = 2 * xor_a(n, start / 2);
  if (n & start & 1)
    ans++;
  return ans;
}

int main() {
  printf("%d\n", xorOperation(5, 0)); // expect: 8
  printf("%d\n", xorOperation(4, 3)); // expect: 8
}
