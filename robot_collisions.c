// 2751. Robot Collisions
#include "leetcode.h"

/*
 * there are 'n' 1 indexed robots, each having a position on a line, health, and
 * movement directions. all robots start moving on the line simultaneously at
 * the same speed in their given directions. if two robots ever share the same
 * position while moving, they will collide. if two robots collide, the robot
 * with lower health is removed from the line and the health of the other robot
 * decreases by 1. the surviving robot continues in the same direction it was
 * going. if both robots have the same health they are both removed from the
 * line. return an array containing the health of the remaining robots after no
 * further collisions can occur
 */

struct robot {
  int position;
  int health;
  int index;
  char direction;
};

int cmp_pos(const void *a, const void *b) {
  return ((struct robot *)a)->position - ((struct robot *)b)->position;
}

int cmp_idx(const void *a, const void *b) {
  return ((struct robot *)a)->index - ((struct robot *)b)->index;
}

int *survivedRobotsHealths(int *positions, int positionsSize, int *healths,
                           int healthsSize, char *directions, int *returnSize) {
  int n = positionsSize, m = 0;
  struct robot *robots = (struct robot *)malloc(n * sizeof(struct robot));
  struct robot *stack = (struct robot *)malloc(n * sizeof(struct robot));
  for (int i = 0; i < n; ++i) {
    robots[i].position = positions[i];
    robots[i].health = healths[i];
    robots[i].direction = directions[i];
    robots[i].index = i;
  }
  qsort(robots, n, sizeof(struct robot), cmp_pos);
  for (int i = 0; i < n; ++i) {
    struct robot curr = robots[i];
    if (curr.direction == 'R' || !m || stack[m - 1].direction == 'L') {
      stack[m++] = curr;
      continue;
    }
    if (curr.direction == 'L') {
      bool add = true;
      while (m > 0 && stack[m - 1].direction == 'R' && add) {
        int prev_health = stack[m - 1].health;
        if (curr.health > prev_health) {
          m--;
          curr.health--;
        } else if (curr.health < prev_health) {
          stack[m - 1].health--;
          add = false;
        } else {
          m--;
          add = false;
        }
      }
      if (add)
        stack[m++] = curr;
    }
  }
  qsort(stack, m, sizeof(struct robot), cmp_idx);
  int *ans = (int *)malloc(m * sizeof(int));
  *returnSize = m;
  for (int i = 0; i < m; ++i)
    ans[i] = stack[i].health;
  free(robots);
  free(stack);
  return ans;
}

int main() {
  int p1[] = {5, 4, 3, 2, 1}, h1[] = {2, 17, 9, 15, 10};
  int r1[] = {2, 17, 9, 15, 10}, rs1;
  int p2[] = {3, 5, 2, 6}, h2[] = {10, 10, 15, 12};
  int r2[] = {14}, rs2;
  int p3[] = {1, 2, 5, 6}, h3[] = {10, 10, 11, 11};
  int r3[] = {}, rs3;
  char *s1 = "RRRRR", *s2 = "RLRL", *s3 = "RLRL";
  int *sbh1 =
      survivedRobotsHealths(p1, ARRAY_SIZE(p1), h1, ARRAY_SIZE(h1), s1, &rs1);
  int *sbh2 =
      survivedRobotsHealths(p2, ARRAY_SIZE(p2), h2, ARRAY_SIZE(h2), s2, &rs2);
  int *sbh3 =
      survivedRobotsHealths(p3, ARRAY_SIZE(p3), h3, ARRAY_SIZE(h3), s3, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", sbh1[i]);
    assert(r1[i] == sbh1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", sbh2[i]);
    assert(r2[i] == sbh2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", sbh3[i]);
    assert(r3[i] == sbh3[i]);
  }
  printf("\n");
  free(sbh1);
  free(sbh2);
  free(sbh3);
}
