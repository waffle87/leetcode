// 3841. Palindromic Path Queries in a Tree
#include "leetcode.h"

/*
 * you are given an undirected tree with 'n' nodes labeled 0 to 'n - 1'. this is
 * represented by a 2d array 'edges' of length 'n - 1' where 'edges[i] = [ui,
 * vi]' indicates an undirected edge between nodes 'ui' and 'vi'. you are also
 * given a string 's' of length 'n' consisting of lowercase english letters,
 * where 's[i]' represents the character assigned to node 'i'. you are also
 * given a string 'queries' where each 'queries[i]' is either 'update ui c':
 * change the character at node 'ui' to 'c', or 'query ui vi': determine whether
 * the string formed by the characters on the unique path from 'ui' to 'vi' can
 * be rearranged into a palindrome. return a boolean array 'answer' where
 * 'answer[j]' is true if the 'j'th query of type query can be arranged into a
 * palindrome and false otherwise.
 */

struct bit {
  int *tree;
  int n;
};

static int low_bit(int x) { return x & -x; }

static void bit_init(struct bit *obj, int n) {
  obj->n = n;
  obj->tree = (int *)calloc(n + 1, sizeof(int));
}

static void bit_update(struct bit *obj, int x, int v) {
  while (x <= obj->n) {
    obj->tree[x] ^= v;
    x += low_bit(x);
  }
}

static int bit_query(struct bit *obj, int x) {
  int res = 0;
  while (x > 0) {
    res ^= obj->tree[x];
    x -= low_bit(x);
  }
  return res;
}

static void bit_update_range(struct bit *obj, int l, int r, int v) {
  bit_update(obj, l, v);
  bit_update(obj, r + 1, v);
}

struct graph {
  int *head;
  int *to;
  int *next;
  int edge_cnt;
};

static void graph_init(struct graph *obj, int n, int max_edges) {
  obj->head = (int *)malloc(n * sizeof(int));
  obj->to = (int *)malloc(max_edges * sizeof(int));
  obj->next = (int *)malloc(max_edges * sizeof(int));
  memset(obj->head, -1, n * sizeof(int));
}

static void graph_add(struct graph *obj, int u, int v) {
  obj->to[obj->edge_cnt] = v;
  obj->next[obj->edge_cnt] = obj->head[u];
  obj->head[u] = obj->edge_cnt++;
}

static void graph_free(struct graph *obj) {
  free(obj->head);
  free(obj->to);
  free(obj->next);
}

static void dfs(int u, int p, struct graph *gr, int **fa, int *dep, int *l,
                int *r, int *time) {
  (*time)++;
  l[u] = *time;
  fa[u][0] = p;
  for (int i = gr->head[u]; i != -1; i = gr->next[i]) {
    int v = gr->to[i];
    if (v == p)
      continue;
    dep[v] = dep[u] + 1;
    dfs(v, u, gr, fa, dep, l, r, time);
  }
  r[u] = *time;
}

static int lca(int u, int v, int *dep, int **fa, int log) {
  if (dep[u] < dep[v]) {
    int tmp = u;
    u = v;
    v = tmp;
  }
  int diff = dep[u] - dep[v];
  for (int i = 0; i < log; i++)
    if ((diff >> i) & 1)
      u = fa[u][i];
  if (u == v)
    return u;
  for (int i = log - 1; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
    }
  return fa[u][0];
}

bool *palindromePath(int n, int **edges, int edgesSize, int *edgesColSize,
                     char *s, char **queries, int queriesSize,
                     int *returnSize) {
  struct graph gr;
  graph_init(&gr, n, 2 * edgesSize + 1);
  for (int i = 0; i < edgesSize; i++) {
    graph_add(&gr, edges[i][0], edges[i][1]);
    graph_add(&gr, edges[i][1], edges[i][0]);
  }
  int log = 1, time = 0;
  while ((1 << log) <= n)
    log++;
  int **fa = (int **)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    fa[i] = (int *)calloc(log, sizeof(int));
  int *dep = (int *)calloc(n, sizeof(int));
  int *l = (int *)calloc(n, sizeof(int));
  int *r = (int *)calloc(n, sizeof(int));
  dfs(0, 0, &gr, fa, dep, l, r, &time);
  for (int j = 1; j < log; j++)
    for (int i = 0; i < n; i++)
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
  struct bit tree;
  bit_init(&tree, n + 1);
  for (int i = 0; i < n; i++)
    bit_update_range(&tree, l[i], r[i], 1 << (s[i] - 'a'));
  bool *ans = (bool *)malloc(queriesSize * sizeof(bool));
  *returnSize = 0;
  for (int qi = 0; qi < queriesSize; qi++) {
    char *q = queries[qi], *p = q;
    while (*p == ' ')
      p++;
    if (*p == 'u') {
      int u;
      char c;
      sscanf(p, "update %d %c", &u, &c);
      bit_update_range(&tree, l[u], r[u],
                       (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
      s[u] = c;
    } else {
      int u, v;
      sscanf(p, "query %d %d", &u, &v);
      int w = lca(u, v, dep, fa, log);
      int mask =
          bit_query(&tree, l[u]) ^ bit_query(&tree, l[v]) ^ (1 << (s[w] - 'a'));
      ans[(*returnSize)++] = __builtin_popcount(mask) <= 1;
    }
  }
  for (int i = 0; i < n; i++)
    free(fa[i]);
  free(fa);
  free(dep);
  free(l);
  free(r);
  free(tree.tree);
  graph_free(&gr);
  return ans;
}

int main() {
  int e1i[2][2] = {{0, 1}, {1, 2}}, rs1;
  int e2i[3][2] = {{0, 1}, {0, 2}, {0, 3}}, rs2;
  bool r1[] = {true, false};
  bool r2[] = {false, false, true};
  char *s1 = "aac";
  char *q1[] = {"query 0 2", "update 1 b", "query 0 2"};
  char *s2 = "abca";
  char *q2[] = {"query 1 2", "update 0 b", "query 2 3", "update 3 a",
                "query 1 3"};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  bool *pp1 = palindromePath(3, e1->arr, e1->row_size, e1->col_size, s1, q1,
                             ARRAY_SIZE(q1), &rs1);
  bool *pp2 = palindromePath(4, e2->arr, e2->row_size, e2->col_size, s2, q2,
                             ARRAY_SIZE(q2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", pp1[i]);
    assert(pp1[i] == r1[i]);
  };
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", pp2[i]);
    assert(pp2[i] == r2[i]);
  };
  printf("\n");
  free(pp1);
  free(pp2);
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
