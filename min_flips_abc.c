// 1318. Minimum Flips to Make a OR b Equal to c
#include <stdio.h>
#include <stdlib.h>

/*
 * given three positive numbers 'a, b, c'. return the minimum flips required in
 * some bits of 'a | b == c'. flip operation consists of changing any single bit
 * 1 to 0 or changing the bit 0 to 1 in their binary representation
 */

int minFlips(int a, int b, int c) {
  int *digit = calloc(31, sizeof(int));
  int idx = 0;
  while (a) {
    digit[idx] += (a & 1);
    a >>= 1;
    idx++;
  }
  idx = 0;
  while (b) {
    digit[idx] += (b & 1);
    b >>= 1;
    idx++;
  }
  int ans = 0;
  for (int i = 0; i < 31; i++) {
    if ((c >> i) & 1)
      ans += (digit[i] == 0);
    else
      ans += digit[i];
  }
  return ans;
}

int main() {
  printf("%d\n", minFlips(2, 6, 5)); // expect: 3
  printf("%d\n", minFlips(4, 2, 7)); // expect: 1
  printf("%d\n", minFlips(1, 2, 3)); // expect: 0
}
