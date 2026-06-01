// 2144. Minimum Cost of Buying Candies With Discount
#include "leetcode.h"

/*
 * a shop is selling candies at a discount. for every two candies sold, the shop
 * gives a third candy for free. the customer can choose any candy to take away
 * for free as long as the cost of the chosen candy is less than or equal to the
 * minimum cost of the two candies bought. given a 0-indexed integer array
 * 'cost', where 'cost[i]' denotes the cost of the i'th candy, return the
 * minimum cost of buying all the candies.
 */

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int minimumCost(int *cost, int costSize) {
  qsort(cost, costSize, sizeof(int), cmp);
  int ans = 0;
  for (int i = 0; i < costSize; ++i)
    if (i % 3 != 2)
      ans += cost[i];
  return ans;
}

int main() {
  int c1[] = {1, 2, 3}, c2[] = {6, 5, 7, 9, 2, 2}, c3[] = {5, 5};
  int r1 = minimumCost(c1, ARRAY_SIZE(c1));
  int r2 = minimumCost(c2, ARRAY_SIZE(c2));
  int r3 = minimumCost(c3, ARRAY_SIZE(c3));
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 23);
  printf("%d\n", r3);
  assert(r3 == 10);
}
