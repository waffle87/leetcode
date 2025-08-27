// 3356. Zero Array Transformation II
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and a 2d array 'queries'
 * where 'queries[i] [l_i, r_i, val_i]'. each 'queries[i]' represents the
 * following action on 'nums': decrement the value at each index in the range
 * '[l_i, r_i]' in 'nums' by at most 'val_i'. the amount by which each value is
 * decremented can be chosen independently for each index. a zero array is an
 * array with all its elements equal to 0. return the minimum possible
 * non-negative value of 'k', such that after processing the first 'k' queries
 * in sequence, 'nums' becomes a zero array. if no such 'k' exists, return -1.
 */

bool can_cover(int *nums, int n, int **queries, int k) {
  int *diff = (int *)calloc(n + 1, sizeof(int));
  for (int i = 0; i < k; i++) {
    int l = queries[i][0];
    int r = queries[i][1];
    int val = queries[i][2];
    diff[l] += val;
    if (r + 1 < n)
      diff[r + 1] -= val;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += diff[i];
    if (sum < nums[i]) {
      free(diff);
      return false;
    }
  }
  free(diff);
  return true;
}

int minZeroArray(int *nums, int numsSize, int **queries, int queriesSize,
                 int *queriesColSize) {
  int already_zero = 1;
  for (int i = 0; i < numsSize; i++)
    if (nums[i]) {
      already_zero = 0;
      break;
    }
  if (already_zero)
    return 0;
  int l = 1, r = queriesSize, ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (can_cover(nums, numsSize, queries, mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}

int main() {
  int n1[] = {2, 0, 2}, q1i[3][3] = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
  int n2[] = {4, 3, 2, 1}, q2i[2][3] = {{1, 3, 2}, {0, 2, 1}};
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  printf("%d\n", minZeroArray(n1, ARRAY_SIZE(n1), q1->arr, q1->row_size,
                              q1->col_size)); // expect: 2
  printf("%d\n", minZeroArray(n2, ARRAY_SIZE(n2), q2->arr, q2->row_size,
                              q2->col_size)); // expect: -1
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
