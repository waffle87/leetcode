// 2126. Destroying Asteroids
#include "leetcode.h"

/*
 * you are given an integer 'mass', which represents the original mass of a
 * planet. you are further given an integer array 'asteroids', where
 * 'asteroids[i]' is he mass of the i'th asteroid. you can arrange for the
 * planet to collide with the asteroids in any arbitrary order. if the mass of
 * the planet is greater than or equal to the mass of the asteroid, the asteroid
 * is destroyed and the planet gains the mass of the asteroid. otherwise, the
 * planet is destroyed. return true if all asteroids can be destroyed, otherwise
 * return false.
 */

bool asteroidsDestroyed(int mass, int *asteroids, int asteroidsSize) {
  int total = mass, sum[32] = {0}, min[32];
  for (int i = 0; i < 32; i++)
    min[i] = INT_MAX;
  for (int i = 0; i < asteroidsSize; i++) {
    int x = 31 - __builtin_clz(asteroids[i]);
    min[x] = fmin(min[x], asteroids[i]);
    sum[x] += asteroids[i];
  }
  for (int i = 0; i < 32; i++) {
    if (min[i] == INT_MAX)
      continue;
    if (total < min[i])
      return false;
    total += sum[i];
  }
  return true;
}

int main() {
  int a1[] = {3, 9, 19, 5, 21}, a2[] = {4, 9, 23, 4};
  bool r1 = asteroidsDestroyed(10, a1, ARRAY_SIZE(a1));
  bool r2 = asteroidsDestroyed(5, a2, ARRAY_SIZE(a2));
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
}
