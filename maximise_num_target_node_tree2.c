// 3373. Maximize the Number of Target Nodes After Connecting Trees II
#include "leetcode.h"

/*
 * there exists two undirect trees with 'n' and 'm' nodes, labeled from '[0, n -
 * 1]' andc '[0, m - 1]' respectively. you are given two 2d integer arrays
 * 'edges1' and 'edges2' of lengths 'n - 1' and 'm - 1' respectively. node 'u'
 * is target to node 'v' if the number of edges on the path from 'u' to 'v' is
 * even. note that a node is always target to itself. return an array of
 * integers where 'ans[i]' is the maximum possible number of nodes that are
 * target to node 'i' of the first tree if you had to connect one node from the
 * first tree to another node in the second tree. note that queries are
 * independent from each other. that is, for every query, you will remove the
 * added edge before proceeding to the next query.
 */

int *maxTargetNodes(int **edges1, int edges1Size, int *edges1ColSize,
                    int **edges2, int edges2Size, int *edges2ColSize,
                    int *returnSize) {
  int n = edges1Size + 1, m = edges2Size + 1;
  *returnSize = n;
  int *ans = (int *)malloc(n * sizeof(int));
  int *g1deg = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < edges1Size; i++) {
    int u = edges1[i][0], v = edges1[i][1];
    g1deg[u]++;
    g1deg[v]++;
  }
  int **g1adj = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    g1adj[i] = (int *)malloc(g1deg[i] * sizeof(int));
  int *tmpd1 = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < edges1Size; i++) {
    int u = edges1[i][0], v = edges1[i][1];
    g1adj[u][tmpd1[u]++] = v;
    g1adj[v][tmpd1[v]++] = u;
  }
  free(tmpd1);
  int *c1 = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    c1[i] = -1;
  int *q1 = (int *)malloc(n * sizeof(int));
  int front1 = 0, rear1 = 0, cnt10 = 0, cnt11 = 0;
  c1[0] = 0;
  cnt10++;
  q1[rear1++] = 0;
  while (front1 < rear1) {
    int u = q1[front1++];
    for (int i = 0; i < g1deg[u]; i++) {
      int v = g1adj[u][i];
      if (c1[v] == -1) {
        c1[v] = c1[u] ^ 1;
        if (!c1[v])
          cnt10++;
        else
          cnt11++;
        q1[rear1++] = v;
      }
    }
  }
  for (int i = 0; i < n; i++)
    free(g1adj[i]);
  free(g1adj);
  free(g1deg);
  free(q1);

  int *g2deg = (int *)calloc(m, sizeof(int));
  for (int i = 0; i < edges2Size; i++) {
    int u = edges2[i][0], v = edges2[i][1];
    g2deg[u]++;
    g2deg[v]++;
  }
  int **g2adj = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++)
    g2adj[i] = (int *)malloc(g2deg[i] * sizeof(int));
  int *tmpd2 = (int *)calloc(m, sizeof(int));
  for (int i = 0; i < edges2Size; i++) {
    int u = edges2[i][0], v = edges2[i][1];
    g2adj[u][tmpd2[u]++] = v;
    g2adj[v][tmpd2[v]++] = u;
  }
  free(tmpd2);
  int *v2 = (int *)malloc(m * sizeof(int));
  for (int i = 0; i < m; i++)
    v2[i] = -1;
  int *q2 = (int *)malloc(m * sizeof(int));
  int front2 = 0, rear2 = 0, cnt20 = 0, cnt21 = 0;
  v2[0] = 0;
  cnt20++;
  q2[rear2++] = 0;
  while (front2 < rear2) {
    int u = q2[front2++];
    for (int i = 0; i < g2deg[u]; i++) {
      int v = g2adj[u][i];
      if (v2[v] == -1) {
        v2[v] = v2[u] ^ 1;
        if (!v2[v])
          cnt20++;
        else
          cnt21++;
        q2[rear2++] = v;
      }
    }
  }
  int m2 = cnt20 > cnt21 ? cnt20 : cnt21;
  for (int i = 0; i < n; i++)
    ans[i] = (!c1[i] ? cnt10 : cnt11) + m2;
  free(c1);
  return ans;
}

int main() {
  int e11i[4][2] = {{0, 1}, {0, 2}, {2, 3}, {2, 4}},
      e21i[7][2] = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}},
      rs1;
  int e12i[4][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}},
      e22i[3][2] = {{0, 1}, {1, 2}, {2, 3}}, rs2;
  struct two_d_arr e11, e21, e12, e22;
  two_d_arr_init(&e11, ARRAY_SIZE(e11i), ARRAY_SIZE(e11i[0]), e11i);
  two_d_arr_init(&e21, ARRAY_SIZE(e21i), ARRAY_SIZE(e21i[0]), e21i);
  two_d_arr_init(&e12, ARRAY_SIZE(e12i), ARRAY_SIZE(e12i[0]), e12i);
  two_d_arr_init(&e22, ARRAY_SIZE(e22i), ARRAY_SIZE(e22i[0]), e22i);
  int *mtn1 = maxTargetNodes(e11.arr, e11.row_size, e11.col_size, e21.arr,
                             e21.row_size, e21.col_size, &rs1);
  int *mtn2 = maxTargetNodes(e12.arr, e12.row_size, e12.col_size, e22.arr,
                             e22.row_size, e22.col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", mtn1[i]); // expect: 8 7 7 8 8
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", mtn2[i]); // expect: 3 6 6 6 6
  printf("\n");
  free(mtn1);
  free(mtn2);
  two_d_arr_free(&e11);
  two_d_arr_free(&e21);
  two_d_arr_free(&e12);
  two_d_arr_free(&e22);
}
