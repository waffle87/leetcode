// 1552. Magnetic Force Between Two Balls
#include "leetcode.h"

/*
 * in the universe earth c-137 rick discovered a special form of magnetic force
 * between two balls if they are put in his new invented basket. rick has 'n'
 * empty baskets the i'th basket is at 'position[i]', more has 'm' ball and
 * needs to distribute the balls into the baskets such that the minimum magnetic
 * force between any two balls is maximum. rick stated that magnetic force
 * betweeen two different balls at positions 'x' and 'y' is '|x - y|'. given the
 * integer array 'position' and the integer 'm', return the required force.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int cnt_ball(int *position, int positionSize, int distance) {
  int cnt = 1, ptr = position[0];
  for (int i = 1; i < positionSize; i++)
    if (position[i] - ptr >= distance) {
      ptr = position[i];
      cnt++;
    }
  return cnt;
}

int maxDistance(int *position, int positionSize, int m) {
  qsort(position, positionSize, sizeof(int), cmp);
  int left = 1, right = position[positionSize - 1], mid;
  while (left + 1 < right) {
    mid = (left + right) / 2;
    if (cnt_ball(position, positionSize, mid) >= m)
      left = mid;
    else
      right = mid - 1;
  }
  return cnt_ball(position, positionSize, right) >= m ? right : left;
}

int main() {
  int p1[] = {1, 2, 3, 4, 7}, p2[] = {5, 4, 3, 2, 1, 1000000000};
  printf("%d\n", maxDistance(p1, ARRAY_SIZE(p1), 3)); // expect: 3
  printf("%d\n", maxDistance(p2, ARRAY_SIZE(p2), 2)); // expect: 9999999
}
