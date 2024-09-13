// 1310. XOR Queries of a Subarray
#include "leetcode.h"

/*
 * you are given an array 'arr' of positive integers. you are also given the
 * array 'queries' where 'queries[i] = [left_i, right_i]'. for each query 'i'
 * compute the xor of elements from 'left_i' to 'right_i'. return an array
 * 'answer' where 'answer[i]' is the answer to the i'th query
 */

int *xorQueries(int *arr, int arrSize, int **queries, int queriesSize,
                int *queriesColSize, int *returnSize) {
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  int *prefix = (int *)calloc(arrSize, sizeof(int));
  for (int i = 0; i < arrSize; i++)
    prefix[i] = !i ? arr[i] : prefix[i - 1] ^ arr[i];
  for (int i = 0; i < queriesSize; i++) {
    int left = queries[i][0], right = queries[i][1];
    ans[i] = !left ? prefix[right] : prefix[right] ^ prefix[left - 1];
  }
  *returnSize = queriesSize;
  free(prefix);
  return ans;
}

int main() {
  int a1[] = {1, 3, 4, 8}, q1[4][2] = {{0, 1}, {1, 2}, {0, 3}, {3, 3}},
      qcs1 = 4, rs1;
  int a2[] = {4, 8, 2, 10}, q2[4][2] = {{2, 3}, {1, 3}, {0, 0}, {0, 3}},
      qcs2 = 4, rs2;
  int *xq1 =
      xorQueries(a1, ARRAY_SIZE(a1), (int **)q1, ARRAY_SIZE(q1), &qcs1, &rs1);
  int *xq2 =
      xorQueries(a2, ARRAY_SIZE(a2), (int **)q2, ARRAY_SIZE(q2), &qcs2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", xq1[i]); // expect: 2 7 14 8
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", xq2[i]); // expect: 8 0 4 4
  printf("\n");
  free(xq1), free(xq2);
}
