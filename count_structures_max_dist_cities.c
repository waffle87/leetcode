// 1617. Count Subtrees With Max Distance Between Cities
#include "leetcode.h"

/*
 * there are 'n' cities numbered from 1 to 'n'. you are given an array 'edges'
 * of size 'n - 1', where 'edges[i] = [ui, vi]' represents a bidirectional edge
 * between cities 'ui' and 'vi'. there exists a unique path between each pair of
 * cities. in other words, the cities form a tree. a subtree is a subset of
 * cities where every city is reachable from every other city in the subset,
 * where the path between each pair passes through only the cities from the
 * subset. two subtrees are different if there is a city in one subtree that is
 * not present in the other. for each 'd' from 'n - 1', find the number of
 * subtrees in which the maximum distance between any two cities in the subtree
 * is equal to 'd'. return an array of size 'n - 1' where the d'th element is
 * the number of subtrees in which the maximum distance between any two cities
 * is equal to 'd'. notice that the distance between the two cities is the
 * number of edges in the path between them.
 */

struct arr {
  int size;
  int data[15];
};

static struct arr adj[15];

struct arr *combinations(struct arr *a, struct arr *b) {
  if (a->size > b->size)
    return combinations(b, a);
  struct arr *res = (struct arr *)calloc(1, sizeof(struct arr));
  res->size = b->size;
  res->data[0] = a->data[0] * b->data[0];
  for (int i = 1; i < a->size; ++i)
    a->data[i] += a->data[i - 1];
  for (int i = 1; i < b->size; ++i)
    b->data[i] += b->data[i - 1];
  for (int i = 1; i < a->size; ++i)
    res->data[i] = a->data[i] * b->data[i] - a->data[i - 1] * b->data[i - 1];
  for (int i = a->size; i < b->size; ++i)
    res->data[i] = (b->data[i] - b->data[i - 1]) * a->data[a->size - 1];
  return res;
}

struct arr *dfs(int root, int parent) {
  struct arr *res = (struct arr *)malloc(sizeof(struct arr));
  res->data[0] = res->size = 1;
  struct arr *tmp, *comb;
  for (int i = 0; i < adj[root].size; ++i) {
    int node = adj[root].data[i];
    if (node == parent)
      continue;
    tmp = dfs(node, root);
    comb = combinations(tmp, res);
    free(tmp);
    free(res);
    res = comb;
  }
  memmove(res->data + 1, res->data, res->size * sizeof(int));
  res->data[0] = 1;
  ++res->size;
  return res;
}

int *countSubgraphsForEachDiameter(int n, int **edges, int edgesSize,
                                   int *edgesColSize, int *returnSize) {
  for (int i = 0; i < n; ++i)
    adj[i].size = 0;
  for (int i = 0; i < edgesSize; ++i) {
    int u = edges[i][0] - 1, v = edges[i][1] - 1;
    adj[u].data[adj[u].size++] = v;
    adj[v].data[adj[v].size++] = u;
  }
  int res[15] = {0};
  for (int i = 0; i < edgesSize; ++i) {
    int u = edges[i][0] - 1, v = edges[i][1] - 1;
    struct arr *ut = dfs(u, v), *vt = dfs(v, u);
    int min = fmin(ut->size, vt->size);
    for (int j = 1; j < min; ++j)
      res[(j << 1) - 1] += ut->data[j] * vt->data[j];
    free(ut);
    free(vt);
  }
  for (int i = 0; i < n; ++i) {
    if (adj[i].size == 1)
      continue;
    struct arr *tree = dfs(adj[i].data[0], i);
    int curr[15] = {0};
    for (int j = 1; j < adj[i].size; ++j) {
      struct arr *curr_tree = dfs(adj[i].data[j], i);
      int k = 1, prefix = curr_tree->data[1] + 1;
      for (int l = 4; l < n; l += 2) {
        while (k + 1 < fmin(l >> 1, curr_tree->size))
          prefix += curr_tree->data[++k];
        curr[l] *= prefix;
      }
      int min = fmin(tree->size, curr_tree->size);
      for (int l = 0; l < min; ++l)
        curr[l << 1] += tree->data[l] * curr_tree->data[l];
      struct arr *tmp = combinations(tree, curr_tree);
      free(tree);
      free(curr_tree);
      tree = tmp;
    }
    free(tree);
    for (int j = 2; j < n; j += 2)
      res[j] += curr[j];
  }
  int *ans = (int *)malloc((n - 1) * sizeof(int));
  *returnSize = n - 1;
  memcpy(ans, res + 1, (n - 1) * sizeof(int));
  return ans;
}

int main() {
  int e1i[3][2] = {{1, 2}, {2, 3}, {2, 4}}, rs1;
  int e2i[1][2] = {{1, 2}}, rs2;
  int e3i[2][2] = {{1, 2}, {2, 3}}, rs3;
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  struct two_d_arr *e3 =
      two_d_arr_init(ARRAY_SIZE(e3i), ARRAY_SIZE(e3i[0]), e3i);
  int *csfed1 = countSubgraphsForEachDiameter(4, e1->arr, e1->row_size,
                                              e1->col_size, &rs1);
  int *csfed2 = countSubgraphsForEachDiameter(2, e2->arr, e2->row_size,
                                              e2->col_size, &rs2);
  int *csfed3 = countSubgraphsForEachDiameter(3, e3->arr, e3->row_size,
                                              e3->col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", csfed1[i]); // expect: 3 4 0
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", csfed2[i]); // expect: 1
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", csfed3[i]); // expect: 2 1
  printf("\n");
  free(csfed1);
  free(csfed2);
  free(csfed3);
  two_d_arr_free(e1);
  two_d_arr_free(e2);
  two_d_arr_free(e3);
}
