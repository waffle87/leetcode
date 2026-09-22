// 3525. Find X Value of Array II
#include "leetcode.h"

#define MAX_K 6

struct segment_tree {
  int k;
  int n;
  int *tree;
};

static inline int *get_node(struct segment_tree *obj, int o) {
  return &obj->tree[o * MAX_K];
}

static void make_leaf(struct segment_tree *obj, int o, int val) {
  int *node = get_node(obj, o);
  memset(node, 0, MAX_K * sizeof(int));
  int r = val % obj->k;
  node[r] = 1;
  node[obj->k] = r;
}

static void merge_pre(struct segment_tree *obj, int *left, int *right,
                      int *res) {
  int l = left[obj->k], r = right[obj->k];
  res[obj->k] = (l * r) % obj->k;
  for (int x = 0; x < obj->k; x++)
    res[x] = left[x];
  for (int x = 0; x < obj->k; x++)
    res[(l * x) % obj->k] += right[x];
}

static void maintain(struct segment_tree *obj, int o) {
  int *left = get_node(obj, o * 2);
  int *right = get_node(obj, o * 2 + 1);
  int *node = get_node(obj, o);
  merge_pre(obj, left, right, node);
}

static void build(struct segment_tree *obj, int *nums, int o, int l, int r) {
  if (l == r) {
    make_leaf(obj, o, nums[l]);
    return;
  }
  int m = (l + r) / 2;
  build(obj, nums, o * 2, l, m);
  build(obj, nums, o * 2 + 1, m + 1, r);
  maintain(obj, o);
}

struct segment_tree *segment_tree_init(int *nums, int n, int k) {
  struct segment_tree *obj =
      (struct segment_tree *)malloc(sizeof(struct segment_tree));
  obj->k = k;
  obj->n = n;
  int size = 2 << (int)ceil(log2(n));
  obj->tree = (int *)calloc(size * MAX_K, sizeof(int));
  build(obj, nums, 1, 0, n - 1);
  return obj;
}

void segment_tree_free(struct segment_tree *obj) {
  if (obj) {
    free(obj->tree);
    free(obj);
  }
}

void update(struct segment_tree *obj, int o, int l, int r, int idx, int val) {
  if (l == r) {
    make_leaf(obj, o, val);
    return;
  }
  int m = (l + r) / 2;
  if (idx <= m)
    update(obj, o * 2, l, m, idx, val);
  else
    update(obj, o * 2 + 1, m + 1, r, idx, val);
  maintain(obj, o);
}

void query(struct segment_tree *obj, int o, int l, int r, int left, int right,
           int *res) {
  if (left <= l && r <= right) {
    int *node = get_node(obj, o);
    memcpy(res, node, MAX_K * sizeof(int));
    return;
  }
  int m = (l + r) / 2;
  if (right <= m) {
    query(obj, o * 2, l, m, left, right, res);
    return;
  }
  if (left > m) {
    query(obj, o * 2 + 1, m + 1, r, left, right, res);
    return;
  }
  int ll[MAX_K], rr[MAX_K];
  query(obj, o * 2, l, m, left, right, ll);
  query(obj, o * 2 + 1, m + 1, r, left, right, rr);
  merge_pre(obj, ll, rr, res);
}

int *resultArray(int *nums, int numsSize, int k, int **queries, int queriesSize,
                 int *queriesColSize, int *returnSize) {
  int n = numsSize;
  struct segment_tree *seg = segment_tree_init(nums, n, k);
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  for (int i = 0; i < queriesSize; i++) {
    int *q = queries[i];
    int idx = q[0];
    int val = q[1];
    int beg = q[2];
    int num = q[3];
    update(seg, 1, 0, n - 1, idx, val);
    int pre[MAX_K];
    query(seg, 1, 0, n - 1, beg, n - 1, pre);
    ans[i] = pre[num];
  }
  segment_tree_free(seg);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5}, r1[] = {0, 0, 3}, rs1;
  int q1i[3][4] = {{2, 2, 0, 2}, {3, 3, 3, 0}, {0, 1, 0, 1}};
  int n2[] = {1, 2, 4, 8, 16, 32}, r2[] = {5, 5}, rs2;
  int q2i[2][4] = {{0, 2, 0, 2}, {0, 2, 0, 1}};
  int n3[] = {1, 1, 2, 1, 1}, r3[] = {3}, rs3;
  int q3i[1][4] = {{2, 1, 0, 1}};
  struct two_d_arr *q1 = two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i), q1i);
  struct two_d_arr *q2 = two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i), q2i);
  struct two_d_arr *q3 = two_d_arr_init(ARRAY_SIZE(q3i), ARRAY_SIZE(q3i), q3i);
  int *ra1 = resultArray(n1, ARRAY_SIZE(n1), 3, q1->arr, q1->row_size,
                         q1->col_size, &rs1);
  int *ra2 = resultArray(n2, ARRAY_SIZE(n2), 4, q2->arr, q2->row_size,
                         q2->col_size, &rs2);
  int *ra3 = resultArray(n3, ARRAY_SIZE(n3), 2, q3->arr, q3->row_size,
                         q3->col_size, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", ra1[i]);
    assert(ra1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", ra2[i]);
    assert(ra2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", ra3[i]);
    assert(ra3[i] == r3[i]);
  }
  printf("\n");
  free(ra1);
  free(ra2);
  free(ra3);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
  two_d_arr_free(q3);
}
