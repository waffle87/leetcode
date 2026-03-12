// 3600. Maximize Spanning Tree Stability with Upgrades
#include "leetcode.h"

/*
 * you are given an integer 'n' representing 'n' nodes numbered from 0 to 'n -
 * 1' and a list of 'edges' where 'edges[i] = [ui, vi, si, musti]'. you are also
 * given an integer 'k', the maximum number of upgrades you can perform. each
 * upgrade doubles the strength of an ede, and each eligible edge (with 'musti
 * == 0') can be upgraded at most once. the stability of a spanning tree is
 * defined as the minimum strength score among all edges included in it. return
 * the maximum possible stability of any valid spanning tree. if it is
 * impossible to connect all nodes, return -1.
 */

struct edge {
  int u;
  int v;
  int w;
};

static int components;

int find_parent(int *parent, int u) {
  if (parent[u] == -1)
    return u;
  else
    return parent[u] = find_parent(parent, parent[u]);
}

void unite(int *parent, int *size, int u, int v) {
  u = find_parent(parent, u);
  v = find_parent(parent, v);
  if (u == v)
    return;
  components--;
  if (size[u] > size[v]) {
    size[u] += size[v];
    parent[v] = u;
  } else {
    size[v] += size[u];
    parent[u] = v;
  }
}

void merge(int l, int r, int m, struct edge *e) {
  int i, j, k, n1 = m - l + 1, n2 = r - m;
  struct edge *el = (struct edge *)malloc(n1 * sizeof(struct edge));
  struct edge *er = (struct edge *)malloc(n2 * sizeof(struct edge));
  for (i = 0; i < n1; i++)
    el[i] = e[l + i];
  for (i = 0; i < n2; i++)
    er[i] = e[m + 1 + i];
  i = j = k = 0;
  while (i < n1 && j < n2) {
    if (el[i].w >= er[j].w) {
      e[k] = el[i];
      i++;
    } else {
      e[k] = er[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    e[k] = el[i];
    i++;
    k++;
  }
  while (j < n2) {
    e[k] = er[j];
    j++;
    k++;
  }
  free(el);
  free(er);
}

void merge_sort(int l, int r, struct edge *e) {
  if (l < r) {
    int m = (l + r) / 2;
    merge_sort(l, m, e);
    merge_sort(m + 1, r, e);
    merge(l, r, m, e);
  }
}

int maxStability(int n, int **edges, int edgesSize, int *edgesColSize, int k) {
  components = n;
  int *parent = (int *)malloc(n * sizeof(int));
  int *size = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    parent[i] = -1;
    size[i] = 1;
  }
  struct edge *optional =
      (struct edge *)malloc(edgesSize * sizeof(struct edge));
  int optional_cnt = 0, ans = INT_MAX;
  for (int i = 0; i < edgesSize; i++) {
    int u = edges[i][0], v = edges[i][1], w = edges[i][2], must = edges[i][3];
    if (must) {
      if (find_parent(parent, u) == find_parent(parent, v))
        return -1;
      unite(parent, size, u, v);
      ans = fmin(ans, w);
    } else {
      struct edge e;
      e.u = u;
      e.v = v;
      e.w = w;
      optional[optional_cnt++] = e;
    }
  }
  merge_sort(0, optional_cnt - 1, optional);
  int *taken = (int *)malloc(edgesSize * sizeof(int));
  int track_idx = 0;
  for (int i = 0; i < optional_cnt; i++) {
    int u = optional[i].u, v = optional[i].v;
    if (find_parent(parent, u) == find_parent(parent, v))
      continue;
    unite(parent, size, u, v);
    taken[track_idx++] = optional[i].w;
  }
  if (components > 1)
    return -1;
  for (int i = track_idx - 1; k && i >= 0; i--, k--)
    taken[i] *= 2;
  for (int i = track_idx - 1; i >= 0; i--)
    ans = fmin(ans, taken[i]);
  free(parent);
  free(size);
  free(optional);
  free(taken);
  return ans;
}

int main() {
  int e1i[2][4] = {{0, 1, 2, 1}, {1, 2, 3, 0}};
  int e2i[3][4] = {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}};
  int e3i[3][4] = {{0, 1, 1, 1}, {1, 2, 1, 1}, {2, 0, 1, 1}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  struct two_d_arr *e3 =
      two_d_arr_init(ARRAY_SIZE(e3i), ARRAY_SIZE(e3i[0]), e3i);
  int r1 = maxStability(3, e1->arr, e1->row_size, e1->col_size, 1);
  int r2 = maxStability(3, e2->arr, e2->row_size, e2->col_size, 2);
  int r3 = maxStability(3, e3->arr, e3->row_size, e3->col_size, 0);
  printf("%d\n", r1); // expect: 2
  assert(r1 == 2);
  printf("%d\n", r2); // expect: 6
  assert(r2 == 6);
  printf("%d\n", r3); // expect: -1
  assert(r3 == -1);
  two_d_arr_free(e1);
  two_d_arr_free(e2);
  two_d_arr_free(e3);
}
