// 3653. XOR After Range Multiplication Queries I
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and a 2d integer array
 * 'queries' of size 'q', where 'queries[i] = [l, r, k, v]'. for each query, you
 * must apply the following operations in order: set 'idx = l', while 'idx <=
 * r', update 'nums[idx] = (nums[idx] * v) % (10^9 + 7)', set 'idx += k'. return
 * the bitwise xor of all elements in 'nums' after processing all queries.
 */

int xorAfterQueries(int *nums, int numsSize, int **queries, int queriesSize,
                    int *queriesColSize) {
  static int mod = 1e9 + 7;
  for (int i = 0; i < queriesSize; i++) {
    int l = queries[i][0];
    int r = queries[i][1];
    int k = queries[i][2];
    int v = queries[i][3];
    for (int j = l; j <= r; j += k)
      nums[j] = (int)((int64_t)nums[j] * v % mod);
  }
  int ans = 0;
  for (int i = 0; i < numsSize; i++)
    ans ^= nums[i];
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
