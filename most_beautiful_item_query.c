// 2070. Most Beautiful Item for Each Query
#include "leetcode.h"

/*
 * you are given a 2d integer array 'items' where 'items[i] = [price_i,
 * beauty_i]' denotes the price and beauty of an item respectively. you are also
 * given a 0-indexed integer array 'queries'. for each 'queries[i]' you want to
 * determine the maximum beauty of an item whose price is less than or equal to
 * 'queries[i]'. if no such item exists, then the answer to this query is 0.
 * return an array 'answer' of the same length as 'queries' where 'answer[i]' is
 * the answer to the i'th query.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a;
  int *bb = *(int **)b;
  if (aa[0] != bb[0])
    return aa[0] - bb[0];
  return aa[1] - bb[1];
}

int binsearch(int **items, int n, int target) {
  int left = 0, right = n - 1, res = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (items[mid][0] <= target) {
      res = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  return res;
}

int *maximumBeauty(int **items, int itemsSize, int *itemsColSize, int *queries,
                   int queriesSize, int *returnSize) {
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  qsort(items, itemsSize, sizeof(items), cmp);
  int *max = (int *)malloc(itemsSize * sizeof(int)), curr_max = -1;
  for (int i = 0; i < itemsSize; i++) {
    max[i] = fmax(curr_max, items[i][1]);
    curr_max = max[i];
  }
  for (int i = 0; i < queriesSize; i++) {
    int valid = binsearch(items, itemsSize, queries[i]);
    if (valid == -1) {
      ans[i] = 0;
      continue;
    }
    ans[i] = max[valid];
  }
  *returnSize = queriesSize;
  return ans;
}

int main() {
  int i1i[5][2] = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}},
      q1[] = {1, 2, 3, 4, 5, 6}, rs1;
  int i2i[4][2] = {{1, 2}, {1, 2}, {1, 3}, {1, 4}}, q2[] = {1}, rs2;
  int i3i[1][2] = {{10, 1000}}, q3[] = {5}, rs3;
  struct two_d_arr i1, i2, i3;
  two_d_arr_init(&i1, 5, 2, i1i);
  two_d_arr_init(&i2, 4, 2, i2i);
  two_d_arr_init(&i3, 1, 2, i3i);
  int *mb1 =
      maximumBeauty(i1.arr, i1.row_size, i1.col_size, q1, ARRAY_SIZE(q1), &rs1);
  int *mb2 =
      maximumBeauty(i2.arr, i2.row_size, i2.col_size, q2, ARRAY_SIZE(q2), &rs2);
  int *mb3 =
      maximumBeauty(i3.arr, i3.row_size, i3.col_size, q3, ARRAY_SIZE(q3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", mb1[i]); // expect: 2 4 5 5 6 6
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", mb2[i]); // expect: 4
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", mb3[i]); // expect: 0
  printf("\n");
  free(mb1), free(mb2), free(mb3);
  two_d_arr_free(&i1), two_d_arr_free(&i2), two_d_arr_free(&i3);
}
