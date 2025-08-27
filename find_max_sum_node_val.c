// 3068. Find the Maximum Sum of Node Values
#include "leetcode.h"

/*
 * there exists an undirected tree with 'n' nodes numbered 0 to 'n - 1'. you are
 * given a 0-indexed 2d integer array 'edges' of length 'n - 1', where 'edges[i]
 * = [ui,vi]' indicates that there is an edge between nodes 'ui' and 'vi' in the
 * tree. you are also given a positive integer 'k' and a 0 indexed array of non
 * negative integers 'nums' of length 'n' where 'nums[i]' represents the value
 * of the node numbered 'i'. return the maximum possible sum of the values alice
 * can achieve by performing the operation any number of times.
 */

long long maximumValueSum(int *nums, int numsSize, int k, int **edges,
                          int edgesSize, int *edgesColSize) {
  long long ans = 0;
  int u = 1 << 30, v = 0;
  for (int i = 0; i < numsSize; i++) {
    int curr = nums[i] ^ k;
    ans += fmax(nums[i], curr);
    u ^= nums[i] < curr;
    v = fmin(v, abs(nums[i] - curr));
  }
  return ans - u * v;
}

int main() {
  int n1[] = {1, 2, 1}, e1i[2][2] = {{0, 1}, {0, 2}};
  int n2[] = {2, 3}, e2i[1][2] = {{0, 1}};
  int n3[] = {7, 7, 7, 7, 7, 7},
      e3i[5][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  struct two_d_arr *e3 =
      two_d_arr_init(ARRAY_SIZE(e3i), ARRAY_SIZE(e3i[0]), e3i);
  printf("%lld\n", maximumValueSum(n1, ARRAY_SIZE(n1), 3, e1->arr, e1->row_size,
                                   e1->col_size)); // expect: 6
  printf("%lld\n", maximumValueSum(n2, ARRAY_SIZE(n2), 7, e2->arr, e2->row_size,
                                   e2->col_size)); // expect: 9
  printf("%lld\n", maximumValueSum(n3, ARRAY_SIZE(n3), 3, e3->arr, e3->row_size,
                                   e3->col_size)); // expect: 42
  two_d_arr_free(e1);
  two_d_arr_free(e2);
  two_d_arr_free(e3);
}
