// 3501. Maximize Active Section with Trade II
#include "leetcode.h"

/*
 * you are given a binary string 's' of length 'n' where '1' represents an
 * active section, and '0' represents an inactive section. you can perform at
 * most one trade to maximise the number of active sections in 's'.
 * additionally, you are given a 2d array 'queries' where 'queries[i] = [l_i,
 * r_i]' represents a substring 's[l_i ... r_i]'. for each query, determine the
 * maximum possible number of active sections in 's' after making the optimal
 * trade on the substring 's[l_i ... r_i]'. return an array 'answer' where
 * 'answer[i]' is the result for 'queries[i]'.
 */

struct zero_run {
  int start;
  int end;
};

struct pair {
  int l1;
  int r1;
  int l2;
  int r2;
  int sum;
};

int get_bit_len(int n) {
  int res = 0;
  while (n > 0) {
    res++;
    n >>= 1;
  }
  return res;
}

int lower_bound_r1(int *arr, int n, int val) {
  int l = 0, r = n;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (arr[m] >= val)
      r = m;
    else
      l = m + 1;
  }
  return l;
}

int upper_bound_l2(int *arr, int n, int val) {
  int l = 0, r = n;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (arr[m] > val)
      r = m;
    else
      l = m + 1;
  }
  return l;
}

int query_stack(int **stack, int l, int r) {
  if (l > r)
    return 0;
  int n = r - l + 1;
  int j = get_bit_len(n) - 1;
  return fmax(stack[l][j], stack[r - (1 << j)][j]);
}

int *maxActiveSectionsAfterTrade(char *s, int **queries, int queriesSize,
                                 int *queriesColSize, int *returnSize) {
  int n = strlen(s), ones_cnt = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '1')
      ones_cnt++;
  struct zero_run *zero_runs =
      (struct zero_run *)malloc(n * sizeof(struct zero_run));
  int zero_cnt = 0, i = 0;
  while (i < n) {
    if (s[i] == '0') {
      int start = i;
      while (i < n && s[i] == '0')
        i++;
      zero_runs[zero_cnt++] = (struct zero_run){start, i - 1};
    } else
      i++;
  }
  int pair_cnt = zero_cnt > 1 ? zero_cnt - 1 : 0;
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  if (!pair_cnt) {
    for (int q = 0; q < queriesSize; q++)
      ans[q] = ones_cnt;
    free(zero_runs);
    return ans;
  }
  struct pair *pairs = (struct pair *)malloc(pair_cnt * sizeof(struct pair));
  int *r1_list = (int *)malloc(pair_cnt * sizeof(int));
  int *l2_list = (int *)malloc(pair_cnt * sizeof(int));
  for (int k = 0; k < pair_cnt; k++) {
    int l1 = zero_runs[k].start, r1 = zero_runs[k].end;
    int l2 = zero_runs[k + 1].start, r2 = zero_runs[k + 1].end;
    pairs[k] = (struct pair){l1, r1, l2, r2, (r1 - l1 + 1) + (r2 - l2 + 1)};
    r1_list[k] = r1;
    l2_list[k] = l2;
  }
  int k = get_bit_len(pair_cnt);
  int **stack = (int **)malloc(pair_cnt * sizeof(int *));
  for (int j = 0; j < pair_cnt; j++)
    stack[i] = (int *)calloc(k, sizeof(int));
  for (int j = 0; j < pair_cnt; j++)
    stack[j][0] = pairs[j].sum;
  for (int j = 1; j < k; j++)
    for (int i = 0; i <= pair_cnt - (1 << j); i++)
      stack[i][j] = fmax(stack[i][j - 1], stack[i + (1 << (j - 1))][j - 1]);
  for (int q = 0; q < queriesSize; q++) {
    int l = queries[q][0], r = queries[q][1];
    int first_k = lower_bound_r1(r1_list, pair_cnt, l);
    int last_k = upper_bound_l2(l2_list, pair_cnt, r) - 1;
    if (first_k > last_k) {
      ans[q] = ones_cnt;
      continue;
    }
    int best_gain = 0;
    if (first_k == last_k) {
      struct pair p = pairs[first_k];
      int gain = (p.r1 - fmax(p.l1, l) + 1) + (fmin(p.r2, r) - p.l2 + 1);
      best_gain = fmax(best_gain, gain);
    } else {
      struct pair p1 = pairs[first_k], p2 = pairs[last_k];
      int gain1 = (p1.r1 - fmax(p1.l1, l) + 1) + (fmin(p1.r2, r) - p1.l2 + 1);
      int gain2 = (p2.r1 - fmax(p2.l1, l) + 1) + (fmin(p2.r2, r) - p2.l2 + 1);
      if (first_k + 1 <= last_k - 1)
        best_gain =
            fmax(best_gain, query_stack(stack, first_k + 1, last_k - 1));
    }
    ans[q] = ones_cnt + best_gain;
  }
  for (int j = 0; j < pair_cnt; j++)
    free(stack[j]);
  free(stack);
  free(zero_runs);
  free(pairs);
  free(r1_list);
  free(l2_list);
  return ans;
}

int main() {
  char *s1 = "01", *s2 = "0100", *s3 = "1000100", *s4 = "01010";
  int q1i[1][2] = {{0, 1}};
  int q2i[4][2] = {{0, 3}, {0, 2}, {1, 3}, {2, 3}};
  int q3i[3][2] = {{1, 5}, {0, 6}, {0, 4}};
  int q4i[3][2] = {{0, 3}, {1, 4}, {1, 3}};
  int r1[] = {1}, rs1;
  int r2[] = {4, 3, 1, 1}, rs2;
  int r3[] = {6, 7, 2}, rs3;
  int r4[] = {4, 4, 2}, rs4;
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  struct two_d_arr *q3 =
      two_d_arr_init(ARRAY_SIZE(q3i), ARRAY_SIZE(q3i[0]), q3i);
  struct two_d_arr *q4 =
      two_d_arr_init(ARRAY_SIZE(q4i), ARRAY_SIZE(q4i[0]), q4i);
  int *masat1 = maxActiveSectionsAfterTrade(s1, q1->arr, q1->row_size,
                                            q1->col_size, &rs1);
  int *masat2 = maxActiveSectionsAfterTrade(s2, q2->arr, q2->row_size,
                                            q2->col_size, &rs2);
  int *masat3 = maxActiveSectionsAfterTrade(s3, q3->arr, q3->row_size,
                                            q3->col_size, &rs3);
  int *masat4 = maxActiveSectionsAfterTrade(s4, q4->arr, q4->row_size,
                                            q4->col_size, &rs4);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", masat1[i]);
    assert(masat1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", masat2[i]);
    assert(masat2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", masat3[i]);
    assert(masat3[i] == r3[i]);
  }
  printf("\n");
  for (int i = 0; i < rs4; i++) {
    printf("%d ", masat4[i]);
    assert(masat4[i] == r4[i]);
  }
  printf("\n");
  free(masat1);
  free(masat2);
  free(masat3);
  free(masat4);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
  two_d_arr_free(q3);
  two_d_arr_free(q4);
}
