// 2211. Count Collisions on a Road
#include "leetcode.h"

/*
 * thee are 'n' cars on an infinitely long road. the cars numbered from 0 to 'n
 * - 1' from left to right and each car is present at a unique point. you are
 * given a 0-indexed string 'directions' of length 'n'. 'directions[i]' can be
 * either 'L', 'R', or 'S' denoting whether the i'th car is moving towards the
 * left, right, or staying at its current point. each moving car has the same
 * speed. after a collision, the cars involved can no longer move and will stay
 * at the point where they collided. other than that, cars cannot change their
 * state or direction of motion.
 */

int countCollisions(char *directions) {
  int n = strlen(directions), left = 0, right = n - 1;
  while (left < n && directions[left] == 'L')
    left++;
  while (right >= 0 && directions[right] == 'R')
    right--;
  int collisions = 0;
  for (int i = left; i <= right; i++)
    if (directions[i] != 'S')
      collisions++;
  return collisions;
}

int main() {
  char *d1 = "RLRSLL", *d2 = "LLRR";
  printf("%d\n", countCollisions(d1)); // expect: 5
  printf("%d\n", countCollisions(d2)); // expect: 0
}
