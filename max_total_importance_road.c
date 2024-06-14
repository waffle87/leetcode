// 2285. Maximum Total Importance of Roads
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

long long maximumImportance(int n, int **roads, int roadsSize,
                            int *roadsColSize) {
  long long ans = 0, *timeShown = calloc(n, sizeof(long long));
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
  int roads1[][2] = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}},
      roadsColSize1[] = {6};
  int roads2[][2] = {{0, 3}, {2, 4}, {1, 3}}, roadsColSize2[] = {3};
  printf("%llu\n", maximumImportance(5, roads1, 6, roadsColSize1)); // expect:
                                                                    // 43
  printf("%llu\n", maximumImportance(5, roads1, 3, roadsColSize1)); // expect:
                                                                    // 20
  return 0;
}
