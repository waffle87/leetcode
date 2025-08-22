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
  int *tree;
  int *max;
  int size;
};

struct segment_tree *segment_tree_init(int size) {
  struct segment_tree *obj =
      (struct segment_tree *)malloc(sizeof(struct segment_tree));
  obj->size = size;
  obj->tree = (int *)malloc(size * sizeof(int));
  obj->max = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    obj->tree[i] = -1;
    obj->max[i] = -1;
  }
  return obj;
}

void segment_tree_update(struct segment_tree *obj, int idx) {
  int tmp = 0, max = 0, start = 0;
  if (obj->tree[idx] != -1) {
    start = idx;
    max = obj->max[idx];
  } else {
    for (int i = idx; i >= 0; i--) {
      if (obj->tree[i] != -1) {
        start = i;
        max = obj->max[i];
        break;
      }
    }
  }
  obj->tree[idx] = -2;
  for (int i = start; i < idx; i++) {
    if (obj->tree[i] == -1)
      obj->tree[i] = tmp;
    if (tmp > max)
      max = tmp;
    tmp++;
    if (obj->tree[i] == -2)
      tmp = 1;
    obj->max[i] = max;
  }
  if (tmp > max)
    max = tmp;
  obj->max[idx] = max;
  for (int i = idx + 1; i < obj->size; i++) {
    if (obj->tree[i] == -1)
      break;
    if (obj->max[i] == max && (obj->tree[i] == -2 || obj->tree[i] == max))
      break;
    if (obj->tree[i] == -2) {
      if (tmp > max)
        max = tmp;
      tmp = 0;

    } else
      obj->tree[i] = tmp;
    if (tmp > max)
      max = tmp;
    tmp++;
    obj->max[i] = max;
  }
}

int segment_tree_query(struct segment_tree *obj, int end, int size) {
  if (end - size < 0)
    return 0;
  for (int i = end; i >= 0; i--) {
    if (end - i >= size)
      return size;
    if (obj->tree[i] != -1)
      return obj->max[i];
  }
  return 0;
}

bool is_intersected(struct segment_tree *obj, int end, int size) {
  if (end - size < 0)
    return false;
  int max = segment_tree_query(obj, end, size);
  return max >= size;
}

bool *getResults(int **queries, int queriesSize, int *queriesColSize,
                 int *returnSize) {
  *returnSize = 0;
  int tree_size = 0;
  for (int i = 0; i < queriesSize; i++) {
    if (tree_size < queries[i][1])
      tree_size = queries[i][1];
    if (queriesColSize[i] == 3 && queries[i][0] == 2)
      (*returnSize)++;
  }
  tree_size++;
  bool *ans = (bool *)malloc(*returnSize * sizeof(bool));
  struct segment_tree *tree = segment_tree_init(tree_size);
  int idx = 0;
  for (int i = 0; i < queriesSize; i++) {
    int m = queriesColSize[i], *curr = queries[i];
    if (m == 2 && curr[0] == 1) {
      int val = curr[1];
      segment_tree_update(tree, val);
    } else if (m == 3 && curr[0] == 2) {
      int end = curr[1], size = curr[2];
      ans[idx++] = is_intersected(tree, end, size);
    }
  }
  free(tree->tree), free(tree);
  return ans;
}

int main() {
  int q1i[4][3] = {{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}}, qcs1[] = {}, rs1;
  int q2i[5][3] = {{1, 7}, {2, 7, 6}, {1, 2}, {2, 7, 5}, {2, 7, 6}},
      qcs2[] = {}, rs2;
  for (int i = 0; i < ARRAY_SIZE(q1i); i++)
    qcs1[i] = ARRAY_SIZE(q1i[i]);
  for (int i = 0; i < ARRAY_SIZE(q2i); i++)
    qcs2[i] = ARRAY_SIZE(q2i[i]);
  struct two_d_arr q1, q2;
  two_d_arr_init(&q1, ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  two_d_arr_init(&q2, ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  bool *gr1 = getResults(q1.arr, q1.row_size, qcs1, &rs1);
  bool *gr2 = getResults(q2.arr, q2.row_size, qcs2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", gr1[i]); // expect: 0 1 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", gr1[i]); // expect: 1 1 1
  printf("\n");
  free(gr1);
  free(gr2);
  two_d_arr_free(&q1);
  two_d_arr_free(&q2);
}
