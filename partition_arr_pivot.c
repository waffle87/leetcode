// 2161. Partition Array According to Given Pivot
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' and an integer 'pivot'.
 * rearrange 'nums' such that the following conditions are satisfied: every
 * element less than 'pivot' appears befor every element greater than 'pivot',
 * every element equal to 'pivot' appears in between the elements less than and
 * greater than 'pivot', the relative order of the elments less than 'pivot' and
 * the elements greater than 'pivot' is maintained. return 'nums' after the
 * rearrangement
 */

uint64_t pack(int32_t a, int32_t b) {
  return ((uint64_t)(b & 0xFFFFFFFF) << 32) | (a & 0xFFFFFFFF);
}

void unpack(uint64_t s, int32_t *a, int32_t *b) {
  *a = (int32_t)(s & 0xFFFFFFFF);
  *b = (int32_t)((s >> 32) & 0xFFFFFFFF);
}

int *pivotArray(int *nums, int numsSize, int pivot, int *returnSize) {
  int *ans = (int *)malloc(numsSize * sizeof(int));
  *returnSize = numsSize;
  for (int i = 0; i < numsSize; i++)
    ans[i] = nums[i];
  int j = 0, cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    if (ans[i] < pivot) {
      if (ans[j] > pivot) {
        uint64_t packed = pack(ans[i], ans[j]);
        ans[j] = (int)packed;
      } else
        ans[j] = ans[i];
      j++;
    } else if (ans[i] == pivot)
      cnt++;
  }
  j = numsSize - 1;
  for (int i = numsSize - 1; i >= 0; i--) {
    if (ans[i] > pivot) {
      if (ans[i] > INT_MAX) {
        int32_t a, b;
        unpack((uint64_t)ans[i], &a, &b);
        ans[j] = a;
        ans[i] = b;
      } else
        ans[j] = ans[i];
      j--;
    }
  }
  for (int i = j + 1; i <= j + cnt; i++)
    ans[i] = pivot;
  return ans;
}

int main() {
  int n1[] = {9, 12, 5, 10, 14, 3, 10}, r1[] = {9, 5, 3, 10, 14, 3, 10}, rs1;
  int n2[] = {-3, 4, 3, 2}, r2[] = {-3, 4, 2, 3}, rs2;
  int *pa1 = pivotArray(n1, ARRAY_SIZE(n1), 10, &rs1);
  int *pa2 = pivotArray(n2, ARRAY_SIZE(n2), 2, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", pa1[i]);
    assert(pa1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", pa2[i]);
    assert(pa2[i] == r2[i]);
  }
  printf("\n");
  free(pa1);
  free(pa2);
}
