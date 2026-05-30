// 3161. Block Placement Queries
#include "leetcode.h"

/*
 * there exists an infinite number line, with its origin at 0 and extending
 * towards the positive x-axis. you are given a 2d array 'qeuries', which
 * contains two types of queries: for a query of type 1, 'queries{i} = {1, x}'.
 * build an obstacle at distance 'x' from the origin. it is guaranteed that
 * there is no obstacle at distance 'x' when the query is asked. for query type
 * 2, 'queries{i} = {2, x, sz}'. check if it is possible to place a block of
 * size 'sz' anywhere in the range '{0, x}' on the line, such that the block
 * entirely lies in the range '{0, x}'. a block cannot be placed if it
 * intersects with any obstacle, but it may touch it. note that you do not
 * actually place the block. queries are separate. return a boolean array
 * 'results' where 'results{i}' is true if you can place a block specified in
 * the i'th query of type 2, and false otherwise.
 */

struct segment_tree {
  int n;
  int *tree;
};

void update(struct segment_tree *obj, int i, int val) {
  for (obj->tree[i += obj->n] = val; i > 1; i >>= 1)
    obj->tree[i >> 1] = fmax(obj->tree[i], obj->tree[i ^ 1]);
}

int query(struct segment_tree *obj, int r) {
  int res = 0;
  for (int l = obj->n, r_idx = r + obj->n + 1; l < r_idx;
       l >>= 1, r_idx >>= 1) {
    if (l & 1)
      res = fmax(res, obj->tree[l++]);
    if (r_idx & 1)
      res = fmax(res, obj->tree[--r_idx]);
  }
  return res;
}

bool *getResults(int **queries, int queriesSize, int *queriesColSize,
                 int *returnSize) {
  int max_x = 0, n = 1;
  for (int i = 0; i < queriesSize; i++)
    max_x = fmax(max_x, queries[i][1]);
  while (n <= max_x + 1)
    n *= 2;
  struct segment_tree st = {n, (int *)calloc(2 * n, sizeof(int))};
  int *obstacles = (int *)malloc((queriesSize + 1) * sizeof(int));
  obstacles[0] = 0;
  int obstacle_cnt = 1;
  bool *ans = (bool *)malloc(queriesSize * sizeof(bool));
  *returnSize = 0;
  for (int i = 0; i < queriesSize; i++) {
    int type = queries[i][0], x = queries[i][1];
    int left = 0, right = obstacle_cnt;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (obstacles[mid] > x)
        right = mid;
      else
        left = mid + 1;
    }
    int idx = left;
    if (type == 1) {
      int prev = obstacles[idx - 1];
      int next = idx < obstacle_cnt ? obstacles[idx] : -1;
      update(&st, x, x - prev);
      if (next != -1)
        update(&st, next, next - x);
      memmove(&obstacles[idx + 1], &obstacles[idx],
              (obstacle_cnt - idx) * sizeof(int));
      obstacles[idx] = x;
      obstacle_cnt++;
    } else {
      int sz = queries[i][2], prev = obstacles[idx - 1];
      int max = fmax(x - prev, query(&st, prev));
      ans[(*returnSize)++] = (sz <= max);
    }
  }
  free(obstacles);
  free(st.tree);
  return ans;
}

int main() {
  int q1i[4][3] = {{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}};
  int qcs1[] = {}, rs1;
  bool r1[] = {false, true, true};
  int q2i[5][3] = {{1, 7}, {2, 7, 6}, {1, 2}, {2, 7, 5}, {2, 7, 6}};
  int qcs2[] = {}, rs2;
  bool r2[] = {true, true, false};
  for (int i = 0; i < ARRAY_SIZE(q1i); i++)
    qcs1[i] = ARRAY_SIZE(q1i[i]);
  for (int i = 0; i < ARRAY_SIZE(q2i); i++)
    qcs2[i] = ARRAY_SIZE(q2i[i]);
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[1]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[1]), q2i);
  bool *gr1 = getResults(q1->arr, q1->row_size, qcs1, &rs1);
  bool *gr2 = getResults(q2->arr, q2->row_size, qcs2, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", gr1[i]);
    assert(gr1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", gr2[i]);
    assert(gr2[i] == r2[i]);
  }
  printf("\n");
  free(gr1);
  free(gr2);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
