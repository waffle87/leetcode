// 3152. Special Array II
#include "leetcode.h"

/*
 * an array is considered special if every pair of its adjacent elements
 * contains two numbers with different parity. you are given an array of integer
 * 'nums' and a 2d integer array 'matrix' 'queries', where for 'queries[i] =
 * [from_i, to_i]' your task is to check that subarray 'nums[from_i .. to_i]' is
 * special or not. return array of booleans 'answer' such that 'answer[i]' is
 * true if 'nums[from_i .. to_i]' is special
 */

bool *isArraySpecial(int *nums, int numsSize, int **queries, int queriesSize,
                     int *queriesColSize, int *returnSize) {
  *returnSize = queriesSize;
  bool *ans = (bool *)malloc(queriesSize * sizeof(bool));
  int *bad = (int *)malloc(numsSize * sizeof(int));
  bad[0] = 0;
  for (int i = 1; i < numsSize; i++)
    bad[i] = bad[i - 1] + ((nums[i] % 2 == nums[i - 1] % 2) ? 1 : 0);
  for (int i = 0; i < queriesSize; i++) {
    int from = queries[i][0], to = queries[i][1], bad_cnt;
    bad_cnt = from == to ? 0 : bad[to] - bad[from];
    ans[i] = !bad_cnt;
  }
  free(bad);
  return ans;
}

int main() {
  int n1[] = {3, 4, 1, 2, 6}, q1i[1][2] = {{0, 4}}, rs1;
  int n2[] = {4, 3, 1, 6}, q2i[2][2] = {{0, 2}, {2, 3}}, rs2;
  struct two_d_arr *q1 = two_d_arr_init(1, 2, q1i);
  struct two_d_arr *q2 = two_d_arr_init(2, 2, q2i);
  bool *ias1 = isArraySpecial(n1, ARRAY_SIZE(n1), q1->arr, q1->row_size,
                              q1->col_size, &rs1);
  bool *ias2 = isArraySpecial(n2, ARRAY_SIZE(n2), q2->arr, q2->row_size,
                              q2->col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ias1[i]); // expect: 0
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ias2[i]); // expect: 0 1
  printf("\n");
  free(ias1), free(ias2);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
