// 3355. Zero Array Transformation I
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and a 2d array 'queries'
 * where 'queries[i] = [li, ri]'. for each 'queries[i]' select a subset of
 * indices within the range '[li, ri]' in 'nums' and decrement the values at the
 * selected indices by 1. a zero array is an array where all elements are equal
 * to 0. return true if it is possible to transform 'nums' into a zero array
 * after processing all the queries sequentially, otherwise return false.
 */

bool isZeroArray(int *nums, int numsSize, int **queries, int queriesSize,
                 int *queriesColSize) {
  int *freq = (int *)calloc(numsSize + 1, sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int l = queries[i][0], r = queries[i][1];
    freq[l]++;
    freq[r + 1]--;
  }
  int cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    cnt += freq[i];
    if (nums[i] > cnt) {
      free(freq);
      return false;
    }
  }
  free(freq);
  return true;
}

int main() {
  int n1[] = {1, 0, 1}, q1i[1][2] = {{0, 2}};
  int n2[] = {4, 3, 2, 1}, q2i[2][2] = {{1, 3}, {0, 2}};
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  printf("%d\n", isZeroArray(n1, ARRAY_SIZE(n1), q1->arr, q1->row_size,
                             q1->col_size)); // expect: 1
  printf("%d\n", isZeroArray(n2, ARRAY_SIZE(n2), q2->arr, q2->row_size,
                             q2->col_size)); // expect: 0
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
