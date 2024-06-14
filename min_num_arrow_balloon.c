// 452. Minimum Number of Arrows to Burst Balloons
#include "leetcode.h"

/*
 * there are some spherical balloons taped onto a flat wall that represents the
 * xy plane. the ballooons are represented as a 2d integer array 'points' where
 * 'points[i] = [x_start, x_end]'. you do not know the exact y coordinates of
 * the balloons. arrows can be shot up directly vertically in the positive y
 * direction. from different points along the x axis. given the array points,
 * return the minimum number of arrows that must be shot to burst all balloons.
 */

int cmp(const void **p1, const void **p2) {
  int *arr1 = *(int **)p1;
  int *arr2 = *(int **)p2;
  if (arr1[1] == arr2[1]) {
    if (arr1[0] == arr2[0])
      return 0;
    else if (arr1[0] > arr2[0])
      return 1;
    else
      return -1;
  } else {
    if (arr1[1] == arr2[1])
      return 0;
    else if (arr1[1] > arr2[1])
      return 1;
    else
      return -1;
  }
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
  qsort(points, pointsSize, sizeof(int *), cmp);
  int k = points[0][1], cnt = 1;
  for (int i = 1; i < pointsSize; i++) {
    if (points[i][0] > k) {
      cnt++;
      k = points[i][1];
    }
  }
  return cnt;
}

int main() {
  int p1[4][2] = {{10, 16}, {2, 8}, {1, 6}, {7, 12}},
      p2[4][4] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  int pcs1, pcs2;
  printf("%d\n",
         findMinArrowShots((int **)p1, ARRAY_SIZE(p1), &pcs1)); // expect: 2
  printf("%d\n",
         findMinArrowShots((int **)p2, ARRAY_SIZE(p2), &pcs2)); // expect: 2
}
