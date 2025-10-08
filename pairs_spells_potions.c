// 2300. Successful Pairs of Spells and Potions
#include "leetcode.h"

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

int lower_bound(int *arr, int arr_size, long long target) {
  int low = 0, high = arr_size - 1, res = arr_size;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= target) {
      res = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return res;
}

int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize,
                     long long success, int *returnSize) {
  qsort(potions, potionsSize, sizeof(int), cmp);
  int *ans = (int *)malloc(spellsSize * sizeof(int));
  *returnSize = spellsSize;
  for (int i = 0; i < spellsSize; i++) {
    long long req = (success + spells[i] - 1) / spells[i];
    ans[i] = potionsSize - lower_bound(potions, potionsSize, req);
  }
  return ans;
}

int main() {
  int s1[] = {5, 1, 3}, s2[] = {3, 1, 2};
  int p1[] = {1, 2, 3, 4, 5}, p2[] = {8, 5, 8};
  int rs1,
      *ex1 = successfulPairs(s1, ARRAY_SIZE(s1), p1, ARRAY_SIZE(p1), 7, &rs1);
  int rs2,
      *ex2 = successfulPairs(s2, ARRAY_SIZE(s2), p2, ARRAY_SIZE(p2), 16, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ex1[i]); // expect: 4 0 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ex2[i]); // expect: 2 0 2
  free(ex1);
  free(ex2);
}
