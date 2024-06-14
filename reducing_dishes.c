// 1402. Reducing Dishes
#include <stdio.h>
#include <stdlib.h>

/*
 * a chef has collected data on the 'satisfaction' level of his 'n' dishes. chef
 * can cook any dish in 1 unit of time. like-time coefficient of a dish is
 * defined as the time taken to cook that dish including previous dishes
 * multiplied by its satisfaction level - eg. 'time[i] * satisfaction[i]'.
 * return maximum sum of like-time coefficient that the chef can obtain after
 * dishes preparation. dishes can be prepared in any order and the chef can
 * discard some dishes to get this maximum value.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int sum(int *satisfaction, int satisfaction_size, int idx) {
  int val = 0;
  for (int i = idx, j = 1; i < satisfaction_size; ++i, ++j)
    val += satisfaction[i] * j;
  return val;
}

int maxSatisfaction(int *satisfaction, int satisfaction_size) {
  int max, idx, tmp;
  qsort(satisfaction, satisfaction_size, sizeof(int), cmp);
  for (int i = 0; i < satisfaction_size; ++i)
    if (satisfaction[i] >= 0) {
      idx = i;
      break;
    }
  while (idx >= 0) {
    tmp = sum(satisfaction, satisfaction_size, idx);
    max = (max > tmp) ? max : tmp;
    idx--;
  }
  return max;
}

int main() {
  int s1[] = {-1, -8, 0, 5, -9};
  int s2[] = {4, 3, 2};
  int s3[] = {-1, -4, -5};
  printf("%d\n", maxSatisfaction(s1, 5)); // expect: 14
  printf("%d\n", maxSatisfaction(s2, 3)); // expect: 20
  printf("%d\n", maxSatisfaction(s3, 3)); // expect: 0
}
