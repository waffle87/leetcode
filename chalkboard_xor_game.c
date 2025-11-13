// 810. Chalkboard XOR Game
#include "leetcode.h"

/*
 * you are given an array of integers 'nums' that represents the numbers written
 * on a chalboard. alice and bob take turns erasing exactly one number from the
 * chalboard, with alice starting first. if erasing a number causes the bitwise
 * xor of all the elements of the chalboard to become 0, then the player loses.
 * the bitwise xor of one element is that element itself, and the bitwise xor of
 * no elements is 0. also, if any player starts their turn with the bitwise xor
 * of all the elements of the Chalkboard equal to 0 then that player wins.
 * return true if and only if alice wins the game, assuming both players play
 * optimally.
 */

bool xorGame(int *nums, int numsSize) {
  int x = 0;
  for (int i = 0; i < numsSize; i++)
    x ^= nums[i];
  return !x || !(numsSize % 2);
}

int main() {
  int n1[] = {1, 1, 2}, n2[] = {0, 1}, n3[] = {1, 2, 3};
  printf("%d\n", xorGame(n1, ARRAY_SIZE(n1))); // expect: 0
  printf("%d\n", xorGame(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", xorGame(n3, ARRAY_SIZE(n3))); // expect: 1
}
