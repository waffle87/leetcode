// 754. Reach a Number
#include "leetcode.h"

/*
 * you are standing at position zero on an infinite number line. there is a
 * destination at position 'target'. you can make some number of moves
 * 'numMoves' so that on each move you can either go left or right, during the
 * i'th move starting from 'i == 1' to 'i == numMoves', you take 'i' steps in
 * the chosen direction. given the integer 'target', return the minimum number
 * of moves required to reach the destination
 */

int reachNumber(int target) {
  target = abs(target);
  int step = sqrt(target * 2);
  int k = (step + 1) * step / 2;
  if (k == target)
    return step;
  if (k < target)
    step++;
  while (1) {
    k = (step + 1) * step / 2;
    if (!((k - target) % 2))
      return step;
    step++;
  }
  return -1;
}

int main() {
  printf("%d\n", reachNumber(2)); // expect: 3
  printf("%d\n", reachNumber(3)); // expect: 2
}
