// 2078. Two Furthest Houses With Different Colors
#include "leetcode.h"

/*
 * there are 'n' houses evenly lined up on the street, and each house is
 * beautifully painted. you are given a 0-indexed integer array 'colors' of
 * length 'n' where 'colors[i]' represents the color of the i'th house. return
 * the maximum distance between two houses with different colors. the distance
 * between the i'th and the j'th house is 'abs(i - j)'.
 */

int maxDistance(int *colors, int colorsSize) {
  int left = 0, right = colorsSize - 1;
  while (colors[left] == colors[colorsSize - 1])
    left++;
  while (colors[right] == colors[0])
    right--;
  return fmax(right, colorsSize - 1 - left);
}

int main() {
  int c1[] = {1, 1, 1, 6, 1, 1, 1};
  int c2[] = {1, 8, 3, 8, 3};
  int c3[] = {0, 1};
  int r1 = maxDistance(c1, ARRAY_SIZE(c1));
  int r2 = maxDistance(c2, ARRAY_SIZE(c2));
  int r3 = maxDistance(c3, ARRAY_SIZE(c3));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 4);
  printf("%d\n", r3);
  assert(r3 == 1);
}
