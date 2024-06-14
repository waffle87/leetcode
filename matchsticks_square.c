// 473. Matchsticks to Square
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'matchsticks' where 'matchsticks[i]' is the length of
 * the i'th matchstick. you want to use all the matchsticks to make one square.
 * you should not break any stick, but you can link them up, and each matchstick
 * can be used exactly one time. return 1 if you make square, 0 if not.
 */

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

bool dfs(int *nums, bool *visited, int curr, int n, int group, long long target,
         long long sum) {
  if (group == 4)
    return true;
  if (sum > target)
    return false;
  if (sum == target)
    return dfs(nums, visited, group, n, group + 1, target, 0);
  int last = -1;
  for (int i = curr; i < n; i++) {
    if (visited[i] == true)
      continue;
    if (nums[i] == last)
      continue;
    visited[i] = true;
    if (dfs(nums, visited, i + 1, n, group, target, sum + nums[i]) == true)
      return true;
    visited[i] = false;
    last = nums[i];
  }
  return false;
}

bool makeSquare(int *matchsticks, int matchsticksSize) {
  int n = matchsticksSize;
  bool ans;
  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum += matchsticks[i];
  if (sum % 4 != 0)
    return false;
  long long target = sum / 4;
  qsort(matchsticks, n, sizeof(int), cmp);
  if (matchsticks[0] > target)
    return false;
  bool *visited = calloc(n, sizeof(bool));
  ans = dfs(matchsticks, visited, 0, n, 0, target, 0);
  free(visited);
  return ans;
}

int main() {
  int matchsticks1[] = {1, 1, 2, 2, 2}, ms1 = 5;
  int matchsticks2[] = {3, 3, 3, 3, 4}, ms2 = 5;
  printf("%d\n", makeSquare(matchsticks1, ms1)); // expect: 1
  printf("%d\n", makeSquare(matchsticks2, ms2)); // expect: 0
}
