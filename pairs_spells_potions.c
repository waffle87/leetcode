// 2300. Successful Pairs of Spells and Potions
#include <stdio.h>
#include <stdlib.h>

/*
 * given two positive integer arrays 'spells' and 'potions', of length n and m
 * respectively where 'spells[i]' represents the strength of the i'th spell and
 * 'potions[j] represents the strength of the j'th potion. also given an integer
 * success. a spell and potion pair is considered successful if the product of
 * their strengths is at least 'success'. return an integer array 'pairs' of
 * lengthn where 'pairs[i]' is the number of potions that will form a successful
 * pair with the i'th spell.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int find_successful(int *potions, int potions_size, double val) {
  int left = 0, right = potions_size - 1, mid;
  while (left < right) {
    mid = (left + right) >> 1;
    if ((double)potions[mid] >= val)
      right = mid;
    else
      left = mid + 1;
  }
  if ((double)potions[left] >= val)
    return potions_size - left;
  else
    return 0;
}

int *successfulPairs(int *spells, int spells_size, int *potions,
                     int potions_size, long long success, int *return_size) {
  int i, j;
  qsort(potions, potions_size, sizeof(int), cmp);
  double *spells_float = malloc(spells_size * sizeof(double));
  for (i = 0; i < spells_size; i++)
    spells_float[i] = 1.0 * success / spells[i];
  *return_size = spells_size;
  int *ans = malloc(spells_size * sizeof(int));
  for (i = 0; i < spells_size; i++)
    ans[i] = find_successful(potions, potions_size, spells_float[i]);
  free(spells_float);
  return ans;
}

int main() {
  int s1[] = {5, 1, 3}, s2[] = {3, 1, 2};
  int p1[] = {1, 2, 3, 4, 5}, p2[] = {8, 5, 8};
  int rs1[] = {3}, rs2[] = {3};
  int *ex1 = successfulPairs(s1, 3, p1, 5, 7, rs1);
  int *ex2 = successfulPairs(s2, 3, p2, 3, 16, rs2);
  for (int i = 0; i < 3; i++)
    printf("%d ", ex1[i]); // expect: 4 0 3
  printf("\n");
  for (int i = 0; i < 3; i++)
    printf("%d ", ex2[i]); // expect: 2 0 2
}
