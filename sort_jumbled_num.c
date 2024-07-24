// 2191. Sort the Jumbled Numbers
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'mapping' which represents the
 * mapping rule of a shuffled decimal system. 'mapping[i] = j' means the digit
 * 'i' should be mapped to digit 'j' in this system. the mapped value of an
 * integer is the new integer obtained by replacing each occurence of digit 'i'
 * in the integer with 'mapping[i]' for all '0 <= i <= 9'. you are also given
 * another integer array 'nums'. return the array 'nums' sorted in non
 * decreasing order based on the mapped values of its elements.
 */

struct item {
  int old;
  int new;
  int idx;
};

int cmp(const void *a, const void *b) {
  return (((struct item *)a)->new == ((struct item *)b)->new)
             ? ((struct item *)a)->idx - ((struct item *)b)->idx
             : ((struct item *)a)->new - ((struct item *)b)->new;
}

int *sortJumbled(int *mapping, int mappingSize, int *nums, int numsSize,
                 int *returnSize) {
  struct item *data = (struct item *)malloc(sizeof(struct item) * numsSize);
  int *ans = (int *)malloc(sizeof(int) * numsSize);
  char digits[10];
  *returnSize = numsSize;
  for (int i = 0; i < numsSize; i++) {
    sprintf(digits, "%d", nums[i]);
    for (int i = 0; digits[i]; i++)
      digits[i] = mapping[digits[i] - '0'] + '0';
    data[i].old = nums[i];
    data[i].new = atoi(digits);
    data[i].idx = i;
  }
  qsort(data, numsSize, sizeof(struct item), cmp);
  for (int i = 0; i < numsSize; i++)
    ans[i] = data[i].old;
  free(data);
  return ans;
}

int main() {
  int m1[] = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6},
      m2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, n1[] = {991, 338, 38},
      n2[] = {789, 456, 123}, rs1, rs2;
  int *sj1 = sortJumbled(m1, ARRAY_SIZE(m1), n1, ARRAY_SIZE(n1), &rs1);
  int *sj2 = sortJumbled(m2, ARRAY_SIZE(m2), n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", sj1[i]); // expect: 338,38,991
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", sj2[i]); // expect: 123,456,789
  printf("\n");
  free(sj1), free(sj2);
}
