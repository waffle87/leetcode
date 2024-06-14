// 403. Frog Jump
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * a frog is crossing a river. the river is divided into some number of units
 * and at each unit, there may or may not exist a stone. the frog can jump on a
 * stone, but it must not jump into the water. given a list of 'stones'
 * positions in (units) in sorted ascending order, determine if the frog can
 * cross the river by landing on the last stone. initially, the frog is on the
 * first stone and assumes the frist just must be 1 unit. if the frog's last
 * jump was k units, its next jujp must be either 'k - 1' or 'k + 1' units. the
 * frog can only jump in the forward direction.
 */

bool dfs(int *stones, int stones_size, int t, long long **hash, int x) {
  if (stones_size == 1)
    return true;
  int p = -1, c = -1, n = -1;
  long long val = (stones[0] << 10) + t;
  long long d = val;
  while (1) {
    if (!hash[d % x])
      break;
    else if (hash[d % x][0] == val)
      return false;
    else
      d++;
  }
  for (int i = 1; i < stones_size; i++) {
    if (stones[i] == stones[0] + t + 1)
      n = i;
    if (stones[i] == stones[0] + t)
      c = i;
    if (stones[i] == stones[0] + t - 1)
      p = i;
    if (stones[i] > stones[0] + t + 1)
      break;
  }
  if (n != -1 && dfs(stones + n, stones_size - n, t + 1, hash, x))
    return true;
  if (c != -1 && dfs(stones + c, stones_size - c, t, hash, x))
    return true;
  if (p != -1 && dfs(stones + p, stones_size - p, t - 1, hash, x))
    return true;
  d = val;
  while (1) {
    if (!hash[d % x]) {
      hash[d % x] = malloc(sizeof(long long));
      hash[d % x][0] = val;
      break;
    } else
      d++;
  }
  return false;
}

bool canCross(int *stones, int stones_size) {
  if (stones[0] || stones[1] != 1)
    return false;
  int x = 100 * stones_size;
  long long **hash = calloc(x, sizeof(long long *));
  bool ans = dfs(stones + 1, stones_size - 1, 1, hash, x);
  for (int i = 0; i < x; i++) {
    if (!hash[i])
      continue;
    free(hash[i]);
  }
  free(hash);
  return ans;
}

int main() {
  int s1[] = {0, 1, 3, 5, 6, 8, 12, 17}, s2[] = {0, 1, 2, 3, 4, 8, 9, 11};
  printf("%d\n", canCross(s1, 8)); // expect: 1
  printf("%d\n", canCross(s2, 8)); // expect: 0
}
