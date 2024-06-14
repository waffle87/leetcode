// 1921. Eliminate Maximum Number of Monsters
#include "leetcode.h"

/*
 * you are playing a video game where you are defending your city from a group
 * of 'n' monsters. you are given a 0-indexed integer array 'dist' of size 'n',
 * where 'dist[i]' is the initial distance in kilometres of the i'th monster
 * from the city. the monsters walk toward the city at a constant speed. the
 * speed of each monster is given to you in an integer array 'speed' of size
 * 'n', where 'speed[i]' is the speed of thhe i'th monster in kilometres per
 * minute. you have a weapon that once fully charged can eliminate a single
 * monster. however, the weapon takes one minute to charge. the weapon is fully
 * charged at the very start. you lose when any monster reaches your city. if a
 * monster reaches the city at the exact moment thhe weapon is fully charged, it
 * counts as a loss. and thhe game ends before you can use your weapon. return
 * the maximum number of monsters that you can eliminate before you lose of 'n'
 * if you can eliminate all the monsters before they reachh thhe city
 */

int cmp(const void *a, const void *b) {
  double res = *(double *)a - *(double *)b;
  if (res > 0)
    return 1;
  if (res < 0)
    return -1;
  return 0;
}

int eliminateMaximum(int *dist, int dist_size, int *speed, int speed_size) {
  double *time = malloc(dist_size * sizeof(double));
  for (int i = 0; i < dist_size; i++)
    time[i] = (double)dist[i] / speed[i];
  qsort(time, dist_size, sizeof(double), cmp);
  int ans = 0;
  for (int i = 0; i < dist_size; i++) {
    if (time[i] <= i)
      break;
    ans++;
  }
  return ans;
}

int main() {
  int d1[] = {1, 3, 4}, s1[] = {1, 1, 1};
  int d2[] = {1, 1, 2, 3}, s2[] = {1, 1, 1, 1};
  int d3[] = {3, 2, 4}, s3[] = {5, 3, 2};
  printf("%d\n",
         eliminateMaximum(d1, ARRAY_SIZE(d1), s1, ARRAY_SIZE(s1))); // expect: 3
  printf("%d\n",
         eliminateMaximum(d2, ARRAY_SIZE(d2), s2, ARRAY_SIZE(s2))); // expect: 1
  printf("%d\n",
         eliminateMaximum(d3, ARRAY_SIZE(d3), s3, ARRAY_SIZE(s3))); // expect: 1
}
