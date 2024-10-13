// 632. Smallest Range Covering Elements from K Lists
#include "leetcode.h"

/*
 * you have 'k' lists of sorted integers in non decreasing order. find the
 * smallest range that includes at least one number from each of the 'k' lists.
 * we define the range '[a, b]' is smaller than the range '[c, d]' if 'b - a < d
 * - c' or 'a < c' if 'b - a == d - c'
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int *smallestRange(int **nums, int numsSize, int *numsColSize,
                   int *returnSize) {
  int n = 0, idx = 0;
  for (int i = 0; i < numsSize; i++)
    n += numsColSize[i];
  int *data = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < numsSize; i++)
    for (int j = 0; j < numsColSize[i]; j++)
      data[idx++] = nums[i][j] * 4096 | i;
  qsort(data, n, sizeof(int), cmp);
  int *ans = (int *)calloc(2, sizeof(int));
  int left = 0, right = 0, list_cnt = 0,
      min_range = (data[n - 1] >> 12) - (data[0] >> 1);
  ans[0] = data[0] >> 12;
  ans[1] = data[n - 1] >> 12;
  idx = 0;
  memset(numsColSize, 0, numsSize * sizeof(int));
  while (right < n) {
    int list_idx = data[right++] & 0xFFF;
    numsColSize[list_idx]++;
    if (numsColSize[list_idx] == 1) {
      list_cnt++;
      while (list_cnt == numsSize) {
        int diff = (data[right - 1] >> 12) - (data[left] >> 12);
        if (diff < min_range) {
          ans[0] = data[left] >> 12;
          ans[1] = data[right - 1] >> 12;
          min_range = diff;
        }
        list_idx = data[left++] & 0xFFF;
        numsColSize[list_idx]--;
        if (!numsColSize[list_idx])
          list_cnt--;
      }
    }
  }
  *returnSize = 2;
  free(data);
  return ans;
}

int main() {
  int n1[3][5] = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}},
      ncs1 = 3, rs1;
  int n2[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, ncs2 = 3, rs2;
  int *sr1 = smallestRange((int **)n1, ARRAY_SIZE(n1), &ncs1, &rs1);
  int *sr2 = smallestRange((int **)n2, ARRAY_SIZE(n2), &ncs2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", sr1[i]); // expect: 20 24
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", sr2[i]); // expect: 1 1
  printf("\n");
  free(sr1), free(sr2);
}
