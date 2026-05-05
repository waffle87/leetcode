// 2497. Maximum Star Sum of a Graph
#include "leetcode.h"

/*
 * there is an undirected graph consisting of 'n' nodes numbered from 0 to 'n -
 * 1'. you are given a 0-indexed integer array 'vals' of length 'n' where
 * 'vals[i]' denotes the value of the i'th node. you are also given a 2d integer
 * array 'edges' where 'edges[i] = [ai, bi]' denotes that there exists an
 * undirected edge connecting nodes 'ai' and 'bi'. a star graph is a subgraph of
 * the given graph having a center node containing 0 or more neighbours. given
 * an integer 'k', return the maximum star sum of a star graph containing at
 * most 'k' edges.
 */

struct node {
  int id;
  struct node *next;
};

int cmp(const void *a, const void *b) { return *((int *)b) - *((int *)a); }

int maxStarSum(int *vals, int valsSize, int **edges, int edgesSize,
               int *edgesColSize, int k) {
  int *neighbours = (int *)malloc(valsSize * sizeof(int));
  int ans = INT_MIN;
  struct node **adj = (struct node **)calloc(valsSize, sizeof(struct node *));
  for (int i = 0; i < edgesSize; i++) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->id = edges[i][0];
    tmp->next = adj[edges[i][1]];
    adj[edges[i][1]] = tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->id = edges[i][1];
    tmp->next = adj[edges[i][0]];
    adj[edges[i][0]] = tmp;
  }
  for (int i = 0; i < valsSize; i++) {
    int cnt = 0;
    for (struct node *j = adj[i], *l; j;) {
      neighbours[cnt] = vals[j->id];
      l = j;
      j = j->next;
      free(l);
      cnt++;
    }
    qsort(neighbours, cnt, sizeof(int), cmp);
    int sum = vals[i];
    for (int j = 0; j < k && j < cnt && neighbours[j] > 0; j++)
      sum += neighbours[j];
    ans = fmax(ans, sum);
  }
  free(neighbours);
  free(adj);
  return ans;
}

int main() {
  int v1[] = {1, 2, 3, 4, 10, -10, -20},
      e1i[6][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}, {3, 6}};
  int v2[] = {-5}, e2i[] = {{}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 = two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i), e2i);
  int r1 =
      maxStarSum(v1, ARRAY_SIZE(v1), e1->arr, e1->row_size, e1->col_size, 2);
  int r2 =
      maxStarSum(v2, ARRAY_SIZE(v2), e2->arr, e2->row_size, e2->col_size, 0);
  printf("%d\n", r1);
  assert(r1 == 16);
  printf("%d\n", r2);
  assert(r2 == -5);
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
