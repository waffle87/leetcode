// 1051. Height Checker
#include "leetcode.h"

/*
 * a school is trying to take an annual photo of all the students. the students
 * are asked to stand in a single file line in non decreasing order by height.
 * let this ordering be represented by the integer array 'expected' where
 * 'expected[i]' is the expected height of the i'th student in line. you are
 * given an integer array 'heights' representing the current order that the
 * students are standing in. each 'heights[i]' is the height of the i'th student
 * in line. return the number of indices where 'heights[i] != expected[i]'
 */

int cmp(const void *a, const void *b) {
  long aa = *(int *)a, bb = *(int *)b;
  return aa - bb;
}

int heightChecker(int *heights, int heightsSize) {
  if (heightsSize < 2)
    return 0;
  int *expected = (int *)malloc(sizeof(int) * heightsSize);
  memcpy(expected, heights, sizeof(int) * heightsSize);
  qsort(expected, heightsSize, sizeof(int), cmp);
  int diff = 0;
  for (int i = 0; i < heightsSize; i++)
    if (heights[i] != expected[i])
      diff++;
  free(expected);
  return diff;
}

int main() {
  int h1[] = {1, 1, 4, 2, 1, 3}, h2[] = {5, 1, 2, 3, 4}, h3[] = {1, 2, 3, 4, 5};
  printf("%d\n", heightChecker(h1, ARRAY_SIZE(h1))); // expect: 3
  printf("%d\n", heightChecker(h2, ARRAY_SIZE(h2))); // expect: 5
  printf("%d\n", heightChecker(h3, ARRAY_SIZE(h3))); // expect: 0
}
