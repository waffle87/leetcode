// 881. Boats to Save People
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array 'people' where 'people[i]' is the weight of the i'th person,
 * and an infinite number of boats where each boat can carry a maximum weight of
 * 'limit'. each boat carries at most two people at the same time, provided the
 * sum of the weight of those people is at most 'limit'. return minimum number
 * of boats to carry every person
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int numRescueBoats(int *people, int people_size, int limit) {
  qsort(people, people_size, sizeof(int), cmp);
  int max_weight = people_size - 1, min_weight = 0, ans = 0;
  while (min_weight <= max_weight) {
    if (people[min_weight] + people[max_weight] <= limit) {
      min_weight++;
      max_weight--;
    } else
      max_weight--;
    ans++;
  }
  return ans;
}

int main() {
  int p1[] = {1, 2}, p2[] = {3, 2, 2, 1}, p3[] = {3, 5, 3, 4};
  printf("%d\n", numRescueBoats(p1, 2, 3)); // expect: 1
  printf("%d\n", numRescueBoats(p2, 4, 3)); // expect: 3
  printf("%d\n", numRescueBoats(p3, 4, 5)); // expect: 4
}
