// 2833. Furthest Point From Origin
#include "leetcode.h"

/*
 * you are given a string 'moves' of length 'n' consisting only of characters L
 * R and _. the string represents your movement on a number line starting from
 * the origin. in the i'th move, you can choose one of the following directions:
 * move to the left if 'moves[i] = L' or 'moves[i] = _', and move to the right
 * 'moves[i] = R' or 'moves[i] = _'. return the distance from the origin of the
 * furthest point you can get to after 'n' moves.
 */

int furthestDistanceFromOrigin(char *moves) {
  int l = 0, r = 0, n = strlen(moves);
  for (int i = 0; i < n; i++) {
    l += (moves[i] == 'R') - (moves[i] == 'L');
    r += moves[i] == '_';
  }
  return abs(l) + r;
}

int main() {
  char *m1 = "L_RL__R";
  char *m2 = "_R__LL_";
  char *m3 = "_______";
  int r1 = furthestDistanceFromOrigin(m1);
  int r2 = furthestDistanceFromOrigin(m2);
  int r3 = furthestDistanceFromOrigin(m3);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 5);
  printf("%d\n", r3);
  assert(r3 == 7);
}
