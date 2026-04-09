// 3655. XOR After Range Multiplication Queries II
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and a 2d integer array
 * 'queries' of size 'q', where 'queries[i] = [l, r, k, v]'. for each query, you
 * must apply the following operations in order. set 'idx = l', while 'idx <=
 * r', update 'nums[idx] = (nums[idx] * v) % (10^9 + 7)', set 'idx += k'. return
 * the bitwise xor of all elements in 'nums' after processing all queries.
 */

const int mod = 1e9 + 7;

int pow_mod(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1)
      res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return (int)res;
}

int xorAfterQueries(int *nums, int numsSize, int **queries, int queriesSize,
                    int *queriesColSize) {
  int n = numsSize, t = (int)sqrt(n);
  int ***groups = (int ***)malloc(t * sizeof(int **));
  int *groups_cnt = (int *)calloc(t, sizeof(int));
  int *groups_cap = (int *)calloc(t, sizeof(int));
  for (int i = 0; i < t; i++) {
    groups_cap[i] = 10;
    groups[i] = (int **)malloc(groups_cap[i] * sizeof(int *));
  }
  for (int i = 0; i < queriesSize; i++) {
    int l = queries[i][0];
    int r = queries[i][1];
    int k = queries[i][2];
    int v = queries[i][3];
    if (k < t) {
      if (groups_cnt[k] >= groups_cap[k]) {
        groups_cap[k] *= 2;
        groups[k] = (int **)realloc(groups[k], groups_cap[k] * sizeof(int *));
      }
      int *q = (int *)malloc(3 * sizeof(int));
      q[0] = l;
      q[1] = r;
      q[2] = v;
      groups[k][groups_cnt[k]++] = q;
    } else
      for (int j = l; j <= r; j += k)
        nums[i] = (int)((long long)nums[i] * v % mod);
  }
  long long *diff = (long long *)calloc(n + t, sizeof(long long));
  for (int k = 1; k < t; k++) {
    if (!groups_cnt[k])
      continue;
    for (int i = 0; i < n + t; i++)
      diff[i] = 1;
    for (int g = 0; g < groups_cnt[k]; g++) {
      int l = groups[k][g][0];
      int r = groups[k][g][1];
      int v = groups[k][g][2];
      diff[l] = diff[l] * v % mod;
      int new_r = ((r - 1) / k + 1) * k + 1;
      diff[new_r] = diff[new_r] * pow_mod(v, mod - 2) % mod;
    }
    for (int i = k; i < n; i++)
      diff[i] = diff[i] * diff[i - k] % mod;
    for (int i = 0; i < n; i++)
      nums[i] = (int)((long long)nums[i] * diff[i] % mod);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans ^= nums[i];
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < groups_cnt[i]; j++)
      free(groups[i][j]);
    free(groups[i]);
  }
  free(groups);
  free(groups_cnt);
  free(groups_cap);
  free(diff);
  return ans;
}

int main() {
  int n1[] = {1, 1, 1}, q1i[1][4] = {{0, 2, 1, 4}};
  int n2[] = {2, 3, 1, 5, 4}, q2i[2][4] = {{1, 4, 2, 3}, {0, 2, 1, 2}};
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  int r1 =
      xorAfterQueries(n1, ARRAY_SIZE(n1), q1->arr, q1->row_size, q1->col_size);
  int r2 =
      xorAfterQueries(n2, ARRAY_SIZE(n2), q2->arr, q2->row_size, q2->col_size);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 31);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
