// 717. 1-bit and 2-bit Characters
#include "leetcode.h"

/*
 * we have two special characters: the first character is represented by one bit
 * 0, and the second character can be represented by two bits (10 or 11). given
 * a binary array 'bits' that ends with 0, return true if the last character
 * must be a one-bit character.
 */

bool isOneBitCharacter(int *bits, int bitsSize) {
  int i = bitsSize - 2;
  while (i >= 0 && bits[i] > 0)
    i--;
  return !((bitsSize - i) % 2);
}

int main() {
  int b1[] = {1, 0, 0}, b2[] = {1, 1, 1, 0};
  printf("%d\n", isOneBitCharacter(b1, ARRAY_SIZE(b1))); // expect: 1
  printf("%d\n", isOneBitCharacter(b2, ARRAY_SIZE(b2))); // expect: 0
}
