// 3074. Apple Redistribution into Boxes
#include "leetcode.h"

/*
 * you are given an array 'apple' of size 'n' and an array 'capacity' of size
 * 'm'. there are 'n' packs where the i'th pack contains 'apple[i]' apples.
 * there are 'm' boxes as well, and the i'th box has a capacity of 'capacity[i]'
 * apples. return the minimum number of boxes you need to redistribute these 'n'
 * packs of apples into boxes. note that apples from the same pack can be
 * distributed into different boxes.
 */

int cmp(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int minimumBoxes(int *apple, int appleSize, int *capacity, int capacitySize) {
  int total = 0, ans = 0;
  for (int i = 0; i < appleSize; i++)
    total += apple[i];
  qsort(capacity, capacitySize, sizeof(int), cmp);
  while (total > 0)
    total -= capacity[ans++];
  return ans;
}

int main() {
  int a1[] = {1, 3, 2}, c1[] = {4, 3, 1, 5, 2};
  int a2[] = {5, 5, 5}, c2[] = {2, 4, 2, 7};
  printf("%d\n",
         minimumBoxes(a1, ARRAY_SIZE(a1), c1, ARRAY_SIZE(c1))); // expect: 2
  printf("%d\n",
         minimumBoxes(a2, ARRAY_SIZE(a2), c2, ARRAY_SIZE(c2))); // expect: 4
}
