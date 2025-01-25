// 2948. Make Lexicographically Smallest Array by Swapping Elements
#include "leetcode.h"

/*
 * you are given a 0-indexed array of positive integers 'nums' and a positive
 * integer 'limit'. in one operation, you can choose any two indices 'i' and 'j'
 * and swap 'nums[i]' and 'nums[j]' if '|nums[i] - nums[j]| <= limit'. return
 * the lexicographically smallest array that can be obtained by performingthe
 * operation any number of times.
 */

int cmp1(const void *a, const void *b) {
  int *aa = (int *)a;
  int *bb = (int *)b;
  return aa[0] - bb[0];
}

int cmp2(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int *lexicographicallySmallestArray(int *nums, int numsSize, int limit,
                                    int *returnSize) {
  int *ans = (int *)malloc(numsSize * sizeof(int));
  *returnSize = numsSize;
  int cpy[numsSize][2];
  for (int i = 0; i < numsSize; i++) {
    cpy[i][0] = nums[i];
    cpy[i][1] = i;
  }
  qsort(cpy, numsSize, sizeof(cpy[0]), cmp1);
  int indices[numsSize];
  for (int i = 0; i < numsSize;) {
    int size = 0, prev = cpy[i][0];
    while (i < numsSize && cpy[i][0] <= (prev + limit)) {
      indices[size++] = cpy[i][1];
      prev = cpy[i][0];
      i++;
    }
    qsort(indices, size, sizeof(int), cmp2);
    for (int j = 0, k = i - size; j < size; j++, k++)
      ans[indices[j]] = cpy[k][0];
  }
  return ans;
}

int main() {
  int n1[] = {1, 5, 3, 9, 8}, rs1;
  int n2[] = {1, 7, 6, 18, 2, 1}, rs2;
  int n3[] = {1, 7, 28, 19, 10}, rs3;
  int *lsa1 = lexicographicallySmallestArray(n1, ARRAY_SIZE(n1), 2, &rs1);
  int *lsa2 = lexicographicallySmallestArray(n2, ARRAY_SIZE(n2), 3, &rs2);
  int *lsa3 = lexicographicallySmallestArray(n3, ARRAY_SIZE(n3), 3, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", lsa1[i]); // expect: 1 3 5 8 9
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", lsa2[i]); // expect: 1 6 7 18 1 2
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", lsa3[i]); // expect: 1 7 28 19 10
  printf("\n");
  free(lsa1);
  free(lsa2);
  free(lsa3);
}
