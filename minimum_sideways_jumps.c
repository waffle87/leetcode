// 1824. Minimum Sideway Jumps
#include "leetcode.h"

/*
 * there is a 3 lane road of length 'n' that consists of 'n + 1' points labeled
 * from 0 to 'n'. a frog starts at point 0 in the second lane and wants to jump
 * to point 'n'. however there could be obstacles along the way. you are given
 * an array 'obstacles' of length 'n + 1' where each 'obstacles[i]' (ranging
 * from 0 to 3) describes an obstacle on the lane 'obstacles[i]' at point 'i'.
 * if 'obstacles[i] == 0' there are no obstacles at point 'i'. there will be at
 * most one obstacles in the 3 lanes at each point. the frog can only travel
 * from point 'i' to point 'i + 1' on the same lane if there is not an obstacle
 * on the lane at point 'i + 1'. return the minimum number of side jumps the
 * frog needs to reach any lane at point 'n' starting from lane 2 at point 0.
 */

int minSideJumps(int *obstacles, int obstaclesSize) {
  int cnt = 0, status = 2;
  for (int i = 0; i < obstaclesSize - 1; i++) {
    if (obstacles[i + 1] == 2 && (status & (1 << 1))) {
      status -= 2;
      if (!status) {
        cnt++;
        status = 5;
        if (obstacles[i])
          status -= (1 << (obstacles[i] - 1));
      }
    } else if (obstacles[i + 1] == 3 && (status & (1 << 2))) {
      status -= 4;
      if (!status) {
        cnt++;
        status = 3;
        if (obstacles[i])
          status -= (1 << (obstacles[i] - 1));
      }
    } else if (obstacles[i + 1] == 1 && (status & 1)) {
      status--;
      if (!status) {
        cnt++;
        status = 6;
        if (obstacles[i])
          status -= (1 << (obstacles[i] - 1));
      }
    }
  }
  return cnt;
}

int main() {
  int o1[] = {0, 1, 2, 3, 0}, o2[] = {0, 1, 1, 3, 3, 0},
      o3[] = {0, 2, 1, 0, 3, 0};
  printf("%d\n", minSideJumps(o1, ARRAY_SIZE(o1))); // expect: 2
  printf("%d\n", minSideJumps(o2, ARRAY_SIZE(o2))); // expect: 0
  printf("%d\n", minSideJumps(o3, ARRAY_SIZE(o3))); // expect: 2
}
