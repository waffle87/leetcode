// 3756. Concatenate Non-Zero Digits and Multiply by Sum II
#include "leetcode.h"

/*
 * you are given a string 's' of length 'm' consisting of digits. you are also
 * given a 2d integer array 'queries' where 'queries[i] = [l_i, r_i]'. for each
 * 'queries[i]', extract the substring 's[l_i ... r_i]'. then perform the
 * following: form a new integer 'x' by concatenating all the non-zero digits
 * from the substring in their original order. if there are no non-zero digits,
 * 'x = 0'. let 'sum' be the sum of digits in 'x'. the answer is 'x * sum'.
 * return an array of integers 'answer' where 'answer[i]' is the answer to the
 * i'th query. since the answers may be very large, return them modulo 10^9 + 7.
 */

#define MAX_N 100005
static long long pow10[MAX_N];
static int mod = 1e9 + 7;
static bool initialised = false;

void pow10_init(void) {
  if (initialised)
    return;
  pow10[0] = 1;
  for (int i = 1; i < MAX_N; ++i)
    pow10[i] = (pow10[i - 1] * 10) % mod;
  initialised = true;
}

int *sumAndMultiply(char *s, int **queries, int queriesSize,
                    int *queriesColSize, int *returnSize) {
  pow10_init();
  int n = strlen(s), m = queriesSize;
  int *sum = (int *)calloc(n + 1, sizeof(int));
  int *cnt = (int *)calloc(n + 1, sizeof(int));
  int *ans = (int *)malloc(m * sizeof(int));
  *returnSize = m;
  long long *x = (long long *)calloc(n + 1, sizeof(long long));
  for (int i = 0; i < n; ++i) {
    int d = s[i] - '0';
    sum[i + 1] = sum[i] + d;
    x[i + 1] = d > 0 ? (x[i] * 10 + d) % mod : x[i];
    cnt[i + 1] = cnt[i] + (d > 0);
  }
  for (int i = 0; i < m; ++i) {
    int l = queries[i][0], r = queries[i][1];
    int len = cnt[r] - cnt[l];
    long long val_x = (x[r] - x[l] * pow10[len] % mod + mod) % mod;
    long long val_sum = sum[r] - sum[l];
    ans[i] = (int)((val_x * val_sum) % mod);
  }
  free(sum);
  free(cnt);
  free(x);
  return ans;
}

int main() {
  int q1i[3][2] = {{0, 7}, {1, 3}, {4, 6}};
  int q2i[2][2] = {{0, 3}, {1, 1}};
  int q3i[1][2] = {{0, 9}};
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  struct two_d_arr *q3 =
      two_d_arr_init(ARRAY_SIZE(q3i), ARRAY_SIZE(q3i[0]), q3i);
  char *s1 = "10203004";
  char *s2 = "1000";
  char *s3 = "9876543210";
  int r1[] = {738, 4, 9}, rs1;
  int r2[] = {1, 0}, rs2;
  int r3[] = {444444137}, rs3;
  int *sam1 = sumAndMultiply(s1, q1->arr, q1->row_size, q1->col_size, &rs1);
  int *sam2 = sumAndMultiply(s2, q2->arr, q2->row_size, q2->col_size, &rs2);
  int *sam3 = sumAndMultiply(s3, q3->arr, q3->row_size, q3->col_size, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", sam1[i]);
    assert(sam1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", sam2[i]);
    assert(sam2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", sam3[i]);
    assert(sam3[i] == r3[i]);
  }
  printf("\n");
  free(sam1);
  free(sam2);
  free(sam3);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
  two_d_arr_free(q3);
}
