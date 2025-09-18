// 2055. Plates Between Candles
#include "leetcode.h"

/*
 * there is a long table with a line of plates and candles arranged on top of
 * it. you are given a 0-indexed string 's' consisting of characters '*' and '|'
 * only where '*' represents a plate and '|' represents a candle. return an
 * integer array 'answer' where 'answer[i]' is the answer to the i'th query.
 */

int *platesBetweenCandles(char *s, int **queries, int queriesSize,
                          int *queriesColSize, int *returnSize) {
  int n = strlen(s), cnt = 0, lidx = -1, ridx = -1;
  int *dp = (int *)calloc(n, sizeof(int));
  int *left = (int *)calloc(n, sizeof(int));
  int *right = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    if (s[i] == '*')
      cnt++;
    else
      lidx = i;
    dp[i] = cnt;
    left[i] = lidx;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '|')
      ridx = i;
    right[i] = ridx;
  }
  *returnSize = queriesSize;
  int *ans = (int *)malloc((*returnSize) * sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int r = right[queries[i][0]], l = left[queries[i][1]];
    ans[i] = (r == -1 || l == -1 || r >= l) ? 0 : dp[l] - dp[r];
  }
  free(dp);
  free(left);
  free(right);
  return ans;
}

int main() {
  int q1i[2][2] = {{2, 5}, {5, 9}},
      q2i[5][2] = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
  char *s1 = "**|**|***|", *s2 = "***|**|*****|**||**|*";
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  int rs1, *pbc1 = platesBetweenCandles(s1, q1->arr, q1->row_size, q1->col_size,
                                        &rs1);
  int rs2, *pbc2 = platesBetweenCandles(s2, q2->arr, q2->row_size, q2->col_size,
                                        &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pbc1[i]); // expect: 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", pbc2[i]); // expect: 9 0 0 0 0
  printf("\n");
  free(pbc1);
  free(pbc2);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
