// 2285. Maximum Total Importance of Roads
#include "leetcode.h"

/*
 * given an integer 'n' denoting the number of cities in a country. the cities
 * are numbered from 0 to 'n - 1'. you are also given a 2d integer array 'roads'
 * where 'roads[i] = [ai, bi]', where each value can only be used once. the
 * importance of a road is then defined as the sum of the values of the two
 * cities it connects. return the maximum total importance of all roads possible
 * after assigning the values optimally.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

long long maximumImportance(int n, int **roads, int roadsSize,
                            int *roadsColSize) {
  long long ans = 0, *timeShown = (long long *)calloc(n, sizeof(long long));
  for (int i = 0; i < roadsSize; i++)
    for (int j = 0; j < 2; j++)
      timeShown[roads[i][j]]++;
  qsort(timeShown, n, sizeof(long long), cmp);
  for (int i = n - 1; i >= 0; i--)
    ans += timeShown[i] * (i + 1);
  free(timeShown);
  return ans;
}

int main() {
  int r1[][2] = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}},
      roadsColSize1[] = {6};
  int r2[][2] = {{0, 3}, {2, 4}, {1, 3}}, roadsColSize2[] = {3};
  printf("%llu\n",
         maximumImportance(5, (int **)r1, 6, roadsColSize1)); // expect:
                                                              // 43
  printf("%llu\n",
         maximumImportance(5, (int **)r1, 3, roadsColSize1)); // expect:
                                                              // 20
}
