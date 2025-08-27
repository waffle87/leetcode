// 2438. Range Product Queries of Powers
#include "leetcode.h"

/*
 * given a positive integer 'n', there exists a 0-indexed array called 'powers'
 * composed of the minimum number of powers of 2 that sum to 'n'. the array is
 * sorted in non-decreasing order, and there is only one way to form the array.
 * you are also given a 0-indexed 2d integer array 'queries' where 'queries[i] =
 * [left_i, right_i]'. each 'queries[i]' represents a query where you have to
 * find the product of all 'powers[j]' with 'left_i <= j <= right_i'. return an
 * array 'answers', equal in length to 'queries', where 'answers[i]' is the
 * answer to each i'th query. since the answer may be too large, each
 * 'answers[i]' should be returned modulo 10e9+7.
 */

const int mod = 1e9 + 7;

void get_products(int *powers, long long *seg, int root, int low, int high) {
  if (low == high) {
    seg[root] = powers[low];
    return;
  }
  int i = (root << 1) + 1;
  int mid = (low + high) >> 1;
  get_products(powers, seg, i, low, mid);
  get_products(powers, seg, i + 1, mid + 1, high);
  seg[root] = (seg[i] * seg[i + 1]) % mod;
}

int range_query(long long *seg, int root, int low, int high, int left,
                int right) {
  if (high < left || low > right)
    return 1;
  if (low >= left && high <= right)
    return seg[root];
  int i = (root << 1) + 1;
  int mid = (low + high) >> 1;
  long p1 = range_query(seg, i, low, mid, left, right);
  long p2 = range_query(seg, i + 1, mid + 1, high, left, right);
  return (p1 * p2) % mod;
}

int *productQueries(int n, int **queries, int queriesSize, int *queriesColSize,
                    int *returnSize) {
  int powers[33], ns = 0, mask = 1;
  while (n > 0) {
    if (n & mask) {
      powers[ns++] = mask;
      n &= ~mask;
    }
    mask <<= 1;
  }
  long long seg[150];
  get_products(powers, seg, 0, 0, ns - 1);
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i)
    ans[i] = range_query(seg, 0, 0, ns - 1, queries[i][0], queries[i][1]);
  *returnSize = queriesSize;
  return ans;
}

int main() {
  int q1i[3][2] = {{0, 1}, {2, 2}, {0, 3}}, q2i[1][2] = {{0, 0}};
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  int rs1, *pq1 = productQueries(15, q1->arr, q1->row_size, q1->col_size, &rs1);
  int rs2, *pq2 = productQueries(2, q2->arr, q2->row_size, q2->col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pq1[i]); // expect: 2 4 6
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", pq2[i]); // expect: 2
  printf("\n");
  free(pq1);
  free(pq2);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
