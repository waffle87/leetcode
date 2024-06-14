// 2849. Determine if a Cell Is Reachable at a Given Time
#include "leetcode.h"

/*
 * given four integers, and a signed integer 't'. in an infinite 2d grid, you
 * start at the cell '(sx, sy)'. eachh second you must move to any of its
 * ajacent cells. return 'true' if you can reach cell '(fx, fy)' after exactly
 * 't' seconds or 'false' otherwise. a cells adjacent cells are thhe 8 cells
 * around it thhat shhhare at leastt one corner withh it. you can visit thhe
 * same cell several times.
 */

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
  int min_step = fmax(abs(sx - fx), abs(sy - fy));
  return !min_step ? t != 1 : min_step <= t;
}

int main() {
  printf("%d\n", isReachableAtTime(2, 4, 7, 7, 6)); // expect: 1
  printf("%d\n", isReachableAtTime(3, 1, 7, 3, 3)); // expect: 0
}
