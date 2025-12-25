// 3075. Maximize Happiness of Selected Children
#include "leetcode.h"

/*
 * given an array 'happiness' of length 'n' and a positive integer 'k'. there
 * are 'n' children standing in a queue where the i'th child has happiness value
 * 'happiness[i]'. you want to select 'k' children from these 'n' children in
 * 'k' turns. in each turn you select a child the happiness value of all the
 * children that have not been selected till now decreases by one. note that the
 * happiness value cannot become negative and decremented only if it is
 * positive. return the maximum sum of the happiness values of the selected
 * children you can achieve by selecting 'k' children.
 */

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

long long maximumHappinessSum(int *happiness, int happinessSize, int k) {
  qsort(happiness, happinessSize, sizeof(int), cmp);
  long long ans = 0, i = 0;
  while (k--) {
    happiness[i] = fmax(happiness[i] - i, 0);
    ans += happiness[i++];
  }
  return ans;
}

int main() {
  int h1[] = {1, 2, 3}, h2[] = {1, 1, 1, 1}, h3[] = {2, 3, 4, 5};
  printf("%lld\n", maximumHappinessSum(h1, ARRAY_SIZE(h1), 2)); // expect: 4
  printf("%lld\n", maximumHappinessSum(h2, ARRAY_SIZE(h2), 2)); // expect: 1
  printf("%lld\n", maximumHappinessSum(h3, ARRAY_SIZE(h3), 1)); // expect: 5
}
